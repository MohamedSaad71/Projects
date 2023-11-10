/*
 * Keypad_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "Keypad_Types.h"
#include "Keypad_registers.h"
#include "Keypad_private.h"


/****************************************Functions Prototypes******************************/

 /* Initialization function for keypad */
E_ErrorType HAL_KPD_init(void);
/* Function to get the pressed key */
u8PinValue HAL_KPD_getKey(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
