/*
 * Author: Hoang Khanh Toan
 * Create: 12:22AM
 * Date: 19/08/2021
 */

#ifndef BM1383_H
#define BM1383_H

#include "../../BM1383/BM1383_basic.X/mcc_generated_files/mcc.h"

#if(BM1383_ENABLE)

typedef struct{
    uint8_t BM1383_Add;
}BM1383_t;



void WriteByteBM1383(const BM1383_t *BM1383, uint8_t Reg_Add, uint8_t data);
uint8_t ReadByteBM1383(const BM1383_t *BM1383, uint8_t Reg_Add);

#endif

#endif
