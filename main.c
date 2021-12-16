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
uint8t fir_raise, fir_fall, sec_raise, high, period;
long freq;
float duty_cycle;
char frequency[14], duty[7];
int main() {
	dio_init();
	lcd_init();
	lcd_send_cmd(0x80); //moves the cursor to start from first row
	lcd_send_str("Freq=");
	lcd_send_cmd(0xC0); //moves the cursor to the second row
	lcd_send_str("Duty=");
	Cursor_pos(0, 6);
	Timer1_init();
	Timer_PWM();
	while (1) {

		Freq_Duty(fir_raise, fir_fall, sec_raise, high, period, &freq, &duty_cycle);
		ltoa(freq, frequency, 10);
		itoa((int) duty_cycle, duty, 10);

		lcd_send_str(frequency);
		lcd_send_str(" Hz");
		lcd_send_cmd(0xC0); //moves the cursor to the second row
		Cursor_pos(0, 6);
		lcd_send_str(duty);
		lcd_send_str(" %");

	}

	return 0;
}
