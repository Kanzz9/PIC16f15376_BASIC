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
void WriteByteBMP180(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t data){
    
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

uint8_t ReadByteBMP180(const BMP180_t *BMP180, uint8_t Reg_Add){
    
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
#endif