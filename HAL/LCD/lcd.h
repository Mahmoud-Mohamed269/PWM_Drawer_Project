/*
 * lcd.h
 *
 *  Created on: Sep 24, 2021
 *      Author: LENOVOOOO
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
#include "../../bit_math.h"
void lcd_send_ch(unsigned char data);
void lcd_send_cmd(unsigned char cmd);
void lcd_init(void);
void lcd_send_str(char* string);
void Cursor_pos(unsigned char x_pos, unsigned char y_pos);
void lcd_clear (void);
#endif /* HAL_LCD_LCD_H_ */
