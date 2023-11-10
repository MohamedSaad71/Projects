/*
 * LM35_Prog.c
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#include "LM35_Interface.h"


/* Function that reads the temperature value */
LM35_TempValue HAL_LM35_readTemp(LM35_ADC_val val)
{
	LM35_TempValue temp =0;
	/* Calculate the temperature from the ADC value */
	temp = (((500*val)/1023));
	/* Return the temperature value */
	return temp;
}
