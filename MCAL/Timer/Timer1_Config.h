/*
 * Timer1_Config.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Mahmoud
 */

#ifndef MCAL_TIMER_TIMER1_CONFIG_H_
#define MCAL_TIMER_TIMER1_CONFIG_H_

//Prescalers
#define TIMO_NO_CLK  0
#define TIMO_NO_PRES 1
#define TIMO_8_PRES  2
#define TIMO_64_PRES 3
#define TIMO_256_PRES 4
#define TIMO_1024_PRES 5
#define TIMO_PRES  TIMO_NO_PRES

//mode
#define TIMER1_NORMAL 0
#define TIMER1_PWM_PHASE_CORRECT_8 1
#define TIMER1_PWM_PHASE_CORRECT_9 2
#define TIMER1_PWM_PHASE_CORRECT_10 3
#define TIMER1_CTC 4
#define TIMER1_PWM_FAST_8 5
#define TIMER1_PWM_FAST_9 6
#define TIMER1_PWM_FAST_10 7
#define TIMER1_MODE  TIMER1_CTC

//compare output mode
#define COM_OUT_DIS 0
#define COM_OUT_TOG 1
#define COM_OUT_CLR 2
#define COM_OUT_SET 3
#define TIMER1_COMPARE_OUTPUT  COM_OUT_DIS

#endif /* MCAL_TIMER_TIMER1_CONFIG_H_ */
