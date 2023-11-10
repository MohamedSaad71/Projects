/*
 * Timer0_interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#include "common_macros.h"
#include "Timer0_config.h"
#include "Timer0_register.h"
#include "Timer0_private.h"
#include "Timer0_types.h"





/***********************************************************
 *
 *                   Functions Prototypes
 *
 **********************************************************/

/***********************
 *  Timer0 Init for OverFlow Mode
 ***********************/



E_Timer0ErrorType MCAL_Timer0_OVF_Init(E_Prescaler prescaler);

E_Timer0ErrorType MCAL_Timer0_CTC_Init(E_Prescaler prescaler,u8CompareValue CompareValue);

E_Timer0ErrorType MCAL_Timer0_FastPWM_Init(E_Prescaler prescaler,u8DutyCyle Duty_Cycle);

E_Timer0ErrorType MCAL_Timer0_PCPWM_Init(E_Prescaler prescaler,u8DutyCyle Duty_Cycle);

#endif /* TIMER0_INTERFACE_H_ */
