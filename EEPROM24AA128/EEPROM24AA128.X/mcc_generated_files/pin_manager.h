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

// get/set UNIBUS_WP aliases
#define UNIBUS_WP_TRIS                 TRISBbits.TRISB0
#define UNIBUS_WP_LAT                  LATBbits.LATB0
#define UNIBUS_WP_PORT                 PORTBbits.RB0
#define UNIBUS_WP_WPU                  WPUBbits.WPUB0
#define UNIBUS_WP_OD                   ODCONBbits.ODCB0
#define UNIBUS_WP_ANS                  ANSELBbits.ANSB0
#define UNIBUS_WP_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define UNIBUS_WP_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define UNIBUS_WP_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define UNIBUS_WP_GetValue()           PORTBbits.RB0
#define UNIBUS_WP_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define UNIBUS_WP_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define UNIBUS_WP_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define UNIBUS_WP_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define UNIBUS_WP_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define UNIBUS_WP_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define UNIBUS_WP_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define UNIBUS_WP_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set UNIBUS_A2 aliases
#define UNIBUS_A2_TRIS                 TRISBbits.TRISB1
#define UNIBUS_A2_LAT                  LATBbits.LATB1
#define UNIBUS_A2_PORT                 PORTBbits.RB1
#define UNIBUS_A2_WPU                  WPUBbits.WPUB1
#define UNIBUS_A2_OD                   ODCONBbits.ODCB1
#define UNIBUS_A2_ANS                  ANSELBbits.ANSB1
#define UNIBUS_A2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define UNIBUS_A2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define UNIBUS_A2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define UNIBUS_A2_GetValue()           PORTBbits.RB1
#define UNIBUS_A2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define UNIBUS_A2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define UNIBUS_A2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define UNIBUS_A2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define UNIBUS_A2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define UNIBUS_A2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define UNIBUS_A2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define UNIBUS_A2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set UNIBUS_A1 aliases
#define UNIBUS_A1_TRIS                 TRISBbits.TRISB2
#define UNIBUS_A1_LAT                  LATBbits.LATB2
#define UNIBUS_A1_PORT                 PORTBbits.RB2
#define UNIBUS_A1_WPU                  WPUBbits.WPUB2
#define UNIBUS_A1_OD                   ODCONBbits.ODCB2
#define UNIBUS_A1_ANS                  ANSELBbits.ANSB2
#define UNIBUS_A1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define UNIBUS_A1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define UNIBUS_A1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define UNIBUS_A1_GetValue()           PORTBbits.RB2
#define UNIBUS_A1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define UNIBUS_A1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define UNIBUS_A1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define UNIBUS_A1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define UNIBUS_A1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define UNIBUS_A1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define UNIBUS_A1_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define UNIBUS_A1_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set UNIBUS_A0 aliases
#define UNIBUS_A0_TRIS                 TRISDbits.TRISD7
#define UNIBUS_A0_LAT                  LATDbits.LATD7
#define UNIBUS_A0_PORT                 PORTDbits.RD7
#define UNIBUS_A0_WPU                  WPUDbits.WPUD7
#define UNIBUS_A0_OD                   ODCONDbits.ODCD7
#define UNIBUS_A0_ANS                  ANSELDbits.ANSD7
#define UNIBUS_A0_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define UNIBUS_A0_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define UNIBUS_A0_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define UNIBUS_A0_GetValue()           PORTDbits.RD7
#define UNIBUS_A0_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define UNIBUS_A0_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define UNIBUS_A0_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define UNIBUS_A0_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define UNIBUS_A0_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define UNIBUS_A0_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define UNIBUS_A0_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define UNIBUS_A0_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

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