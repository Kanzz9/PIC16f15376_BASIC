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
        Device            :  PIC32MM0064GPM048
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
#include "I2C.h"
#include "AT30TS74.h"
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    AT30TS74_t AT30TS74;
    uint8_t data[2];
    //uint8_t reg=0x00;
    int32_t tmp;
    float temp;
    AR30TS74_Init(AT30TS74);
    while (1)
    {
        // Add your application code
//        I2C_Write(AT30TS74_DEVICE_ADD,AT30TS74_Temp_Register,&data,1);
//        DELAY_milliseconds(5);
//        I2C_Read(AT30TS74_DEVICE_ADD,AT30TS74_Temp_Register,&data,1);
//        
//        tmp= data[0]<<8| data[1];
//            if(tmp&0x8000) // Temperature<0
//            {
//                tmp>>=7;// 9bit mode
//                tmp-=512;
//                temp=tmp;
//                temp*=0.5f;
//            }
//            else // Temperature>0
//            {
//                tmp>>=7;
//                temp=tmp;
//                temp*=0.5f;
//            }
              AT30TS74_Read_Temp();
//              temp*=0.5f;
              DELAY_milliseconds(1000);
              //printf("\nT=%.2f%cC\n", temp, 0xB0);
        
    }
    return 1; 
}
/**
 End of File
*/

