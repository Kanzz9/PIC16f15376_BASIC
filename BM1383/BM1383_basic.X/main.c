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

#define device_control_code  0b1010 // All I2C devices have a control code assigned to them.
                                    // and the control code for a serial eeprom is b'1010'

//int fputc(int ch, FILE *f){
//    
//    EUSART1_Write(ch);
//    return ch;
//}

void Send_I2C_Data(uint8_t databyte)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit
    SSP1BUF = databyte;              // send databyte
    while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}


//**************************************************************************************
// Read one byte from SEE
//**************************************************************************************
unsigned int Read_I2C_Data(void)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit
    SSP1CON2bits.RCEN=1;         // set the receive enable bit to initiate a read of 8 bits from the serial eeprom
    while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete    
    return (SSP1BUF);            // Data from eeprom is now in the SSPBUF so return that value
}

//**************************************************************************************
// Send control byte to SEE (this includes 4 bits of device code, block select bits and the R/W bit)
//**************************************************************************************
// Notes:
// 1) The device code for serial eeproms is defined as '1010' which we are using in this example
// 2) RW_bit can only be a one or zero
// 3) Block address is only used for SEE devices larger than 4K, however on
// some other devices these bits may become the hardware address bits that allow you
// to put multiple devices of the same type on the same bus.  Read the datasheet
// on your particular serial eeprom device to be sure.
//**************************************************************************************
void Send_I2C_ControlByte(uint8_t BlockAddress,uint8_t RW_bit)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit

    // Assemble the control byte from device code, block address bits and R/W bit
    // so it looks like this: CCCCBBBR
    // where 'CCCC' is the device control code
    // 'BBB' is the block address
    // and 'R' is the Read/Write bit

    SSP1BUF = ((device_control_code << 4) | (BlockAddress <<1)) + RW_bit;  // send the control byte
    while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

//**************************************************************************************
// Send start bit to SEE
//**************************************************************************************
void Send_I2C_StartBit(void)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit
    SSP1CON2bits.SEN=1;          // send start bit
    while(!PIR3bits.SSP1IF);    // Wait for the SSPIF bit to go back high before we load the data buffer
}

//**************************************************************************************
// Send stop bit to SEE
//**************************************************************************************
void Send_I2C_StopBit(void)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit
    SSP1CON2bits.PEN=1;          // send stop bit
    while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}


//**************************************************************************************
// Send ACK bit to SEE
//**************************************************************************************
void Send_I2C_ACK(void)
{
   PIR3bits.SSP1IF=0;          // clear SSP interrupt bit
   SSP1CON2bits.ACKDT=0;        // clear the Acknowledge Data Bit - this means we are sending an Acknowledge or 'ACK'
   SSP1CON2bits.ACKEN=1;        // set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
   while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

//**************************************************************************************
// Send NAK bit to SEE
//**************************************************************************************
void Send_I2C_NAK(void)
{
    PIR3bits.SSP1IF=0;           // clear SSP interrupt bit
    SSP1CON2bits.ACKDT=1;        // set the Acknowledge Data Bit- this means we are sending a No-Ack or 'NAK'
    SSP1CON2bits.ACKEN=1;        // set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
    while(!PIR3bits.SSP1IF);    // Wait for interrupt flag to go high indicating transmission is complete
}

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
    
    unsigned int eeprom_array[20];
    unsigned int i;
    volatile unsigned int eeprom_data,incoming_data;
    volatile unsigned int block_address, word_address;
    unsigned int ACK_bit;
    
    SSP1CON1bits.SSPM=0x08; 
    SSP1CON1bits.SSPEN=1;         // enable MSSP port
    __delay_ms(10); // let everything settle.
    
//    block_address = 0x00;   // Set the eeprom block address that we will write the data to
//    word_address = 0x00;    // Set the eeprom word address that we will write the data to 
//    eeprom_data = 0x55;     // This is the data  we are going to write
//
////    Send_I2C_StartBit();                    // send start bit
////    Send_I2C_ControlByte(block_address,0);  // send control byte with R/W bit set low
////    Send_I2C_Data(word_address);            // send word address
////    Send_I2C_Data(eeprom_data);             // send data byte
////    Send_I2C_StopBit();                     // send stop bit
//    
//    // ************************ polling loop ***************************************************
//    block_address = 0x00;   // Set the eeprom block address
//
//    ACK_bit = 1;            // init the Ack bit high
//    while(ACK_bit)          // loop as long as the ack bit is high
//    {
//        Send_I2C_StartBit();
//        Send_I2C_ControlByte(block_address,0);
//        ACK_bit = SSP1CON2bits.ACKSTAT;  // Ack bit will come back low when the write is complete
//    }
//    // ******************************************************************************************

    EepWriteByte(0x00,1214,12);
    uint8_t data=0;
    
    while (1)
    {
        // Add your application code
        //EepWriteByte(0x00,1214,255);
       // uint8_t data=0;
        data=EepReadByte(0x00,1214);
//        if(data==121){
//
//            LED_SetHigh();
//        }
//        else
//            LED_SetLow();
        printf("value: %d\n", data);
        __delay_ms(500);
    }
    
}
/**
 End of File
*/