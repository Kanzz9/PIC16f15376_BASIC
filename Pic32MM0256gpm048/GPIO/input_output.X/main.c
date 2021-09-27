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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.166.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.41
        MPLAB 	          :  MPLAB X v5.30
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
#include "mcc_generated_files/system.h"
#include "TickTimer32.h"
#include "pin_manager.h"
#include "Buttons.h"
#include "mccp1_compare.h"

#define duty_max 2499

bool Button_GetState(void);

/*
                         Main application
 */
int main(void)
{
    bool toggle=0;
    uint16_t i;
    
    tick_timer_t Tick, Tick1;
    Tick_Timer_Reset(Tick);
    Tick_Timer_Reset(Tick1);
    
    button_t Bt;
    // initialize the device
    SYSTEM_Initialize();
    
    Tick_Timer_Init(NULL);
    Button_Init(&Bt,Button_GetState,HIGH_2_LOW,50);
    
    while (1)
    {
        // Add your application code
        if(toggle){
            
            if(Tick_Timer_Is_Over_Ms(Tick,200))
                LED_Toggle();
        }

        if(Button_Is_Pressed(&Bt))
            toggle^=1;
        
        if(Tick_Timer_Is_Over_Ms(Tick1,10)){
            
            i++;
            if(i>=duty_max)
                i=0;
            MCCP1_COMPARE_DualEdgeBufferedConfig(0,i);
        }         
    }
    return 1; 
}
/**
 End of File
*/

