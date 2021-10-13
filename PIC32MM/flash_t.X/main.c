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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
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
#include "mcc_generated_files/system.h"
#include "stdio.h"
#include "delay.h"
#include "pin_manager.h"
//#include "mcc.h"
/*
                         Main application
 */
//uint8_t SST_Read(uint8_t *buf, uint32_t addr, uint8_t len);
//uint8_t SST_High_Speed_Read(uint8_t *buf, uint32_t addr, uint8_t len);
//unsigned char SST_Read_Status_Register(void);
//void SST_Read_ID(unsigned char *buf);
void SST_Write_Enable(void);
void SST_Write_Disable(void);
void SST_Read_Jedec_ID(uint8_t *buf);
void SST_Byte_Program(uint8_t addr, uint8_t *data);
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //printf("\nFlash TEST\n");
    uint8_t b=0xAA;
    uint8_t a,buf=0;
   // 
    SST_Read_Jedec_ID(&buf);
    while (1)
    {
        // Add your application code
        printf("\nFlash TEST\n");
//        a = SST_High_Speed_Read(&b, 0x00, 20);
//        printf("b = %x \n",a);
       // SST_Read_ID(&buf);
        
        
        DELAY_milliseconds(1000);
    }
    return 0; 
}
//uint8_t SST_Read(uint8_t *buf, uint32_t addr, uint8_t len)// read 25M
//{
//	SS_SetLow();
//	spi2_writeByte(0x03);
//	spi2_writeByte((addr & 0xff0000) >> 16);
//	spi2_writeByte((addr & 0x00ff00) >> 8);
//	spi2_writeByte(addr & 0x0000ff);
//	//spi2_writeByte(0);	
//	while(len-- > 0)
//		*buf++ = spi2_writeByte(0);
//    SS_SetHigh();
//	return *buf;
//}
//
uint8_t SST_High_Speed_Read(uint8_t *buf, uint32_t addr, uint8_t len)// read 80M
{
    uint32_t i;
	SS_SetLow();
	spi2_exchangeByte(0x0B);
	spi2_exchangeByte((addr & 0xff0000) >> 16);
	spi2_exchangeByte((addr & 0x00ff00) >> 8);
	spi2_exchangeByte(addr & 0x0000ff);
	spi2_exchangeByte(0);	
	for(i=0;i<len;i++)
    {
		buf[i] = spi2_exchangeByte(0);
    }
     SS_SetHigh();
	return *buf;
}
//unsigned char SST_Read_Status_Register(void)
//{
//    
//	unsigned char res;
//    SS_SetLow();
//	spi2_writeByte(0x01);
//	res = spi2_writeByte(0);
//    SS_SetHigh();
//	return res;
//}
//void SST_Read_ID(unsigned char *buf)
//{
//    int num;
//    uint8_t ID;
//	SS_SetLow();
//	spi2_writeByte(0x90);
//	spi2_writeByte(0);
//	spi2_writeByte(0);
//	spi2_writeByte(0);
//	*buf++ = spi2_writeByte(0);
//	*buf = spi2_writeByte(0);
//    ID = *buf;
//    printf("%d ADDr: %x\n",++num,ID);   
//	SS_SetHigh();
//}
void SST_Write_Enable(void)
{
    SS_SetLow();
	spi2_exchangeByte(0x06);
    SS_SetHigh();
}
void SST_Write_Disable(void)
{
    SS_SetLow();
	spi2_exchangeByte(0x04);
    SS_SetHigh();
}
void SST_Byte_Program(uint8_t addr, uint8_t *data)
{
    uint16_t i;
	SST_Write_Enable();
    DELAY_milliseconds(1);
	SS_SetLow();
	spi2_exchangeByte(0x02);    
	spi2_exchangeByte((addr & 0xff0000) >> 16);
	spi2_exchangeByte((addr & 0x00ff00) >> 8);
	spi2_exchangeByte(addr & 0x0000ff);
	for(i=0;i<256;i++)
    {
        spi2_exchangeByte(data[i]);
    }
	SS_SetHigh();
	DELAY_milliseconds(4);
}
void SST_Read_Jedec_ID(uint8_t *buf)
{
    int num;
    uint16_t i;
	SS_SetLow();
	spi2_exchangeByte(0x9f);
	buf[i]=spi2_exchangeByte(0);
	buf[i]=spi2_exchangeByte(0);
	buf[i]=spi2_exchangeByte(0);
    printf("%d ADDr2: %x\n",++num,buf[i]);
	SS_SetHigh();
}

/**
 End of File
*/

