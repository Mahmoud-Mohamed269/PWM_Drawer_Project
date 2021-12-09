/*
 * DIO.c
 *
 *  Created on: Sep 11, 2021
 *      Author: LENOVOOOO
 */
//0->PORTA
//1->PORTB
//2->PORTC
//3->PORTD
#include "DIO.h"
extern pin_config_type pin_configs[];
extern int n;
void DIO_WRITE(uint8 channel, uint8 state) {
	uint8 port_v = channel / 8;
	uint8 pin_num = channel % 8;
	switch (port_v) {
	case 0:
		if (state == 1)
			SET_BIT(PORTA, pin_num);
		else
			CLR_BIT(PORTA, pin_num);
		break;
	case 1:
		if (state == 1)
			SET_BIT(PORTB, pin_num);
		else
			CLR_BIT(PORTB, pin_num);
		break;
	case 2:
		if (state == 1)
			SET_BIT(PORTC, pin_num);
		else
			CLR_BIT(PORTC, pin_num);
		break;
	case 3:
		if (state == 1)
			SET_BIT(PORTD, pin_num);
		else
			CLR_BIT(PORTD, pin_num);
		break;
	}
}
state_type DIO_READ(uint8 channel) {
	Dio_port_type port_v = channel / 8;
	Dio_pin_type pin_num = channel % 8;
	state_type state = 0;
	switch (port_v) {
	case 0:
		state = GET_BIT(PINA, pin_num);
		break;
	case 1:
		state = GET_BIT(PINB, pin_num);
		break;
	case 2:
		state = GET_BIT(PINC, pin_num);
		break;
	case 3:
		state = GET_BIT(PIND, pin_num);
		break;
	default:
		state = -1;
		break;
	}
	return state;
}

void dio_init(void) {
	int i;
	for (i = 0; i < n; i++) {
		switch (pin_configs[i].port) {
		case DIO_PORTA:
			if (pin_configs[i].dir == OUTPUT)
				SET_BIT(DDRA, pin_configs[i].pin);
			else
				CLR_BIT(DDRA, pin_configs[i].pin);
			break;
		case DIO_PORTB:
			if (pin_configs[i].dir == OUTPUT)
				SET_BIT(DDRB, pin_configs[i].pin);
			else
				CLR_BIT(DDRB, pin_configs[i].pin);
			break;
		case DIO_PORTC:
			if (pin_configs[i].dir == OUTPUT)
				SET_BIT(DDRC, pin_configs[i].pin);
			else
				CLR_BIT(DDRC, pin_configs[i].pin);
			break;
		case DIO_PORTD:
			if (pin_configs[i].dir == OUTPUT)
				SET_BIT(DDRD, pin_configs[i].pin);
			else
				CLR_BIT(DDRD, pin_configs[i].pin);
			break;
		default:
			break;
		}
	}
}
