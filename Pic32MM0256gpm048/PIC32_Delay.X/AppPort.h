#ifndef APPPORT_H
#define	APPPORT_H

#include "mcc_generated_files/mcc.h"
/* Application Definitions */
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

// Clock sources
#define SYS_CLK                             _XTAL_FREQ
#define PB_CLK                              _XTAL_FREQ
#define CORETIMER_CLK                       (_XTAL_FREQ>>1)
// Watching dog timer
#define ClrWdt()                            WATCHDOG_TimerClear()
// Global interrupt
#define Disable_Global_Interrupt()          __builtin_disable_interrupts()
#define Enable_Global_Interrupt()           __builtin_enable_interrupts()
// Peripheral interrupt
#define Disable_Peripheral_Interrupt()      // Not implemented in PIC32
#define Enable_Peripheral_Interrupt()       // Not implemented in PIC32
// Core timer interrupt
#define Disable_Coretimer_Interrupt()       (IEC0CLR=_IEC0_CTIE_MASK)
#define Enable_Coretimer_Interrupt()        (IEC0SET=_IEC0_CTIE_MASK)
#define Clear_Coretimer_Interrupt()         (IFS0CLR=_IFS0_CTIF_MASK)

#endif