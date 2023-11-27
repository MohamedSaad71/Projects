/*
 * Timer2_Types.h
 *
 *  Created on: Nov 25, 2023
 *      Author: EVA
 */

#ifndef TIMER_2_TIMER2_TYPES_H_
#define TIMER_2_TIMER2_TYPES_H_



/**************************************************/
typedef unsigned char Timer2_Error;
typedef unsigned char DutyCycle;
typedef unsigned char Prescaler_Value;
/**************************************************/

#define TIMER2_OK 		0
#define TIMER2_NOT_OK 	1


/**************************************************/


#define	Prescaler_8 		0
#define	Prescaler_64 		1
#define	Prescaler_256		2
#define	Prescaler_1024		3



/**************************************************/

/*
typedef enum
{
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024
} Prescaler_Value;
*/

#endif /* TIMER_2_TIMER2_TYPES_H_ */
