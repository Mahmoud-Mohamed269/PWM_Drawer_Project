/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: LENOVOOOO
 */

#include <avr/io.h>
#include "bit_math.h"
#include "type.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/Timer/Timer1.h"
#include "HAL/LCD/lcd.h"
#include <util/delay.h>
#include <stdlib.h>
#define F_CPU 16000000UL
uint8t a, b, c, high, period;
long freq;
float duty_cycle;
char frequency[14], duty[7];
int main() {
	dio_init();
	Timer1_init();
	lcd_init();
	Timer_PWM();

	lcd_send_cmd(0x80);
	lcd_send_str("Freq=");
	lcd_send_cmd(0xC0); //moves the cursor to the second row
	lcd_send_str("Duty=");

	while (1) {
		while (OCR1B <= 1022) { //turn LED on
			OCR1B += 1;
			_delay_ms(5);
		}
		_delay_ms(1000);
		while (OCR1B > 0) { //turn LED off
			OCR1B -= 1;
			_delay_ms(5);
		}
		_delay_ms(1000);

		Freq_Duty(a, b, c, high, period, &freq, &duty_cycle);
		ltoa(freq, frequency, 10);
		itoa((int) duty_cycle, duty, 10);

		Cursor_pos(0,6);
		lcd_send_str(frequency);
		lcd_send_str(" Hz");
		lcd_send_cmd(0xC0); //moves the cursor to the second row
		Cursor_pos(0,6);
		lcd_send_str(duty);
		lcd_send_str(" %");

	}

	return 0;
}
