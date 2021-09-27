#include "TickTimer32.h"
#include "AppPort.h"

uint32_t Tick_Per_Us=0;
uint32_t Tick_Per_Ms=0;
uint32_t Tick_Per_Sec=0;
private volatile uint32_t TickCount=0;

public void Tick_Timer_CallBack() // <editor-fold defaultstate="collapsed" desc="Interrupt callback function">
{
    TickCount++;
} // </editor-fold>

public uint64_t Tick_Timer_Get() // <editor-fold defaultstate="collapsed" desc="Get tick value">
{
    uint64_t CurTick;
    uint32_t CurCount;

    do
    {
        CurCount=TickCount;
        CurTick=CurCount;
        CurTick<<=32;
        CurTick|=_CP0_GET_COUNT();
    }
    while(TickCount!=CurCount);

    return CurTick;
} // </editor-fold>

public bool Tick_Timer_Is_Over(tick_timer_t *pTick, uint32_t Time, tick_timer_type_t TickType) // <editor-fold defaultstate="collapsed" desc="Check tick over microsecond">
{
    if(pTick->Timeout)
    {
        pTick->Timeout=0;
        if(TickType==US)
            pTick->Duration=Tick_Per_Us*Time;
        else if(TickType==MS)
            pTick->Duration=Tick_Per_Ms*Time;
        else
            pTick->Duration=Tick_Per_Sec*Time;
        pTick->Start=Tick_Timer_Get();
    }

    if((Tick_Timer_Get()-pTick->Start)>=pTick->Duration)
    {
        pTick->Timeout=1;

        return 1;
    }

    return 0;
} // </editor-fold>

public bool Tick_Counter_Is_Over(tick_counter_t *pTick, uint16_t Count) // <editor-fold defaultstate="collapsed" desc="Check 1 tick">
{
    if((uint16_t) pTick[0]<Count)
        pTick[0]++;
    else
    {
        pTick[0]=0;
        return 1;
    }

    return 0;
} // </editor-fold>

public void Delay(uint32_t Time, tick_timer_type_t TickType) // <editor-fold defaultstate="collapsed" desc="Delay">
{
    tick_timer_t Tick;

    Tick_Timer_Reset(Tick);
    while(Tick_Timer_Is_Over(&Tick, Time, TickType)==0)
        ClrWdt();
} // </editor-fold>

public void Tick_Timer_Init(void (*pNull)(void)) // <editor-fold defaultstate="collapsed" desc="Tick timer initialize, call first and 1 time">
{
    Disable_Coretimer_Interrupt();
    Tick_Per_Sec=CORETIMER_CLK;
    Tick_Per_Ms=Tick_Per_Sec/1000;
    Tick_Per_Us=Tick_Per_Ms/1000;
    Enable_Coretimer_Interrupt();
} // </editor-fold>