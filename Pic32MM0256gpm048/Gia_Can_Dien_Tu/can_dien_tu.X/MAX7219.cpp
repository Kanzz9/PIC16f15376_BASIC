#include "MAX7219.h"
#include "stdint.h"
#include "mcc_generated_files/spi1.h"

// send one byte to MAX7219
void MAX7219_Dot_Matrix_sendByte (uint8_t reg, uint8_t data)
{
    SPI1_Exchange8bit(reg);
    SPI1_Exchange8bit(data);

}  // end of sendByte

void MAX7219_Dot_Matrix_sendToAll (uint8_t reg, uint8_t data, uint8_t Number_Of_Led)
{
  SPI1_SS_SetLow();
  for (uint8_t chip = 0; chip < Number_Of_Led_; chip++)
    MAX7219_Dot_Matrix_sendByte (reg, data);
  SPI1_SS_SetHigh();
}  // end of sendToAll

