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

// get/set EE_WP aliases
#define EE_WP_TRIS                 TRISBbits.TRISB0
#define EE_WP_LAT                  LATBbits.LATB0
#define EE_WP_PORT                 PORTBbits.RB0
#define EE_WP_WPU                  WPUBbits.WPUB0
#define EE_WP_OD                   ODCONBbits.ODCB0
#define EE_WP_ANS                  ANSELBbits.ANSB0
#define EE_WP_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define EE_WP_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define EE_WP_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define EE_WP_GetValue()           PORTBbits.RB0
#define EE_WP_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define EE_WP_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define EE_WP_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define EE_WP_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define EE_WP_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define EE_WP_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define EE_WP_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define EE_WP_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set EE_A2 aliases
#define EE_A2_TRIS                 TRISBbits.TRISB1
#define EE_A2_LAT                  LATBbits.LATB1
#define EE_A2_PORT                 PORTBbits.RB1
#define EE_A2_WPU                  WPUBbits.WPUB1
#define EE_A2_OD                   ODCONBbits.ODCB1
#define EE_A2_ANS                  ANSELBbits.ANSB1
#define EE_A2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define EE_A2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define EE_A2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define EE_A2_GetValue()           PORTBbits.RB1
#define EE_A2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define EE_A2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define EE_A2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define EE_A2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define EE_A2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define EE_A2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define EE_A2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define EE_A2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set EE_A1 aliases
#define EE_A1_TRIS                 TRISBbits.TRISB2
#define EE_A1_LAT                  LATBbits.LATB2
#define EE_A1_PORT                 PORTBbits.RB2
#define EE_A1_WPU                  WPUBbits.WPUB2
#define EE_A1_OD                   ODCONBbits.ODCB2
#define EE_A1_ANS                  ANSELBbits.ANSB2
#define EE_A1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define EE_A1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define EE_A1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define EE_A1_GetValue()           PORTBbits.RB2
#define EE_A1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define EE_A1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define EE_A1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define EE_A1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define EE_A1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define EE_A1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define EE_A1_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define EE_A1_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

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

// get/set SW_SCL aliases
#define SW_SCL_TRIS                 TRISCbits.TRISC4
#define SW_SCL_LAT                  LATCbits.LATC4
#define SW_SCL_PORT                 PORTCbits.RC4
#define SW_SCL_WPU                  WPUCbits.WPUC4
#define SW_SCL_OD                   ODCONCbits.ODCC4
#define SW_SCL_ANS                  ANSELCbits.ANSC4
#define SW_SCL_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW_SCL_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW_SCL_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW_SCL_GetValue()           PORTCbits.RC4
#define SW_SCL_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW_SCL_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW_SCL_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW_SCL_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW_SCL_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW_SCL_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW_SCL_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SW_SCL_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW_SDA aliases
#define SW_SDA_TRIS                 TRISCbits.TRISC6
#define SW_SDA_LAT                  LATCbits.LATC6
#define SW_SDA_PORT                 PORTCbits.RC6
#define SW_SDA_WPU                  WPUCbits.WPUC6
#define SW_SDA_OD                   ODCONCbits.ODCC6
#define SW_SDA_ANS                  ANSELCbits.ANSC6
#define SW_SDA_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SW_SDA_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SW_SDA_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SW_SDA_GetValue()           PORTCbits.RC6
#define SW_SDA_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SW_SDA_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SW_SDA_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SW_SDA_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SW_SDA_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SW_SDA_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SW_SDA_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SW_SDA_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set EE_A0 aliases
#define EE_A0_TRIS                 TRISDbits.TRISD7
#define EE_A0_LAT                  LATDbits.LATD7
#define EE_A0_PORT                 PORTDbits.RD7
#define EE_A0_WPU                  WPUDbits.WPUD7
#define EE_A0_OD                   ODCONDbits.ODCD7
#define EE_A0_ANS                  ANSELDbits.ANSD7
#define EE_A0_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define EE_A0_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define EE_A0_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define EE_A0_GetValue()           PORTDbits.RD7
#define EE_A0_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define EE_A0_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define EE_A0_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define EE_A0_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define EE_A0_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define EE_A0_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define EE_A0_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define EE_A0_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

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