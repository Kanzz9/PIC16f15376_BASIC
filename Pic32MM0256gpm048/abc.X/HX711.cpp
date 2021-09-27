/* 
 * File:   HX711.cpp
 * Author: hoang
 * 
 * Created on April 11, 2021, 10:37 PM
 */

#include "HX711.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/delay.h"

HX711::HX711() {
}

HX711::~HX711() {
}

void HX711::begin(uint8_t gain) {

	set_gain(gain);
}

bool HX711::is_ready() {
   
   return   (!DOUT_GetValue());
}

void HX711::set_gain(uint8_t gain) {
	switch (gain) {
		case 128:		// channel A, gain factor 128
			GAIN = 1;
			break;
		case 64:		// channel A, gain factor 64
			GAIN = 3;
			break;
		case 32:		// channel B, gain factor 32
			GAIN = 2;
			break;
	}

}

long HX711::read() {

	// Wait for the chip to become ready.
	wait_ready();

	// Define structures for reading data into.
	unsigned long value = 0;
//	uint8_t data[3] = { 0 };
//	uint8_t filler = 0x00;

	// Protect the read sequence from system interrupts.  If an interrupt occurs during
	// the time the PD_SCK signal is high it will stretch the length of the clock pulse.
	// If the total pulse time exceeds 60 uSec this will cause the HX711 to enter
	// power down mode during the middle of the read sequence.  While the device will
	// wake up when PD_SCK goes low again, the reset starts a new conversion cycle which
	// forces DOUT high until that cycle is completed.
	//
	// The result is that all subsequent bits read by shiftIn() will read back as 1,
	// corrupting the value returned by read().  The ATOMIC_BLOCK macro disables
	// interrupts during the sequence and then restores the interrupt mask to its previous
	// state after the sequence completes, insuring that the entire read-and-gain-set
	// sequence is not interrupted.  The macro has a few minor advantages over bracketing
	// the sequence between `noInterrupts()` and `interrupts()` calls.


	// Pulse the clock pin 24 times to read the data.
//	data[2] = SHIFTIN_WITH_SPEED_SUPPORT(DOUT, PD_SCK, MSBFIRST);
//	data[1] = SHIFTIN_WITH_SPEED_SUPPORT(DOUT, PD_SCK, MSBFIRST);
//	data[0] = SHIFTIN_WITH_SPEED_SUPPORT(DOUT, PD_SCK, MSBFIRST);
  
   for (uint8_t i=0; i<24; i++){
      PD_SCK_SetHigh();
      value=value<<1;
      PD_SCK_SetLow();
      if(DOUT_GetValue()) value++;
   }
   
    PD_SCK_SetHigh();
    value ^= 0x800000;
    PD_SCK_SetLow();
   
	// Set the channel and the gain factor for the next reading using the clock pin.
//	for (unsigned int i = 0; i < GAIN; i++) {
//		//digitalWrite(PD_SCK, HIGH);
//		#if ARCH_ESPRESSIF
//		delayMicroseconds(1);
//		#endif
//		//digitalWrite(PD_SCK, LOW);
//		#if ARCH_ESPRESSIF
//		delayMicroseconds(1);
//		#endif
//	}


	// Replicate the most significant bit to pad out a 32-bit signed integer
//	if (data[2] & 0x80) {
//		filler = 0xFF;
//	} else {
//		filler = 0x00;
//	}
//
//	// Construct a 32-bit signed integer
//	value = ( static_cast<unsigned long>(filler) << 24
//			| static_cast<unsigned long>(data[2]) << 16
//			| static_cast<unsigned long>(data[1]) << 8
//			| static_cast<unsigned long>(data[0]) );

	return static_cast<long>(value);
}

void HX711::wait_ready(unsigned long delay_ms) {
	// Wait for the chip to become ready.
	// This is a blocking implementation and will
	// halt the sketch until a load cell is connected.
	while (!is_ready()) {
		// Probably will do no harm on AVR but will feed the Watchdog Timer (WDT) on ESP.
		// https://github.com/bogde/HX711/issues/73
		DELAY_milliseconds(delay_ms);
	}
}

bool HX711::wait_ready_retry(int retries, unsigned long delay_ms) {
	// Wait for the chip to become ready by
	// retrying for a specified amount of attempts.
	// https://github.com/bogde/HX711/issues/76
	int count = 0;
	while (count < retries) {
		if (is_ready()) {
			return true;
		}
		DELAY_milliseconds(delay_ms);
		count++;
	}
	return false;
}

bool HX711::wait_ready_timeout(unsigned long timeout, unsigned long delay_ms) {
	// Wait for the chip to become ready until timeout.
	// https://github.com/bogde/HX711/pull/96
//	unsigned long millisStarted = millis();
//	while (millis() - millisStarted < timeout) {
//		if (is_ready()) {
//			return true;
//		}
//		DELAY_milliseconds(delay_ms);
//	}
	return false;
}

long HX711::read_average(uint8_t times) {
	long sum = 0;
	for (uint8_t i = 0; i < times; i++) {
		sum += read();
		// Probably will do no harm on AVR but will feed the Watchdog Timer (WDT) on ESP.
		// https://github.com/bogde/HX711/issues/73
		DELAY_milliseconds(0);
	}
	return sum / times;
}

double HX711::get_value(uint8_t times) {
	return read_average(times) - OFFSET;
}

float HX711::get_units(uint8_t times) {
	return get_value(times) / SCALE;
}

void HX711::tare(uint8_t times) {
	double sum = read_average(times);
	set_offset(sum);
}

void HX711::set_scale(float scale) {
	SCALE = scale;
}

float HX711::get_scale() {
	return SCALE;
}

void HX711::set_offset(long offset) {
	OFFSET = offset;
}

long HX711::get_offset() {
	return OFFSET;
}

void HX711::power_down() {

   PD_SCK_SetLow();
   PD_SCK_SetHigh();
}

void HX711::power_up() {

   PD_SCK_SetLow();
}

