/* 
 * File:   RPR0521RS.h
 * Author: HoangKhanhToan
 *
 * Created on Oct 5, 2021, 9:00 AM
 */


#ifndef AT30TS74_H
#define AT30TS74_H
//#include "mcc.h"



#define AT30TS74_Temp_Register  0x00
#define AT30TS74_Config         0x01
#define AT30TS74_T_L_LIMIT      0x02
#define AT30TS74_T_H_LIMIT      0x03

#define AT30TS74_DEVICE_ADD     0x48


typedef enum{
   
   Selected_Temperature_Register = 0,
   Configuration_Register,
   TLOW_Limit_Register,
   THIGH_Limit_Register  
           
}AT30TS74_Selected_t;

typedef enum{
   
   Normal_Operation = 0,
   Perform_One_Shot_Measurement     
           
}AT30TS74_One_Shot_Mode_t;

typedef enum{
   
   Convert_9b = 0,
   Convert_10b,
   Convert_11b,
   Convert_12b
           
}AT30TS74_Conversion_Resolution_t;

typedef enum{
   
   Alarm_after_1_Fault  = 0,
   Alarm_after_2_Fault,
   Alarm_after_4_Fault,
   Alarm_after_6_Fault
           
}AT30TS74_Fault_Tolerance_Queue_t;

typedef enum{
   
   Active_Low  = 0,
   Active_High
           
}AT30TS74_ALERT_Pin_Polarity_t;


typedef enum{
   
    Comparator_Mode  = 0,
    Interruptt_Mode
           
}AT30TS74_Alarm_Thermostat_Mode_t;

typedef enum{
   
    Enable_shut  = 0,
    Disable_shut
           
}AT30TS74_Shutdown_Mode_t;

typedef struct{
   
   AT30TS74_Selected_t                  AT30TS74_Selected;
   AT30TS74_One_Shot_Mode_t             AT30TS74_One_Shot_Mode;
   AT30TS74_Conversion_Resolution_t     AT30TS74_Conversion_Resolution;
   AT30TS74_Fault_Tolerance_Queue_t     AT30TS74_Fault_Tolerance_Queue;
   AT30TS74_ALERT_Pin_Polarity_t        ALERT_Pin_Polarity;
   AT30TS74_Alarm_Thermostat_Mode_t     Alarm_Thermostat_Mode;
   AT30TS74_Shutdown_Mode_t             Shutdown_Mode;
}AT30TS74_t;
void AT30TS74_Config_Reg(AT30TS74_t AT30TS74);
void AT30TS74_Selected_reg(AT30TS74_t AT30TS74);
void AR30TS74_Init(AT30TS74_t AT30TS74);
void AT30TS74_Read_Temp(void);
#endif