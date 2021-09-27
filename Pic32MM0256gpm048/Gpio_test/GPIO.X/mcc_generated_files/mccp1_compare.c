/**
  MCCP1 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp1.c

  @Summary
    This is the generated driver implementation file for the MCCP1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP1. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.20
        MPLAB             :  MPLAB X v5.25
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

/**
  Section: Included Files
*/

#include "mccp1_compare.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

*/

static uint16_t         gMCCP1Mode;

/**
  Section: Driver Interface
*/


void MCCP1_COMPARE_Initialize (void)
{
    // ON enabled; MOD Dual Edge Compare, Buffered(PWM); ALTSYNC disabled; SIDL disabled; OPS Each Time Base Period Match; CCPSLP disabled; TMRSYNC disabled; RTRGEN disabled; CCSEL disabled; ONESHOT disabled; TRIGEN disabled; T32 16 Bit; SYNC None; OPSSRC Timer Interrupt Event; TMRPS 1:1; CLKSEL SYSCLK; 
    CCP1CON1 = (0x8005 & 0xFFFF7FFF); //Disabling CCPON bit
    //OCCEN disabled; OCDEN disabled; ASDGM disabled; OCEEN disabled; ICGSM Level-Sensitive mode; OCFEN disabled; ICS ICM1; SSDG disabled; AUXOUT Disabled; ASDG 0; OCAEN enabled; OCBEN disabled; OENSYNC disabled; PWMRSEN disabled; 
    CCP1CON2 = 0x1000000;
    //DT 0; OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP1CON3 = 0x00;
    //SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; ICGARM disabled; RBWIP disabled; TRCLR disabled; RAWIP disabled; TMRHWIP disabled; TMRLWIP disabled; PRLWIP disabled; 
    CCP1STAT = 0x00;
    //TMRL 0; TMRH 0; 
    CCP1TMR = 0x00;
    //PRH 0; PRL 5000; 
    CCP1PR = 0x1388;
    //CMPA 0; 
    CCP1RA = 0x00;
    //CMPB 0; 
    CCP1RB = 0x00;
    //BUFL 0; BUFH 0; 
    CCP1BUF = 0x00;

    CCP1CON1bits.ON = 0x1; //Enabling CCP

    gMCCP1Mode = CCP1CON1bits.MOD;

}

void __attribute__ ((weak)) MCCP1_COMPARE_CallBack(void)
{
    // Add your custom callback code here
}

void MCCP1_COMPARE_Tasks( void )
{
    if(IFS2bits.CCP1IF)
    {
		// MCCP1 COMPARE callback function 
		MCCP1_COMPARE_CallBack();
		
        IFS2CLR= 1 << _IFS2_CCP1IF_POSITION;
    }
}

void __attribute__ ((weak)) MCCP1_COMPARE_TimerCallBack(void)
{
    // Add your custom callback code here
}


void MCCP1_COMPARE_TimerTasks( void )
{
    if(IFS2bits.CCT1IF)
    {
		// MCCP1 COMPARE Timer callback function 
		MCCP1_COMPARE_TimerCallBack();
	
        IFS2CLR= 1 << _IFS2_CCT1IF_POSITION;
    }
}

void MCCP1_COMPARE_Start( void )
{
    /* Start the Timer */
    CCP1CON1SET = (1 << _CCP1CON1_ON_POSITION);
}

void MCCP1_COMPARE_Stop( void )
{
    /* Start the Timer */
    CCP1CON1CLR = (1 << _CCP1CON1_ON_POSITION);
}

void MCCP1_COMPARE_SingleCompare16ValueSet( uint16_t value )
{   
    CCP1RA = value;
}


void MCCP1_COMPARE_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_DualEdgeBufferedConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_CenterAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_EdgeAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_VariableFrequencyPulseConfig( uint16_t priVal )
{
    CCP1RA = priVal;
}

bool MCCP1_COMPARE_IsCompareCycleComplete( void )
{
    return(IFS2bits.CCP1IF);
}

bool MCCP1_COMPARE_TriggerStatusGet( void )
{
    return( CCP1STATbits.CCPTRIG );
    
}

void MCCP1_COMPARE_TriggerStatusSet( void )
{
    CCP1STATSET = (1 << _CCP1STAT_TRSET_POSITION);
}

void MCCP1_COMPARE_TriggerStatusClear( void )
{
    /* Clears the trigger status */
    CCP1STATCLR = (1 << _CCP1STAT_TRCLR_POSITION);
}

bool MCCP1_COMPARE_SingleCompareStatusGet( void )
{
    return( CCP1STATbits.SCEVT );
}

void MCCP1_COMPARE_SingleCompareStatusClear( void )
{
    /* Clears the trigger status */
    CCP1STATCLR = (1 << _CCP1STAT_SCEVT_POSITION);
    
}
/**
 End of File
*/
