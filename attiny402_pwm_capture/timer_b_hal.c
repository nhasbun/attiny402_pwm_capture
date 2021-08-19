/*
 * timer_b_hal.c
 *
 * Created: 06-08-2021 17:06:45
 *  Author: nhasbun
 */ 

#include "timer_b_hal.h"


bool pwm_capture_available() {
	return TCB0_INTFLAGS;
}


uint16_t get_pwm_width() {	
	// Since timer counter uses 3.33MHz main clock,
	// then period between ticks is 0.3us
	return TCB0_CCMP * 3 / 10;  // --> width in microseconds
}


void clear_pwm_cnt() {
	TCB0_CNT = 0;
}
