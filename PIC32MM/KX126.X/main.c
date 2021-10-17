/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0256GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "KX126_1063.h"
#include "i2c_using_simple.h"
/*
                         Main application
 */

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    KX126_1063_t KX126_1063;
//    KX126_1063.KX126_1063_PC1 = higher_power_lower_noise_mode;
//    KX126_1063.KX126_1063_RES = low_power_higher_noise_mode;
//    KX126_1063.KX126_1063_DRDYE = disable;
//    KX126_1063.KX126_1063_Selects_ACC_RANGEOUT = range_2g;
//    KX126_1063.KX126_1063_TDTE = TDTE_enable;
//    KX126_1063.KX126_1063_PDE = PDE_enable;
//    KX126_1063.KX126_1063_TPE = TPE_enable;
//    KX126_1063.KX126_1063_OTP = set_12dot5_hz;
//    KX126_1063.KX126_1063_OTDT = set_400hz;
//    KX126_1063.KX126_1063_OWUF = set_0dot781_hz;
//    KX126_1063.KX126_1063_OBT = s_0d781hz;
//    KX126_1063.KX126_1063_HPE = HPE_Disabled;
//    KX126_1063.KX126_1063_IIR_BYPASS = filtering_applied;
//    KX126_1063.KX126_1063_LPRO = set_ODRslash9;
    
//    KX126_1063.KX126_1063_BUFE = sample_buffer_inactive;
//    KX126_1063.KX126_1063_BRES = set_8_bit_samples;
//    KX126_1063.KX126_1063_BFIE = BFIE_disabled;
//    KX126_1063.KX126_1063_BM = set_FIFO;
//    KX126_1063_Init(KX126_1063);
    
    int8_t x_axis , y_axis, z_axis;
    uint8_t cntl_1;
    while (1)
    {
        // Add your application code
       
       //KX126_1063_ReadID();
       I2C_Read(KX126_1063_DEVICE_ADDRESS, KX126_1063_CNTL1, cntl_1, 1); 
//       KX126_1063_getHighPassAccelAxis(&x_axis, &y_axis, &z_axis);
//       KX126_1063_getAccelAxis(&x_axis, &y_axis, &z_axis);
//       printf("toa do x: %d\n", x_axis);
//       printf("toa do y: %d\n", y_axis);
//       printf("toa do z: %d\n", z_axis);
      // printf("");
       
//        I2C_Read(KX126_1063_DEVICE_ADDRESS, 0x11, &x_axis, 1);
        printf("CNTL1 default: %x\n", cntl_1);
        DELAY_milliseconds(1000);
    }
    return 1; 
}
/**
 End of File
*/

