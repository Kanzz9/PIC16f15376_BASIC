/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
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
#include <stdint.h>
#include "stdio.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/delay.h"
/*
                         Main application
 */
 #define SLAVE_I2C_GENERIC_RETRY_MAX           100//
 #define SLAVE_I2C_GENERIC_DEVICE_TIMEOUT      50 //

typedef enum 
{
    I2C1_MESSAGE_FAIL,
    I2C1_MESSAGE_PENDING,
    I2C1_MESSAGE_COMPLETE,
    I2C1_STUCK_START,
    I2C1_MESSAGE_ADDRESS_NO_ACK,
    I2C1_DATA_NO_ACK,
    I2C1_LOST_STATE
} I2C1_MESSAGE_STATUS;
void UART2_Write(uint8_t txData);
void I2C1_MasterWrite(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                I2C1_MESSAGE_STATUS *pstatus);


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    uint16_t        dataAddress;
    uint8_t         sourceData[16] = {  0xA0, 0xA1, 0xA2, 0xA3, 
                                        0xA4, 0xA5, 0xA6, 0xA7, 
                                        0xA8, 0xA9, 0xAA, 0xAB, 
                                        0xAC, 0xAD, 0xAE, 0xAF }; 
    uint8_t   *pData;
    uint16_t nCount;

    uint8_t  writeBuffer[3];
    uint8_t  *pD;
    uint16_t counter, timeOut, slaveTimeOut;
    //uint16_t status;
    
     I2C1_MESSAGE_STATUS  status = I2C1_MESSAGE_PENDING;

    dataAddress = 0x10;             // starting EEPROM address 
    pD = sourceData;                // initialize the source of the data
    nCount = 16;                    // number of bytes to write

    while (1)
    {
        // Add your application code
//        LED_2_Toggle();
//        DELAY_milliseconds(1000);
//        LED_1_SetLow();
          
          printf("sdsdksd");
          UART2_Write('b');
          DELAY_microseconds(1000);
//        for (counter = 0; counter < nCount; counter++)
//        {
//
//            // build the write buffer first
//            // starting address of the EEPROM memory
//            writeBuffer[0] = (dataAddress >> 8);                // high address
//            writeBuffer[1] = (uint8_t)(dataAddress);            // low low address
//
//            // data to be written
//            writeBuffer[2] = *pD++;
//
//            // Now it is possible that the slave device will be slow.
//            // As a work around on these slaves, the application can
//            // retry sending the transaction
//            timeOut = 0;
//            slaveTimeOut = 0;
// 
//            while( status != I2C1_MESSAGE_FAIL)
//            {
//                // write one byte to EEPROM (3 is the number of bytes to write)
//                I2C1_MasterWrite( writeBuffer, 3, 0x80, &status);
//                DELAY_milliseconds(5);
//                // wait for the message to be sent or status has changed.
//                while( status == I2C1_MESSAGE_PENDING)
//                {
//                    // add some delay here
//
//                    // timeout checking
//                    // check for max retry and skip this byte
//                    if (slaveTimeOut == SLAVE_I2C_GENERIC_DEVICE_TIMEOUT)
//                        break;
//                    else
//                        slaveTimeOut++;
//                } 
//                if ((slaveTimeOut == SLAVE_I2C_GENERIC_DEVICE_TIMEOUT) || 
//                    (status == I2C1_MESSAGE_COMPLETE))
//                    break;
//
//                // if status is  I2C1_MESSAGE_ADDRESS_NO_ACK,
//                //               or I2C1_DATA_NO_ACK,
//                // The device may be busy and needs more time for the last
//                // write so we can retry writing the data, this is why we
//                // use a while loop here
//
//                // check for max retry and skip this byte
//                if (timeOut == SLAVE_I2C_GENERIC_RETRY_MAX)
//                    break;
//                else
//                    timeOut++;
//            }
//
//            if (status == I2C1_MESSAGE_FAIL)
//            {
//                break;
//            }
//            dataAddress++;
//
//        }
        
    }
    return 0; 
}
/**
 End of File
*/

