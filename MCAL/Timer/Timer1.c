/*
 * Timer1.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Mahmoud
 */
#include "Timer1.h"
void Timer1_init() {
#if TIMER1_MODE == TIMER1_NORMAL
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_8
	SET_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_9
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_10
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_CTC
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_FAST_8
	SET_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_FAST_9
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM12);
#elif TIMER1_MODE == TIMER1_PWM_FAST_10
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, CS10);
#endif

#if TIMER1_COMPARE_OUTPUT == COM_OUT_DIS
	CLR_BIT(TCCR1A, COM1A0);
	CLR_BIT(TCCR1A, COM1A1);
#elif TIMER1_COMPARE_OUTPUT == COM_OUT_TOG
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif TIMER1_COMPARE_OUTPUT == COM_OUT_CLR
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#elif TIMER1_COMPARE_OUTPUT == COM_OUT_SET
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif

#if TIMO_PRES == TIMO_NO_CLK
	CLR_BIT(TCCR1, CS10);
	CLR_BIT(TCCR1, CS11);
	CLR_BIT(TCCR1, CS12);
#elif TIMO_PRES == TIMO_NO_PRES
	SET_BIT(TCCR1A, 0);
	CLR_BIT(TCCR1A, 1);
	CLR_BIT(TCCR1A, 2);
#elif TIMO_PRES == TIMO_8_PRES
	CLR_BIT(TCCR1, 0);
	SET_BIT(TCCR1, 1);
	CLR_BIT(TCCR1, 2);
#elif TIMO_PRES == TIMO_64_PRES
	SET_BIT(TCCR1, 0);
	SET_BIT(TCCR1, 1);
	CLR_BIT(TCCR1, 2);
#elif TIMO_PRES == TIMO_256_PRES
	CLR_BIT(TCCR1A, 0);
	CLR_BIT(TCCR1A, 1);
	SET_BIT(TCCR1A, 2);
#elif TIMO_PRES == TIMO_1024_PRES
	SET_BIT(TCCR1A, 0);
	CLR_BIT(TCCR1A, 1);
	SET_BIT(TCCR1A, 2);
#endif
}
void Timer_PWM() {
	//fast PWM mode
	//CS10 = 1 (NO Prescaler)
	//CTC mode is enabled
	OCR1A = 800;
	OCR1B = 0;
}
void Freq_Duty(uint8t a, uint8t b, uint8t c, uint8t h, uint8t p, long *f, float *d)
{
	TCCR1A = 0;
	TCNT1 = 0;
	TIFR = (1 << ICF1); /* Clear ICF (Input Capture flag) flag */

	TCCR1B = 0x41; /* Rising edge, no prescaler */
	while ((TIFR & (1 << ICF1)) == 0)
		;
	a = ICR1; /* Take value of capture register */
	SET_BIT(TIFR, ICF1); /* Clear ICF flag */

	TCCR1B = 0x01; /* Falling edge, no prescaler */
	while ((TIFR & (1 << ICF1)) == 0)
		;
	b = ICR1; /* Take value of capture register */
	SET_BIT(TIFR, ICF1); /* Clear ICF flag */

	TCCR1B = 0x41; /* Rising edge, no prescaler */
	while ((TIFR & (1 << ICF1)) == 0)
		;
	c = ICR1; /* Take value of capture register */
	SET_BIT(TIFR, ICF1); /* Clear ICF flag */

	TCCR1B = 0; /* Stop the timer */

if(a<b && b<c) /* Check for valid condition,
 to avoid timer overflow reading */
{
	h=b-a;
	p=c-a;
	*f= F_CPU/p;
	*d =((float) h /(float)p)*100;}
}
