

#include "mcc_generated_files/mcc.h"
#include"TEXTLCD.h"
#include<stdio.h>
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    float a,AD;
    unsigned int c,d;
    char buff[10];
    SYSTEM_Initialize();
    TextLCD_Init(TEXTLCD1602);
    ADC_Initialize();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
     //TextLCD_Puts(0,0,"HOANG TOAN",0);
    while (1)
    {
        AD=0;
        ADC_SelectChannel(channel_AND4 );
        ADC_StartConversion();
        while(!ADC_IsConversionDone());
        AD=ADC_GetConversionResult();
        a=(float)(AD*5)/1023; //doi sang dien ap(volt)
		c=(unsigned int)(a*1000);//doi sang mV
       TextLCD_Puts(0,0,"Dien AP: ",0);
        sprintf(buff,"%.3f V",a);
        TextLCD_Puts(0,9,buff,0);
        TextLCD_Puts(1,0,"Dien AP: ",0);
        sprintf(buff,"%.3d mV",c);
        TextLCD_Puts(1,9,buff,0);
        if(c<500)
        {
            LED1_SetHigh();
            LED2_SetHigh();
        }else if(c>3500)
        {
            BUZZER_SetHigh();
            LED3_SetHigh();
        }
        else
        {
            LED1_SetLow();
            LED2_SetLow();
            BUZZER_SetLow();
            LED3_SetLow();
        }
        // Add your application code
    }
}
/**
 End of File
*/