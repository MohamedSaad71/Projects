/*
 * LM35_Interface.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_


#include "LM35_Config.h"
#include "LM35_Private.h"
#include "LM35_Registers.h"
#include "LM35_Types.h"

/* Function that reads the temperature value */
LM35_TempValue HAL_LM35_readTemp(LM35_ADC_val);


#endif /* LM35_INTERFACE_H_ */
