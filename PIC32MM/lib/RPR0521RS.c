/*
 
 
 */
#include "RPR0521RS.h"
#include "I2C.h"
#include <stdint.h>
#include "mcc.h"

#if(RPR0521RS_Enable)

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

#endif
