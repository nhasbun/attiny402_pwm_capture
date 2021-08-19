#include <atmel_start.h>
#include <stdio.h>
#include "rtc_hal.h"
#include "timer_b_hal.h"


#define PWM_ERROR_TOLERANCE 5


void main_loop();


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	printf("attiny402 PWM capture starting...\r\n");
	main_loop();
	
	return 0;
}


void main_loop() {
	
	bool pwm_timeout = true;
	uint16_t pwm_width = 0;
	uint16_t last_pwm_width = 1;  // Used to print changes via serial
	
	while (1) {
		
		if(pwm_capture_available() && !pwm_timeout) {
			
			pwm_width = get_pwm_width();
			rtc_reset();
		}
			
		else if(pwm_capture_available() && pwm_timeout) {
			// We skip first reading after timeout,
			// to avoid timer counter overflow errors.
			
			get_pwm_width();
			rtc_reset();
			pwm_timeout = false;
		
		} else {
			
			uint16_t rtc_count = get_rtc_count();
			
			if(rtc_count > 2 * RTC_1_SECOND_COUNT) {
				// PWM signal timeout after 2 seconds
				pwm_width = 0;
				rtc_reset();
				pwm_timeout = true;
			}
		}
		
		// Serial debugging captured relevant values,
		// skipping small changes.
		if(abs(last_pwm_width - pwm_width) > PWM_ERROR_TOLERANCE) {	
			printf("Captured value: %u \r\n", pwm_width);
		}
		
		last_pwm_width = pwm_width;
	}
}
