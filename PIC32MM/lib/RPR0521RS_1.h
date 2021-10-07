/* 
 * File:   RPR0521RS.h
 * Author: HoangKhanhToan
 *
 * Created on Sep 28, 2021, 9:00 AM
 */


#ifndef RPR0521RS_H
#define RPR0521RS_H
//
#include "mcc.h"

//#if(RPR0521RS_Enable)

#define RPR0521RS_SYMTEM_CONTROL    0X40
#define RPR0521RS_MODE_CONTROL      0X41
#define RPR0521RS_ALS_PS_CONTROL    0X42
#define RPR0521RS_PS_CONTROL        0X43
#define RPR0521RS_PS_DATA_LSBs      0X44
#define RPR0521RS_PS_DATA_MSBs      0X45
#define RPR0521RS_ALS_DATA0_LSBs    0X46
#define RPR0521RS_ALS_DATA0_MSBs    0X47
#define RPR0521RS_ALS_DATA1_LSBs    0X48
#define RPR0521RS_ALS_DATA1_MSBs    0X49
#define RPR0521RS_INTERRUPT         0X4A
#define RPR0521RS_PS_TH_LSBs        0X4B
#define RPR0521RS_PS_TH_MSBs        0X4C
#define RPR0521RS_PS_TL_LSBs        0X4D
#define RPR0521RS_PS_TL_MSBs        0X4E
#define RPR0521RS_ALS_DATA0_TH_LSBs 0X4F
#define RPR0521RS_ALS_DATA0_TH_MSBs 0X50
#define RPR0521RS_ALS_DATA0_TL_LSBs 0X51
#define RPR0521RS_ALS_DATA0_TL_MSBs 0X52
#define RPR0521RS_PS_OFFSET_LSBs    0X53
#define RPR0521RS_PS_OFFSET_MSBs    0X54
#define RPR0521RS_MANUFACT_ID       0X92



#define RPR0521RS_DEVICE_ADDRESS                   0x38    // 7bit Addrss
#define RPR0521RS_PART_ID_VAL                      0x0A
#define RPR0521RS_MANUFACT_ID_VAL                  0xE0

#define RPR0521RS_MODE_CONTROL_MEASTIME_100_100MS  (6 << 0)
#define RPR0521RS_MODE_CONTROL_PS_EN               (1 << 6)
#define RPR0521RS_MODE_CONTROL_ALS_EN              (1 << 7)

#define RPR0521RS_ALS_PS_CONTROL_LED_CURRENT_100MA (2 << 0)
#define RPR0521RS_ALS_PS_CONTROL_DATA1_GAIN_X1     (0 << 2)
#define RPR0521RS_ALS_PS_CONTROL_DATA0_GAIN_X1     (0 << 4)

#define RPR0521RS_PS_CONTROL_PS_GAINX1             (0 << 4)

#define RPR0521RS_MODE_CONTROL_VAL                 (RPR0521RS_MODE_CONTROL_MEASTIME_100_100MS | RPR0521RS_MODE_CONTROL_PS_EN | RPR0521RS_MODE_CONTROL_ALS_EN)
#define RPR0521RS_ALS_PS_CONTROL_VAL               (RPR0521RS_ALS_PS_CONTROL_DATA0_GAIN_X1 | RPR0521RS_ALS_PS_CONTROL_DATA1_GAIN_X1 | RPR0521RS_ALS_PS_CONTROL_LED_CURRENT_100MA)
#define RPR0521RS_PS_CONTROL_VAL                   (RPR0521RS_PS_CONTROL_PS_GAINX1)

#define RPR0521RS_NEAR_THRESH                      (1000) // example value
#define RPR0521RS_FAR_VAL                          (0)
#define RPR0521RS_NEAR_VAL                         (1)

#define RPR0521RS_ERROR                            (-1)

typedef enum{
   
   Initial_Reset_Not_Started = 0,
   Initial_Reset_Started
}RPR0521RS_SW_Reset_t;

typedef enum{
   
   INT_Pin_Status_Not_Initialized = 0,
   INT_Pin_Become_Inactive //( high impedance )
}RPR0521RS_INT_Reset_t;

typedef enum{
   
   ALS_Standby = 0,
   ALS_Enable
}RPR0521RS_ALS_EN_t;

typedef enum{
   
   PS_Standby = 0,
   PS_Enable
}RPR0521RS_PS_EN_t;

typedef enum{
   
   PS_LED_Pulse_Width_200us = 0,
   PS_LED_Pulse_Width_330us // (PS sensor out is doubled)
}RPR0521RS_PS_PULSE_t;

typedef enum{
   
   Normal_Mode = 0,
   Twice_Measurement_Mode
}RPR0521RS_PS_Mode_t;

typedef enum{
   
   ALS_STB_PS_STB = 0,
   ALS_STB_PS_10ms,
   ALS_STB_PS_40ms,
   ALS_STB_PS_100ms,
   ALS_STB_PS_400ms,
   ALS_100ms_PS_50ms,
   ALS_100ms_PS_100ms,
   ALS_100ms_PS_400ms,
   ALS_400ms_PS_50ms, //ALS: Measurement time is 100ms, sleep time is 300ms
   ALS_400ms_PS_100ms,//ALS: Measurement time is 100ms, sleep time is 300ms
   ALS_400ms_PS_STB,  //ALS: High sensitivity mode, measurement time is 400ms
   ALS_400ms_PS_400ms,//ALS: High sensitivity mode, measurement time is 400ms
   ALS_50ms_PS_50ms   //ALS: Additional software process is necessary. Please refer to P.18(datasheet)     
}RPR0521RS_Measurement_Time_t;

typedef enum{
   
   Gain_DATA0_X1 = 0,
   Gain_DATA0_X2,
   Gain_DATA0_X64,
   Gain_DATA0_X128
}RPR0521RS_ALS_DATA0_GAIN_t;

typedef enum{
   
   Gain_DATA1_X1 = 0,
   Gain_DATA1_X2,
   Gain_DATA1_X64,
   Gain_DATA1_X128
}RPR0521RS_ALS_DATA1_GAIN_t;

typedef enum{
   
   LED_25mA = 0,
   LED_50mA,
   LED_100mA,
   LED_200mA
}RPR0521RS_LED_CURRENT_t;

typedef enum{
   
   LAmbient_Infrared_Level_Low = 0,
   Ambient_Infrared_Level_High ,
   Ambient_Infrared_Level_too_High
}RPR0521RS_Ambient_Ir_Flag_t;

typedef enum{
   
   PS_GAIN_X1 = 0,
   PS_GAIN_X2,
   PS_GAIN_X4
}RPR0521RS_PS_GAIN_t;

typedef enum{
   
   PS_Interrupt_Persistence_Setting = 0,
   Int_Becomes_Active_At_Each_Measurement_End,
   Int_Status_Updated_At_Each_Measurement_End,
   Int_Status_Updated_If_Two_Consecutive_Threshold_Judgments_The_Same,
   Int_Status_Updated_If_Threshold_Judgments_The_Same_Over_Consecutive_Set_Times 
}RPR0521RS_PERSISTENCE_t;

typedef enum{
   
   PS_Int_Signal_Inactive = 0,
   PS_Int_Signal_Active
}RPR0521RS_PS_INT_STAUTS_t;

typedef enum{
   
   ALS_Int_Signal_Inactive = 0,
   ALS_Int_Signal_Active
}RPR0521RS_ALS_INT_STATUS_t;

typedef enum{
   
   Only_PS_TH_H_Effective = 0,
   PS_TH_H_PS_TH_L_Effective_As_Hysteresis,
   PS_TH_H_PS_TH_L_Effective_As_Outside_Detection
           
}RPR0521RS_INT_MODE_t;

typedef enum{
   
   INT_Pin_ASSERT = 0,
   INT_Pin_ASSERT_RST
}RPR0521RS_INT_ASSERT_t;

typedef enum{
   
   INT_Pin_Latched = 0, //INT pin is latched until INTERRUPT register is read or initialized
   INT_Pin_Updated
}RPR0521RS_INT_LATCH_t;

typedef enum{
   
   INT_Pin_Inactive = 0,
   Trigg_By_Only_PS_Measurement,
   Trigg_By_Only_ALS_Measurement,
   Trigg_By_PS_ALS_Measurement        
}RPR0521RS_INT_TRIG_t;

typedef struct{
   
   RPR0521RS_ALS_EN_t           RPR0521RS_ALS_EN;
   RPR0521RS_PS_EN_t            RPR0521RS_PS_EN;
   RPR0521RS_SW_Reset_t         RPR0521RS_SW_RST;
   RPR0521RS_INT_Reset_t        RPR0521RS_INT_RST;
   RPR0521RS_Measurement_Time_t Mesu_time;
   RPR0521RS_ALS_DATA0_GAIN_t   DATA0_GAIN;
   RPR0521RS_ALS_DATA1_GAIN_t   DATA1_GAIN;
   RPR0521RS_LED_CURRENT_t      LED_CURR;
   RPR0521RS_PS_PULSE_t         PS_PULSE;
   RPR0521RS_PS_Mode_t          CHOOSE_MODE;
   RPR0521RS_Ambient_Ir_Flag_t  Ambient_Ir_Flag;
   RPR0521RS_PS_GAIN_t          PS_GAIN;
   RPR0521RS_PERSISTENCE_t      PERSISTENCE; 
   RPR0521RS_ALS_INT_STATUS_t   PS_INT_STAUTS;
   RPR0521RS_ALS_INT_STATUS_t   ALS_INT_STATUS;
   RPR0521RS_INT_MODE_t         INT_MODE;
   RPR0521RS_INT_ASSERT_t       INT_ASSERT;
   RPR0521RS_INT_LATCH_t        INT_LATCH;
   RPR0521RS_INT_TRIG_t         INT_TRIG;
   
}RPR0521RS_t;

/* @Summary
    Read device ID

  @Description
    Read device ID
  @Preconditions
    None.

  @Param
    None.

  @Returns
    device ID. 
 */
uint8_t RPR0521RS_ReadID(void);

/* @Summary
    Read PS_DATA

  @Description
    Read PS_DATA
  @Preconditions
    None.

  @Param
    None.

  @Returns
    PS_DATA
 */
uint16_t RPR0521RS_Read_PS_DATA(void);

/* @Summary
    Read ALS_DATA

  @Description
    Read ALS_DATA
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.
 */
void RPR0521RS_Read_ALS_DATA(uint16_t *ALS_DATA_0, uint16_t *ALS_DATA_1);

/* @Summary
    Read PS_TH

  @Description
    Read PS_TH
  @Preconditions
    None.

  @Param
    None.

  @Returns
    PS_TH.
 */
uint16_t RPR0521RS_Read_PS_TH(void);

/* @Summary
    Read PS_TL

  @Description
    Read PS_TL
  @Preconditions
    None.

  @Param
    None.

  @Returns
    PS_TL.
 */
uint16_t RPR0521RS_Read_PS_TL(void);

/* @Summary
    Read ALS_DATA0_TH

  @Description
    Read ALS_DATA0_TH
  @Preconditions
    None.

  @Param
    None.

  @Returns
    ALS_DATA0_TH.
 */
uint16_t RPR0521RS_Read_ALS_DATA0_TH(void);

/* @Summary
    Read ALS_DATA0_TL

  @Description
    Read ALS_DATA0_TL
  @Preconditions
    None.

  @Param
    None.

  @Returns
    ALS_DATA0_TL.
 */
uint16_t RPR0521RS_Read_ALS_DATA0_TL(void);

/* @Summary
    Read PS_OFFSET

  @Description
    Read PS_OFFSET
  @Preconditions
    None.

  @Param
    None.

  @Returns
    PS_OFFSET.
 */
uint16_t RPR0521RS_Read_PS_OFFSET(void);

/* @Summary
    RPR0521RS_Init

  @Description
    RPR0521RS_Init
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.
 */
void RPR0521RS_Init(RPR0521RS_t RPR0521RS);

/* @Summary
    RPR0521RS_Mode_Config

  @Description
    RPR0521RS_Mode_Config
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.
 */
void RPR0521RS_Mode_Config(RPR0521RS_t RPR0521RS);
void RPR0521RS_SYMTEMCONTROL(RPR0521RS_t RPR0521RS);
void RPR0521RS_ALS_PS_CONTROLL (RPR0521RS_t RPR0521RS);
void RPR0521RS_PS_CONTROLL(RPR0521RS_t RPR0521RS);

///* @Summary
//    Read ALS_DATA
//
//  @Description
//    Read ALS_DATA
//  @Preconditions
//    None.
//
//  @Param
//    None.
//
//  @Returns
//    None.
// */
//void RPR0521RS_ReadALS(uint16_t *ALS_DATA_0, uint16_t *ALS_DATA_1);

//    uint8_t RPR0521RS_init(void);
//    uint8_t RPR0521RS_get_rawpsalsval(uint8_t *data);
//    uint8_t RPR0521RS_get_psalsval(uint16_t *ps, float *als);
//    int RPR0521RS_convert_lx(uint16_t *data);
//    uint16_t RPR0521RS_check_near_far(uint16_t data);
//    unsigned char _als_data0_gain;
//    unsigned char _als_data1_gain;
//    unsigned char _als_measure_time;

//#endif
    
#endif