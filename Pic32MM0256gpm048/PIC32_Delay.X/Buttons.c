#include "Buttons.h"

public bool Button_Is_Pressed(button_t *BT) // <editor-fold defaultstate="collapsed" desc="Check pressed button">
{
    switch(BT->BtTask)
    {
        case BT_CHECK_NOISE:
            if(Tick_Counter_Is_Over(&BT->Count, BT->DetectCount))
            {
                BT->BtTask=BT_PRESSED;
                if(BT->Edge==HIGH_2_LOW)
                    return 1;
            }
            else BT->BtTask=BT_CHECK_AGAIN;
            break;

        case BT_CHECK_AGAIN:
            if(BT->SignalFunc()==0)
                BT->BtTask=BT_CHECK_NOISE;
            else
            {
                Tick_Counter_Reset(BT->Count);
                BT->BtTask=BT_UNPRESSED;
            }
            break;

        case BT_PRESSED:
            if(BT->SignalFunc()==1)
            {
                BT->BtTask=BT_UNPRESSED;
                if(BT->Edge==LOW_2_HIGH)
                    return 1;
            }
            break;

        default:
            if(BT->SignalFunc()==0)
            {
                Tick_Counter_Reset(BT->Count);
                BT->BtTask=BT_CHECK_NOISE;
            }
            break;
    }

    return 0;
} // </editor-fold>

public void Button_Init(button_t *BT, signal_handler_t SignalFunc,
                 edge_t Edge, uint16_t DetectCount) // <editor-fold defaultstate="collapsed" desc="Button Initialize">
{
    BT->Edge=Edge;
    BT->BtTask=BT_UNPRESSED;
    BT->DetectCount=DetectCount;
    BT->SignalFunc=SignalFunc;
    Tick_Counter_Reset(BT->Count);
} // </editor-fold>