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

// get/set TEXTLCD_D7 aliases
#define TEXTLCD_D7_TRIS                 TRISAbits.TRISA0
#define TEXTLCD_D7_LAT                  LATAbits.LATA0
#define TEXTLCD_D7_PORT                 PORTAbits.RA0
#define TEXTLCD_D7_WPU                  WPUAbits.WPUA0
#define TEXTLCD_D7_OD                   ODCONAbits.ODCA0
#define TEXTLCD_D7_ANS                  ANSELAbits.ANSA0
#define TEXTLCD_D7_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TEXTLCD_D7_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TEXTLCD_D7_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TEXTLCD_D7_GetValue()           PORTAbits.RA0
#define TEXTLCD_D7_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TEXTLCD_D7_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TEXTLCD_D7_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TEXTLCD_D7_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TEXTLCD_D7_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define TEXTLCD_D7_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define TEXTLCD_D7_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TEXTLCD_D7_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set TEXTLCD_D6 aliases
#define TEXTLCD_D6_TRIS                 TRISAbits.TRISA1
#define TEXTLCD_D6_LAT                  LATAbits.LATA1
#define TEXTLCD_D6_PORT                 PORTAbits.RA1
#define TEXTLCD_D6_WPU                  WPUAbits.WPUA1
#define TEXTLCD_D6_OD                   ODCONAbits.ODCA1
#define TEXTLCD_D6_ANS                  ANSELAbits.ANSA1
#define TEXTLCD_D6_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define TEXTLCD_D6_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define TEXTLCD_D6_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define TEXTLCD_D6_GetValue()           PORTAbits.RA1
#define TEXTLCD_D6_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define TEXTLCD_D6_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define TEXTLCD_D6_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define TEXTLCD_D6_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define TEXTLCD_D6_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define TEXTLCD_D6_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define TEXTLCD_D6_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define TEXTLCD_D6_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TEXTLCD_D5 aliases
#define TEXTLCD_D5_TRIS                 TRISAbits.TRISA3
#define TEXTLCD_D5_LAT                  LATAbits.LATA3
#define TEXTLCD_D5_PORT                 PORTAbits.RA3
#define TEXTLCD_D5_WPU                  WPUAbits.WPUA3
#define TEXTLCD_D5_OD                   ODCONAbits.ODCA3
#define TEXTLCD_D5_ANS                  ANSELAbits.ANSA3
#define TEXTLCD_D5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define TEXTLCD_D5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define TEXTLCD_D5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define TEXTLCD_D5_GetValue()           PORTAbits.RA3
#define TEXTLCD_D5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define TEXTLCD_D5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define TEXTLCD_D5_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define TEXTLCD_D5_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define TEXTLCD_D5_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define TEXTLCD_D5_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define TEXTLCD_D5_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define TEXTLCD_D5_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set TEXTLCD_D4 aliases
#define TEXTLCD_D4_TRIS                 TRISAbits.TRISA4
#define TEXTLCD_D4_LAT                  LATAbits.LATA4
#define TEXTLCD_D4_PORT                 PORTAbits.RA4
#define TEXTLCD_D4_WPU                  WPUAbits.WPUA4
#define TEXTLCD_D4_OD                   ODCONAbits.ODCA4
#define TEXTLCD_D4_ANS                  ANSELAbits.ANSA4
#define TEXTLCD_D4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define TEXTLCD_D4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define TEXTLCD_D4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define TEXTLCD_D4_GetValue()           PORTAbits.RA4
#define TEXTLCD_D4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define TEXTLCD_D4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define TEXTLCD_D4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define TEXTLCD_D4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define TEXTLCD_D4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define TEXTLCD_D4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define TEXTLCD_D4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define TEXTLCD_D4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set channel_AND4 aliases
#define channel_AND4_TRIS                 TRISDbits.TRISD4
#define channel_AND4_LAT                  LATDbits.LATD4
#define channel_AND4_PORT                 PORTDbits.RD4
#define channel_AND4_WPU                  WPUDbits.WPUD4
#define channel_AND4_OD                   ODCONDbits.ODCD4
#define channel_AND4_ANS                  ANSELDbits.ANSD4
#define channel_AND4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define channel_AND4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define channel_AND4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define channel_AND4_GetValue()           PORTDbits.RD4
#define channel_AND4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define channel_AND4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define channel_AND4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define channel_AND4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define channel_AND4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define channel_AND4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define channel_AND4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define channel_AND4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set TEXTLCD_EN aliases
#define TEXTLCD_EN_TRIS                 TRISEbits.TRISE1
#define TEXTLCD_EN_LAT                  LATEbits.LATE1
#define TEXTLCD_EN_PORT                 PORTEbits.RE1
#define TEXTLCD_EN_WPU                  WPUEbits.WPUE1
#define TEXTLCD_EN_OD                   ODCONEbits.ODCE1
#define TEXTLCD_EN_ANS                  ANSELEbits.ANSE1
#define TEXTLCD_EN_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define TEXTLCD_EN_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define TEXTLCD_EN_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define TEXTLCD_EN_GetValue()           PORTEbits.RE1
#define TEXTLCD_EN_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define TEXTLCD_EN_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define TEXTLCD_EN_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define TEXTLCD_EN_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define TEXTLCD_EN_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define TEXTLCD_EN_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define TEXTLCD_EN_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define TEXTLCD_EN_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set TEXTLCD_RS aliases
#define TEXTLCD_RS_TRIS                 TRISEbits.TRISE2
#define TEXTLCD_RS_LAT                  LATEbits.LATE2
#define TEXTLCD_RS_PORT                 PORTEbits.RE2
#define TEXTLCD_RS_WPU                  WPUEbits.WPUE2
#define TEXTLCD_RS_OD                   ODCONEbits.ODCE2
#define TEXTLCD_RS_ANS                  ANSELEbits.ANSE2
#define TEXTLCD_RS_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define TEXTLCD_RS_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define TEXTLCD_RS_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define TEXTLCD_RS_GetValue()           PORTEbits.RE2
#define TEXTLCD_RS_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define TEXTLCD_RS_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define TEXTLCD_RS_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define TEXTLCD_RS_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define TEXTLCD_RS_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define TEXTLCD_RS_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define TEXTLCD_RS_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define TEXTLCD_RS_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

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