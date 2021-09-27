/**
  @Generated PIC24 / dsPIC33 / PIC32MM MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    clock.c

  @Summary:
    This is the clock.c file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB             :  MPLAB X v5.10
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include "xc.h"
#include "stdint.h"
#include "clock.h"
#include "system.h"

void CLOCK_Initialize(void)
{
    SYSTEM_RegUnlock();
    //Temporarily switch to FRC (without PLL), so we can safely change the PLL settings,
    //in case we had previously been already running from the PLL.
    OSCCON = OSCCON & 0xF8FFF87E;
    if(OSCCONbits.COSC != OSCCONbits.NOSC)
    {
        OSCCONbits.OSWEN = 1;            //Initiate clock switching operation.
        while(OSCCONbits.OSWEN == 1);    //Wait for switching complete.
    }
    // ORPOL disabled; SIDL disabled; SRC SOSC; TUN Center frequency; POL disabled; ON disabled; 
    OSCTUN = 0x00;
    // PLLODIV 1:64; PLLMULT 4x; PLLICLK POSC; 
    SPLLCON = 0x6020000;
    // SBOREN disabled; VREGS disabled; RETEN disabled; 
    PWRCON = PWRCON | 0x00;
    //Clear NOSC,CLKLOCK and OSWEN bits
    OSCCONCLR = _OSCCON_NOSC_MASK | _OSCCON_CLKLOCK_MASK | _OSCCON_OSWEN_MASK;
    // CF No Clock Failure; FRCDIV FRC/1; SLPEN Device will enter Idle mode when a WAIT instruction is issued; NOSC SPLL; SOSCEN disabled; CLKLOCK Clock and PLL selections are not locked and may be modified; OSWEN Switch is Complete; 
    OSCCON = (0x100 | _OSCCON_OSWEN_MASK);
    SYSTEM_RegLock();
    // Wait for Clock switch to occur 
    while(OSCCONbits.OSWEN == 1); 
    // ON disabled; DIVSWEN disabled; RSLP disabled; ROSEL SYSCLK; OE disabled; SIDL disabled; RODIV 0; 
    REFO1CON = REFO1CON | 0x00;
    while(!REFO1CONbits.ACTIVE & REFO1CONbits.ON);
    // ROTRIM 0; 
    REFO1TRIM = REFO1TRIM | 0x00;
}
