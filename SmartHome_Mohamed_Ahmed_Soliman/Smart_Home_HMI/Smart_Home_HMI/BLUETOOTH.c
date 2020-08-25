/*
 * BLUETOOTH.c
 *
 * Created: 25-Aug-20 11:16:24 AM
 *  Author: Mohamed Soliman
 */ 


#include "BLUETOOTH.h"

void Bluetooth_init(void)
{
	UART_init(BAUDRATE);
}

uint8 Bluetooth_receive(void)
{
	return UART_receive_char();
}