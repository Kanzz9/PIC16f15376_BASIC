/* 
 * File:   KX126_1063.h
 * Author: HoangKhanhToan
 *
 * Created on Oct 14, 2021, 11:00 PM
 */
#ifndef KX126_1063_H
#define KX126_1063_H
#include "mcc.h"
//////
#define KX126_1063_DEVICE_ADDRESS       0x1E

#define KX126_1063_MANUFACT_ID          0x00
#define KX126_1063_PART_ID              0x01    
#define KX126_1063_XHP_L                0X02
#define KX126_1063_XHP_H                0X03
#define KX126_1063_YHP_L                0X04
#define KX126_1063_YHP_H                0X05
#define KX126_1063_ZHP_L                0X06
#define KX126_1063_ZHP_H                0X07
#define KX126_1063__XOUTL               0x08
#define KX126_1063__XOUTH               0x09
#define KX126_1063__YOUTL               0x0A
#define KX126_1063__YOUTH               0x0B
#define KX126_1063__ZOUTL               0x0C
#define KX126_1063__ZOUTH               0x0D
#define KX126_1063__PED_STPL            0x0E
#define KX126_1063__PED_STPH            0x0F
#define KX126_1063__COTR                0x10
#define KX126_1063__WHO_AM_I            0x11
#define KX126_1063__TSCP                0x12
#define KX126_1063__TSPP                0x13
#define KX126_1063__INS1                0x14
#define KX126_1063__INS2                0x15
#define KX126_1063__INS3                0x16
#define KX126_1063__STAT                0x17
#define KX126_1063__INT_REL             0x19
#define KX126_1063__CNTL1               0x1A
#define KX126_1063__CNTL2               0x1B
#define KX126_1063__CNTL3               0x1C
#define KX126_1063__CNTL4               0x1D
#define KX126_1063__CNTL5               0x1E
#define KX126_1063__ODCNTL              0x1F
#define KX126_1063__INC1                0x20
#define KX126_1063__INC2                0x21
#define KX126_1063__INC3                0x22
#define KX126_1063__INC4                0x23
#define KX126_1063__INC5                0x24
#define KX126_1063__INC6                0x25
#define KX126_1063__INC7                0x26
#define KX126_1063__TILT_TIMER          0x27
#define KX126_1063__TDTRC               0x28
#define KX126_1063__TDTC                0x29
#define KX126_1063__TTH                 0x2A
#define KX126_1063__TTL                 0x2B
#define KX126_1063__FTD                 0x2C
#define KX126_1063__STD                 0x2D
#define KX126_1063__TLT                 0x2E
#define KX126_1063__TWS                 0x2F
#define KX126_1063__FFTH                0x30
#define KX126_1063__FFC                 0x31
#define KX126_1063__FFCNTL              0x32
#define KX126_1063__TILT_ANGLE_LL       0x34
#define KX126_1063__TILT_ANGLE_HL       0x35
#define KX126_1063__HYST_SET            0x36
#define KX126_1063__LP_CNTL             0x37
#define KX126_1063__WUFTH               0x3C
#define KX126_1063__BTSWUFTH            0x3D             
#define KX126_1063__BTSTH               0x3E
#define KX126_1063__BTSC                0x3F             
#define KX126_1063__WUFC                0x40
#define KX126_1063__PED_WM_L            0x41
#define KX126_1063__PED_WM_H            0x42
#define KX126_1063__PED_CNTL1           0x43
#define KX126_1063__PED_CNTL2           0x44
#define KX126_1063__PED_CNTL3           0x45
#define KX126_1063__PED_CNTL4           0x46
#define KX126_1063__PED_CNTL5           0x47
#define KX126_1063__PED_CNTL6           0x48
#define KX126_1063__PED_CNTL7           0x49
#define KX126_1063__PED_CNTL8           0x4A
#define KX126_1063__PED_CNTL9           0x4B
#define KX126_1063__PED_CNTL10          0x4C
#define KX126_1063__SELF_TEST           0x4D

#define KX126_1063_BUF_CNTL1            0x5A
#define KX126_1063_BUF_CNTL2            0x5B
#define KX126_1063_BUF_STATUS_1         0x5C
#define KX126_1063_BUF_STATUS_2         0x5D
#define KX126_1063_BUF_CLEAR            0x5E
#define KX126_1063_BUF_READ             0x5F


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
//sets the output data rate for the Tilt Position function
typedef enum{
   
    set_1dot563_hz = 0,
    set_6dot25_hz,
    set_12dot5_hz,
    set_50Hz
           
} KX126_1063_OTP_t;
//sets the output data rate for the Directional TapTM function
typedef enum{
   
    set_50hz = 0,
    set_100hz,
    set_200hz,
    set_400hz,
    set_12dot5hz,
    set_25hz,        
    set_800hz,
    set_1600hz       
} KX126_1063_OTDT_t;
//sets the output data rate 
typedef enum{
   
    set_0dot781_hz = 0,
    set_1d563_hz,
    set_3dot125_hz,
    set_6d25_hz,
    set_12d5_hz,
    set_25_hz,        
    set_50_hz,
    set_100_hz        
} KX126_1063_OWUF_t;
//
typedef enum{
   
   filtering_applied = 0,
   filter_bypassed
} KX126_1063_IIR_BYPASS_t;
//low-pass filter roll off control
typedef enum{
   
   set_ODRslash9 = 0,
   set_ODRslash2
} KX126_1063_LPRO_t;
//acceleration output data rate
typedef enum{
   
    s_12d5_hz = 0,
    s_25_hz,
    s_50_hz,
    s_100_hz,
    s_200_hz,
    s_400_hz,        
    s_800_hz,
    s_1600_hz,
    s_0dot781_hz,
    s_1dot563_hz,
    s_3dot125_hz,
    s_6dot25_hz,
    s_3200_hz,
    s_6400_hz,
    s_12800_hz,
    s_25600_hz
} KX126_1063_OSA_t;
//defines debounce counter operation
typedef enum{
   
   clear_mode = 0,
   decrement_mode
} KX126_1063_C_MODE_t;
//defines wake / back-to-sleep threshold mode
typedef enum{
   
   absolute_threshold = 0,
   relative_threshold
} KX126_1063_TH_MODE_t;
//enables the Wake up engine 
typedef enum{
   
   WUFE_Disabled = 0,
   WUFE_Enable
} KX126_1063_WUFE_t;
//enables the Back to sleep engine
typedef enum{
   
   BTSE_Disabled = 0,
   BTSE_Enable
} KX126_1063_BTSE_t;
//enables the High-pass outputs XHP, YHP, ZHP
typedef enum{
   
   HPE_Disabled = 0,
   HPE_Enable
} KX126_1063_HPE_t;
//sets the output data rate at which the back-to-sleep (motion detection) performs its function during wake state
typedef enum{
   
    s_0d781hz = 0,
    s_1d563hz,
    s_3dot125hz,
    s_6d25hz,
    s_12d5hz,
    s_25hz,        
    s_50hz,
    s_100hz        
} KX126_1063_OBT_t;
//controls activation of the sample buffer
typedef enum{
   
   sample_buffer_inactive = 0,
   sample_buffer_active
} KX126_1063_BUFE_t;
//determines the resolution of the acceleration data samples collected by the sample buffer
typedef enum{
   
   set_8_bit_samples = 0,
   set_16_bit_samples
} KX126_1063_BRES_t;
//buffer full interrupt enable bit
typedef enum{
   
   BFIE_disabled = 0,
   BFIE_Enable_and_updated_in_INS2
} KX126_1063_BFIE_t;
//selects the operating mode of the sample buffer
typedef enum{
   
    set_FIFO = 0,
    set_Stream,
    set_Trigger,
    set_FILO
           
} KX126_1063_BM_t;
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
    KX126_1063_OTP_t                        KX126_1063_OTP;
    KX126_1063_OTDT_t                       KX126_1063_OTDT;
    KX126_1063_OWUF_t                       KX126_1063_OWUF;
    KX126_1063_IIR_BYPASS_t                 KX126_1063_IIR_BYPASS;
    KX126_1063_LPRO_t                       KX126_1063_LPRO;  
    KX126_1063_OSA_t                        KX126_1063_OSA;
    KX126_1063_C_MODE_t                     KX126_1063_C_MODE;
    KX126_1063_TH_MODE_t                    KX126_1063_TH_MODE;
    KX126_1063_WUFE_t                       KX126_1063_WUFE;
    KX126_1063_BTSE_t                       KX126_1063_BTSE;
    KX126_1063_HPE_t                        KX126_1063_HPE;
    KX126_1063_OBT_t                        KX126_1063_OBT;
    KX126_1063_BUFE_t                       KX126_1063_BUFE;
    KX126_1063_BRES_t                       KX126_1063_BRES;
    KX126_1063_BFIE_t                       KX126_1063_BFIE;
    KX126_1063_BM_t                         KX126_1063_BM;
}KX126_1063_t;

//////////////////
void KX126_1063_Init(KX126_1063_t KX126_1063);
uint8_t KX126_1063_ReadID(void);
uint8_t KX126_1063_PARTID(void);
void KX126_1063_getAccelAxis(int8_t *x_axis, int8_t *y_axis, int8_t *z_axis);
void KX126_1063_getHighPassAccelAxis(int8_t *x_axis, int8_t *y_axis, int8_t *z_axis);

void KX126_1063_Control1(KX126_1063_t KX126_1063);
void KX126_1063_Control2(KX126_1063_t KX126_1063);
void KX126_1063_Control3(KX126_1063_t KX126_1063);
void KX126_1063_Control4(KX126_1063_t KX126_1063);
void KX126_1063_Output_data_control(KX126_1063_t KX126_1063);
void KX126_1063_BUF_CNTL2_R(KX126_1063_t KX126_1063);
#endif

