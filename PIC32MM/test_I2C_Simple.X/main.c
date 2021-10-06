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
#include "stdio.h"
#include "delay.h"
#include "i2c1_driver.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"
#include "mcc_generated_files/drivers/i2c_master.h"
//#include "mcc_generated_files/watchdog.h"
#include <xc.h>
//#include "i2c_simple_master.h"
/*
                         Main application
 */

void I2C_Scan_Multi(void);

//i2c_writeNBytes(i2c_address_t address, void* data, size_t len);
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    printf("Hello\n");
    
    
    while (1)
    {
        // Add your application code
         //I2C_Scan_Multi();
        //printf("MAMAMAMA \n");
        I2C_Scan_Multi();
        DELAY_milliseconds(1000);
      
    }
    return 0; 
}
void I2C_Scan_Multi(void){
    
    //i2c1_driver_isStart();
    uint8_t reg = 0x00;
    uint8_t num = 0, add = 0;
    //WATCHDOG_TimerClear();
    //i2c_open(add);
    while(!i2c_open(add));
    for(add=0; add<255; add++)
    {    
        
        i2c_writeNBytes(add, &reg, 1);
        DELAY_milliseconds(5);
        printf("Device: %d Address: %x\n", ++num, add);
        //i2c1_driver_sendACK();
        

        while(I2C_BUSY == i2c_close());


    }          

}

/**
 End of File
*/

