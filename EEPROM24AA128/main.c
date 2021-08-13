#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"

void EE_Write(uint16_t addr, uint8_t data)
{
    uint8_t frame[3];

    frame[0]=(uint8_t) (addr>>8); // high address
    frame[1]=(uint8_t) addr; // low address
    frame[2]=data; // data
    //EE_WP_SetLow(); // disable write protect
    i2c_writeNBytes(0b01010000, &frame[0], 3);
    __delay_ms(5);
    //EE_WP_SetHigh(); // enable write protect
}

uint8_t EE_Read(uint16_t addr)
{
    uint8_t frame[3];

    frame[0]=(uint8_t) (addr>>8); // high address
    frame[1]=(uint8_t) addr; // low address
    i2c_writeNBytes(0b01010000, &frame[0], 2);
    i2c_readNBytes(0b01010000, &frame[2], 1);

    return frame[2];
}

void main(void)
{
    uint8_t data;
    uint16_t addr=0;

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    printf("\nEEPROM 24AA128 TEST\n");

    while(1)
    {
        if(EUSART1_is_rx_ready())
        {
            uint8_t c=EUSART1_Read();

            switch(c)
            {
                case 'r':
                case 'R':
                    data=EE_Read(addr);
                    printf("\nRead %02X @ %04X", data, addr);
                    break;

                case 'w':
                case 'W':
                    do
                        addr=(uint16_t) rand();
                    while(addr>0x3FFF);

                    data=(uint8_t) rand();
                    EE_Write(addr, data);
                    printf("\nWrite %02X @ %04X", data, addr);
                    break;

                default:
                    while(!EUSART1_is_tx_ready());
                    EUSART1_Write(c);
                    break;
            }
        }
    }
}