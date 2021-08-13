#include <string.h>
#include "mcc_generated_files/mcc.h"

#ifdef USE_SOFT_I2C
#include "mcc_generated_files/SW_I2C_Master.h"
#define i2c_writeNBytes(slv, pD, len)   SW_I2C_WriteNBytes(slv, pD, len)
#define i2c_readNBytes(slv, pD, len)    SW_I2C_ReadNBytes(slv, pD, len)
#else
#include "mcc_generated_files/drivers/i2c_simple_master.h"
#endif

void EE_Write(uint16_t addr, uint8_t data) // <editor-fold defaultstate="collapsed" desc="Write byte">
{
    uint8_t frame[3];

    frame[0] = (uint8_t) (addr >> 8); // high address
    frame[1] = (uint8_t) addr; // low address
    frame[2] = data; // data
    EE_WP_SetLow(); // disable write protect
    i2c_writeNBytes(0b01010000, &frame[0], 3);
    __delay_ms(5);
    EE_WP_SetHigh(); // enable write protect
} // </editor-fold>

uint8_t EE_Read(uint16_t addr) // <editor-fold defaultstate="collapsed" desc="Read byte">
{
    uint8_t frame[3];

    frame[0] = (uint8_t) (addr >> 8); // high address
    frame[1] = (uint8_t) addr; // low address
    i2c_writeNBytes(0b01010000, &frame[0], 2);
    i2c_readNBytes(0b01010000, &frame[2], 1);

    return frame[2];
} // </editor-fold>

void EE_WritePage(uint16_t addr, const uint8_t *pdata) // <editor-fold defaultstate="collapsed" desc="Write page (64 bytes)">
{
    uint8_t frame[66];

    frame[0] = (uint8_t) (addr >> 8); // high address
    frame[1] = (uint8_t) addr; // low address
    memcpy((void*) &frame[2], pdata, 64);
    EE_WP_SetLow(); // disable write protect
    i2c_writeNBytes(0b01010000, &frame[0], 66);
    __delay_ms(5);
    EE_WP_SetHigh(); // enable write protect
} // </editor-fold>

void EE_ReadPage(uint16_t addr, uint8_t *pData) // <editor-fold defaultstate="collapsed" desc="Read page (64 bytes)">
{
    uint8_t frame[2];

    frame[0] = (uint8_t) (addr >> 8); // high address
    frame[1] = (uint8_t) addr; // low address

    i2c_writeNBytes(0b01010000, &frame[0], 2);
    i2c_readNBytes(0b01010000, pData, 64);
} // </editor-fold>

void RandomArray(uint8_t *pD, uint8_t len) // <editor-fold defaultstate="collapsed" desc="Generate random array">
{
    while (len > 0) {
        *pD = (uint8_t) rand();
        pD++;
        len--;
    }
} // </editor-fold>

bool MemoryTest(uint16_t addr, const uint8_t *pdata1, const uint8_t *pdata2, uint8_t len) // <editor-fold defaultstate="collapsed" desc="Compare 2 data array">
{
    uint8_t i;
    bool rslt = 1;

    for (i = 0; i < len; i++) {
        if (pdata1[i] != pdata2[i]) {
            rslt = 0;
            printf("\nError @%04X: %02X # %02X", addr + i, pdata1[i], pdata2[i]);
        }
    }

    return rslt;
} // </editor-fold>

void main(void) // <editor-fold defaultstate="collapsed" desc="Main">
{
    uint8_t datain[64], a;
    uint8_t dataout[64];
    uint16_t addr = 0;
    uint8_t DoNext = 0;

    SYSTEM_Initialize();

#ifdef USE_SOFT_I2C
    SW_I2C_Init();
#else
    I2C1_Initialize();
#endif
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    printf("\nEEPROM 24AA128 TEST\n");
    EE_Write(0x00, 0xAA);
    __delay_ms(5);
    while (1) {
        //        a=EE_Read(0x00);
        //        printf("a: %02X\n",a);
        //        __delay_ms(500);
        switch (DoNext) {
            case 0:
                printf("\nStart Test:");

                for (addr = 0; addr < 0x4000; addr += 64) {
                    RandomArray(datain, 64); // generate 64 random bytes
                    EE_WritePage(addr, datain);
                    EE_ReadPage(addr, dataout);

                    if (MemoryTest(addr, datain, dataout, 64))
                        printf(".");
                }

                DoNext++;
                printf("Done\nPress 'T' to test again\n");
                break;

            default:
                if (EUSART1_is_rx_ready()) {
                    if (EUSART1_Read() == 'T')
                        DoNext = 0;
                }
                break;
        }
    }
} // </editor-fold>