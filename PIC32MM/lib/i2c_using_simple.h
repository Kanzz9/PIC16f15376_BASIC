/*
 * author: Hoang Khanh Toan
 * 
 */
#include "../../PIC32MM/RPR_0521RS.X/mcc_generated_files/mcc.h"
#include "mcc.h"
#ifndef i2c_using_simple_H
#define i2c_using_simple_H

#if(i2c_using_simple_Enable)

void I2C_Scan_Multi(void);

void I2C_Write(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount);

#endif
#endif