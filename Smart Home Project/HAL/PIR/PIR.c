/*
 * PIR.c

 *
 *  Created on: Nov 5, 2023
 *      Author: dell
 */


#include "PIR_interface.h"

/* PIR initialization */
E_ErrorType HAL_PIR_Init ()
{
	/* u8LocalReturn  is local variable */
	E_ErrorType u8LocalReturn =E_NOT_OK;
	/* PIR_interface is structure used to define port and pin and direction for output pin */
	S_Dio PIR_interface;
	/* PIR port */
	PIR_interface.port_num=PIR_port;
	/* PIR pin */
	PIR_interface.pin_num=PIR_pin;
	/* Direction of output pin */
	PIR_interface.Direction=INPUT;
	/* DIO initialization  */
	u8LocalReturn=MCAL_Dio_Init(&PIR_interface);
	/* Set pin direction for PIR output pin */
	u8LocalReturn= MCAL_Dio_SetPinDirection(&PIR_interface);
	return E_OK;
}

/* Read PIR */
E_ErrorType HAL_PIR_Read (u8PinValue *pin_value)
{
	/* u8LocalReturn  is local variable */
	E_ErrorType u8LocalReturn =E_NOT_OK;
	/* PIR_interface is structure used to define port and pin and direction for output pin */
	S_Dio PIR_interface;
	/* PIR port */
	PIR_interface.port_num=PIR_port;
	/* PIR pin */
	PIR_interface.pin_num=PIR_pin;
	/* Read the value of the PIR output pin */
	u8LocalReturn= MCAL_Dio_ReadSinglePin(&PIR_interface,PIR_interface.pin_num,pin_value);
	return E_OK;

}
