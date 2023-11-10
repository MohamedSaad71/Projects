/*
 * Check_IR.c
 *
 *  Created on: 6 Nov 2023
 *      Author: Ayaya
 */


#include "Check_IR.h"

void SERVICE_Check_IR()
{
	_delay_ms(1000);
	// Read the IR sensor
	char c = HAL_IR_Read();

	if (c == DETECTED) {
		// Object is detected
		// LED on
		HAL_LED_ON(LIVING_LED_PORT, LIVING_LED_PIN);
		//Set on flag
		SERVICE_SET_ON_FLAG();

	}
	else
	{
		// Object is not detected
	}
	_delay_ms(100); // Delay to prevent rapid readings
}
