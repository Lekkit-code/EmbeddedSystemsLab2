#include <avr/io.h>
#include "led.h"

#define LED_PIN 6
#define LED_PORT PORTD

void LED_init(void) {
	DDRD |= (1 << LED_PIN);
}

void LED_flip(void) {
	LED_PORT ^= (1 << LED_PIN);
}
