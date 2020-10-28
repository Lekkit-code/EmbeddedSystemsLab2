#include <avr/io.h>
#include "led.h"

#define LED_PIN 3
#define LED_PORT PORTB

void LED_init(void) {
	DDRB |= (1 << 3);
}

void LED_flip(void) {
	LED_PORT ^= (1 << LED_PIN);
}
