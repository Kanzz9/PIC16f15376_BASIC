#include <stdint.h>
#include "i2c_config.h"
#include "TickTimer32.h"

void I2C_Init(void){
   
    I2C2CON=0;
    I2C2CONbits.DISSLW = 1;     // disable slew rate for 100khz
    I2C2BRG = 0x25;             // 100Khz
    I2C2CONbits.ON = 1;         // turn on I2C2 module
}

void I2C_Wait_For_Idle(void){
    
    while(I2C2CON & 0x1F); // 
    while (I2C2STATbits.TRSTAT);// bit = 0 ? Master transmit is not is progress
}

void I2C_Start(void){
    
    I2C_Wait_For_Idle();
    I2C2CONbits.SEN = 1;
    while(I2C2CONbits.SEN == 1);
}

void I2C_Stop(){
    
    I2C_Wait_For_Idle();
    I2C2CONbits.PEN = 1;
}

void I2C_Restart(){
    
    I2C_Wait_For_Idle();
    I2C2CONbits.RSEN = 1;
    while(I2C2CONbits.RSEN == 1);
}

void I2C_Ack(void){
    
    I2C_Wait_For_Idle();
    I2C2CONbits.ACKDT = 0; // set hardware to send ack bit
    I2C2CONbits.ACKEN = 1; // set ack bit, will be ...
    while(I2C2CONbits.ACKEN);
}

void I2C_Nack(void){
    
    I2C_Wait_For_Idle();
    I2C2CONbits.ACKDT = 1;
    I2C2CONbits.ACKEN = 1;
    while(I2C2CONbits.ACKEN);
}

void I2C_Write(uint8_t address, char wait_ack){
    
    static tick_timer_t tick, tick1;
    
    I2C2TRN = address | 0;
    
    while(I2C2STATbits.TBF == 1 && Tick_Timer_Is_Over_Ms(tick,10));
    I2C_Wait_For_Idle();
    if(wait_ack) while (I2C2STATbits.ACKSTAT == 1 && Tick_Timer_Is_Over_Ms(tick1,10));
}

void I2C_Read(uint8_t *value, char ack_nack){
    
    I2C2CONbits.RCEN = 1;
    while(I2C2CONbits.RCEN);
    while(!I2C2STATbits.RBF);
    *value = I2C2RCV;
    
    if(!ack_nack)
        I2C_Ack();
    else
        I2C_Nack();
}

uint8_t I2C_Mem_Write(uint8_t DevAddress, uint8_t RegAddress, uint8_t *data, uint16_t lenght){
    
   I2C_Start();
   I2C_Write(DevAddress << 1, 1);
   I2C_Write(RegAddress, 1);
   uint16_t i=0;
   for(i=0; i< lenght; i++){
       I2C_Write(data[i], 1);
   }
   
   I2C_Stop();
   
   return 0;
}
