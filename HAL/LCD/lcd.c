/*
 * lcd.c
 *
 *  Created on: Sep 24, 2021
 *      Author: LENOVOOOO
 */
#include "lcd.h"

void lcd_send_ch(unsigned char data) {
	DIO_WRITE(RS, HIGH);
	DIO_WRITE(RW, LOW);
	if (GET_BIT(data, 4)) {DIO_WRITE(D4, HIGH);}else{DIO_WRITE(D4, LOW);}
	if (GET_BIT(data, 5)) {DIO_WRITE(D5, HIGH);}else {DIO_WRITE(D5, LOW);}
	if (GET_BIT(data, 6)) {DIO_WRITE(D6, HIGH);}else {DIO_WRITE(D6, LOW);}
	if (GET_BIT(data, 7)) {DIO_WRITE(D7, HIGH);}else {DIO_WRITE(D7, LOW);}
	DIO_WRITE(E, HIGH);
	_delay_us(10);
	DIO_WRITE(E, LOW);
	_delay_us(200);

	if (GET_BIT(data, 0)) {DIO_WRITE(D4, HIGH);}else {DIO_WRITE(D4, LOW);}
	if (GET_BIT(data, 1)) {DIO_WRITE(D5, HIGH);}else {DIO_WRITE(D5, LOW);}
	if (GET_BIT(data, 2)) {DIO_WRITE(D6, HIGH);}else {DIO_WRITE(D6, LOW);}
	if (GET_BIT(data, 3)) {DIO_WRITE(D7, HIGH);}else {DIO_WRITE(D7, LOW);}
	DIO_WRITE(E, HIGH);
	_delay_us(10);
	DIO_WRITE(E, LOW);
	_delay_us(200);

}
void lcd_send_cmd(unsigned char cmd) {
	DIO_WRITE(RS, LOW);
	DIO_WRITE(RW, LOW);

	if (GET_BIT(cmd, 4)) {DIO_WRITE(D4, HIGH);}else {DIO_WRITE(D4, LOW);}
	if (GET_BIT(cmd, 5)) {DIO_WRITE(D5, HIGH);}else {DIO_WRITE(D5, LOW);}
	if (GET_BIT(cmd, 6)) {DIO_WRITE(D6, HIGH);}else {DIO_WRITE(D6, LOW);}
	if (GET_BIT(cmd, 7)) {DIO_WRITE(D7, HIGH);}else {DIO_WRITE(D7, LOW);}
	DIO_WRITE(E, HIGH);
	_delay_us(10);
	DIO_WRITE(E, LOW);
	_delay_us(2000);

	if (GET_BIT(cmd, 0)) {DIO_WRITE(D4, HIGH);}else {DIO_WRITE(D4, LOW);}
	if (GET_BIT(cmd, 1)) {DIO_WRITE(D5, HIGH);}else {DIO_WRITE(D5, LOW);}
	if (GET_BIT(cmd, 2)) {DIO_WRITE(D6, HIGH);}else {DIO_WRITE(D6, LOW);}
	if (GET_BIT(cmd, 3)) {DIO_WRITE(D7, HIGH);}else {DIO_WRITE(D7, LOW);}
	DIO_WRITE(E, HIGH);
	_delay_us(10);
	DIO_WRITE(E, LOW);
	_delay_us(2000);

}
void lcd_init(void) {
	_delay_ms(20);
	lcd_send_cmd(0x33);
	lcd_send_cmd(0x32); //send for 4 bit initialization of lcd
	lcd_send_cmd(0x28); //select 4 bit mode, 5*7 dots
	lcd_send_cmd(0x0f); //display on, cursor blinking
	lcd_send_cmd(0x06); //entry mode increment cursor to right
	lcd_send_cmd(0x01); //clear display
}
void lcd_send_str(char *string) {
	int i;
	for(i=0;string[i]!=0;i++)
		lcd_send_ch(string[i]);
}
void Cursor_pos(unsigned char x_pos, unsigned char y_pos){
	int add = 0;
	if(x_pos == 0)
		add = 0x80;
	else if(x_pos == 1)
		add = 0xc0;
	if(y_pos < 16)
		add += y_pos;
	lcd_send_cmd(add);
}
