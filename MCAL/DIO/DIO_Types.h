/*
 * DIO_Types.h
 *
 *  Created on: Sep 17, 2021
 *      Author: LENOVOOOO
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

typedef enum{
	LOW,
	HIGH
}state_type;

typedef enum{
	//port A
	PINA_0,
	PINA_1,
	Relay,
	Buzzer,
	D4,
	D5,
	D6,
	D7,

	//port B
	Button_0,
	RS,
	RW,
	E,
	SS,
	MOSI,
	MISO,
	SCK,

	//port C
	SCL,
	SDA,
	LED_0,
	A1,
	A2,
	A3,
	A4,
	LED1,

	//port D
	RX,ROW0=24,
	TX,ROW1=25,
	Button2,ROW2=26,
	LED_2,ROW3=27,
	EN1,COL0=28,
	EN2,COL1=29,
	Button1,COL2=30,
	SERVO,COL3=31
}channel_type;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}Dio_port_type;

typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}Dio_pin_type;

typedef enum{
	INPUT,
	OUTPUT
}Dio_Dir_type;

typedef enum{
	ORG_1,
	YEL_2,
	PINK_3,
	BLU_4
}steper;

typedef enum{
	M1,
	M2,
	M3,
	M4
}dc_m;
#endif /* MCAL_DIO_DIO_TYPES_H_ */
