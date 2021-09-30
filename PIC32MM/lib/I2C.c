#include "I2C.h"

I2C1_MESSAGE_STATUS I2C_Write(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount){
        
    I2C1_MESSAGE_STATUS status;
    uint8_t *b;
    
    b = (uint8_t*)calloc(nCount+1, sizeof(uint8_t));
    
    int i=0;
    for(i=1; i<=nCount; i++){
        *(b+i)= *(pData+i-1);
    }
    *(b+0) = dataAddress;
    
    I2C1_MasterWrite(b, nCount+1, slaveDeviceAddress, &status);
     
    free(b);
    return status;
}

uint8_t I2C_Read(uint16_t slaveDeviceAddress, uint8_t dataAddress, uint8_t *pData, uint16_t nCount)
{
    I2C1_MESSAGE_STATUS status;
    I2C1_TRANSACTION_REQUEST_BLOCK readTRB[2];
    uint16_t    timeOut, slaveTimeOut;

    // this initial value is important
    status = I2C1_MESSAGE_PENDING;

    // build the write buffer first
    // starting address of the EEPROM memory
//    writeBuffer[0] = (dataAddress >> 8);                        // high address
//    writeBuffer[1] = (uint8_t)(dataAddress);                    // low low address

    // we need to create the TRBs for a random read sequence to the EEPROM
    // Build TRB for sending address
    I2C1_MasterWriteTRBBuild(    &readTRB[0],
                                    &dataAddress,
                                    1,
                                    slaveDeviceAddress);
    // Build TRB for receiving data
    I2C1_MasterReadTRBBuild(     &readTRB[1],
                                    pData,
                                    nCount,
                                    slaveDeviceAddress);

    timeOut = 0;
    slaveTimeOut = 0;

    while(status != I2C1_MESSAGE_FAIL)
    {
        // now send the transactions
        I2C1_MasterTRBInsert(2, readTRB, &status);

        // wait for the message to be sent or status has changed.
        while(status == I2C1_MESSAGE_PENDING)
        {
            // add some delay here
            DELAY_milliseconds(10);
            // timeout checking
            // check for max retry and skip this byte
            if (slaveTimeOut == SLAVE_I2C_GENERIC_SLAVE_TIMEOUT)
                return (0);
            else
                slaveTimeOut++;
        }

        if (status == I2C1_MESSAGE_COMPLETE)
            break;

        // if status is  I2C1_MESSAGE_ADDRESS_NO_ACK,
        //               or I2C1_DATA_NO_ACK,
        // The device may be busy and needs more time for the last
        // write so we can retry writing the data, this is why we
        // use a while loop here

        // check for max retry and skip this byte
        if (timeOut == SLAVE_I2C_GENERIC_SLAVE_TIMEOUT)
            return (0);
        else
            timeOut++;

    }
    return (1);
} 