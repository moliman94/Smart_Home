/*
 * Smart_Home_CTRL.c
 *
 * Created: 24-Aug-20 2:22:19 PM
 * Author : Mohamed Soliman
 */ 

#include <avr/io.h>
#include "Std_messages.h"
#include "Std_macros.h"
#include "SPI.h"
#include "LED.h"
#include "Servo.h"

extern uint8 door_status;

int main(void)
{
    SPI_slave_init();
	LED_init();
	servo_init();
	
	uint8 messageID;
	

    while (1) 
    {
		messageID = SPI_receive_char();
		switch(messageID)
		{
			case ROOM1_TURN_ON:
			LED1_On();
			break;
			
			case  ROOM1_TURN_OFF:
			LED1_Off();
			break;
			
			case  ROOM2_TURN_ON:
			LED2_On();
			break;
			
			case  ROOM2_TURN_OFF:
			LED2_Off();
			break;
			
			case DOOR_OPEN:
			door_status = DOOR_OPENED;
			break;
			
			case DOOR_CLOSE:
			door_status = DOOR_CLOSED;
			break;
		}
		
    }
}

