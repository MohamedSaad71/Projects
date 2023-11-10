/*
 * TempControl.h
 *
 *  Created on: 6 Nov 2023
 *      Author: Ayaya
 */

#ifndef TEMPCONTROL_H_
#define TEMPCONTROL_H_

#include "../../HAL/LM35/LM35_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/DC TRIAL/DC TRIAL/DCMOTOR_Interface.h"

// Include the dc motor too

#define LOW_TEMP  	23
#define MED_TEMP 	28
#define HIGH_TEMP	32

#define AC_LED_PORT	PORTA_ID
#define AC_LED_PIN	PIN4_ID


void SERVICE_TempControl(void);

#endif /* TEMPCONTROL_H_ */
