#ifndef _PAD_H
#define _PAD_H
	#if defined(ARDUINO) && ARDUINO >= 100
		#include <Arduino.h>
	#else
		#include <WProgram.h>
	#endif
	class Button {
		public:
			#define NONE_10BIT_ADC		1023
			#define UP_10BIT_ADC		634
			#define RIGHT_10BIT_ADC		231
			#define DOWN_10BIT_ADC		386
			#define LEFT_10BIT_ADC		692
			#define A_10BIT_ADC			70
			#define B_10BIT_ADC			1
			#define BUTTONHYSTERESIS	10
			#define BUTTON_ADC_PIN		A1
			#define BUTTON_NULL			99
			#define BUTTON_NONE			0 
			#define BUTTON_UP			1 
			#define BUTTON_RIGHT		2 
			#define BUTTON_DOWN			3 
			#define BUTTON_LEFT			4 
			#define BUTTON_A			5
			#define BUTTON_B			6
			#define STATE_OFF			0
			#define STATE_UP			1
			#define STATE_DOWN			2
			#define STATE_ON			3
			byte buttonJustPressed;
			byte buttonJustReleased;
			byte buttonWas;
			unsigned int voltage;
			byte id;
			byte id_last;
			void init();
			void update();
		private:
			byte read();
	};
#endif

