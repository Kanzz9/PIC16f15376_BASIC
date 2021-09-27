
/**
  SPI1 Generated Driver API Source File

  Company:
    Microchip Technology Inc.

  File Name:
    spi1.c

  @Summary
    This is the generated source file for the SPI1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for driver for SPI1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.40
        MPLAB             :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include "spi1.h"

/**
 Section: File specific functions
*/

/**
  SPI1 Transfer Mode Enumeration

  @Summary
    Defines the Transfer Mode enumeration for SPI1.

  @Description
    This defines the Transfer Mode enumeration for SPI1.
 */
typedef enum {
    SPI1_TRANSFER_MODE_32BIT  = 2,
    SPI1_TRANSFER_MODE_16BIT = 1,
    SPI1_TRANSFER_MODE_8BIT = 0
}SPI1_TRANSFER_MODE;

inline __attribute__((__always_inline__)) SPI1_TRANSFER_MODE SPI1_TransferModeGet(void);
static void SPI1_Exchange( uint8_t *pTransmitData, uint8_t *pReceiveData );
static uint16_t SPI1_ExchangeBuffer(uint32_t *pTransmitData, uint16_t byteCount, uint32_t *pReceiveData);

/**
 Section: Driver Interface Function Definitions
*/


void SPI1_Initialize (void)
{
    // FRMERR disabled; 
    SPI1STAT = 0x00;
    // SPI1BRG 1; 
    SPI1BRG = 0x01;
    // AUDMONO disabled; AUDEN disabled; SPITUREN disabled; FRMERREN disabled; IGNROV disabled; SPISGNEXT disabled; SPIROVEN disabled; AUDMOD disabled; IGNTUR disabled; 
    SPI1CON2 = 0x00;
    // MCLKSEL PBCLK; DISSDO disabled; SRXISEL Last Word is Read; CKP Idle:Low, Active:High; FRMEN disabled; FRMSYPW One-Clock; SSEN disabled; FRMCNT 1; MSSEN disabled; MSTEN Master; MODE16 enabled; FRMPOL disabled; SMP Middle; SIDL disabled; FRMSYNC disabled; CKE Idle to Active; MODE32 enabled; SPIFE Frame Sync pulse precedes; STXISEL Complete; DISSDI disabled; ON enabled; ENHBUF enabled; 
    SPI1CON = 0x18C20;

}

static void SPI1_Exchange( uint8_t *pTransmitData, uint8_t *pReceiveData )
{

    while( SPI1STATbits.SPITBF == true )
    {

    }

    SPI1BUF = *((uint32_t*)pTransmitData);

    while ( SPI1STATbits.SPIRBE == true)
    {
    
    }

    *((uint32_t*)pReceiveData) = SPI1BUF;


}

static uint16_t SPI1_ExchangeBuffer(uint32_t *pTransmitData, uint16_t byteCount, uint32_t *pReceiveData)
{

    uint16_t dataSentCount = 0;
    uint16_t dataReceivedCount = 0;
    uint32_t dummyDataReceived = 0;
    uint32_t dummyDataTransmit = (uint32_t)SPI1_DUMMY_DATA;
    uint8_t fifoMultiplier;
    uint8_t fifoLimit32Bit;
    uint16_t quotient;
    uint16_t remainder;
    uint16_t count = 0;
    uint32_t  *pSend, *pReceived;

    byteCount >>= 2;
    fifoMultiplier = 1;
    fifoLimit32Bit = ((SPI1_FIFO_FILL_LIMIT)*fifoMultiplier);
    quotient = (byteCount>>2);
    remainder = ((byteCount)&(0x0003));
    
    if((pTransmitData == NULL)&&(pReceiveData == NULL))
    {
        return dataSentCount;
    }
    else if (pTransmitData == NULL)
    {
        pReceived = (uint32_t*)pReceiveData;
        count = quotient;
        while (quotient--)
        {
            while ( SPI1STATbits.SPITBE != true );

            SPI1BUF = dummyDataTransmit;
            SPI1BUF = dummyDataTransmit;
            SPI1BUF = dummyDataTransmit;
            SPI1BUF = dummyDataTransmit;

            while ( SPI1STATbits.SPIRBF != true );

            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
        }

        dataSentCount = count*fifoLimit32Bit;
        dataReceivedCount = dataSentCount;

        if (remainder)
        {
            while ( SPI1STATbits.SPITBE != true );

            while ( remainder-- )
            {
                SPI1BUF = dummyDataTransmit;
            }
            dataSentCount = dataSentCount + (byteCount - dataSentCount);

            while( dataReceivedCount < byteCount )
            {
                if (SPI1STATbits.SPIRBE == false)
                {
                    *(pReceived++) = SPI1BUF;
                    dataReceivedCount++;
                }
            }
        }   
    }
    else if (pReceiveData == NULL)
    {
        pSend = (uint32_t*)pTransmitData;
        count = quotient;
        while (quotient--)
        {
            while ( SPI1STATbits.SPITBE != true );

            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);

            while ( SPI1STATbits.SPIRBF != true );

            dummyDataReceived = SPI1BUF;
            dummyDataReceived = SPI1BUF;
            dummyDataReceived = SPI1BUF;
            dummyDataReceived = SPI1BUF;
        }

        dataSentCount = count*fifoLimit32Bit;
        dataReceivedCount = dataSentCount;

        if (remainder)
        {
            while ( SPI1STATbits.SPITBE != true );

            while ( remainder-- )
            {
                SPI1BUF = *(pSend++);
            }
            dataSentCount = dataSentCount + (byteCount - dataSentCount);

            while( dataReceivedCount < byteCount )
            {
                if (SPI1STATbits.SPIRBE == false)
                {
                    dummyDataReceived = SPI1BUF;
                    dataReceivedCount++;
                }
            }
        }
    }
    else
    {
        pSend = (uint16_t*)pTransmitData;
        pReceived = (uint16_t*)pReceiveData;
        count = quotient;
        while (quotient--)
        {
            while ( SPI1STATbits.SPITBE != true );

            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);
            SPI1BUF = *(pSend++);

            while ( SPI1STATbits.SPIRBF != true );

            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
            *(pReceived++) = SPI1BUF;
        }

        dataSentCount = count*fifoLimit32Bit;
        dataReceivedCount = dataSentCount;

        if (remainder)
        {
            while ( SPI1STATbits.SPITBE != true );

            while ( remainder-- )
            {
                SPI1BUF = *(pSend++);
            }
            dataSentCount = dataSentCount + (byteCount - dataSentCount);

            while( dataReceivedCount < byteCount )
            {
                if (SPI1STATbits.SPIRBE == false)
                {
                    *(pReceived++) = SPI1BUF;
                    dataReceivedCount++;
                }
            }
        } 
    }
    return dataSentCount;
}

uint32_t SPI1_Exchange32bit( uint32_t data )
{
    uint32_t receiveData;

    SPI1_Exchange((uint8_t*)&data, (uint8_t*)&receiveData);

    return (receiveData);
}


uint16_t SPI1_Exchange32bitBuffer(uint32_t *dataTransmitted, uint16_t byteCount, uint32_t *dataReceived)
{
    return (SPI1_ExchangeBuffer((uint32_t*)dataTransmitted, byteCount, (uint32_t*)dataReceived));
}


inline __attribute__((__always_inline__)) SPI1_TRANSFER_MODE SPI1_TransferModeGet(void)
{
    if (SPI1CONbits.MODE32 == 1)
        return SPI1_TRANSFER_MODE_32BIT;
    else if (SPI1CONbits.MODE16 == 1)
        return SPI1_TRANSFER_MODE_16BIT;
    else
        return SPI1_TRANSFER_MODE_8BIT;
}

SPI1_STATUS SPI1_StatusGet()
{
    return(SPI1STAT);
}

/**
 End of File
*/
