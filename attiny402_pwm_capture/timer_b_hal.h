/*
 * timer_b_hal.h
 *
 * Created: 06-08-2021 17:06:35
 *  Author: nhasbun
 */ 


#ifndef TIMER_B_HAL_H_
#define TIMER_B_HAL_H_

#include "atmel_start.h"


bool pwm_capture_available();
uint16_t get_pwm_width();
void clear_pwm_cnt();


#endif