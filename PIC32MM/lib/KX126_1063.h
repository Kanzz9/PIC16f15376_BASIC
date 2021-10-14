/* 
 * File:   KX126_1063.h
 * Author: HoangKhanhToan
 *
 * Created on Oct 14, 2021, 11:00 PM
 */
#ifndef KX126_1063_H
#define KX126_1063_H
#include "mcc.h"
#define KX126_1063_DEVICE_ADDRESS       0x1E
#define KX126_1063_MANUFACT_ID          0x00
#define KX126_1063_PART_ID              0x01    
#define KX126_1063_XHP_L                0X02
#define KX126_1063_XHP_H                0X03
#define KX126_1063_YHP_L                0X04
#define KX126_1063_YHP_H                0X05
#define KX126_1063_ZHP_L                0X06
#define KX126_1063_ZHP_H                0X07
#define KX126_1063__X_AXIS_OUTPUT_LOW   0x08
#define KX126_1063__X_AXIS_OUTPUT_HIGH  0x09
#define KX126_1063__Y_AXIS_OUTPUT_LOW   0x0A
#define KX126_1063__Y_AXIS_OUTPUT_HIGH  0x0B
#define KX126_1063__Z_AXIS_OUTPUT_LOW   0x0C
#define KX126_1063__Z_AXIS_OUTPUT_HIGH  0x0D


#define KX126_1063_CONTROL1             0x1A
#define KX126_1063_CONTROL2             0x1B
#define KX126_1063_CONTROL3             0x1C
#define KX126_1063_CONTROL4             0x1D
#define KX126_1063_CONTROL5             0x1E
typedef enum{
   
   stand_by_mode = 0,
   full_power_or_low_power_mode
}KX126_1063_PC1_t;

///controls the resolution of the accelerometer output
typedef enum{
   
   low_power_higher_noise_mode = 0,
   higher_power_lower_noise_mode
}KX126_1063_RES_t;

///enables the data ready engine
typedef enum{
   
   disable = 0,
   enable
}KX126_1063_DRDYE_t;
///selects the acceleration range of the accelerometer outputs
typedef enum{
   
   range_2g = 0,
   range_4g,
   range_8g
}KX126_1063_Selects_ACC_RANGEOUT_t;

///enables the Tap/Double tap engine
typedef enum{
   
   TDTE_disable = 0,
   TDTE_enable
}KX126_1063_TDTE_t;
///
typedef enum{
   
   PDE_disabled = 0,
   PDE_enable
}KX126_1063_PDE_t;
///enables the Tilt engine
typedef enum{
   
   TPE_disable = 0,
   TPE_enable
}KX126_1063_TPE_t;

///initiates software reset
typedef enum{
   
   SRST_no_action = 0,
   SRST_start
} KX126_1063_SRST_t;
///Command test control
typedef enum{
   
   COTC_no_action = 0,
   SRST_set
} KX126_1063_COTC_t;
//


typedef struct{
    KX126_1063_PC1_t                        KX126_1063_PC1;
    KX126_1063_RES_t                        KX126_1063_RES;
    KX126_1063_DRDYE_t                      KX126_1063_DRDYE;
    KX126_1063_Selects_ACC_RANGEOUT_t       KX126_1063_Selects_ACC_RANGEOUT;
    KX126_1063_TDTE_t                       KX126_1063_TDTE;
    KX126_1063_PDE_t                        KX126_1063_PDE;
    KX126_1063_TPE_t                        KX126_1063_TPE;
    KX126_1063_SRST_t                       KX126_1063_SRST;
    KX126_1063_COTC_t                       KX126_1063_COTC;
}KX126_1063_t;

//////////////////
uint8_t KX126_1063_ReadID(void);
uint8_t KX126_1063_PARTID(void);
void KX126_1063_getAccelAxis(uint8_t *x_axis, uint8_t *y_axis, uint8_t *z_axis);
void KX126_1063_getHighPassAccelAxis(uint8_t *x_axis, uint8_t *y_axis, uint8_t *z_axis);
void KX126_1063_Control1(KX126_1063_t KX126_1063);
#endif

