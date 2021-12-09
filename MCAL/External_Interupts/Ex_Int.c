/*
 * Ex_Int.c
 *
 *  Created on: Oct 1, 2021
 *      Author: LENOVOOOO
 */
#include "../External_Interupts/Ex_Int.h"

void init_interrupt(){
#if EXTI_INT0 == ENABLED
	GICR |= (1<<INT0);
#else
	GICR &= ~(1<<INT0);
#endif

#if EXTI_INT0_EDGE == LOW_LEVEL
	MCUCR &= ~(1<<ISC01);
	MCUCR &= ~(1<<ISC00);

#elif EXTI_INT0_EDGE == BOTH_EDGES
	MCUCR &= ~(1<<ISC01);
	MCUCR |= (1<<ISC00);

#elif EXTI_INT0_EDGE == FAILING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR & = (1<<ISC00);
#elif EXTI_INT0_EDGE == RAISING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR | = (1<<ISC00);
#endif

#if EXTI_INT1 == ENABLED
	GICR |= (1<<INT0);
#else
	GICR &= ~(1<<INT0);
#endif

#if EXTI_INT1_EDGE == LOW_LEVEL
	MCUCR &= ~(1<<ISC01);
	MCUCR &= ~(1<<ISC00);

#elif EXTI_INT1_EDGE == BOTH_EDGES
	MCUCR &= ~(1<<ISC01);
	MCUCR |= (1<<ISC00);

#elif EXTI_INT1_EDGE == FAILING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR & = (1<<ISC00);
#elif EXTI_INT1_EDGE == RAISING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR | = (1<<ISC00);
#endif

#if EXTI_INT2 == ENABLED
	GICR |= (1<<INT0);
#else
	GICR &= ~(1<<INT0);
#endif

#if EXTI_INT2_EDGE == LOW_LEVEL
	MCUCR &= ~(1<<ISC01);
	MCUCR &= ~(1<<ISC00);

#elif EXTI_INT2_EDGE == BOTH_EDGES
	MCUCR &= ~(1<<ISC01);
	MCUCR |= (1<<ISC00);

#elif EXTI_INT2_EDGE == FAILING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR & = (1<<ISC00);
#elif EXTI_INT2_EDGE == RAISING_EDGE
	MCUCR | = ~(1<<ISC01);
	MCUCR | = (1<<ISC00);
#endif
}

void init_int0(){
	SET_BIT(GICR,INT0); //Enable Interrupt 0
	//Make interrupt at any logical change
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
}

ISR(INT0_vect){
	p1();
}
ISR(INT1_vect){
	p1();
}
ISR(INT2_vect){
	p1();
}
void set_cb_int0(void(*p2)()){
	p1 = p2;
}
void set_cb_int1(void(*p2)()){
	p1 = p2;
}
void set_cb_int2(void(*p2)()){
	p1 = p2;
}
