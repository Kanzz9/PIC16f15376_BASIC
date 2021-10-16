#include "KX126_1063.h"

#include <stdint.h>
//
#if(i2c_using_simple_Enable)
    #include "i2c_using_simple.h"

#elif(I2C_Enable)

    #include "I2C.h"

#endif

#if(KX126_1063_Enable)

void KX126_1063_Init(KX126_1063_t KX126_1063){
    KX126_1063_Control1(KX126_1063);
    KX126_1063_Control2(KX126_1063);
    KX126_1063_Control3(KX126_1063);
    KX126_1063_Output_data_control(KX126_1063);
}
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
void KX126_1063_getAccelAxis(int8_t *x_axis, int8_t *y_axis, int8_t *z_axis)
{
    int8_t buf1[2],buf2[2],buf3[2];
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__X_AXIS_OUTPUT_LOW, buf1, 1); 
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__Y_AXIS_OUTPUT_LOW, buf2, 1);
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063__Z_AXIS_OUTPUT_LOW, buf3, 1);
    *x_axis = buf1[1]<<4 | buf1[0];
    *y_axis = buf2[1]<<4 | buf2[0];
    *z_axis = buf3[1]<<4 | buf3[0]; 
}

void KX126_1063_getHighPassAccelAxis(int8_t *x_axis, int8_t *y_axis, int8_t *z_axis)
{
    int8_t buf1[2],buf2[2],buf3[2];
    
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_XHP_L, buf1, 1);
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_YHP_L, buf2, 1);
     I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_ZHP_L, buf3, 1);
    *x_axis = buf1[1]<<4 | buf1[0];
    *y_axis = buf2[1]<<4 | buf2[0];
    *z_axis = buf3[1]<<4 | buf3[0];      
    
}
void KX126_1063_Control1(KX126_1063_t KX126_1063)
{
    uint8_t data ;
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
//
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
//
void KX126_1063_Control3(KX126_1063_t KX126_1063)
{
    uint8_t data ;
    switch(KX126_1063.KX126_1063_OTP)
        {
            case set_1dot563_hz:
                data &=0x3F;
                break;
            case set_6dot25_hz:
                data |= 0x40;
                break; 
            case set_12dot5_hz:
                data |= 0x80;
                break;     
            default:
                data |= 0xc0;
                break;
        }
    ///////////////
    switch(KX126_1063.KX126_1063_OTDT)
        {
            case set_50hz:
                data &=0xC7;
                break;
            case set_100hz:
                data |= 0x08;
                break; 
            case set_200hz:
                data |= 0x10;
                break;  
            case set_400hz:
                data |= 0x18;
                break; 
            case set_12dot5hz:
                data |= 0x20;
                break; 
            case set_25hz:
                data |= 0x28;
                break; 
            case set_800hz:
                data |= 0x30;
                break;     
            default:
                data |= 0x38;
                break;
        }
    /////////////////
        switch(KX126_1063.KX126_1063_COTC)
        {
            case set_0dot781_hz:
                data &=0xF8;
                break;
            case set_1d563_hz:
                data |= 0x01;
                break; 
            case set_3dot125_hz:
                data |= 0x02;
                break;  
            case set_6d25_hz:
                data |= 0x03;
                break; 
            case set_12d5_hz:
                data |= 0x04;
                break; 
            case set_25hz:
                data |= 0x05;
                break; 
            case set_50_hz:
                data |= 0x06;
                break;     
            default:
                data |= 0x07;
                break;
        }
    I2C_Write(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL3,&data,1);
    I2C_Read(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL3,&data,1);
}
void KX126_1063_Control4(KX126_1063_t KX126_1063)
{
    uint8_t data ;
    if(KX126_1063.KX126_1063_C_MODE == filtering_applied){
            data &= 0x7F; 
        }
        else data |= 0x80; 
    //
    if(KX126_1063.KX126_1063_TH_MODE == set_ODRslash9){
        data &= 0xBF; 
    }
    else data |= 0x40;
    //
    if(KX126_1063.KX126_1063_WUFE == WUFE_Disabled){
        data &= 0xDF; 
    }
    else data |= 0x20; 
    //
    if(KX126_1063.KX126_1063_BTSE == BTSE_Disabled){
        data &= 0xEF; 
    }
    else data |= 0x10; 
    //
    if(KX126_1063.KX126_1063_HPE == HPE_Disabled){
        data &= 0xF7; 
    }
    else data |= 0x08; 
    //
     switch(KX126_1063.KX126_1063_OBT)
        {
            case s_0d781hz:
                data &=0xF8;
                break;
            case s_1d563hz:
                data |= 0x01;
                break; 
            case s_3dot125hz:
                data |= 0x02;
                break;  
            case s_6d25hz:
                data |= 0x03;
                break; 
            case s_12d5hz:
                data |= 0x04;
                break; 
            case s_25hz:
                data |= 0x05;
                break; 
            case s_50hz:
                data |= 0x06;
                break;     
            default:
                data |= 0x07;
                break;
        }
    
}
void KX126_1063_Output_data_control(KX126_1063_t KX126_1063)
{
    uint8_t data;
    if(KX126_1063.KX126_1063_C_MODE == clear_mode){
            data &= 0x7F; 
        }
        else data |= 0x80; 
    //
    if(KX126_1063.KX126_1063_TH_MODE == absolute_threshold){
        data &= 0xBF; 
    }
    else data |= 0x40;
    //
     switch(KX126_1063.KX126_1063_OSA)
        {
            case s_12d5_hz:
                data &=0xF0;
                break;
            case s_25_hz:
                data |= 0x01;
                break; 
            case s_50_hz:
                data |= 0x02;
                break;  
            case s_100_hz:
                data |= 0x03;
                break; 
            case s_200_hz:
                data |= 0x04;
                break; 
            case s_400_hz:
                data |= 0x05;
                break; 
            case s_800_hz:
                data |= 0x06;
                break;  
            case s_1600_hz:
                data |= 0x07;
                break; 
            case s_0dot781_hz:
                data |= 0x08;
                break; 
            case s_1dot563_hz:
                data |= 0x09;
                break; 
            case s_3dot125_hz:
                data |= 0x0A;
                break;
            case s_6dot25_hz:
                data |= 0x0B;
                break; 
            case s_3200_hz:
                data |= 0x0C;
                break;     
            case s_6400_hz:
                data |= 0x0D;
                break; 
            case s_12800_hz:
                data |= 0x0E;
                break;     
            default:
                data |= 0x0F;
                break;
        }
    I2C_Write(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL_DATA_OUT,&data,1);
    I2C_Read(KX126_1063_DEVICE_ADDRESS,KX126_1063_CONTROL_DATA_OUT,&data,1);
    
}
void KX126_1063_BUF_CNTL2_R(KX126_1063_t KX126_1063)
{
    uint8_t data;
    
    if(KX126_1063.KX126_1063_BUFE == sample_buffer_inactive){
            data &= 0x7F; 
        }
        else data |= 0x80; 
    //
    if(KX126_1063.KX126_1063_BRES == set_8_bit_samples){
        data &= 0xBF; 
    }
    else data |= 0x40;
    //
    if(KX126_1063.KX126_1063_BFIE == BFIE_disabled){
        data &= 0xDF; 
    }
    else data |= 0x20; 
    //
    switch(KX126_1063.KX126_1063_BM)
        {
            case set_FIFO:
                data &=0xF8;
                break;
            case set_Stream:
                data |= 0x01;
                break; 
            case set_Trigger:
                data |= 0x02;
                break;  
            default:
                data |= 0x03;
                break;
        }
    //
    I2C_Write(KX126_1063_DEVICE_ADDRESS,KX126_1063_BUF_CNTL2,&data,1);
    I2C_Read(KX126_1063_DEVICE_ADDRESS,KX126_1063_BUF_CNTL2,&data,1);
}
#endif