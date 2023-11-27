/*
 * Timer0_Register.h
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TCCR0	*((volatile unsigned char *)(0x53))
#define TCNT0	*((volatile unsigned char*)(0x52))
#define TIMSK	*((volatile unsigned char*)(0x59))
#define TIFR	*((volatile unsigned char*)(0x58))
#define OCR0	*((volatile unsigned char*)(0x5C))



#endif /* TIMER0_REGISTER_H_ */
