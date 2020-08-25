/*
 * HMI_config.h
 *
 * Created: 25-Aug-20 11:13:30 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef HMI_CONFIG_H_
#define HMI_CONFIG_H_

#include "Std_macros.h"

// Misc #defines
#ifndef TRUE
#define FALSE 0
#define TRUE (!FALSE)
#endif

#define NULL (0)

#define RETURN_NORMAL  0
#define RETURN_ERROR   1

//----------BLUETOOTH CONFIGURATION----------------
#define BAUDRATE (uint32)9600





#endif /* HMI_CONFIG_H_ */