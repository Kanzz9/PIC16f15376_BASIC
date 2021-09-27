/*
 * Author: Hoang Khanh Toan
 * Create: 1:15 AM
 * Date: 22/08/2021
 */
#include "BMP180.h"
#if(BMP180_ENABLE)
#include "I2C.h"
/*
 * @brief write 1 byte into the BMP180
 * @return non
 */
void BMP180WriteByte(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t data){
    
    bool ACK_bit = 1;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    Send_I2C_Data(Reg_Add);
    Send_I2C_Data(data);
    Send_I2C_StopBit();
}

/*
 * @brief Read 1 byte from the BMP180
 * @return data of Reg_Add
 */
uint8_t BMP180ReadByte(const BMP180_t *BMP180, uint8_t Reg_Add){
    
    bool ACK_bit = 1;            // init the Ack bit high
    uint8_t data=0;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    //Send_I2C_ACK();
    Send_I2C_Data(Reg_Add);
    //Send_I2C_ACK();
    
    ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 1);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    data=Read_I2C_Data();
    Send_I2C_NAK();
    Send_I2C_StopBit();  
    
    return data;
}

/*
 * @brief Read multiple byte into the BMP180
 * @return non
 */
void BMP180ReadMultiByte(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t *data, uint8_t length){
    
    bool ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    //Send_I2C_ACK();
    Send_I2C_Data(Reg_Add);
    //Send_I2C_ACK();
    
    ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 1);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    
    for(uint8_t i=0; i<(length-1); i++){
        
        *(data+i)=Read_I2C_Data();
        //__delay_us(15);
        Send_I2C_ACK();
    }
    *(data+(length-1))=Read_I2C_Data();
    Send_I2C_NAK();
    Send_I2C_StopBit();
}

/*
 * @brief Reset BMP180
 * @return non
 */
void BMP180Reset(const BMP180_t *BMP180){
    
    BMP180WriteByte(BMP180, BMP180_SOFT_RESET_REGISTER, BMP180_COMMAND_RESET);
}

/*
 * @brief Read data from EEPROM of BMP180
 * @return non
 */
void BMP180ReadEeprom(BMP180_t *BMP180){
    
    uint8_t data[22]={0};
 
    BMP180ReadMultiByte(BMP180, BMP180_INDEX_EEPROM_REGISTER, data, 22);    // 22 means the number of bytes to read
    
    BMP180->AC1 = (data[0] << 8) + data[1];
    BMP180->AC2 = (data[2] << 8) + data[3];
    BMP180->AC3 = (data[4] << 8) + data[5];
    BMP180->AC4 = (data[6] << 8) + data[7];
    BMP180->AC5 = (data[8] << 8) + data[9];
    BMP180->AC6 = (data[10] << 8) + data[11];
    BMP180->B1  = (data[12] << 8) + data[13];
    BMP180->B2  = (data[14] << 8) + data[15];
    BMP180->MB  = (data[16] << 8) + data[17];
    BMP180->MC  = (data[18] << 8) + data[19];
    BMP180->MD  = (data[20] << 8) + data[21];  
}

/*
 * @brief init BMP180
 * @return non
 */
void BMP180_Init(BMP180_t *BMP180){
    
    BMP180Reset(BMP180);
    BMP180_ID_Request(BMP180);
    BMP180ReadEeprom(BMP180);
}


/*
 * @brief Read uncompensated tempparature value
 * @return data UT
 */
int32_t BMP180ReadTeamUT(BMP180_t *BMP180){
    
    uint8_t data[2]={0};
    
    BMP180WriteByte(BMP180, BMP180_CTRL_MESUREMENT_REGISTER, BMP180_COMMAND_TEMPERATURE);
    __delay_ms(5);
    BMP180ReadMultiByte(BMP180, BMP180_OUT_MSB_REGISTER, data, 2);
    
    return ((data[0] << 8) + data[1]);
}

/*
 * @brief Read uncompensated pressure value
 * @return data UP
 */
int32_t BMP180ReadPressUP(BMP180_t *BMP180){
    
    uint8_t data[3]={0};
    int32_t press;
    BMP180WriteByte(BMP180, BMP180_CTRL_MESUREMENT_REGISTER, BMP180_COMMAND_PRESSURE0); // note: option BMP180_COMMAND_PRESSURE0 + oss<<6 
    __delay_ms(5);
    BMP180ReadMultiByte(BMP180, BMP180_OUT_MSB_REGISTER, data, 3);
    
    press = (data[0]<<16) | (data[1]<<8) | data[2];
    //press = press>>8;
    return press;
}

/*
 * @brief Read  tempparature and pressure
 * @return non
 */
void BMP180ReadData(const BMP180_t *BMP180, float *temp){
    
    int32_t X1, X2, B5, UT;
    int32_t X3, B3, B4, B6, B7, UP;
    
    printf("\nBMP180_AC1: %d\n", BMP180->AC1);
    printf("BMP180_AC2: %d\n", BMP180->AC2);
    printf("BMP180_AC3: %d\n", BMP180->AC3);
    printf("BMP180_AC4: %d\n", BMP180->AC4);
    printf("BMP180_AC5: %d\n", BMP180->AC5);
    printf("BMP180_AC6: %d\n", BMP180->AC6);
    printf("BMP180_B1: %d\n", BMP180->B1);
    printf("BMP180_B2: %d\n", BMP180->B2);
    printf("BMP180_MB: %d\n", BMP180->MB);
    printf("BMP180_MC: %d\n", BMP180->MC);
    printf("BMP180_MD: %d\n", BMP180->MD);
    
    UT = BMP180ReadTeamUT(BMP180);
    printf("BMP180_UT: %d\n", UT);
    
    X1 = (int32_t)UT-BMP180->AC6;
    X1 = X1*BMP180->AC5/32768;
    printf("BMP180_X1: %ld\n", X1);
    X2 = (int32_t)BMP180->MC*2048;
    X2 = X2/(X1+BMP180->MD);
    printf("BMP180_X2: %ld\n", X2);
    B5 = X1 + X2;
    printf("BMP180_B5: %d\n", B5);
    *temp = (float)(B5 + 8)/160.0; 
    
    UP = BMP180ReadPressUP(BMP180);
    printf("BMP180_UP: %ld\n", UP);
}

/*
 * @brief Read ID from BMP180
 * @return ID of BM180
 */
uint8_t BMP180_ID_Request(BMP180_t *BMP180){
    
    uint8_t BMP180_ID = 0;
    
    BMP180_ID = BMP180ReadByte(BMP180, BMP180_ID_REGISTER);
    BMP180->BMP180_Id = BMP180_ID;
    
    #if(UART_ENABLE)
        printf("BMP180 ID: %d\n", BMP180_ID);
    #endif

    return BMP180_ID;
}

/*
uint8_t ReadADC_BMP180(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t len){
    
    bool ACK_bit = 1;            // init the Ack bit high
    uint8_t *data=0;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    //Send_I2C_ACK();
    Send_I2C_Data(Reg_Add);
    //Send_I2C_ACK();
    
    ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BMP180->BMP180_Add, 1);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    for(uint8_t x ; x < len ;x++)
    {
        data[x] = Read_I2C_Data();
    }
    Send_I2C_NAK();
    Send_I2C_StopBit();  
    
    return data;
}
uint8_t startTemperature(void)
// Begin a temperature reading.
// Will return delay in ms to wait, or 0 if I2C error
{
	uint8_t data[2], result;
	
	data[0] = BMP180_REG_CONTROL;
	data[1] = BMP180_COMMAND_TEMPERATURE;
	 WriteByteBMP180(0x77,result,data);
	if (result) // good write?
		return(5); // return the delay in ms (rounded up) to wait before retrieving data
	else
		return(0); // or return 0 if there was a problem communicating with the BMP
}
uint8_t getTemperature(uint8_t *T)
// Retrieve a previously-started temperature reading.
// Requires begin() to be called once prior to retrieve calibration parameters.
// Requires startTemperature() to have been called prior and sufficient time elapsed.
// T: external variable to hold result.
// Returns 1 if successful, 0 if I2C error.
{
	unsigned char data[2];
	uint8_t result;
	double tu, a;
	
	data[0] = BMP180_REG_RESULT;

	result = ReadADC_BMP180(0X77, BMP180_REG_RESULT, 2);
	if (result) // good read, calculate temperature
	{
		
	
	}
	return(result);
}

*/
#endif