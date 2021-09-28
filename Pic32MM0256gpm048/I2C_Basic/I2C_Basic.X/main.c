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
#include "mcc_generated_files/delay.h"
#include "mcc_generated_files/i2c1.h"
#include "stdio.h"  

#define MCHP24AA512_RETRY_MAX       100  // define the retry count
#define MCHP24AA512_ADDRESS         0x50 // slave device address
#define MCHP24AA512_DEVICE_TIMEOUT  50   // define slave timeout

uint8_t I2C_Scan(void);
void I2C_Scan_Multi(uint8_t* dev_add, uint8_t* num_dev);

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    uint8_t dev_add, num_dev = 0;
    uint8_t dev_add_multi[10] = {0};
    int i;
    while (1)
    {
        // Add your application code
        //dev_add = I2C_Scan();
        I2C_Scan_Multi(dev_add_multi, &num_dev);
        printf("Num of device: %d\n",num_dev);
        for(i=0; i<num_dev; i++){
            printf("device_add: %x\n",dev_add_multi[i]);
        }
        DELAY_milliseconds(500);
        
    }
    return 0; 
}

uint8_t I2C_Scan(void){
    
    I2C1_MESSAGE_STATUS status;
    uint8_t reg_index = 0x00;
    uint8_t dev_add = 0;
    
    while(status != I2C1_MESSAGE_FAIL){
        
        I2C1_MasterWrite(&reg_index, 1, dev_add, &status);
        DELAY_milliseconds(5);
        if(status == I2C1_MESSAGE_COMPLETE)
            return dev_add;
        else
            dev_add++;
        
        if(dev_add == 255)
            return 0;
    }
    return 0;
}

void I2C_Scan_Multi(uint8_t* dev_add, uint8_t* num_dev){
    
    I2C1_MESSAGE_STATUS status;
    uint8_t reg_index = 0x00;
    uint8_t add = 0;
    uint8_t num = 0;

    for(add=0; add<255; add++){    
        
        I2C1_MasterWrite(&reg_index, 1, add, &status);
        DELAY_milliseconds(5);
        if(status == I2C1_MESSAGE_COMPLETE){
            
            *(dev_add++) = add;
            num++;
            status = I2C1_MESSAGE_ADDRESS_NO_ACK;
        }
    }
    *num_dev = num;

}
/**
 End of File
*/

