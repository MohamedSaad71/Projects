/*
 * Timer0_config.h
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "../DIO/DIO_interface.h"

#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7
#define WGM11   1


/* TIMSK Register */
#define TOIE0	0
#define OCIE0	1

/* TIFR Register */
#define TOV0	0
#define OCF0	1

#define TIMER0_PWM_PIN  3
#define TIMER0_PWM_PORT DIO_DDRB


#endif /* TIMER0_CONFIG_H_ */
