/*
 * small_utils.c
 *
 * Created: 04-08-2021 23:34:22
 *  Author: nhasbun
 */ 
#include "small_utils.h"

void print(char * str) {
	while(*str) {
		USART_write(*str++);
	}
}


/*
 *	Prints 16bit unsigned integer using easy conversion from integer to ascii.
 * Integer to ascii is single digit + 48.
 * https://www.edaboard.com/threads/how-to-convert-int-to-string.208844/
 */
void print_u16(uint16_t value) {
	
	uint8_t buf[10] = {0};
	uint8_t index = 9;
	uint8_t len = 0;
	
	for(;;) {
		uint8_t remainder = value%10 + 48;
		buf[index--] = remainder;		
		len++;
		
		value = value/10;
		if (value == 0) break;
	}
	
	for (uint8_t i = 0; i <= len; i++) {
		USART_write(buf[index+i]);
	}
}
