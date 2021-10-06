/* 
 * File:   I2C.h
 * Author: Toan
 *
 * Created on September 29, 2021, 11:11 PM
 */

#ifndef  I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif


//#include "mcc.h"
//
//#define I2C_TIMEOUT 5
//
//I2C1_MESSAGE_STATUS I2C_Write(uint8_t Dev_add, uint8_t Reg_add, uint8_t data);   
//
//I2C1_MESSAGE_STATUS I2C_Read(uint8_t Dev_add, uint8_t Reg_add, uint8_t *data, uint8_t len);

#include "mcc.h"
#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"   
#if(I2C_Enable)   

#define SLAVE_I2C_GENERIC_RETRY_MAX       5  
#define SLAVE_I2C_GENERIC_SLAVE_TIMEOUT   5
   
void I2C_Scan_Multi(void);
   
I2C1_MESSAGE_STATUS I2C_Write(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount);   

uint8_t I2C_Read(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount);

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

