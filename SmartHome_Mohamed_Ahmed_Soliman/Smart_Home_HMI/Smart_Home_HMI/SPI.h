/*
 * SPI.h
 * 
 * SPI driver for ATmega32 microcontroller
 * Created: 29-Apr-20 12:10:14 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Std_macros.h"

#define DDR_SPI DDRB
#define SS PB4
#define MOSI PB5
#define MISO PB6
#define SCK PB7

void SPI_master_init();
void SPI_slave_init();
void SPI_send_char(uint8 data);
uint8 SPI_receive_char();



#endif /* SPI_H_ */