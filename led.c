#include <avr/io.h>
#include "led.h"

void LED_init() {
	void led_init(void) //Set the pin on bit 3 of the LED_PORT to 1 to represent an output pin.
	{
		DDRB |= (1 << 3);
	}
}
