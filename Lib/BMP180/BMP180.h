/* 
 * File:   BMP180.h
 * Author: HoangKhanhToan
 *
 * Created on August 22, 2021, 1:00 AM
 */

#ifndef BMP180_H
#define	BMP180_H
//#include"stdio.h"
#include "../../BMP180/BMP180_basic.X/mcc_generated_files/mcc.h"

#if(BMP180_ENABLE)

typedef enum{
   TIME_1 = 0,
   TIMES_2,
   TIMES_4,
   TIMES_8
}Oversampling_Pressure_t;

typedef struct {
   uint8_t BMP180_Add;
   uint8_t BMP180_Id;
   uint8_t BMP180_OSS;
   int16_t AC1;
   int16_t AC2;
   int16_t AC3;
   uint16_t AC4;
   uint16_t AC5;
   uint16_t AC6;
   int16_t B1;
   int16_t B2;
   int16_t MB;
   int16_t MC;
   int16_t MD;
}BMP180_t;

#define	BMP180_COMMAND_TEMPERATURE 0x2E
#define	BMP180_COMMAND_PRESSURE0   0x34
#define	BMP180_COMMAND_PRESSURE1   0x74
#define	BMP180_COMMAND_PRESSURE2   0xB4
#define	BMP180_COMMAND_PRESSURE3   0xF4
#define	BMP180_COMMAND_RESET       0xB6

#define  BMP180_ID_REGISTER               0xD0
#define  BMP180_SOFT_RESET_REGISTER       0xE0
#define  BMP180_CTRL_MESUREMENT_REGISTER  0xF4
#define  BMP180_OUT_MSB_REGISTER          0xF6
#define  BMP180_OUT_LSB_REGISTER          0xF7
#define  BMP180_OUT_XLSB_REGISTER         0xF8
#define  BMP180_INDEX_EEPROM_REGISTER     0xAA

void BMP180WriteByte(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t data);
uint8_t BMP180ReadByte(const BMP180_t *BMP180, uint8_t Reg_Add);
void BMP180ReadMultiByte(const BMP180_t *BMP180, uint8_t Reg_Add, uint8_t *data, uint8_t length);

/*
 * @brief init BMP180
 * @return non
 */
void BMP180_Init(BMP180_t *BMP180);

/*
 * @brief Reset BMP180
 * @return non
 */
void BMP180Reset(const BMP180_t *BMP180);

/*
 * @brief Read data from EEPROM of BMP180
 * @return non
 */
void BMP180ReadEeprom(BMP180_t *BMP180);

/*
 * @brief Read uncompensated tempparature value
 * @return data UT
 */
int32_t BMP180ReadTeamUT(BMP180_t *BMP180);

/*
 * @brief Read uncompensated pressure value
 * @return data UP
 */
int32_t BMP180ReadPressUP(BMP180_t *BMP180);

/*
 * @brief Read  tempparature and pressure
 * @return non
 */
void BMP180ReadData(const BMP180_t *BMP180, float *temp);

uint8_t BMP180_ID_Request(BMP180_t *BMP180);

#endif
#endif	/* BMP180_H */

