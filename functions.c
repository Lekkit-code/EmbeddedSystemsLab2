#include <stdint.h>
#include "functions.h"


volatile uint8_t value = 1;
volatile int dir = -1;

uint8_t simple_ramp() {
	if (value == 0) {
		dir = 1;
	}
	else if (value == 255) {
		dir = -1;
	}
	value += dir;
	return value;
}