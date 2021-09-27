/* 
 * File:   HX711.h
 * Author: hoang
 *
 * Created on April 12, 2021, 11:17 PM
 */

#ifndef HX711_H
#define	HX711_H

#ifdef	__cplusplus
extern "C" {
#endif
   
#include "main.h"   
   
typedef enum{
   
   channelA = 0,
   channelB   
}channel_t;

typedef enum{
   
   gain_128 = 0,
   gain_64,
   gain_32
}gain_t;

typedef struct{
   
   channel_t channel;
   gain_t gain;
   uint8_t numberPluses;
} __attribute__((packed)) HX711_t;   

bool HX711_Init(HX711_t* HX711);
bool HX711_Ready(void);
bool HX711_Read(uint32_t* weight, const HX711_t* HX711);

#ifdef	__cplusplus
}
#endif

#endif	/* HX711_H */

