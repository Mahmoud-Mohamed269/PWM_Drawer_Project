/*
 * Timer1.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Mahmoud
 */

#ifndef MCAL_TIMER_TIMER1_H_
#define MCAL_TIMER_TIMER1_H_

#include <avr/io.h>
#include "../../bit_math.h"
#include "Timer1_Config.h"
#include "../External_Interupts/EX_Int.h"
#include <avr/interrupt.h>
void Timer1_init();
void Timer_PWM(void);
#endif /* MCAL_TIMER_TIMER1_H_ */
