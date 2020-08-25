/*
 * SPI.c
 *
 * SPI driver for ATmega32 microcontroller
 *
 * Created: 29-Apr-20 12:09:52 AM
 *  Author: Mohamed Soliman
 */ 

#include "SPI.h"

void SPI_master_init()
{
	//in master microcontroller
	//Setting MOSI, SCK, SS pins as outputs, MISO pin is overridden as input
	DDR_SPI |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	
	//enable SPI in master mode
	SPCR |= (1<<SPE)|(1<<MSTR);
	
	CLRBIT(SPCR, CPOL);       //make SCK low when idle state
	CLRBIT(SPCR, CPHA);       //sample data on leading edge
}

void SPI_slave_init()
{
	//in master microcontroller
	//Setting MISO pin as output, all other pins are overridden as input
	DDR_SPI |= (1<<MISO);
	
	//enable SPI
	SPCR |= (1<<SPE);
	
	CLRBIT(SPCR, CPOL);       //make SCK low when idle state
	CLRBIT(SPCR, CPHA);       //sample data on leading edge
}

void SPI_send_char(uint8 data)
{
	SPDR = data;
	while(READBIT(SPSR, SPIF) == 0);   //wait for transmission complete
}

uint8 SPI_receive_char()
{
	while(READBIT(SPSR, SPIF) == 0);   //wait for reception complete
	return SPDR;
}