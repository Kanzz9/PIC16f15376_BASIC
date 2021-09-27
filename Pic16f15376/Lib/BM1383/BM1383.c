/*
 * Author: Hoang Khanh Toan
 * Create: 12:22AM
 * Date: 19/08/2021
 */
#include "BM1383.h"

#if(BM1383_ENABLE)

#include "I2C.h"

/*
 * @brief write 1 byte into the BM1383
 * @return non
 */
void WriteByteBM1383(const BM1383_t *BM1383, uint8_t Reg_Add, uint8_t data){
    
    bool ACK_bit = 1;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BM1383->BM1383_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    Send_I2C_Data(Reg_Add);
    Send_I2C_Data(data);
    Send_I2C_StopBit();
}

uint8_t ReadByteBM1383(const BM1383_t *BM1383, uint8_t Reg_Add){
    
    bool ACK_bit = 1;            // init the Ack bit high
    uint8_t data=0;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BM1383->BM1383_Add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    //Send_I2C_ACK();
    Send_I2C_Data(Reg_Add);
    //Send_I2C_ACK();
    
    ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(BM1383->BM1383_Add, 1);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    data=Read_I2C_Data();
    Send_I2C_NAK();
    Send_I2C_StopBit();  
    
    return data;
}
                                                                

#endif
