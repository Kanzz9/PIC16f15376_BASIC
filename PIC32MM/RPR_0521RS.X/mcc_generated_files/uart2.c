/**
  UART2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart2.c

  @Summary
    This is the generated driver implementation file for the UART2 driver using Foundation Services Library

  @Description
    This header file provides implementations for driver APIs for UART2.
    Generation Information :
        Product Revision  :  Foundation Services Library - pic24-dspic-pic32mm : v1.26
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.42
        MPLAB             :  MPLAB X 3.45
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

/**
  Section: Included Files
*/
#include <xc.h>
#include "uart2.h"

/**
  Section: UART2 APIs
*/

void UART2_Initialize(void)
{
    // Set the UART2 module to the options selected in the user interface.

    // STSEL 1; PDSEL 8N; RTSMD disabled; OVFDIS disabled; ACTIVE disabled; RXINV disabled; WAKE disabled; BRGH enabled; IREN disabled; ON enabled; SLPEN disabled; SIDL disabled; ABAUD disabled; LPBACK disabled; UEN TX_RX; CLKSEL PBCLK; 
    U2MODE = (0x8008 & ~(1<<15)); // disabling UART ON bit  
    // UTXISEL TX_ONE_CHAR; UTXINV disabled; ADDR 0; MASK 0; URXEN disabled; OERR disabled; URXISEL RX_ONE_CHAR; UTXBRK disabled; UTXEN disabled; ADDEN disabled; 
    U2STA = 0x0;
    // BaudRate = 9600; Frequency = 8000000 Hz; BRG 207; 
    U2BRG = 0xCF;
     
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
    U2STASET = _U2STA_UTXEN_MASK;
    U2MODESET = _U2MODE_ON_MASK;  // enabling UART ON bit
    U2STASET = _U2STA_URXEN_MASK; 
}

uint8_t UART2_Read(void)
{
    while(!(U2STAbits.URXDA == 1))
    {
    }

    if ((U2STAbits.OERR == 1))
    {
        U2STACLR = _U2STA_OERR_MASK;
    }

    return U2RXREG;
}

void UART2_Write(uint8_t txData)
{
    while(U2STAbits.UTXBF == 1)
    {
    }

    U2TXREG = txData;    // Write the data byte to the USART.
}

bool UART2_IsRxReady(void)
{
    return U2STAbits.URXDA;
}

bool UART2_IsTxReady(void)
{
    return (U2STAbits.TRMT && U2STAbits.UTXEN );
}

bool UART2_IsTxDone(void)
{
    return U2STAbits.TRMT;
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
UART2_STATUS __attribute__((deprecated)) UART2_StatusGet (void)
{
    return U2STA;
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART2_DataReady(void)
{
    return UART2_IsRxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART2_is_tx_ready(void)
{
    return UART2_IsTxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART2_is_rx_ready(void)
{
    return UART2_IsRxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART2_is_tx_done(void)
{
    return UART2_IsTxDone();
}

void _mon_putc(char c) {
    UART2_Write(c);
}
