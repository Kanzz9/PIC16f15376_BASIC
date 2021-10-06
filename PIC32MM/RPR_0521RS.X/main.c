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
#include "mcc.h"

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    RPR0521RS_t RPR0521RS;
    uint16_t PS_Data, PS_TH,PS_TL, data0;
    uint16_t ALS_DATA_0=0, ALS_DATA_1=0;
    
    //RPR0521RS.RPR0521RS_ALS_EN = ALS_Standby;
    //RPR0521RS.RPR0521RS_PS_EN  = PS_Enable;
         
    I2C_Scan_Multi(); 
    RPR0521RS_ReadID();
        
   // RPR0521RS_Mode_Config(RPR0521RS);
    RPR0521RS_Init(RPR0521RS);
    while (1)
    {
        // Add your application code
                
        PS_Data = RPR0521RS_Read_PS_DATA();
        RPR0521RS_Read_ALS_DATA(&ALS_DATA_0, &ALS_DATA_1);
        PS_TH = RPR0521RS_Read_PS_TH();
        PS_TL = RPR0521RS_Read_PS_TL();
//        data0 = RPR0521RS_Read_ALS_DATA0_TH;
        printf("ALS_DATA_0: %d\n", ALS_DATA_0);
        printf("ALS_DATA_1: %d\n", ALS_DATA_1);
        printf("PS_TH: %d\n", PS_TH);
       //printf("DATA: %d\n", data0
         printf("PS_Data: %d\n", PS_Data);
             if(PS_Data <= 0)
                printf("Unknown\n");
            if(1 <= PS_Data && PS_Data <30)
                printf("far\n");
            if(PS_Data >= 30)
                printf("near\n");
       
        
        DELAY_milliseconds(2000);
        
    }
    return 1; 
}
/**
 End of File
*/

