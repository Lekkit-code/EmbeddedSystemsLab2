#include <avr/io.h>
#include "timer.h"

void timer_init() {
	TCCR0A |= (1 << WGM01) | (1<< WGM00) | (1<<COM0A1); //Set the mode of TC0 to Fast PWM non-inverted mode.
	TCCR0B |= (1 << CS01) | (1 << CS00);	//Set the prescaler to 64.
}

