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
#include <stdio.h>
#include <string.h>
#include "uart3.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/delay.h"

/*
                         Main application
 */
#define MY_BUFFER_SIZE 36
char buff[100]={0};
char data;
void send_AT(void);
void puts_uart(char *str)
{
	uint8_t temp;
	while(*str)
	{
		temp=*str;
		UART3_Write(temp);
		str++;
	}
}
void gsm_power_key()
{
   
    PW_ON_GSM_SetLow();
    DELAY_microseconds(300);
    PW_ON_GSM_SetHigh();
    DELAY_microseconds(1000);
}
void test_Writebuffer()
{
    uint8_t WriteBuffer[] = "AT\n" ;
    unsigned int numBytes = 0;
    int writebufferLen = 2;
 
    while(numBytes < writebufferLen)
    { 
        int bytesToWrite = UART3_TransmitBufferSizeGet();
        numBytes += UART3_WriteBuffer ( WriteBuffer+numBytes, bytesToWrite) ;
    }
}
void test_Writebuffer1(char *str)
{
    //uint8_t writeBuffer[35] = str ;
    unsigned int numBytes = 0;
    int writebufferLen = strlen((char *)str);
 
    while(numBytes < writebufferLen)
    {
        int bytesToWrite = sizeof( str); 
        numBytes += UART3_WriteBuffer ( str+numBytes, bytesToWrite) ;
 
    }
 
 }
 void test_Readbuffer1()
{
            char myBuffer[MY_BUFFER_SIZE];
          unsigned int numBytes;
          numBytes = 0;
          uint8_t  *str1;
          str1=(uint8_t*)calloc(100,sizeof(uint8_t));
          do
           {
           if( UART3_TRANSFER_STATUS_RX_DATA_PRESENT & UART3_TransferStatusGet() )
           {
           myBuffer[numBytes++] = UART2_Read();
           }
           if ( 13 == myBuffer[numBytes-1])
           {
           break;
           }

          } while( numBytes < MY_BUFFER_SIZE);

          strcpy(str1, myBuffer); //copy buffer to Image

          puts_uart(str1); //Loop Back Buffer Image to UART3
          
          free(str1);
 
 }   

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    gsm_power_key();
     uint8_t  *str1;
    //  str1=(uint8_t*)calloc(100,sizeof(uint8_t));
     test_Writebuffer1("AT\n");
     test_Readbuffer1();
     //printf("AT\r\n");
    while (1)
    {
        
        
        //DELAY_microseconds(100);
//        send_AT();
//        DELAY_microseconds(1000);
//        //str1 = UART2_Read();
//        UART2_ReadBuffer(str1,100);
//        sprintf(buff,"%c",str1);
//        puts_uart(buff);
//        free(str1);
        
        // Add your application code
    }
    return 1; 
}
/**
 End of File
*/
void send_AT(void)
{
    
    printf("AT\r\n");
    DELAY_microseconds(5);
    printf("AT+CGMM\r\n");
    DELAY_microseconds(5);
    printf("AT+CGMR\r\n");
    DELAY_microseconds(5);
    printf("AT+COPS?\r\n");
    DELAY_microseconds(5);
}
//void UART2_Receive_CallBack(void)
//{
//        data = UART2_Read();
//        sprintf(buff,"%c",data);
//        puts_uart(buff);
//        
//}
