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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.167.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.35
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
//#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"
#include "string.h"
#include "stdio.h"
#include "conio.h"
#include "mcc_generated_files/uart2.h"

//void _mon_putc(char c)
//{
//    UART1_Write(c);
//}

/*
                         Main application
 */

void __delay_ms(uint16_t t);

int main(void)
{
    uint8_t *str, *str1;
    // initialize the device
    SYSTEM_Initialize();
    str=(uint8_t*)calloc(100,sizeof(uint8_t));
    str1=(uint8_t*)calloc(100,sizeof(uint8_t));
    while (1)
    {
        
        // Add your application code
        __delay_ms(200);
//                
//        if(strcmp(str,str1)!=0){
//            
//            strcpy(str,str1);
//            if(strstr(str,"batden1")!=NULL){
//                
//                printf("\nbatden1: OK\n");
//                LED_SetHigh();
//            }
//            else
//                if(strstr(str,"tatden1")!=NULL){
//
//                    printf("\ntatden1: OK\n");
//                    LED_SetLow();
//                }
//                else
//                    printf("\ncommand fail\n");
//        }
//        else
            UART2_ReadBuffer(str1,100);
       
        printf("\ncommand fail\n");
    }
    free(str);
    free(str1);
    return 0; 
}
/**
 End of File
*/

void __delay_ms(uint16_t t)
{
    TMR1SET=0;
    while(t--){
        
        while(!IFS0bits.T1IF);
        IFS0bits.T1IF=0;
    }
}

void UART2_Receive_CallBack(){
    
    LED_Toggle();
}
