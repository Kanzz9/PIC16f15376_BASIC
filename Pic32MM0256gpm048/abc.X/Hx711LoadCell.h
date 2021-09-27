/* 
 * File:   Hx711LoadCell.h
 * Author: hoang
 *
 * Created on April 11, 2021, 10:20 PM
 */

#ifndef HX711LOADCELL_H
#define	HX711LOADCELL_H

#include"mcc_generated_files/system.h"

class Hx711LoadCell {
   
private:
   
   uint8_t abc;
   
public:
   
   Hx711LoadCell();
   Hx711LoadCell(uint8_t abc);

};

#endif	/* HX711LOADCELL_H */

