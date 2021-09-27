#include "AppPort.h"
#include "Buttons.h"
#include "TickTimer32.h"

bool Button_GetState() // <editor-fold defaultstate="collapsed" desc="Get button state">
{
    return BUTTON_GetValue();
} // </editor-fold>

int main(void) // <editor-fold defaultstate="collapsed" desc="Main function">
{
    bool EnableLed=1;
    tick_timer_t TickWdt;
    button_t Button;
    
    SYSTEM_Initialize();
    Tick_Timer_Init(NULL);
    Tick_Timer_Reset(TickWdt);
    // "Call Tick_Timer_CallBack() in _CORE_TIMER_ISR(void)"
    Button_Init(&Button, Button_GetState, HIGH_2_LOW, 500);// Press and hold button more than 500ms
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();
    
    while (1)
    {
        if(Tick_Timer_Is_Over_Ms(TickWdt, 100))
        {
            if(EnableLed)
                LED_Toggle();
            ClrWdt();
        }
        
        if(Button_Is_Pressed(&Button))
            EnableLed^=1;
    }
    
    return 1; 
} // </editor-fold>