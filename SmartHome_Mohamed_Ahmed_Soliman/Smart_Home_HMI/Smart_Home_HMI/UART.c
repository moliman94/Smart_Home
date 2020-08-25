/*
 * UART.c
 *
 * UART driver for ATmeaga32 microcontroller
 * F_CPU = 16MHz
 *
 * Created: 27-Apr-20 10:39:01 PM
 *  Author: Mohamed Soliman
 */ 

#include "UART.h"

void UART_init(uint32 baud)
{
	UCSRB |= (1<<RXEN)|(1<<TXEN);        //enable receiver and transmitter
	
	UBRRH &= ~(1<<URSEL);                 //selecting to write on UBRRH register
	if(baud == 4800)
		UBRRL = 207;
	else if(baud == 9600)
		UBRRL = 103;
	else if(baud == 19200)
		UBRRL = 51;
	else if(baud == 28800)
		UBRRL = 34;
	else if(baud == 115200)
		UBRRL = 8;
	
	UCSRC |= (1<<URSEL);                 //selecting to write on UCSRC register
	UCSRC &= ~(1<<UMSEL);                //selecting Async. mode
	UCSRC &= ~((1<<UPM1)|(1<<UPM0));     //disable parity mode
	UCSRC &= ~(1<<USBS);                 //selecting one stop bit
	
	//selecting 8-bit data 
	UCSRB &= ~(1<<UCSZ2);
	UCSRC |= (1<<UCSZ1)|(1<<UCSZ0);
}

void UART_send_char(uint8 data)
{
	while(!(UCSRA & (1<<UDRE)));     //wait for transmit buffer to be ready to receive new data
	UDR = data;
}

void UART_send_9bits(uint16 data)
{
	while(!(UCSRA & (1<<UDRE)));         //wait for transmit buffer to be ready to receive new data
	UCSRB &= ~(1<<TXB8);
	if (data & 0x0100)                   //monitor 9th bit
		UCSRB |= (1<<TXB8);
	/* Put data into buffer, sends the data */
	UDR = data;
}

uint8 UART_receive_char()
{
	while(!(UCSRA & (1<<RXC)));        //wait until there is data need to be read
	return UDR;
}

uint8 UART_receive_9bits()
{
	uint8 resh, resl;
	
	while(!(UCSRA & (1<<RXC)));             /* Wait for data to be received */
	
	/* Get status and 9th bit, then data */
	/* from buffer */
	resh = UCSRB;
	resl = UDR;
	
	/* Filter the 9th bit, then return */
	resh = (resh>>1) & 0x01;
	
	return ((resh<<8) | resl);
}

void UART_send_string(uint8 *str)
{
	uint8 i = 0;
	while(str[i] != '\0')
	{
		UART_send_char(str[i]);
		i++;
	}
	//UART_send_char(str[i]);   //send NULL character
}

void UART_receive_string(uint8 *str)
{
	uint8 temp = 0;
	do
	{
		temp = UART_receive_char();
		*str = temp;
		str++;
	}while(temp != '#');
	
	str--;
	*str = '\0';
}
