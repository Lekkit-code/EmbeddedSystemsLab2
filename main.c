#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "functions.h"

volatile uint8_t brightness = 0;

int main (void) {
	LED_init();
	timer_init();

	sei();

	while (1) {
		OCR0A = brightness;	//Adjust the brightness
	}
	return 0;
}

ISR(TIMER2_COMPA_vect) //When the interrupt triggers, updates the value of brightness and clears the interrupt flag.
{
	brightness = simple_ramp(); 
	TIFR2 &= ~(1 << OCF2A);
}