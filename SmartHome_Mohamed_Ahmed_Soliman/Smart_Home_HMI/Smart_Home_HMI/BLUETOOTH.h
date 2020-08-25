/*
 * BLUETOOTH.h
 *
 * Bluetooth driver for ATmeaga32 microcontroller
 *
 * Created: 25-Aug-20 11:05:36 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

//------ Public function prototypes -------------------------------

#include "Std_macros.h"
#include "HMI_config.h"
#include "UART.h"

void Bluetooth_init(void);
uint8 Bluetooth_receive(void);

#endif /* BLUETOOTH_H_ */