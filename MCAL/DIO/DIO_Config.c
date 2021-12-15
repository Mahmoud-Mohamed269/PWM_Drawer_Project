/*
 * DIO_Config.c
 *
 *  Created on: Sep 17, 2021
 *      Author: LENOVOOOO
 */
#include "DIO_config.h"
pin_config_type pin_configs[] = {
		{DIO_PORTD, DIO_PIN4, OUTPUT},
		{DIO_PORTA, DIO_PIN1, INPUT},
		{DIO_PORTD, DIO_PIN6, INPUT},
		//LCD_PINS
		{DIO_PORTA, DIO_PIN4, OUTPUT},
		{DIO_PORTA, DIO_PIN6, INPUT},
		{DIO_PORTA, DIO_PIN5, OUTPUT},
		{DIO_PORTA, DIO_PIN6, OUTPUT},
		{DIO_PORTA, DIO_PIN7, OUTPUT},
		{DIO_PORTA, DIO_PIN1, INPUT},
		{DIO_PORTB, DIO_PIN1, OUTPUT},
		{DIO_PORTB, DIO_PIN2, OUTPUT},
		{DIO_PORTB, DIO_PIN3, OUTPUT}
	};
int n = sizeof(pin_configs) / sizeof(pin_configs[0]);
