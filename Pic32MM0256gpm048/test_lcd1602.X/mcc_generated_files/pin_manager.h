/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.155.0-a
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.20
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA15, high using LATA15.

  @Description
    Sets the GPIO pin, RA15, high using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA15 high (1)
    BUTTON1_SetHigh();
    </code>

*/
#define BUTTON1_SetHigh()          ( LATASET = (1 << 15) )
/**
  @Summary
    Sets the GPIO pin, RA15, low using LATA15.

  @Description
    Sets the GPIO pin, RA15, low using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA15 low (0)
    BUTTON1_SetLow();
    </code>

*/
#define BUTTON1_SetLow()           ( LATACLR = (1 << 15) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA15, low or high using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA15 to low.
    BUTTON1_SetValue(false);
    </code>

*/
inline static void BUTTON1_SetValue(bool value)
{
  if(value)
  {
    BUTTON1_SetHigh();
  }
  else
  {
    BUTTON1_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA15, using LATA15.

  @Description
    Toggles the GPIO pin, RA15, using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA15
    BUTTON1_Toggle();
    </code>

*/
#define BUTTON1_Toggle()           ( LATAINV = (1 << 15) )
/**
  @Summary
    Reads the value of the GPIO pin, RA15.

  @Description
    Reads the value of the GPIO pin, RA15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA15
    postValue = BUTTON1_GetValue();
    </code>

*/
#define BUTTON1_GetValue()         PORTAbits.RA15
/**
  @Summary
    Configures the GPIO pin, RA15, as an input.

  @Description
    Configures the GPIO pin, RA15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA15 as an input
    BUTTON1_SetDigitalInput();
    </code>

*/
#define BUTTON1_SetDigitalInput()   ( TRISASET = (1 << 15) )
/**
  @Summary
    Configures the GPIO pin, RA15, as an output.

  @Description
    Configures the GPIO pin, RA15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA15 as an output
    BUTTON1_SetDigitalOutput();
    </code>

*/
#define BUTTON1_SetDigitalOutput()   ( TRISACLR = (1 << 15) )
/**
  @Summary
    Sets the GPIO pin, RA3, high using LATA3.

  @Description
    Sets the GPIO pin, RA3, high using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 high (1)
    TEXTLCD_D4_SetHigh();
    </code>

*/
#define TEXTLCD_D4_SetHigh()          ( LATASET = (1 << 3) )
/**
  @Summary
    Sets the GPIO pin, RA3, low using LATA3.

  @Description
    Sets the GPIO pin, RA3, low using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 low (0)
    TEXTLCD_D4_SetLow();
    </code>

*/
#define TEXTLCD_D4_SetLow()           ( LATACLR = (1 << 3) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA3, low or high using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA3 to low.
    TEXTLCD_D4_SetValue(false);
    </code>

*/
inline static void TEXTLCD_D4_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_D4_SetHigh();
  }
  else
  {
    TEXTLCD_D4_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA3, using LATA3.

  @Description
    Toggles the GPIO pin, RA3, using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA3
    TEXTLCD_D4_Toggle();
    </code>

*/
#define TEXTLCD_D4_Toggle()           ( LATAINV = (1 << 3) )
/**
  @Summary
    Reads the value of the GPIO pin, RA3.

  @Description
    Reads the value of the GPIO pin, RA3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA3
    postValue = TEXTLCD_D4_GetValue();
    </code>

*/
#define TEXTLCD_D4_GetValue()         PORTAbits.RA3
/**
  @Summary
    Configures the GPIO pin, RA3, as an input.

  @Description
    Configures the GPIO pin, RA3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an input
    TEXTLCD_D4_SetDigitalInput();
    </code>

*/
#define TEXTLCD_D4_SetDigitalInput()   ( TRISASET = (1 << 3) )
/**
  @Summary
    Configures the GPIO pin, RA3, as an output.

  @Description
    Configures the GPIO pin, RA3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an output
    TEXTLCD_D4_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_D4_SetDigitalOutput()   ( TRISACLR = (1 << 3) )
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    TEXTLCD_EN_SetHigh();
    </code>

*/
#define TEXTLCD_EN_SetHigh()          ( LATASET = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    TEXTLCD_EN_SetLow();
    </code>

*/
#define TEXTLCD_EN_SetLow()           ( LATACLR = (1 << 4) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA4, low or high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA4 to low.
    TEXTLCD_EN_SetValue(false);
    </code>

*/
inline static void TEXTLCD_EN_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_EN_SetHigh();
  }
  else
  {
    TEXTLCD_EN_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    TEXTLCD_EN_Toggle();
    </code>

*/
#define TEXTLCD_EN_Toggle()           ( LATAINV = (1 << 4) )
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = TEXTLCD_EN_GetValue();
    </code>

*/
#define TEXTLCD_EN_GetValue()         PORTAbits.RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    TEXTLCD_EN_SetDigitalInput();
    </code>

*/
#define TEXTLCD_EN_SetDigitalInput()   ( TRISASET = (1 << 4) )
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    TEXTLCD_EN_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_EN_SetDigitalOutput()   ( TRISACLR = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RA8, high using LATA8.

  @Description
    Sets the GPIO pin, RA8, high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 high (1)
    TEXTLCD_RS_SetHigh();
    </code>

*/
#define TEXTLCD_RS_SetHigh()          ( LATASET = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RA8, low using LATA8.

  @Description
    Sets the GPIO pin, RA8, low using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 low (0)
    TEXTLCD_RS_SetLow();
    </code>

*/
#define TEXTLCD_RS_SetLow()           ( LATACLR = (1 << 8) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA8, low or high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA8 to low.
    TEXTLCD_RS_SetValue(false);
    </code>

*/
inline static void TEXTLCD_RS_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_RS_SetHigh();
  }
  else
  {
    TEXTLCD_RS_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA8, using LATA8.

  @Description
    Toggles the GPIO pin, RA8, using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA8
    TEXTLCD_RS_Toggle();
    </code>

*/
#define TEXTLCD_RS_Toggle()           ( LATAINV = (1 << 8) )
/**
  @Summary
    Reads the value of the GPIO pin, RA8.

  @Description
    Reads the value of the GPIO pin, RA8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA8
    postValue = TEXTLCD_RS_GetValue();
    </code>

*/
#define TEXTLCD_RS_GetValue()         PORTAbits.RA8
/**
  @Summary
    Configures the GPIO pin, RA8, as an input.

  @Description
    Configures the GPIO pin, RA8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an input
    TEXTLCD_RS_SetDigitalInput();
    </code>

*/
#define TEXTLCD_RS_SetDigitalInput()   ( TRISASET = (1 << 8) )
/**
  @Summary
    Configures the GPIO pin, RA8, as an output.

  @Description
    Configures the GPIO pin, RA8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an output
    TEXTLCD_RS_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_RS_SetDigitalOutput()   ( TRISACLR = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    TEXTLCD_D6_SetHigh();
    </code>

*/
#define TEXTLCD_D6_SetHigh()          ( LATASET = (1 << 9) )
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    TEXTLCD_D6_SetLow();
    </code>

*/
#define TEXTLCD_D6_SetLow()           ( LATACLR = (1 << 9) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA9, low or high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA9 to low.
    TEXTLCD_D6_SetValue(false);
    </code>

*/
inline static void TEXTLCD_D6_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_D6_SetHigh();
  }
  else
  {
    TEXTLCD_D6_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    TEXTLCD_D6_Toggle();
    </code>

*/
#define TEXTLCD_D6_Toggle()           ( LATAINV = (1 << 9) )
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = TEXTLCD_D6_GetValue();
    </code>

*/
#define TEXTLCD_D6_GetValue()         PORTAbits.RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    TEXTLCD_D6_SetDigitalInput();
    </code>

*/
#define TEXTLCD_D6_SetDigitalInput()   ( TRISASET = (1 << 9) )
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    TEXTLCD_D6_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_D6_SetDigitalOutput()   ( TRISACLR = (1 << 9) )
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    TEXTLCD_D5_SetHigh();
    </code>

*/
#define TEXTLCD_D5_SetHigh()          ( LATBSET = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    TEXTLCD_D5_SetLow();
    </code>

*/
#define TEXTLCD_D5_SetLow()           ( LATBCLR = (1 << 4) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB4, low or high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB4 to low.
    TEXTLCD_D5_SetValue(false);
    </code>

*/
inline static void TEXTLCD_D5_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_D5_SetHigh();
  }
  else
  {
    TEXTLCD_D5_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    TEXTLCD_D5_Toggle();
    </code>

*/
#define TEXTLCD_D5_Toggle()           ( LATBINV = (1 << 4) )
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = TEXTLCD_D5_GetValue();
    </code>

*/
#define TEXTLCD_D5_GetValue()         PORTBbits.RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    TEXTLCD_D5_SetDigitalInput();
    </code>

*/
#define TEXTLCD_D5_SetDigitalInput()   ( TRISBSET = (1 << 4) )
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    TEXTLCD_D5_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_D5_SetDigitalOutput()   ( TRISBCLR = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RB6, high using LATB6.

  @Description
    Sets the GPIO pin, RB6, high using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 high (1)
    LED_SetHigh();
    </code>

*/
#define LED_SetHigh()          ( LATBSET = (1 << 6) )
/**
  @Summary
    Sets the GPIO pin, RB6, low using LATB6.

  @Description
    Sets the GPIO pin, RB6, low using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 low (0)
    LED_SetLow();
    </code>

*/
#define LED_SetLow()           ( LATBCLR = (1 << 6) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB6, low or high using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB6 to low.
    LED_SetValue(false);
    </code>

*/
inline static void LED_SetValue(bool value)
{
  if(value)
  {
    LED_SetHigh();
  }
  else
  {
    LED_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB6, using LATB6.

  @Description
    Toggles the GPIO pin, RB6, using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB6
    LED_Toggle();
    </code>

*/
#define LED_Toggle()           ( LATBINV = (1 << 6) )
/**
  @Summary
    Reads the value of the GPIO pin, RB6.

  @Description
    Reads the value of the GPIO pin, RB6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB6
    postValue = LED_GetValue();
    </code>

*/
#define LED_GetValue()         PORTBbits.RB6
/**
  @Summary
    Configures the GPIO pin, RB6, as an input.

  @Description
    Configures the GPIO pin, RB6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an input
    LED_SetDigitalInput();
    </code>

*/
#define LED_SetDigitalInput()   ( TRISBSET = (1 << 6) )
/**
  @Summary
    Configures the GPIO pin, RB6, as an output.

  @Description
    Configures the GPIO pin, RB6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an output
    LED_SetDigitalOutput();
    </code>

*/
#define LED_SetDigitalOutput()   ( TRISBCLR = (1 << 6) )
/**
  @Summary
    Sets the GPIO pin, RC3, high using LATC3.

  @Description
    Sets the GPIO pin, RC3, high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 high (1)
    TEXTLCD_D7_SetHigh();
    </code>

*/
#define TEXTLCD_D7_SetHigh()          ( LATCSET = (1 << 3) )
/**
  @Summary
    Sets the GPIO pin, RC3, low using LATC3.

  @Description
    Sets the GPIO pin, RC3, low using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 low (0)
    TEXTLCD_D7_SetLow();
    </code>

*/
#define TEXTLCD_D7_SetLow()           ( LATCCLR = (1 << 3) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RC3, low or high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RC3 to low.
    TEXTLCD_D7_SetValue(false);
    </code>

*/
inline static void TEXTLCD_D7_SetValue(bool value)
{
  if(value)
  {
    TEXTLCD_D7_SetHigh();
  }
  else
  {
    TEXTLCD_D7_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RC3, using LATC3.

  @Description
    Toggles the GPIO pin, RC3, using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC3
    TEXTLCD_D7_Toggle();
    </code>

*/
#define TEXTLCD_D7_Toggle()           ( LATCINV = (1 << 3) )
/**
  @Summary
    Reads the value of the GPIO pin, RC3.

  @Description
    Reads the value of the GPIO pin, RC3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC3
    postValue = TEXTLCD_D7_GetValue();
    </code>

*/
#define TEXTLCD_D7_GetValue()         PORTCbits.RC3
/**
  @Summary
    Configures the GPIO pin, RC3, as an input.

  @Description
    Configures the GPIO pin, RC3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an input
    TEXTLCD_D7_SetDigitalInput();
    </code>

*/
#define TEXTLCD_D7_SetDigitalInput()   ( TRISCSET = (1 << 3) )
/**
  @Summary
    Configures the GPIO pin, RC3, as an output.

  @Description
    Configures the GPIO pin, RC3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an output
    TEXTLCD_D7_SetDigitalOutput();
    </code>

*/
#define TEXTLCD_D7_SetDigitalOutput()   ( TRISCCLR = (1 << 3) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0256GPM048
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

#endif
