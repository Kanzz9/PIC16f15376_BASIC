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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.155.0-a
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.40
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include "mcc_generated_files/mcc.h"
#include "AppPort.h"
#include "TickTimer32.h"
#include "Buttons.h"
#include "TEXTLCD.h"
#include "stdio.h"

bool Button1_Getstate(void);

void _mon_putc(char c);


/*
                         Main application
 */

int main(void)
{
    bool cycle=0;
    int16_t i=0;
    tick_timer_t Tick, Tick_Count;
    button_t Button1;
    Tick_Timer_Reset(Tick);
    Tick_Timer_Reset(Tick_Count);
    // initialize the device
    SYSTEM_Initialize();
    Tick_Timer_Init(NULL);
    Button_Init(&Button1,Button1_Getstate,HIGH_2_LOW,50);
    TextLCD_Init(TEXTLCD1602);
    TextLCD_Clear();
    TextLCD_Puts(0,0,"hello",0);
    LED_SetLow();
    while (1)
    {
        // Add your application code
        
        /*test GPIO(output)
        if(Tick_Timer_Is_Over_Ms(Tick,100))
            LED_Toggle();
         */
        
        /*test GPIO(input)
        if(cycle)
            LED_SetHigh();
        else
            LED_SetLow();
        
        if(Button_Is_Pressed(&Button1))
            cycle^=1; 
         */
        
        /*test GPIO(input)
        Button_Is_Pressed_Release(&Button1,&cycle);
        
        if(cycle)
            LED_SetHigh();
        else
            LED_SetLow(); 
         */
        
//        if(Tick_Timer_Is_Over_Ms(Tick,1000)){
//        
//            LED_Toggle();
//        }
//        for(i=-111;i<111;i++){
//            
//            TextLCD_Three_Number_Int(1,0,i);
//            TextLCD_SetCursor(1,0);
//            printf("Number: %.1f",(float)i);
//            __delay_ms(100);
//           
//        }
        if(Tick_Timer_Is_Over_Ms(Tick_Count,500)){
        
            i++;
            TextLCD_Three_Number_Int(1,0,i);
        }
        
        if(Button_Is_Pressed(&Button1))
            cycle^=1;
        
        if(cycle)
            LED_SetHigh();
        else
            LED_SetLow();
    }
    return 1; 
}

bool Button1_Getstate(void){
    
    return BUTTON1_GetValue();
}

void _mon_putc(char c) // <editor-fold defaultstate="collapsed" desc="be used for printf function">
{
    TextLCD_PutChar(c);
} // </editor-fold>

/**
 End of File
*/

