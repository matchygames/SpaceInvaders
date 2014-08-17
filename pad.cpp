#include "pad.h"

void Button::init() {
   pinMode(BUTTON_ADC_PIN, INPUT);
   digitalWrite(BUTTON_ADC_PIN, LOW);
}

void Button::update() {
	id_last = id;
	id = read();
}

byte Button::read() {
	byte b = BUTTON_NONE;
	unsigned int range_a[7];
	unsigned int range_b[7];
	voltage = analogRead(BUTTON_ADC_PIN);
	if (voltage > 0) {
		range_a[BUTTON_NONE] =	NONE_10BIT_ADC	- BUTTONHYSTERESIS;
		range_a[BUTTON_UP] =	UP_10BIT_ADC	- BUTTONHYSTERESIS;
		range_a[BUTTON_RIGHT] = RIGHT_10BIT_ADC - BUTTONHYSTERESIS;
		range_a[BUTTON_DOWN] =	DOWN_10BIT_ADC	- BUTTONHYSTERESIS;
		range_a[BUTTON_LEFT] =	LEFT_10BIT_ADC	- BUTTONHYSTERESIS;
		range_a[BUTTON_A] =		A_10BIT_ADC		- BUTTONHYSTERESIS;
		range_a[BUTTON_B] =		B_10BIT_ADC		- BUTTONHYSTERESIS;
		range_b[BUTTON_NONE] =	NONE_10BIT_ADC	+ BUTTONHYSTERESIS;
		range_b[BUTTON_UP] =	UP_10BIT_ADC	+ BUTTONHYSTERESIS;
		range_b[BUTTON_RIGHT] = RIGHT_10BIT_ADC + BUTTONHYSTERESIS;
		range_b[BUTTON_DOWN] =	DOWN_10BIT_ADC	+ BUTTONHYSTERESIS;
		range_b[BUTTON_LEFT] =	LEFT_10BIT_ADC	+ BUTTONHYSTERESIS;
		range_b[BUTTON_A] =		A_10BIT_ADC		+ BUTTONHYSTERESIS;
		range_b[BUTTON_B] =		B_10BIT_ADC		+ BUTTONHYSTERESIS;
		for (byte i = 0; i < 7; i++) {
			if (voltage > range_a[i] && voltage < range_b[i]) {
				b = i;
				break;
			}
		}
	} else {
		b = BUTTON_B;
	}
	if ((buttonWas == BUTTON_NONE) && (b != BUTTON_NONE)) {
		buttonJustPressed  = true;
		buttonJustReleased = false;
	}
	if ((buttonWas != BUTTON_NONE) && (b == BUTTON_NONE)) {
		buttonJustPressed  = false;
		buttonJustReleased = true;
	}
	buttonWas = b;
	return(b);
}
