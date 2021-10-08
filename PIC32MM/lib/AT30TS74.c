#include "AT30TS74.h"

#include <stdint.h>
//#include "mcc.h"
#if(i2c_using_simple_Enable)
    #include "i2c_using_simple.h"

#elif(I2C_Enable)

    #include "I2C.h"

#endif


#if(AT30TS74_Enable)

void AT30TS74_Init(AT30TS74_t AT30TS74)
{
   AT30TS74_Selected_reg(AT30TS74); 
   AT30TS74_Config_Reg(AT30TS74);
}
/* @Summary
    Selected_reg

  @Description
    Selected_reg
  @Preconditions
    None.

  @Param
    None.

  @Returns
    none. 
 */
void AT30TS74_Selected_reg(AT30TS74_t AT30TS74)   
{
     uint8_t data = 0;
     switch(AT30TS74.AT30TS74_Selected)
        {
            case Selected_Temperature_Register:
                data &= 0xFC;
                break;
            case Configuration_Register:
                data |= 0x01;
                break;
            case TLOW_Limit_Register:
                data |= 0x02;
                break;    
            default:
                data |= 0x03;
                break;
        }
     data |=0x00;
     I2C_Write(AT30TS74_DEVICE_ADD,NULL,&data,1);
}

/* @Summary
    Read Temperature

  @Description
    Read Temperature
  @Preconditions
    None.

  @Param
    None.

  @Returns
    temp. 
 */
void AT30TS74_Read_Temp(void)
{
    uint8_t data[2];
    float temp;
    uint16_t tmp;
    tmp= data[0]<<8| data[1];
    I2C_Write(AT30TS74_DEVICE_ADD,AT30TS74_Temp_Register,&data,1);
    DELAY_milliseconds(5);
    I2C_Read(AT30TS74_DEVICE_ADD,AT30TS74_Temp_Register,&data,1);
    if(tmp&0x8000) // Temperature<0
        {
            tmp>>=7;// 9bit mode
            tmp-=512;
            temp=tmp;
            temp*=0.5f;
        }
        else // Temperature>0
        {
            tmp>>=7;
            temp=tmp;
            temp=(temp*0.5f);
        }
    printf("\nT=%.2f%cC\n", temp, 0xB0);
}

/* @Summary
    Config_Reg

  @Description
    Config_Reg
  @Preconditions
    None.

  @Param
    None.

  @Returns
     
 */
void AT30TS74_Config_Reg(AT30TS74_t AT30TS74)
{
    uint8_t data = 0;
    if(AT30TS74.AT30TS74_One_Shot_Mode==Normal_Operation)
    {
        data &=0x7FFF;
    }
    else
    {data|=0x8000;}
    switch(AT30TS74.AT30TS74_Conversion_Resolution)
        {
            case Convert_9b:
                data &= 0xFFFF9FFF;
                break;
            case Convert_10b:
                data |= 0x2000;
                break;
            case Convert_11b:
                data |= 0x4000;
                break;    
            default:
                data |= 0x6000;
                break;
        }
    switch(AT30TS74.AT30TS74_Fault_Tolerance_Queue)
        {
            case Alarm_after_1_Fault:
                data &= 0xFFFFE7FF;
                break;
            case Alarm_after_2_Fault:
                data |= 0x800;
                break;
            case Alarm_after_4_Fault:
                data |= 0x1000;
                break;    
            default:
                data |= 0x1800;
                break;
        }
    if(AT30TS74.ALERT_Pin_Polarity==Active_Low)
    {
        data &=0xFFFFFBFF;
    }
    else
    {data|=0x400;}
    
    if(AT30TS74.Alarm_Thermostat_Mode==Comparator_Mode)
    {
        data &=0xFFFFFDFF;
    }
    else
    {data|=0x200;}
    if(AT30TS74.Shutdown_Mode==Enable_shut)
    {
        data &=0xFFFFFEFF;
    }
    else
    {data|=0x100;}
    
    data |=0x01;
    I2C_Write(AT30TS74_DEVICE_ADD,AT30TS74_Config,&data,1);
    DELAY_milliseconds(5);
    I2C_Read(AT30TS74_DEVICE_ADD,AT30TS74_Config,&data,1);
    
}
#endif

