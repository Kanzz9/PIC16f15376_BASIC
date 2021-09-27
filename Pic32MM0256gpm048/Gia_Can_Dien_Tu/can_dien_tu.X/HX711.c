#include <stdint.h>

#include "HX711.h"
#include "mcc_generated_files/uart1.h"

bool HX711_Init(HX711_t* HX711){
   
    uint32_t weight;
    
    SCK1_SetLow();

    switch(HX711->gain){

       case gain_128:
            HX711->numberPluses = 1;
            if(HX711->channel == channelB)
               return false; // Gain=128 is only channel A
            break;
       case gain_64:
            HX711->numberPluses = 2;
            if(HX711->channel == channelB)
               return false; // Gain=64 is only channel A
            break;
       case gain_32:
            HX711->numberPluses = 3;
            if(HX711->channel == channelA)
               return false; // Gain=32 is only channel B
            break;
    }
   
    return (HX711_Read(&weight, HX711));
}

bool HX711_Ready(void){
   
    return (!SDI1_GetValue());   
}

bool HX711_Read(uint32_t* weight, const HX711_t* HX711){
   
    uint32_t value=0;
    static tick_timer_t Tick;
    uint8_t i,y;
    
    if(HX711_Ready()){
        
        for(i=0; i<24; i++){
            
            SCK1_SetHigh();
            DELAY_microseconds(1);
            value<<=1;
            SCK1_SetLow();
            if(SDI1_GetValue()) 
                value++;
            DELAY_microseconds(1);
        }
        
        for(y=0; y<(HX711->numberPluses); y++){
            
            SCK1_SetHigh();
            DELAY_microseconds(1);
            SCK1_SetLow();
            DELAY_microseconds(1);
        }
        
        value ^= 0x800000;
        *weight=value;
        return true;
    }
    else{
        
        if(Tick_Timer_Is_Over_Ms(Tick,200))
            return false;
    }
    
    return false;
}



