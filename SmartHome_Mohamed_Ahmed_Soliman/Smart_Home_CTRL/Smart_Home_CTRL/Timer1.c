/*
 * Timer1.c
 *
 * Created: 25-Aug-20 5:17:25 PM
 *  Author: Mohamed Soliman
 */ 

#include "Timer1.h"

void timer_1A_ctc_init()
{
	SETBIT(DDRD, PD5);
	// Toggle OC1A on compare match COM1A1:0 --> ob01
	SETBIT(TCCR1A, COM1A0); 
	
	SETBIT(TCCR1A, FOC1A);
	
	//Select CTC mode
	SETBIT(TCCR1B, WGM12);
	
	//Output Compare A Match Interrupt Enable
	SETBIT(TIMSK, OCIE1A);
	
	//Enable global interrupt
	SETBIT(SREG, 7);
}

void timer_1A_start()
{
	TCCR1B &= ~((1<<CS12)|(1<<CS11)|(1<<CS10));
	
#if PRESCALER == 8
	SETBIT(TCCR1B, CS11);
#endif

}
void timer_1A_stop()
{
	TCCR1B &= ~((1<<CS12)|(1<<CS11)|(1<<CS10));
}