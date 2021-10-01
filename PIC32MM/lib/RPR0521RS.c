/*
 
 
 */
#include "RPR0521RS.h"
#include <stdint.h>


void RPR0521RS_Control(){
    
    uint8_t data;
    I2C_Write(0X40, 0X0A, data);
}
I2C1_MESSAGE_STATUS I2C_Write(uint8_t Dev_add, uint8_t Reg_add, uint8_t data){
        
    I2C1_MESSAGE_STATUS status;
    uint8_t    retryTimeOut;
    uint16_t data_write=0;
    
    data_write = (Reg_add<<8) | data;
    
//    while(status != I2C1_MESSAGE_FAIL)
//        {
            // write one byte to EEPROM (2 is the count of bytes to write)
            I2C1_MasterWrite((uint8_t*)&data_write, 2, Dev_add, &status);
                        
            while(status != I2C1_MESSAGE_COMPLETE)
            {
                // add some delay here
                DELAY_milliseconds(10);   
                I2C1_MasterWrite((uint8_t*)&data_write, 2, Dev_add, &status);
                // timeout checking
                // check for max retry and skip this byte
                if (retryTimeOut == I2C_TIMEOUT)
                    return (I2C1_MESSAGE_ADDRESS_NO_ACK);
                else
                    retryTimeOut++;
            }
                        
    return  I2C1_MESSAGE_COMPLETE;       
//        }

}

I2C1_MESSAGE_STATUS I2C_Read(uint8_t Dev_add, uint8_t Reg_add, uint8_t *data, uint8_t len){
    
    I2C1_MESSAGE_STATUS status;
    uint8_t    retryTimeOut;

//    while(status != I2C1_MESSAGE_FAIL)
//        {
            // write one byte to EEPROM (2 is the count of bytes to write)
            I2C1_MasterWrite(&Reg_add, 1, Dev_add, &status);

            // wait for the message to be sent or status has changed.
            while(status != I2C1_MESSAGE_COMPLETE)
            {
                // add some delay here
                DELAY_milliseconds(10);   
                I2C1_MasterWrite(&Reg_add, 1, Dev_add, &status);
                // timeout checking
                // check for max retry and skip this byte
                if (retryTimeOut == I2C_TIMEOUT)
                    return (I2C1_MESSAGE_ADDRESS_NO_ACK);
                else
                    retryTimeOut++;
            }
            
            I2C_Read(Dev_add, Reg_add, data, len);
            
    return  I2C1_MESSAGE_COMPLETE;       
        }
    
//  uint8_t RPR0521RS_get_rawpsalsval(uint8_t *data)
//{
//  uint8_t rc;
//
//  rc = I2C_Read(0x38,RPR0521RS_PS_DATA_LSBs, data, 6);
//  if (rc != 0) {
//    printf("Can't get RPR0521RS PS/ALS_DATA value");
//  }
//
//  return (rc);
//}
//  uint8_t RPR0521RS_get_psalsval(  uint8_t *ps,uint16_t *als)
//{
//    uint8_t rc;
//  unsigned char val[6];
//  uint8_t rawps;
//  uint8_t rawals[2];
//
//  rc = RPR0521RS_get_rawpsalsval(val);
//  if (rc != 0) {
//    return (rc);
//  }
//
//  rawps     = (val[1] << 8) | val[0];
//  rawals[0] = (val[3] << 8) | val[2];
//  rawals[1] = (val[5] << 8) | val[4];
//
//  *ps  = rawps;
//  *als = (float)RPR0521RS_convert_lx(rawals);
//
//  return (rc);
//}
// uint16_t RPR0521RS_convert_lx(uint16_t *data)
//{
//  uint16_t lx;
//  uint16_t d0, d1, d1_d0;
//
//  
//    if ((data[0] & 0x8000) == 0x8000) {
//      data[0] = 0x7FFF;
//    }
//    if ((data[1] & 0x8000) == 0x8000) {
//      data[1] = 0x7FFF;
//    }
//  
//
//  d0 = (float)data[0] * (100 );// _als_measure_time) / _als_data0_gain;
//  d1 = (float)data[1] * (100); // _als_measure_time) / _als_data1_gain;    
//
//  if (d0 == 0) {
//    lx = 0;
//    return (lx);
//  }
//
//  d1_d0 = (float)d1 / d0;
//
//  if (d1_d0 < 0.595) {
//    lx = (1.682 * d0 - 1.877 * d1);
//  } else if (d1_d0 < 1.015) {
//    lx = (0.644 * d0 - 0.132 * d1);
//  } else if (d1_d0 < 1.352) {
//    lx = (0.756 * d0 - 0.243 * d1);
//  } else if (d1_d0 < 3.053) {
//    lx = (0.766 * d0 - 0.25 * d1);
//  } else {
//    lx = 0;
//  }
//
//  return (lx);
//}