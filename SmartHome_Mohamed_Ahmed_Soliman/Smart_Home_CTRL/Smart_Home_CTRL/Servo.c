/*
 * Servo.c
 *
 * Created: 25-Aug-20 3:27:56 PM
 *  Author: Mohamed Soliman
 */ 


#include "Servo.h"

#define NO_TICKS_MS(time_in_ms)	(((float)time_in_ms*F_CPU)/(1000*PRESCALER)-1)

uint8 door_status = DOOR_CLOSED;

void servo_init(void)
{
	SETBIT(SERVO_PORT, SERVO_PIN);
	timer_1A_ctc_init();
	timer_1A_start();
}


/*
 * Using Timer1 CTC mode to create custom PWM with period 20ms
 *
 * because servo motor operated with PWM period 20ms
 * for 0   degree ---> T_high = 1 ms
 * T_high = 1ms, T_low = 19ms
 * T_high_count = (1ms * F_CPU)/Prescaler - 1 = (1ms * 16MHz)/8 - 1 = 1999
 * T_low_count  = (19ms * F_CPU)/Prescaler - 1 = (19ms * 16MHz)/8 - 1 = 37999
 
 * for 90  degree ---> T_high = 1.5 ms
 * T_high = 1.5ms, T_low = 18.5ms
 * T_high_count = (1.5ms * F_CPU)/Prescaler - 1 = (1.5ms * 16MHz)/8 - 1 = 2999
 * T_low_count  = (18.5ms * F_CPU)/Prescaler - 1 = (18.5ms * 16MHz)/8 - 1 = 36999
 
 * for 180 degree ---> T_high = 2 ms
  * T_high = 2ms, T_low = 18ms
  * T_high_count = (2ms * F_CPU)/Prescaler - 1 = (2ms * 16MHz)/8 - 1 = 3999
  * T_low_count  = (18ms * F_CPU)/Prescaler - 1 = (18ms * 16MHz)/8 - 1 = 35999
 */

ISR(TIMER1_COMPA_vect)
{
	static uint8 open_door_flag = 0;
	static uint8 closed_door_flag = 0;
	
	//Open the door
	//Servo go to 0 degree
	if(door_status == DOOR_CLOSED)
	{
		if(open_door_flag)
		{
			open_door_flag = 0;
			OCR1A = NO_TICKS_MS(19);
		}
		else
		{
			open_door_flag = 1;
			OCR1A = NO_TICKS_MS(1);
		}
	}
	
	//Close the door
	//Servo go to 90 degree
	else if(door_status == DOOR_OPENED)
	{
		if(closed_door_flag)
		{
			closed_door_flag = 0;
			OCR1A = NO_TICKS_MS(18.5);
		}
		else
		{
			closed_door_flag = 1;
			OCR1A = NO_TICKS_MS(1.5);
		}
	}
}