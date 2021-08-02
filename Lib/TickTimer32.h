#ifndef TICKTIMER32_H
#define	TICKTIMER32_H

#include <stdint.h>
#include <stdbool.h>
#include "mcc.h"

#ifdef public
#undef  public
#define public
#else
#define public
#endif

#ifdef private
#undef  private
#define private static
#else
#define private static
#endif

typedef void (*EventFunction) (void);

typedef enum {
    US = 0,
    MS,
    SEC
} tick_timer_type_t;

typedef struct {
    volatile bool Timeout;
    uint64_t Start;
    uint64_t Duration;
    EventFunction EvenHandler;
} __attribute__((packed)) tick_timer_t;

typedef uint16_t tick_counter_t;

extern uint32_t Tick_Per_Us;
extern uint32_t Tick_Per_Ms;
extern uint32_t Tick_Per_Sec;

public void Tick_Timer_CallBack(); // //it most call in coretimer.c// //
public uint64_t Tick_Timer_Get();
public void Tick_Timer_Init(void (*pNull)(void));
public bool Tick_Timer_Is_Over(tick_timer_t *pTick, uint32_t Time, tick_timer_type_t TickType);
public bool Tick_Counter_Is_Over(tick_counter_t *pTick, uint16_t Count);
public void Delay(uint32_t Time, tick_timer_type_t TickType);
public void Delay_Function(uint32_t Time, EventFunction callbackFunc);   

inline static void Delay_Us(Time) {
    Delay(Time, US);
}

inline static void Delay_Ms(Time) {
    Delay(Time, MS);
}

inline static void Delay_Sec(Time) {
    Delay(Time, SEC);
}

inline static uint64_t Tick_GetTimeUs() {
    return (Tick_Get() / Tick_Per_Us);
}

inline static uint64_t Tick_GetTimeMs() {
    return (Tick_Get() / Tick_Per_Ms);
}

inline static uint64_t Tick_GetTimeSec() {
    return (Tick_Get() / Tick_Per_Sec);
}

#define __delay_us(t)                       Delay_Us(t)
#define __delay_ms(t)                       Delay_Ms(t)
#define Tick_Timer_Reset(x)                 x.Timeout=1
#define Tick_Counter_Reset(x)               x=0
#define Tick_Timer_Is_Over_Us(pTick, Time)  Tick_Timer_Is_Over(&pTick, Time, US)
#define Tick_Timer_Is_Over_Ms(pTick, Time)  Tick_Timer_Is_Over(&pTick, Time, MS)
#define Tick_Timer_Is_Over_Sec(pTick, Time) Tick_Timer_Is_Over(&pTick, Time, SEC)

#endif