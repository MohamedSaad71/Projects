/*
 * Timer2_Interface.h
 *
 *  Created on: Nov 25, 2023
 *      Author: EVA
 */

#ifndef TIMER_2_TIMER2_INTERFACE_H_
#define TIMER_2_TIMER2_INTERFACE_H_


#include "Timer2_Config.h"
#include"Timer2_Private.h"
#include "Timer2_Register.h"
#include "Timer2_Types.h"
#include"../common_Files/common_macros.h"

Timer2_Error TIMER2_INIT(Prescaler_Value PRE,DutyCycle Duty);

#endif /* TIMER_2_TIMER2_INTERFACE_H_ */
