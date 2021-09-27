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
#include "i2c_simple_master.h"


/*
                         Main application
 */
int fputc(int ch, FILE *f){
	
    EUSART1_Write((char)ch);
    //TextLCD_PutChar((char)ch);
    return ch;
}

/* ****************************************************************************/
/** This is a private  callback handler for use with I2C_check(...) function.
 * Argument
 *  *Ptr   Callback payload pointer is used for address of nackFlag status value.
 */
//static  i2c1_operations_t  NackAddressHandler(void *Ptr)
//{    /* Do something to notice that Address Nack have occurred. */
//	uint8_t * nackFlag = Ptr;
//    *nackFlag = 1;
//    return I2C1_STOP;          /* Let driver proceed with Stop signal. */
//}

/* *****************************************************************************
 *  nack = I2C_check(  deviceAddress); */
/** 
 * Description:
 *  Function to check if I2C device answer when called.
 * Argument:
 *  deviceAddress is I2C 7-bit address of slave.
 *  Return value == 0   I2C slave is present and responding.
 *               == 1   NACK returned, slave is not connected, or do not respond.
 */
//uint8_t I2C_check( uint8_t  deviceAddress)
//{
//    static uint8_t   NackFlag; 
//    static uint8_t   dummy[2] = {0x00, 0x18};
//    NackFlag = 0;        /* Reset the flag, */
//
//    while(!I2C1_Open(deviceAddress)); // sit here until we get the bus..
//
//    I2C1_SetBuffer(&dummy[1],2);		    /* This should work with i2c_master.c with no change. */
////  I2C_SetBuffer(&dummy[1],0);			/* Zero length transfer require modified driver i2c_master.c */
//    I2C1_SetAddressNackCallback(NackAddressHandler, &NackFlag); /* Pointer to Flag as payload pointer. */
//
//    I2C1_MasterOperation(0);				/* Start a I2C Write operation, same as I2C_MasterWrite. */
//    while(I2C1_BUSY ==  I2C1_Close()); // sit here until finished.
//    return NackFlag;
//}

/* *****************************************************************************
 *  I2C_AddressScan(); */
/**	Description:
 *  Function to scan a I2C bus for available devices.
 */
//void I2C_AddressScan(void)
//{	uint8_t address, flag;
//	printf("I2C 7bit Address \r\n");
////	for (address = 0x50; address < 0x58; address ++)		/* I2C EEPROM addresses. */
//	for (address = 8; address < 120; address ++)			/* Permissible 7-bit addresses. */
//	{			//	LATCbits.LATC3 = 1; /* Diagnostic timing signal. */
//		flag = I2C_check( address);
//				//	LATCbits.LATC3 = 0; /* Diagnostic timing signal. */
//		while (!EUSART1_is_tx_done());	/* Wait until previous print is done. */
//		if (flag)
//			printf(" 0x%X No answer. \r\n", address);
//		else
//			printf(" 0x%X Responding. \r\n", address);
//	}
//}

void EE_Write(uint16_t addr, uint8_t data)
{
    uint8_t frame[3];

    frame[0]=(uint8_t) (addr>>8); // high address
    frame[1]=(uint8_t) addr; // low address
    frame[2]=data; // data
    //EE_WP_SetLow(); // disable write protect
    i2c_writeNBytes(0b01010000, &frame[0], 3);
    __delay_ms(5);
    //EE_WP_SetHigh(); // enable write protect
}

uint8_t EE_Read(uint16_t addr)
{
    uint8_t frame[3];

    frame[0]=(uint8_t) (addr>>8); // high address
    frame[1]=(uint8_t) addr; // low address
    i2c_writeNBytes(0b01010000, &frame[0], 2);
    i2c_readNBytes(0b01010000, &frame[2], 1);

    return frame[2];
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
    //I2C_AddressScan();
    uint8_t data[5]={0,1,2,3,4};
    uint8_t value[5]={0};
    uint8_t a=0;
    //i2c_writeNBytes(0x50,data,5);
    //i2c_readNBytes(0x50,value,5);
    
    EE_Write(0x00,0xAA);
    a=EE_Read(0x00);
    printf("a: %d\n",a);
    while (1)
    {
        // Add your application code
//        printf("abc\n");
//        __delay_ms(500);
//        //I2C1_fReadDataBlock(0x50, 0x01, data, 10);
//        printf("value:");
//        
//        for(uint8_t i=0; i<5; i++){
//            
//            printf("%d, ",value[i]);
//        }    
//        
//        printf("\n");
        
        
        //printf("DATA: %x\n", data);
       // value = i2c_read2ByteRegister(0x50,0x00);
    }
}
/**
 End of File
*/