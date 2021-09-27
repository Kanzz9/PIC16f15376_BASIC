/* 
 * File:   i2c_config.h
 * Author: hoang
 *
 * Created on May 6, 2021, 4:22 PM
 */

#ifndef I2C_CONFIG_H
#define	I2C_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"
   
void I2C_Init(void);
void I2C_Wait_For_Idle(void);
void I2C_Start(void);
void I2C_Stop();
void I2C_Restart();
void I2C_Ack(void);
void I2C_Nack(void);
void I2C_Write(uint8_t address, char wait_ack);
void I2C_Read(uint8_t *value, char ack_nack);
uint8_t I2C_Mem_Write(uint8_t DevAddress, uint8_t RegAddress, uint8_t *data, uint16_t lenght);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_CONFIG_H */

