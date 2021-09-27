/* 
 * File:   MAX7219.h
 * Author: hoang
 *
 * Created on April 2, 2021, 10:13 PM
 */

#ifndef MAX7219_H
#define	MAX7219_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"

  // registers
typedef enum{
    MAX7219_REG_NOOP        = 0x0,
   // codes 1 to 8 are digit positions 1 to 8
    MAX7219_REG_DECODEMODE  = 0x9,
    MAX7219_REG_INTENSITY   = 0xA,
    MAX7219_REG_SCANLIMIT   = 0xB,
    MAX7219_REG_SHUTDOWN    = 0xC,
    MAX7219_REG_DISPLAYTEST = 0xF,
} MAX7219_REG_t;

void MAX7219_Dot_Matrix_sendByte (uint8_t reg, uint8_t data);
void MAX7219_Dot_Matrix_sendToAll (uint8_t reg, uint8_t data, uint8_t Number_Of_Led);
void MAX7219_Dot_Matrix_send64pixels(uint8_t chip, uint8_t pixels [8], uint8_t Number_Of_Led);
void MAX7219_Dot_Matrix_sendChar (uint8_t chip, uint8_t data, uint8_t Number_Of_Led);
void MAX7219_Dot_Matrix_sendString (uint8_t* s, uint8_t Number_Of_Led);
void MAX7219_Dot_Matrix_sendSmooth(uint8_t* s, uint8_t length, int pixel, uint8_t Number_Of_Led);

#ifdef	__cplusplus
}
#endif

#endif	/* MAX7219_H */

