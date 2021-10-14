#include "KX126_1063.h"

#include <stdint.h>
//
#if(i2c_using_simple_Enable)
    #include "i2c_using_simple.h"

#elif(I2C_Enable)

    #include "I2C.h"

#endif

#if(KX126_1063_Enable)


uint8_t KX126_1063_ReadID(void)
{   
    uint8_t ID;  
    
    I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_MANUFACT_ID, &ID, 1);   
    #if(UART_Enable)
        printf("KX126_1063_MAN_ID: %x \n", ID);
    #endif
    return ID;
}
uint8_t KX126_1063_PARTID(void)
{   
    uint8_t ID;  
    
    I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_PART_ID, &ID, 1);   
    #if(UART_Enable)
        printf("KX126_1063_PART_ID: %x \n", ID);
    #endif
    return ID;
}
void KX126_1063_getAccelAxis(uint8_t *x_axis, uint8_t *y_axis, uint8_t *z_axis)
{
    uint8_t buf1[1],buf2[1],buf3[1];
    *x_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__X_AXIS_OUTPUT_LOW, buf1, 1); 
    *y_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__Y_AXIS_OUTPUT_LOW, buf2, 1);
    *z_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__Z_AXIS_OUTPUT_LOW, buf3, 1);
}

void KX126_1063_getHighPassAccelAxis(uint8_t *x_axis, uint8_t *y_axis, uint8_t *z_axis)
{
    uint8_t buf1[1],buf2[1],buf3[1];
    
    *x_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_XHP_L, buf1, 1);
    *y_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_YHP_L, buf2, 1);
    *z_axis = I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_ZHP_L, buf3, 1);
}
void KX126_1063_Control1(KX126_1063_t KX126_1063)
{
    uint8_t data =0;
    if(KX126_1063.KX126_1063_PC1 == stand_by_mode){
        data &= 0x7F; 
    }
    else data |= 0x80; 
    //
    if(KX126_1063.KX126_1063_RES == low_power_higher_noise_mode){
        data &= 0xBF; 
    }
    else data |= 0x40; 
    //
    if(KX126_1063.KX126_1063_DRDYE == disable){
        data &= 0xDF; 
    }
    else data |= 0x20; 
    //
    
    switch(KX126_1063.KX126_1063_Selects_ACC_RANGEOUT)
        {
            case range_2g:
                data &=0xE7;
                break;
            case range_4g:
                data |= 0x08;
                break; 
            default:
                data |= 0x10;
                break;
        }
    //
    if(KX126_1063.KX126_1063_TDTE == TDTE_disable){
        data &= 0xFB; 
    }
    else data |= 0x04; 
    //
    if(KX126_1063.KX126_1063_PDE == PDE_disabled){
        data &= 0xFD; 
    }
    else data |= 0x02;
    //
    if(KX126_1063.KX126_1063_TPE == TPE_disable){
        data &= 0xFE; 
    }
    else data |= 0x01;
    
    
    I2C_Write(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL1,&data,1);
    I2C_Read(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL1,&data,1);
}
void KX126_1063_Control2(KX126_1063_t KX126_1063)
{
    uint8_t data =0;
    if(KX126_1063.KX126_1063_SRST == SRST_no_action){
        data &= 0x7F; 
    }
    else data |= 0x80; 
    //
    if(KX126_1063.KX126_1063_COTC == COTC_no_action){
        data &= 0xBF; 
    }
    else data |= 0x40; 
    I2C_Write(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL2,&data,1);
    I2C_Read(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL2,&data,1);
}


#endif