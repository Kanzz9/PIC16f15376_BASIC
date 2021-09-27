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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36b
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
#include "TickTimer32.h"
#include "Buttons.h"
#include "AppPort.h"


bool Button_GetState(){
    
   return BUTTON_GetValue();
}

/*
                         Main application
 */
int main(void)
{
    
    uint16_t duty=0;
    uint8_t count=0;
    bool cycle=1;
    tick_timer_t Tick_Pwm, Tick_Led;
    button_t Button;
    // initialize the device
    SYSTEM_Initialize();
    Tick_Timer_Init(NULL);
    Tick_Timer_Reset(Tick_Pwm);
    Tick_Timer_Reset(Tick_Led);
    // "Call Tick_Timer_CallBack() in _CORE_TIMER_ISR(void)"
    Button_Init(&Button, Button_GetState, HIGH_2_LOW, 10);// Press and hold button more than 500ms
    char OMG[] = "HELLO WORLD OMG !!";
    LED_SetHigh();
    while (1)
    {
        __delay_ms(100);
        // Add your application code
        /*
         if(Tick_Timer_Is_Over_Ms(TickWdt, 500))
        {
            LED_Toggle();
            ClrWdt();
        }
         if(Button_Is_Pressed(&button))
            EnableLed^=1;
        
        if(Enableled)
            LED_Toggle();
       // __delay_ms(100);
        */
        
         if(Tick_Timer_Is_Over_Ms(Tick_Pwm, 10))
        {
            if(cycle==0){
                
                MCCP1_COMPARE_DualEdgeBufferedConfig(0,duty);
                duty++;
            }
            
            if(cycle==1){
                
                MCCP1_COMPARE_DualEdgeBufferedConfig(0,duty);
                duty--;
            }
           
            if(duty<=1)
                cycle=0;
            if(duty>=4990)
                cycle=1;
                
        }
        
        if(Button_Is_Pressed(&Button)){
            
            count++;
            if(count>200) count=0;
            LED_Toggle();
        } 
        

        if(Tick_Timer_Is_Over_Ms(Tick_Led, 100)){
            
            count++;
            LED_Toggle();
            if(count>=200) count=0;
        }   
        
        ClrWdt();   
    }
    return 1; 
}
/**
 End of File
*/

