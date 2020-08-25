/*
 * LED.h
 *
 * Created: 25-Aug-20 2:38:42 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef LED_H_
#define LED_H_

#include "Std_macros.h"

#define LED1_PORT PORTC
#define LED1_DIR  DDRC
#define LED1_PIN  PC1

#define LED2_PORT PORTD
#define LED2_DIR  DDRD
#define LED2_PIN  PD2

void LED_init(void);
void LED1_On(void);
void LED1_Off(void);
void LED1_Tog(void);
void LED2_On(void);
void LED2_Off(void);
void LED2_Tog(void);



#endif /* LED_H_ */