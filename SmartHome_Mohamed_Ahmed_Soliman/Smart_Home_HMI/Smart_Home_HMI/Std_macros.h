/*
 * Std_macros.h
 *
 * Created: 07-Mar-20 11:51:02 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>

#define SETBIT(REG,BIT)  (REG |= 1<<BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1<<BIT)
#define READBIT(REG,BIT) ((REG>>BIT) & 1)

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;

typedef signed char  sint8;
typedef signed short sint16;
typedef signed long  sint32;




#endif /* HEADER_H_ */