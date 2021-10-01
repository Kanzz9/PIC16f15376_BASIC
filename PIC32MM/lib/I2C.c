#include <stdint.h>

#include "I2C.h"

//I2C1_MESSAGE_STATUS I2C_Write(uint8_t Dev_add, uint8_t Reg_add, uint8_t data){
//        
//    I2C1_MESSAGE_STATUS status;
//    uint8_t    retryTimeOut;
//    uint16_t data_write=0;
//    
//    data_write = (Reg_add<<8) | data;
//    
////    while(status != I2C1_MESSAGE_FAIL)
////        {
//            // write one byte to EEPROM (2 is the count of bytes to write)
//            I2C1_MasterWrite((uint8_t*)&data_write, 2, Dev_add, &status);
//                        
//            while(status != I2C1_MESSAGE_COMPLETE)
//            {
//                // add some delay here
//                DELAY_milliseconds(10);   
//                I2C1_MasterWrite((uint8_t*)&data_write, 2, Dev_add, &status);
//                // timeout checking
//                // check for max retry and skip this byte
//                if (retryTimeOut == I2C_TIMEOUT)
//                    return (I2C1_MESSAGE_ADDRESS_NO_ACK);
//                else
//                    retryTimeOut++;
//            }
//                        
//    return  I2C1_MESSAGE_COMPLETE;       
////        }
//
//}
//
//I2C1_MESSAGE_STATUS I2C_Read(uint8_t Dev_add, uint8_t Reg_add, uint8_t *data, uint8_t len){
//    
//    I2C1_MESSAGE_STATUS status;
//    uint8_t    retryTimeOut;
//
////    while(status != I2C1_MESSAGE_FAIL)
////        {
//            // write one byte to EEPROM (2 is the count of bytes to write)
//            I2C1_MasterWrite(&Reg_add, 1, Dev_add, &status);
//
//            // wait for the message to be sent or status has changed.
//            while(status != I2C1_MESSAGE_COMPLETE)
//            {
//                // add some delay here
//                DELAY_milliseconds(10);   
//                I2C1_MasterWrite(&Reg_add, 1, Dev_add, &status);
//                // timeout checking
//                // check for max retry and skip this byte
//                if (retryTimeOut == I2C_TIMEOUT)
//                    return (I2C1_MESSAGE_ADDRESS_NO_ACK);
//                else
//                    retryTimeOut++;
//            }
//            
//            I2C_Read(Dev_add, Reg_add, data, len);
//            
//    return  I2C1_MESSAGE_COMPLETE;       
////        }
//}