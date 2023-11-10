/*
 * PIR_interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: dell
 */

#ifndef HAL_PIR_PIR_INTERFACE_H_
#define HAL_PIR_PIR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "PIR_Types.h"
#include "PIR_config.h"
#include "PIR_privite.h"
#include "PIR_register.h"

 /* PIR initialization */
E_ErrorType HAL_PIR_Init ();

/* Read PIR */
E_ErrorType HAL_PIR_Read ();



#endif /* HAL_PIR_PIR_INTERFACE_H_ */
