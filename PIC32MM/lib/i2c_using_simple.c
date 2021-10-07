/*
 
 */
#include "i2c_using_simple.h"

/*
 
 */

#if(i2c_using_simple_Enable)

void I2C_Scan_Multi(void){
    
    i2c_error_t I2C_Status = I2C_FAIL;
    uint8_t num, add = 0;

    for(add=0; add<=127; add++){
        I2C_Status = i2c_open(add);
        DELAY_milliseconds(5);
        if(I2C_Status == I2C_NOERR){
            
            I2C_Status = I2C_FAIL;
            #if(UART_Enable)
                printf("Device: %d Address: %x\n", ++num, add);
                
            #endif
        }
        //if()
        
    }   
}

void I2C_Write(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount)
{
    //I2C1_MESSAGE_STATUS status;
    uint8_t *b;
    
    b = (uint8_t*)calloc(nCount+1, sizeof(uint8_t));
    
    int i=0;
    for(i=1; i<=nCount; i++){
        *(b+i)= *(pData+i-1);
    }
    *(b+0) = dataAddress;
    
    //I2C1_MasterWrite(b, nCount+1, slaveDeviceAddress, &status);
    i2c_writeNBytes(slaveDeviceAddress, b, nCount+1); 
    free(b);
    //return status;
}
uint8_t I2C_Read(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount)
{


}
#endif