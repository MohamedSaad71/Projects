/*
 * Timer0_types.h
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_


typedef unsigned char E_Timer0ErrorType;
typedef unsigned char u8CompareValue;
typedef unsigned char u8DutyCyle;


typedef enum
{
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024
}E_Prescaler;


#define E_OK 0
#define E_NOT_OK 1




#define TIMER0_STATUS_ERROR E_OK

#endif /* TIMER0_TYPES_H_ */
