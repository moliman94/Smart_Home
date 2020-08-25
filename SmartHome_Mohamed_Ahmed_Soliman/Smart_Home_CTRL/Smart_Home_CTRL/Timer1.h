/*
 * Timer1.h
 *
 * Created: 25-Aug-20 5:16:24 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "Std_macros.h"

#define PRESCALER 8

void timer_1A_ctc_init();
void timer_1A_start();
void timer_1A_stop();

#endif /* TIMER1_H_ */