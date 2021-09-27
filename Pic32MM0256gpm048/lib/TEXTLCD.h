/****************************************************************************************************
 * khai bao ket noi                                                                                 *
 * TEXTLCD_D4                                                                                       *
 * TEXTLCD_D5                                                                                       *
 * TEXTLCD_D6                                                                                       *
 * TEXTLCD_D7                                                                                       *
 * TEXTLCD_RS                                                                                       *
 * TEXTLCD_EN                                                                                       *    
 ***************************************************************************************************/


#ifndef TEXTLCD_H
#define TEXTLCD_H

#include <stdint.h>
#include <stdbool.h>

#ifdef public
#undef  public
#define public
#else
#define public
#endif

#ifdef private
#undef  private
#define private static
#else
#define private static
#endif

/* Define these lines in AppPort.h or MCC/ MHC
 * #define TEXTLCD_RS
 * #define TEXTLCD_EN
 * #define TEXTLCD_D4
 * #define TEXTLCD_D5
 * #define TEXTLCD_D6
 * #define TEXTLCD_D7
 */

#define TEXTLCD_PUT_STRING  0

typedef enum {
    TEXTLCD0802 = 0,
    TEXTLCD0804,
    TEXTLCD1602,
    TEXTLCD1604,
    TEXTLCD2002,
    TEXTLCD2004
} textlcd_t;

public bool TextLCD_Init(textlcd_t TextLcdType);
public void TextLCD_Clear(void);
public void TextLCD_PutChar(char data);
public void TextLCD_SetCursor(uint8_t line, uint8_t idx);
public void TextLCD_ClearLine(uint8_t line);
public void TextLCD_Puts(uint8_t line, uint8_t idx, const char *data, uint8_t length_or_type);
public void TextLCD_Three_Number_Int(uint8_t line, uint8_t idx, int16_t value);
    
#endif