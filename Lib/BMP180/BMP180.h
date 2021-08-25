/* 
 * File:   BMP180.h
 * Author: HoangKhanhToan
 *
 * Created on August 22, 2021, 1:00 AM
 */

#ifndef BMP180_H
#define	BMP180_H
//#include"stdio.h"
#include "../../BM1383+BMP180/BM1383_BMP180_basic.X/mcc_generated_files/mcc.h"

#if(BMP180_ENABLE)

typedef struct {
    uint8_t BMP180_Add;
}BMP180_t;
#endif
#define	BMP180_REG_CONTROL 0xF4
#define	BMP180_REG_RESULT 0xF6

#define	BMP180_COMMAND_TEMPERATURE 0x2E
#define	BMP180_COMMAND_PRESSURE0 0x34
#define	BMP180_COMMAND_PRESSURE1 0x74
#define	BMP180_COMMAND_PRESSURE2 0xB4
#define	BMP180_COMMAND_PRESSURE3 0xF4
#endif	/* BMP180_H */

