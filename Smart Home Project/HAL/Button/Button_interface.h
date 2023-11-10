/*
 * Button_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include"../../MCAL/DIO/DIO_interface.h"
#include "Button_Types.h"
#include "Button_private.h"
#include "Button_register.h"


/* Initialize the Button */
E_ErrorType HAL_BUTTON_init( );
/* Read the button */
E_ErrorType HAL_BUTTON_read(u8PinValue *btn_state);
/* Set button as pull up */
E_ErrorType HAL_BUTTON_set_pullup();

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
