/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF15376
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "stdio.h"
//#include "BMP180.h"


/*
                         Main application
 */

//**************************************************************************************
// Send one byte to SEE
//**************************************************************************************







void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();  
    //uint8_t data[27]={0};
    float temp, press;
    BMP180_t BMP180;
    BMP180.BMP180_Add = 0x77;
    BMP180.BMP180_OSS = 0;
    I2C_Init();
    //I2C_Scan();
    BMP180_Init(&BMP180);
    
//    BMP180ReadMultiByte(&BMP180, 0xAA, data, 22);
//    
//    for(uint8_t i=0; i<22; i++)
//        printf("BMP180_ID: %d\n", data[i]);
    BMP180ReadData(&BMP180, &temp, &press);
    printf("BM1383 temp: %0.2f\n", temp);
    
    LED_SetHigh();
    
    while (1)
    {
        // Add your application code
//        BMP180ReadData(&BMP180, &temp);
//        printf("BM1383 temp: %0.2f\n", temp);
//        LED_Toggle();
        BMP180ReadData(&BMP180, &temp, &press);
        printf("BM1383 temp: %0.2f\n", temp);
        __delay_ms(1000);
         printf("BM1383 press: %0.2f\n", press);
        __delay_ms(1000);
        
    }
    
}
/**
 End of File
*/