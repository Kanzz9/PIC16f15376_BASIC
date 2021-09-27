#ifndef SW_I2C_MASTER_CFG_H
#define SW_I2C_MASTER_CFG_H

#define SW_I2C_Delay(x)             __delay_us(16)
// get/set SW_SCL aliases
//#define SW_SCL_TRIS                 TRISCbits.TRISC3
//#define SW_SCL_LAT                  LATCbits.LATC3
//#define SW_SCL_PORT                 PORTCbits.RC3
//#define SW_SCL_SetHigh()            LATCbits.LATC3 = 1
//#define SW_SCL_SetLow()             LATCbits.LATC3 = 0
//#define SW_SCL_Toggle()             LATCbits.LATC3 = ~LATCbits.LATC3
//#define SW_SCL_GetValue()           PORTCbits.RC3
//#define SW_SCL_SetDigitalInput()    TRISCbits.TRISC3 = 1
//#define SW_SCL_SetDigitalOutput()   TRISCbits.TRISC3 = 0

// get/set SW_SDA aliases
//#define SW_SDA_TRIS                 TRISCbits.TRISC4
//#define SW_SDA_LAT                  LATCbits.LATC4
//#define SW_SDA_PORT                 PORTCbits.RC4
//#define SW_SDA_SetHigh()            LATCbits.LATC4 = 1
//#define SW_SDA_SetLow()             LATCbits.LATC4 = 0
//#define SW_SDA_Toggle()             LATCbits.LATC4 = ~LATCbits.LATC4
//#define SW_SDA_GetValue()           PORTCbits.RC4
//#define SW_SDA_SetDigitalInput()    TRISCbits.TRISC4 = 1
//#define SW_SDA_SetDigitalOutput()   TRISCbits.TRISC4 = 0

#endif