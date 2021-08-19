/*
 * rtc_hal.c
 *
 * Created: 06-08-2021 17:01:37
 *  Author: nhasbun
 */ 

#include "rtc_hal.h"

void rtc_reset() {
	RTC_CNT = 0;
}

uint16_t get_rtc_count() {
	return RTC_CNT;
}

void set_rtc_count(uint16_t value) {
	RTC_CNT = value;
}
