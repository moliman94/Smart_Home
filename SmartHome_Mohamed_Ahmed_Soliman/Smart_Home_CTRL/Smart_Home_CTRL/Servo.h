/*
 * Servo.h
 *
 * Created: 25-Aug-20 3:27:34 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "Std_macros.h"
#include "Timer1.h"

#define SERVO_PORT PORTD
#define SERVO_PIN  PD5

#define DOOR_OPENED 0
#define DOOR_CLOSED 1

void servo_init(void);

#endif /* SERVO_H_ */