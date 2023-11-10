/*
 * Check_IR.h
 *
 *  Created on: 6 Nov 2023
 *      Author: Ayaya
 */

#ifndef CHECK_IR_H_
#define CHECK_IR_H_

#include "../../HAL/IR/IR_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../EVERYTHING_ON/EverythingOn.h"

#define LIVING_LED_PORT	PORTA_ID
#define LIVING_LED_PIN	PIN5_ID

unsigned char c;


void SERVICE_Check_IR();

#endif /* CHECK_IR_H_ */
