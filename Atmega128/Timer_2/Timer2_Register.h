/*
 * Timer2_Register.h
 *
 *  Created on: Nov 25, 2023
 *      Author: EVA
 */

#ifndef TIMER_2_TIMER2_REGISTER_H_
#define TIMER_2_TIMER2_REGISTER_H_



#define TCCR2	*((volatile unsigned char*)(0x45))
#define TCNT2	*((volatile unsigned char*)(0x44))
#define OCR2	*((volatile unsigned char*)(0x43))

#endif /* TIMER_2_TIMER2_REGISTER_H_ */
