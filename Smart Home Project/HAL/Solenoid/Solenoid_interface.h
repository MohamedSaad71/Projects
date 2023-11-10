/*
 * Solenoid_interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: dell
 */

#ifndef HAL_SOLENOID_SOLENOID_INTERFACE_H_
#define HAL_SOLENOID_SOLENOID_INTERFACE_H_
#include"../../MCAL/DIO/DIO_interface.h"
#include "Solenoid_Types.h"
#include "Solenoid_config.h"
#include "Solenoid_private.h"
#include "Solenoid_register.h"

/* Solenoid initialization */
E_ErrorType HAL_Solenoid_init();
/* Open solenoid */
E_ErrorType HAL_Solenoid_Open();
/* Close the solenoid */
E_ErrorType HAL_Solenoid_Close( );


#endif /* HAL_SOLENOID_SOLENOID_INTERFACE_H_ */
