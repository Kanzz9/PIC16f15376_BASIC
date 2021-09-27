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
#include <stdint.h>

#include "main.h"
#include "stdlib.h"
#include "HX711.h"
#include "string.h"
#include "stdio.h"
#include "i2c_config.h"
#include "ssd1306.h"

/*
                         Main application
 */

void Led_sw(void){
    
    LED_Toggle();
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    int32_t real=0, weight=0, bif=0;
    uint8_t sampleCount=0;
    float weight_f=0.0f;

    Tick_Timer_Init(NULL);  
    tick_timer_t Tick;

    HX711_t HX711;

    HX711.channel=channelA;
    HX711.gain=gain_128;

    HX711_Init(&HX711);
   
    ssd1306_Init();

    DELAY_milliseconds(1000);

    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();

    DELAY_milliseconds(1000);

    // Write data to local screenbuffer
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Can Dien Tu", Font_11x18, White);

    ssd1306_SetCursor(0, 36);
    ssd1306_WriteString("Hoang Ba Gia", Font_11x18, White);

    // Copy all data from local screenbuffer to the screen
    ssd1306_UpdateScreen();
	
    DELAY_milliseconds(1000);
    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();
	
    char buff[16]={0};
    if(HX711_Read(&bif, &HX711));
   
   /////////////////////
   
      
   while (1)
   {
      // Add your application code
        
        if(Tick_Timer_Is_Over_Ms(Tick,100)){
            //LED_Toggle();
            
            if(sampleCount == 10){
                
                weight_f = (float)(real/10)/25400.0f;
                real=0; // clear
                sampleCount=0; // clear
                //printf("Weight: %.2f\r\n",weight_f);
                ssd1306_SetCursor(0, 0);
                sprintf(buff, "%.1fKg  ",weight_f); 
                ssd1306_WriteString(buff, Font_16x26, White);
                ssd1306_UpdateScreen();
            }
            else{
                
                if(HX711_Read(&weight, &HX711)){
                    //printf("weight: %d\n", weight);
                    
                    weight-=bif;                    
                    real+=weight;
                }
                else{
                
                    printf("ERROR\n");
                    sampleCount=0;
                    weight=0;
                    weight_f=0.0f;
                    real=0;
                    LED_Toggle();
                }      
                sampleCount++;
            }       
        }
        
        if(!BUTTON_GetValue()){
            
            while(!BUTTON_GetValue()){
                LED_Toggle();
                DELAY_milliseconds(100);
            }
            DELAY_milliseconds(500);
            if(HX711_Read(&bif, &HX711));
            DELAY_milliseconds(200);
        }
   }
   return 0; 
}



/**
 End of File
*/

