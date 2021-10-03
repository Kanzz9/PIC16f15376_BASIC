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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
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
#include <stdint.h>
#include "stdio.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/i2c1.h"
#include "mcc_generated_files/delay.h"
#include "RPR0521RS.h"
#include "I2C.h"
/*
                         Main application
 */

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
<<<<<<< HEAD
    RPR0521RS_init();
    //I2C1_MESSAGE_STATUS status;
    //uint8_t data=0;
    //uint8_t data_w = 0xaa;
    uint8_t rc;
    uint16_t ps_val;
    float als_val;
    uint8_t near_far;
  
     RPR0521RS_get_psalsval(&ps_val, &als_val);
    
    while (1)
    {
        // Add your application code
//        LED_2_Toggle();
//        DELAY_milliseconds(1000);
//        LED_1_SetLow();

//        I2C_Read(0x38,RPR0521RS_MANUFACT_ID , &data, 1);//
//        printf("MANUFACT_ID %d\n",data);

//        I2C_Read(0x38, 0x41, &data, 1);
//        printf("MANUFACT_ID %x\n",data);
        //RPR0521RS_init();
        //DELAY_milliseconds(500);
//        //I2C1_MasterWrite(data_w, 2, 0x38, &status);
//        I2C_Write(0x38, 0x41, &data_w, 1);
//        printf("status_ID %d\n",status);
         //.........................................
           //if (rc == 0) 
           //{
                printf("RPR-0521RS (Proximity)= %.2d \n",ps_val);
               // printf(ps_val);
                //printf(" [count]");
           near_far = RPR0521RS_check_near_far(ps_val);
           if (near_far == RPR0521RS_NEAR_VAL) 
           {
                printf(" Near\n");
           } 
           else 
           {
                printf(" Far\n");
           }
            //DELAY_milliseconds(1000);
           if (als_val != RPR0521RS_ERROR) 
           {
                printf("RPR-0521RS (Ambient Light) = %.2d \n",als_val);
                //printf(als_val);
               // printf(" [lx]");
               // printf("\n");
                
           }
         //}
     DELAY_milliseconds(1000);
=======
    
//    RPR0521RS_init();
  
    while (1)
    {
        // Add your application code
        //I2C_Scan_Multi();
        printf("hello\n");
        //UART2_Write('A');
        LED_1_Toggle();
        DELAY_milliseconds(1000);
>>>>>>> origin/master
    }
    return 0; 
}

/**
 End of File
*/

