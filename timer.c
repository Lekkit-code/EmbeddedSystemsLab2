#include <avr/io.h>

#include "timer.h"
#define MYOCR0A ((16000000/1024)*0.01) //Since we're running at 16Mhz with a prescaler of 1024 we want to find out how many times/second the counter will increment. We take that value and multiply it by the amount we want/second to get the value we want in our ORC0A, which is the value we'll be comparing to.

void timer_init() {
	TCCR0A |= (1 << WGM01); //Set the mode of TC0 to CTC.
	TCCR0B |= (1 << CS02) | (1 << CS00);	//Set the prescaler to 1024.
	OCR0A = MYOCR0A;	//Set the value to count to to MYOCR0A.
	TIMSK0 |= (1 << OCIE0A);	//Enable the ISA COMPA vector.
	
}

