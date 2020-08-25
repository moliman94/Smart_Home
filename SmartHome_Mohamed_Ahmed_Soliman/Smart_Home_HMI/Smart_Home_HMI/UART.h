/*
 * UART.h
 *
 * UART driver for ATmeaga32 microcontroller
 * F_CPU = 16MHz
 *
 * Created: 27-Apr-20 10:39:18 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std_macros.h"

void UART_init(uint32 baud);

void UART_send_char(uint8 data);
void UART_send_9bits(uint16 data);

uint8 UART_receive_char();
uint8 UART_receive_9bits();

void UART_send_string(uint8 *str);
void UART_receive_string(uint8 *str);

void UART_flush();         //function to flush receiver buffer


#endif /* UART_H_ */