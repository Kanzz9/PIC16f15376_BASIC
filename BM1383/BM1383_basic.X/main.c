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


/*
                         Main application
 */

//**************************************************************************************
// Send one byte to SEE
//**************************************************************************************




/*
 
void EepWriteByte(uint8_t dev_add, uint16_t reg_add, uint8_t byte){
    
    bool ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(dev_add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    Send_I2C_Data(reg_add>>8);
    //Send_I2C_ACK();
    Send_I2C_Data(reg_add);
    //Send_I2C_ACK();
    Send_I2C_Data(byte);
    //Send_I2C_ACK();
    Send_I2C_StopBit();   
}

uint8_t EepReadByte(uint8_t dev_add, uint16_t reg_add){
    
    bool ACK_bit = 1;            // init the Ack bit high
    uint8_t data=0;
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(dev_add, 0);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    Send_I2C_Data(reg_add>>8);
    //Send_I2C_ACK();
    Send_I2C_Data(reg_add);
    //Send_I2C_ACK();
    
    ACK_bit = 1;            // init the Ack bit high
    while(ACK_bit)          // loop as long as the ack bit is high
    {
        Send_I2C_StartBit();
        Send_I2C_ControlByte(dev_add, 1);
        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
    }
    
    data=Read_I2C_Data();
    Send_I2C_NAK();
    Send_I2C_StopBit();
    
    return data;
}
*/

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
    
    BM1383_t BM1383;
    
    BM1383.BM1383_Add = 0x5D;
    I2C_Init();
    I2C_Scan();
    
    uint8_t i=0;

    LED_SetHigh();
    
    while (1)
    {
        // Add your application code
//        uint8_t ID1_BM1383=0;
//        ID1_BM1383 = ReadByteBM1383(&BM1383, 0x0F);
//        printf("BM1383 ID1: %d\n", ID1_BM1383);
//        LED_SetHigh();
//        __delay_ms(500);
        
    }
    
}
/**
 End of File
*/