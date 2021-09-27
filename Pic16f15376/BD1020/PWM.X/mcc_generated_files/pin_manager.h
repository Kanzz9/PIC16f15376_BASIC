/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF15376
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SW_SDA aliases
#define SW_SDA_TRIS                 TRISCbits.TRISC4
#define SW_SDA_LAT                  LATCbits.LATC4
#define SW_SDA_PORT                 PORTCbits.RC4
#define SW_SDA_WPU                  WPUCbits.WPUC4
#define SW_SDA_OD                   ODCONCbits.ODCC4
#define SW_SDA_ANS                  ANSELCbits.ANSC4
#define SW_SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW_SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW_SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW_SDA_GetValue()           PORTCbits.RC4
#define SW_SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW_SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW_SDA_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW_SDA_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW_SDA_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW_SDA_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW_SDA_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SW_SDA_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW_SCL aliases
#define SW_SCL_TRIS                 TRISCbits.TRISC6
#define SW_SCL_LAT                  LATCbits.LATC6
#define SW_SCL_PORT                 PORTCbits.RC6
#define SW_SCL_WPU                  WPUCbits.WPUC6
#define SW_SCL_OD                   ODCONCbits.ODCC6
#define SW_SCL_ANS                  ANSELCbits.ANSC6
#define SW_SCL_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SW_SCL_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SW_SCL_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SW_SCL_GetValue()           PORTCbits.RC6
#define SW_SCL_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SW_SCL_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SW_SCL_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SW_SCL_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SW_SCL_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SW_SCL_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SW_SCL_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SW_SCL_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/