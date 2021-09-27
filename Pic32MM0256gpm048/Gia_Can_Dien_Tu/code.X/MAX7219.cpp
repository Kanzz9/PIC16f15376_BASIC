#include "MAX7219.h"
#include "stdint.h"
#include "string.h"
#include"main.h"
#include"MAX7219_Dot_Matrix_font.h"
 

// send one byte to MAX7219
void MAX7219_Dot_Matrix_sendByte (uint8_t reg, uint8_t data)
{
    SPI1_Exchange8bit(reg);
    SPI1_Exchange8bit(data);

}  // end of sendByte

void MAX7219_Dot_Matrix_sendToAll (uint8_t reg, uint8_t data, uint8_t Number_Of_Led)
{

    SPI1_SS_SetLow();
    for (uint8_t chip = 0; chip < Number_Of_Led; chip++)
      MAX7219_Dot_Matrix_sendByte (reg, data);
    SPI1_SS_SetHigh();
}  // end of sendToAll

void MAX7219_Dot_Matrix_send64pixels(uint8_t chip, uint8_t pixels [8], uint8_t Number_Of_Led)
  {
  for (uint8_t col = 0; col < 8; col++)
    {
    // start sending
    SPI1_SS_SetLow();
    // send extra NOPs to push the pixels out to extra displays
    for (uint8_t i = 0; i < chip; i++)
        MAX7219_Dot_Matrix_sendByte(MAX7219_REG_NOOP, MAX7219_REG_NOOP);
    // rotate pixels 90 degrees
    uint8_t b = 0;
    for (uint8_t i = 0; i < 8; i++)
      b |=  (pixels [i], col) << (7 - i);
    MAX7219_Dot_Matrix_sendByte(col + 1, b);
    // end with enough NOPs so later chips don't update
    for (int i = 0; i < Number_Of_Led - chip - 1; i++)
      MAX7219_Dot_Matrix_sendByte (MAX7219_REG_NOOP, MAX7219_REG_NOOP);
    // all done!
    SPI1_SS_SetHigh();
    }   // end of for each column
  }  // end of sendChar

void MAX7219_Dot_Matrix_sendChar (uint8_t chip, uint8_t data, uint8_t Number_Of_Led)
  {
  // get this character from PROGMEM
  uint8_t pixels [8];
  for (uint8_t i = 0; i < 8; i++)
     pixels [i] = MAX7219_Dot_Matrix_font [data][i];

  MAX7219_Dot_Matrix_send64pixels(chip, pixels, Number_Of_Led);
  }  // end of sendChar

void MAX7219_Dot_Matrix_sendString (uint8_t* s, uint8_t Number_Of_Led)
{
  uint8_t chip;

  for (chip = 0; chip < Number_Of_Led && *s; chip++)
    MAX7219_Dot_Matrix_sendChar(chip, *s++, Number_Of_Led);

 // space out rest
  while (chip < (Number_Of_Led))
    MAX7219_Dot_Matrix_sendChar(chip++, ' ',Number_Of_Led);

}  // end of sendString

void MAX7219_Dot_Matrix_sendSmooth(uint8_t* s, uint8_t length, int pixel, uint8_t Number_Of_Led)
  {
  uint8_t len = length;
  uint8_t thisChip [3 * 8];  // pixels for current chip with allowance for one each side
  int firstByte = pixel / 8;
  int offset = pixel - (firstByte * 8);

  uint8_t chip;

  for (chip = 0; chip < Number_Of_Led ; chip++)
    {
    memset (thisChip, 0, sizeof thisChip);

    // get pixels to left of current character in case "pixel" is negative
    if (offset < 0)
      {
      if (firstByte + chip - 1 >= 0 && firstByte + chip - 1 < len)
        for (uint8_t i = 0; i < 8; i++)
           thisChip [i] =  (MAX7219_Dot_Matrix_font [((uint8_t *) s) [firstByte  + chip - 1]][i]);
      }  // negative offset

    // get the current character
    if (firstByte + chip >= 0 && firstByte + chip < len)
      for (uint8_t i = 0; i < 8; i++)
         thisChip [i + 8] =  (MAX7219_Dot_Matrix_font [((uint8_t *) s) [firstByte + chip]][i]);

    // get pixels to right of current character in case "pixel" is positive
    if (offset > 0)
      {
      if (firstByte + chip + 1 >= 0 && firstByte + chip + 1 < len)
        for (uint8_t i = 0; i < 8; i++)
           thisChip [i + 16] = (MAX7219_Dot_Matrix_font [((uint8_t *) s) [firstByte + chip + 1]][i]);
      }  // positive offset

    // send the appropriate 8 pixels (offset will be from -7 to +7)
    MAX7219_Dot_Matrix_send64pixels(chip, &thisChip [8 + offset], Number_Of_Led);

    } // for each chip

  } // end of MAX7219_Dot_Matrix::sendSmooth
