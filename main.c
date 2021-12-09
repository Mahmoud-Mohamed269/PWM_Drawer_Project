/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: LENOVOOOO
 */

#include <avr/io.h>
#include "bit_math.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/Timer/Timer1.h"
#include "HAL/LCD/lcd.h"
#include <util/delay.h>
#include <stdlib.h>

unsigned int first_rise, first_fall, second_rise, high, period;
char frequency[14] = { ' ' }, duty[7] = { ' ' };

int main() {
	dio_init();
	lcd_init();
	lcd_send_str("Freq=");
	lcd_send_cmd(0xC0);
	//move cursor to start from 2nd line
	lcd_send_str("Duty=");

	while (1) {
		TCCR1A = 0;
		TCNT1 = 0;
		TIFR = (1 << ICF1); // clear ICP flag (Input Capture flag)

		TCCR1B = 0x41; // rising edge, No prescaler
		while ((TIFR & (1 << ICF1)) == 0);

		first_rise = ICR1; // take value of capture register
		TIFR = (1 << ICF1); // clear ICP flag (Input Capture flag)

		TCCR1B = 0x01; // falling edge, No prescaler
		while ((TIFR & (1 << ICF1)) == 0)
			;
		first_fall = ICR1; // take value of capture register
		TIFR = (1 << ICF1); // clear ICP flag (Input Capture flag)

		TCCR1B = 0x41; // rising edge, No prescaler
		while ((TIFR & (1 << ICF1)) == 0)
			;
		second_rise = ICR1; // take value of capture register
		TIFR = (1 << ICF1); // clear ICP flag (Input Capture flag)

		TCCR1B = 0; // stop the timer

		if (first_rise < first_fall && first_fall < second_rise) {
			high = first_fall - first_rise;
			period = second_rise - first_rise;
		}
			long freq = 16000000 / period;
			int duty_cycle = ((float) high / (float) period) * 100;

			for (int i = 0; i < 12; i++) {
				frequency[i] = ' ';
			}
			Cursor_pos(0, 5);
			itoa(freq, frequency, 10); //frequency conversion
			for (int i = 0; i < 14; i++) {
				if (frequency[i] < '0' || frequency[i] > '9')
					lcd_send_ch(' ');
				else
					lcd_send_ch(frequency[i]);
			}

			for (int i = 0; i < 3; i++) {
				duty[i] = ' ';
			}
			Cursor_pos(1, 5);
			itoa(duty_cycle, duty, 10); //duty conversion
			for (int i = 0; i < 3; i++) {
				if (duty[i] < '0' || duty[i] > '9')
					lcd_send_ch(' ');
				else
					lcd_send_ch(duty[i]);
			}
			_delay_ms(250);

	}
		return 0;
	}
