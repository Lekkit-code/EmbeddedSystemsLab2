#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main (void) {
	uart_init();
	LED_init();
	
	while (1) {
		/* remove this once you've verified it works */
		//printf_P(PSTR("Hello there\n"));
		PORTB |= (1 << 3);
		_delay_ms(1000);
		PORTB &= ~(1 << 3);
		_delay_ms(1000);
	}
	return 0;
}
