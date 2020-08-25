/*
 * Smart_Home_HMI.c
 *
 * Created: 24-Aug-20 2:20:16 PM
 * Author : Mohamed Soliman
 */ 

#include <avr/io.h>
#include "HMI_config.h"
#include "Std_messages.h"
#include "Std_macros.h"
#include "BLUETOOTH.h"
#include "SPI.h"

int main(void)
{
	//-------------Initializations-------------------
	SPI_master_init();
	Bluetooth_init();

	uint8 messageID;
	
	//-----------Periodic code-----------------------
    while (1) 
    {
		//Read the bluetooth received message from mobile phone
		messageID = Bluetooth_receive();
		
		switch(messageID)
		{
			case ROOM1_TURN_ON:
			SPI_send_char(ROOM1_TURN_ON);
			break;
			
			case ROOM1_TURN_OFF:
			SPI_send_char(ROOM1_TURN_OFF);
			break;
			
			case ROOM2_TURN_ON:
			SPI_send_char(ROOM2_TURN_ON);
			break;
			
			case ROOM2_TURN_OFF:
			SPI_send_char(ROOM2_TURN_OFF);
			break;
			
			case DOOR_OPEN:
			SPI_send_char(DOOR_OPEN);
			break;
			
			case DOOR_CLOSE:
			SPI_send_char(DOOR_CLOSE);
			break;
		}	
    }
}

