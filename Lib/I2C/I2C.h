/*
 * author: Hoang Khanh Toan
 * 
 */
#ifndef I2C_H
#define I2C_H

#include "../../BMP180/BMP180_basic.X/mcc_generated_files/mcc.h"

#if(I2C_Enable)

void I2C_Init(void);
uint8_t I2C_Scan(void);
void Send_I2C_Data(uint8_t databyte);
unsigned int Read_I2C_Data(void);
void Send_I2C_ControlByte(uint8_t Dev_Add,uint8_t RW_bit);
void Send_I2C_StartBit(void);
void Send_I2C_StopBit(void);
void Send_I2C_ACK(void);
void Send_I2C_NAK(void);

#endif
#endif

