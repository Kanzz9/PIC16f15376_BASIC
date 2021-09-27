#ifndef SW_I2C1_MASTER_H
#define SW_I2C1_MASTER_H

#include <stdint.h>
#include <stdbool.h>
#include "SW_I2C_Master_Cfg.h"

#define SW_I2C_OK   0
#define SW_I2C_BUSY 1
#define SW_I2C_ERR  (-1)

/* *************************************************************** Simple API */
void SW_I2C_Init(void); //Call first, return 0: success
void SW_I2C_ReadNBytes(uint8_t address, uint8_t *data, size_t len);
void SW_I2C_WriteNBytes(uint8_t address, uint8_t *data, size_t len);
/* ************************************************************* Advanced API */
int8_t SW_I2C_Open(uint8_t SlvAddr);
int8_t SW_I2C_Close(void);
int8_t SW_I2C_MasterOperation(bool read);
void SW_I2C_SetBuffer(void *buffer, size_t bufferSize);

#endif