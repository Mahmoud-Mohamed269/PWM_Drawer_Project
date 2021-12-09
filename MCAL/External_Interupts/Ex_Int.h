/*
 * Ex_Int.h
 *
 *  Created on: Oct 1, 2021
 *      Author: LENOVOOOO
 */

#ifndef MCAL_EXTERNAL_INTERUPTS_EX_INT_H_
#define MCAL_EXTERNAL_INTERUPTS_EX_INT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../../bit_math.h"

#define ENABLED 1
#define DISABLED 0
#define EXTI_INT0 ENABLED
#define EXTI_INT1 DISABLED
#define EXTI_INT2 DISABLED

#define LOW_LEVEL 0
#define BOTH_EDGES 1
#define FALLING_EDGE 2
#define RAISING_EDGE 3
#define EXTI_INT0_EDGE  BOTH_EDGES
#define EXTI_INT1_EDGE  BOTH_EDGES
#define EXTI_INT2_EDGE  BOTH_EDGES

void init_interrupt();
void init_int0();
void (*p1)();
void set_cb_int0();
void set_cb_int1();
void set_cb_int2();
#endif /* MCAL_EXTERNAL_INTERUPTS_EX_INT_H_ */
