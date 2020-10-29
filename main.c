#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main (void) {
	uart_init();
	LED_init();
	timer_init();

	while (1) {
		OCR0A = 10; //Set the duty cycle to 3,9%. ((10/256)*100)
		_delay_ms(1000);
		OCR0A = 100;	//Set the duty cycle to 39% ((100/256)*100)
		_delay_ms(1000);
		OCR0A = 250;	//Set the duty cycle to 97,6% ((250/256)*100)
		_delay_ms(1000);
	}
	return 0;
}
