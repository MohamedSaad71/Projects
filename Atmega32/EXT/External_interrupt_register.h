/*
 * External_interrupt_register.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_EXT_EXTERNAL_INTERRUPT_REGISTER_H_
#define MCAL_EXT_EXTERNAL_INTERRUPT_REGISTER_H_


#define MCUCR *((volatile unsigned int *)0x55)
/* MCU control and status register */
#define MCUCSR *((volatile unsigned int *)0x54)
/* General interrupt control register */
#define GICR *((volatile unsigned int *)0x5B)
/* General interrupt flag register */
#define GIFR *((volatile unsigned int*)0x5A)
/* External interrupt 0 sense bits */
#define ISC00   0
#define ISC01   1
/* External interrupt 1 sense bits */
#define ISC10   2
#define ISC11   3
/* External interrupt 2 sense bits */
#define ISC2   6
/* External interrupt enable bits */
#define INT2    5
#define INT0    6
#define INT1    7


#endif /* MCAL_EXT_EXTERNAL_INTERRUPT_REGISTER_H_ */
