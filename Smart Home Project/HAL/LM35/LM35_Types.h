/*
 * LM35_Types.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ayaya
 */

#ifndef LM35_TYPES_H_
#define LM35_TYPES_H_


/* Temperature value */
typedef unsigned char LM35_TempValue;
/* Adc value on the channel */
typedef unsigned short int LM35_ADC_val;
/* Error types */
typedef enum
{
	LM35_E_OK,
	LM35_E_NOT_OK
}E_LM35_ErrorType;


#endif /* LM35_TYPES_H_ */
