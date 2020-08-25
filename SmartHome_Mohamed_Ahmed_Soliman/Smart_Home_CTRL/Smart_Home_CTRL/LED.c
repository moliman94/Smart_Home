/*
 * LED.c
 *
 * Created: 25-Aug-20 2:39:08 PM
 *  Author: Mohamed Soliman
 */ 

#include "LED.h"

void LED_init(void)
{
	SETBIT(LED1_DIR, LED1_PIN);        //set LED1 pin as output
	SETBIT(LED2_DIR, LED2_PIN);        //set LED2 pin as output
}

void LED1_On(void)
{
	SETBIT(LED1_PORT, LED1_PIN);
}
void LED1_Off(void)
{
	CLRBIT(LED1_PORT, LED1_PIN);
}
void LED1_Tog(void)
{
	TOGBIT(LED1_PORT, LED1_PIN);
}
void LED2_On(void)
{
	SETBIT(LED2_PORT, LED2_PIN);
}
void LED2_Off(void)
{
	CLRBIT(LED2_PORT, LED2_PIN);
}
void LED2_Tog(void)
{
	TOGBIT(LED2_PORT, LED2_PIN);
}