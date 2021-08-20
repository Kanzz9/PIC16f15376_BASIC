/*
 
 */

#include "I2C.h"

#if(I2C_Enable)

void I2C_Init(void){
        
    SSP1CON1bits.SSPM=0x08; 
    SSP1CON1bits.SSPEN=1;         // enable MSSP port
}

//void I2C_H

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
void Send_I2C_ControlByte(uint8_t Dev_Add, uint8_t RW_bit)
{
    PIR3bits.SSP1IF=0;          // clear SSP interrupt bit

    // Assemble the control byte from device code, block address bits and R/W bit
    // so it looks like this: CCCCBBBR
    // where 'CCCC' is the device control code
    // 'BBB' is the block address
    // and 'R' is the Read/Write bit

    SSP1BUF = (Dev_Add<<1) + RW_bit ;  // send the control byte
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

#endif

