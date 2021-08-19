/*
 * rtc_hal.h
 *
 * Created: 06-08-2021 17:01:07
 *  Author: nhasbun
 */ 

#ifndef RTC_HAL_H_
#define RTC_HAL_H_

#include "atmel_start.h"

#define RTC_1_SECOND_COUNT 64  // Valid for DIV512 prescaler

void rtc_reset();
uint16_t get_rtc_count();
void set_rtc_count(uint16_t value);


#endif