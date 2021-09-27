#ifndef BUTTONS_H
#define BUTTONS_H

//#include <stdint.h>
//#include <stdbool.h>
#include "TickTimer32.h"

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

typedef enum EDGE_DETECT {
    LOW_2_HIGH = 0,
    HIGH_2_LOW
} edge_t;

typedef enum BUTTON_TASKS {
    BT_UNPRESSED = 0,
    BT_CHECK_AGAIN,
    BT_CHECK_NOISE,
    BT_PRESSED,
    BT_CHECK_NOISE_RELEASE,
    BT_CHECK_AGAIN_RELEASE,
} button_task_t;

typedef bool (*signal_handler_t)(void);

typedef struct {
    edge_t Edge;
    button_task_t BtTask;
    uint16_t DetectTime;
    signal_handler_t SignalFunc;
    tick_timer_t Tick;
} button_t;

public bool Button_Is_Pressed(button_t *BT);
public void Button_Is_Pressed_Release(button_t *BT, bool *button);
public void Button_Init(button_t *BT, signal_handler_t SignalFunc,
        edge_t Edge, uint16_t DetectCount);

#endif

