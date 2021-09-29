/*
 
 
 */
#include "RPR0521RS.h"



uint8_t RPR0521RS_WriteByte(const RPR0521RS_t *RPR0251RS, uint8_t Reg_Add, uint8_t data)
{
    I2C1_MESSAGE_STATUS status;
    while(status != I2C1_MESSAGE_FAIL)
    {
        if(status == I2C1_MESSAGE_COMPLETE)
        I2C1_MasterWrite(&data, 1, RPR0251RS->RPR0521RS_Add, &status);
    }

}


