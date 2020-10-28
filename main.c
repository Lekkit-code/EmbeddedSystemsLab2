#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

volatile int counter = 0; //Needs to be volatile to work with interrupts.

int main (void) {
	uart_init();
	LED_init();
	timer_init();

	sei(); //Enables interrupts.
	
	while (1) {
		
		if (counter == 10)//Every 10th interrupt we turn our LED on/off.
		{
			counter = 0;
			LED_flip();
		}
	}
	return 0;
}



ISR(TIMER0_COMPA_vect) //Triggers when TCNT0 and OCR0A have the same value, which happens every 10th ms. Adds one to the counter and then clears the interrupt flag.
{
    counter++;
    TIFR0 &= ~(1 << OCF0A);
}