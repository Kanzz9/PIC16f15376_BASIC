/*
 
 
 */
#include "RPR0521RS.h"

#if(RPR0521RS_Enable)

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
uint8_t RPR0521RS_ReadID(void)
{   
    uint8_t ID;  
    
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_MANUFACT_ID, &ID, 1);   
    #if(UART_Enable)
        printf("RPR0521RS_ID: %x\n", ID);
    #endif
    return ID;
}

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
uint16_t RPR0521RS_Read_PS_DATA(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_PS_DATA_LSBs, &buff, 2);
    data = ((buff[1]&0x0F)<<8) | buff[0];
    return data;
}

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
void RPR0521RS_Read_ALS_DATA(uint16_t *ALS_DATA_0, uint16_t *ALS_DATA_1){
    
    uint8_t buff[4]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_ALS_DATA0_LSBs, &buff, 4);
    *ALS_DATA_0 = buff[1]<<8 | buff[0];
    *ALS_DATA_1 = buff[3]<<8 | buff[2];
}

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
uint16_t RPR0521RS_Read_PS_TH(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_PS_TH_LSBs, &buff, 2);
    data = ((buff[1]&0x0F)<<8) | buff[0];
    return data;
}

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
uint16_t RPR0521RS_Read_PS_TL(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_PS_TL_LSBs, &buff, 2);
    data = ((buff[1]&0x0F)<<8) | buff[0];
    return data;
}

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
uint16_t RPR0521RS_Read_ALS_DATA0_TH(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_ALS_DATA0_TH_LSBs, &buff, 2);
    data = buff[1]<<8 | buff[0];
    return data;
}

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
uint16_t RPR0521RS_Read_ALS_DATA0_TL(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_ALS_DATA0_TL_LSBs, &buff, 2);
    data = buff[1]<<8 | buff[0];
    return data;
}

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
uint16_t RPR0521RS_Read_PS_OFFSET(void){
    
    uint8_t buff[2]={0};
    uint16_t data=0;
    I2C_Read(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_PS_OFFSET_LSBs, &buff, 2);
    data = ((buff[1]&0x03)<<8) | buff[0];
    return data;
}

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
void RPR0521RS_Init(RPR0521RS_t RPR0521RS){
    
}

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
void RPR0521RS_Mode_Config(RPR0521RS_t RPR0521RS){
    
    uint8_t data=0;
    
    /////////// Config ALS_EN ////////////////////
    if(RPR0521RS.RPR0521RS_ALS_EN == ALS_Standby){
        
        data &= 0x7F; // set bit 7(ALS_EN) = 0
    }
    else
        data |= 0x80; // set bit 7(ALS_EN) = 1
    /////////// End config ALS_EN ///////////////
    
    /////////// Config PS_EN ////////////////////
    if(RPR0521RS.RPR0521RS_PS_EN == PS_Standby){
        
        data &= 0xBF; // set bit 6(PS_EN) = 0
    }
    else
        data |= 0x40; // set bit 6(PS_EN) = 1
    /////////// End config PS_EN ///////////////
    
    data |= 0x01;
    
    I2C_Write(RPR0521RS_DEVICE_ADDRESS, RPR0521RS_MODE_CONTROL, &data, 1);
    
}


/*
uint8_t RPR0521RS_init(void)
{
    uint8_t rc;
    uint8_t data=0;
    uint8_t data_m = 0xe0;
    uint8_t index;
    // MODE CONTROL
    uint8_t als_gain_table[] = {1, 2, 64, 128};
    uint16_t als_meas_time_table[] = {0,0,0,0,0,100,100,100,100,100,400,400,50,0,0,0};

    rc = I2C_Read(0x38, 0x41,&data,1);
    if (rc != 0) {
      printf("Can't access RPR0521RS\n");
      return (rc);
    }
    //data &= 0x3F;
    printf("RPR0521RS Part ID Register Value = %x\n",data);


    if (data = RPR0521RS_PART_ID_VAL) {
      printf("Can't find RPR0521RS\n");
      return (rc);
    }

    rc = I2C_Read(0x38,RPR0521RS_MANUFACT_ID, &data_m, 1);
    if (rc != 0) {
      printf("Can't access RPR0521RS\n");
      return (rc);
    }
    printf("RPR0521RS MANUFACT_ID Register Value = %x\n",data_m);

    if (data_m != RPR0521RS_MANUFACT_ID_VAL) {
      printf("Can't find RPR0521RS\n");
      return (rc);
    }

    data = RPR0521RS_ALS_PS_CONTROL_VAL;
    rc = I2C_Write(0x38,RPR0521RS_ALS_PS_CONTROL, &data, 1);
    if (rc != 0) {
      printf("Can't write RPR0521RS ALS_PS_CONTROL register\n");
      return (rc);
    }

    rc = I2C_Read(0x38,RPR0521RS_PS_CONTROL, &data, 1);
    if (rc != 0) {
      printf("Can't read RPR0521RS PS_CONTROL register\n");
      return (rc);
    }

    data |= RPR0521RS_PS_CONTROL_VAL;
    rc = I2C_Write(0x38,RPR0521RS_PS_CONTROL, &data, 1);
    if (rc != 0) {
      printf("Can't write RPR0521RS PS_CONTROL register\n");
    }

    data = RPR0521RS_MODE_CONTROL_VAL;
    rc = I2C_Write(0x38,RPR0521RS_MODE_CONTROL, &data, 1);
    if (rc != 0) {
      printf("Can't write RPR0521RS MODE CONTROL register\n");
      return (rc);
    }

    data = RPR0521RS_ALS_PS_CONTROL_VAL;
    index = (data >> 4) & 0x03;
    _als_data0_gain = als_gain_table[index];

    index = (data >> 2) & 0x03;
    _als_data1_gain = als_gain_table[index];

    index = RPR0521RS_MODE_CONTROL_VAL & 0x0F;
    _als_measure_time = als_meas_time_table[index];

    return (rc);
}
uint8_t RPR0521RS_get_rawpsalsval(uint8_t *data)
{
  uint8_t rc;

  rc = I2C_Read(0x38,RPR0521RS_PS_DATA_LSBs, data, 6);
  if (rc != 0) {
    printf("Can't get RPR0521RS PS/ALS_DATA value\n");
  }

  return (rc);
}
uint8_t RPR0521RS_get_psalsval(uint16_t *ps, float *als)
{
  uint8_t rc;
  uint8_t val[6];
  uint16_t rawps;
  uint16_t rawals[2];

  rc = RPR0521RS_get_rawpsalsval(val);
  if (rc != 0) {
    return (rc);
  }

  rawps     = (val[1] << 8) | val[0];
  rawals[0] = (val[3] << 8) | val[2];
  rawals[1] = (val[5] << 8) | val[4];

  *ps  = rawps;
  *als = RPR0521RS_convert_lx(rawals);

  return (rc);
}
int RPR0521RS_convert_lx(uint16_t *data)
{
  float lx;
  float d0, d1, d1_d0;

  if (_als_data0_gain == 0) 
  {
    return (RPR0521RS_ERROR);
  }

  if (_als_data1_gain == 0) 
  {
    return (RPR0521RS_ERROR);
  }

  if (_als_measure_time == 0) 
  {
    return (RPR0521RS_ERROR);
  }  
  if (_als_measure_time == 50) 
  {
    if ((data[0] & 0x8000) == 0x8000) 
    {
      data[0] = 0x7FFF;
    }
    if ((data[1] & 0x8000) == 0x8000) 
    {
      data[1] = 0x7FFF;
    }
  }

  d0 = (float)data[0] * (100 / _als_measure_time) / _als_data0_gain;
  d1 = (float)data[1] * (100 / _als_measure_time) / _als_data1_gain;

  if (d0 == 0) 
  {
    lx = 0;
    return (lx);
  }

  d1_d0 = d1 / d0;

  if (d1_d0 < 0.595) 
  {
    lx = (1.682 * d0 - 1.877 * d1);
  }  
  if (d1_d0 < 1.015) 
  {
    lx = (0.644 * d0 - 0.132 * d1);
  } 
  if (d1_d0 < 1.352) 
  {
    lx = (0.756 * d0 - 0.243 * d1);
  }
  if (d1_d0 < 3.053) 
  {
    lx = (0.766 * d0 - 0.25 * d1);
  } 
  else 
  {
    lx = 0;
  }

  return (lx);
}

uint16_t RPR0521RS_check_near_far(uint16_t data)
{
  if (data >= RPR0521RS_NEAR_THRESH) 
  {
    return (RPR0521RS_NEAR_VAL);
  } 
  else 
  {
    return (RPR0521RS_FAR_VAL);
  }
}
*/
#endif
