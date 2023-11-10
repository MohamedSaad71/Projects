/*
 * Timer0.c
 *
 *  Created on: Oct 28, 2023
 *      Author: pc
 */

#include "Timer0_interface.h"


/***************************************************************
 *
 *                         Functions Definitions
 *
 **************************************************************/

/* For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 *  (Tick Time = (prescaler / freq.) ms
 * so put initial timer counter = 0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second
 *
 * Time0 Interrupt ISR(TIMER0_OVF_vect)
 *
 */


E_Timer0ErrorType MCAL_Timer0_OVF_Init(E_Prescaler prescaler)
{
	E_Timer0ErrorType error;
	if(TIMER0_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else
	{
		TCNT0 = 0; //To start counting from 0
		/* Configure the timer control register
		 * . Non PWM mode FOC0=1
		 * . Normal Mode WGM01=0 & WGM00=0
		 * . Normal Mode COM00=0 & COM01=0
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */
		SET_BIT(TCCR0,FOC0);

		switch (prescaler)
		{
		case 0:
			SET_BIT(TCCR0,CS00);

			break;

		case 1:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case 2:
			SET_BIT(TCCR0,CS02);
			break;
		case 3:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);

			break;
		default:

			break;
		}


		//Enable Time0 Iterrupt
		SET_BIT(TIMSK,TOIE0);
	}


	return error;
}


/* Description:
 * Put our desired Compare value to match, It fires an interrupt when this value is matched by timer0
 * For clock=1Mhz and prescale every count will take 1ms
 * (Tick Time = (prescaler / freq.) ms
 * so we just need 250 counts to get 250ms every compare match.
 * put initial timer counter=0 and output compare register 0 --> 255 (250ms per compare match)
 * so we need timer to make 2 compare matches to get a 0.5 second
 *
 * Time0 Comapet match mode  ISR(TIMER0_COMP_vect)
 */

E_Timer0ErrorType MCAL_Timer0_CTC_Init(E_Prescaler prescaler,u8CompareValue CompareValue)
{
	E_Timer0ErrorType error;
	if(TIMER0_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else
	{
		TCNT0 = 0;    // Set Timer initial value to 0
		OCR0  = CompareValue; // Set Compare Value

		/* Configure timer0 control register
		 * . Non PWM mode FOC0=1
		 * . CTC Mode WGM01=1 & WGM00=0
		 * . CLear OC0 on compare match
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */
		SET_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM01);
		//SET_BIT(TCCR0,COM01);

		switch (prescaler)
		{
		case 0:
			SET_BIT(TCCR0,CS00);

			break;

		case 1:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case 2:
			SET_BIT(TCCR0,CS02);
			break;
		case 3:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);

			break;
		default:

			break;
		}
		SET_BIT(TIMSK,OCIE0);// Enable Timer0 Compare Interrupt

	}
	return error;
}


/* Description:
 * Put our desired Duty Cycle to generate a PWM Signal On Pin PB3
 * F_PWM=(F_CPU)/(256*N) = (16^6)/(256*1024) = 61
 * Duty Cycle can be changed be update the value in The Compare Register
 */

E_Timer0ErrorType MCAL_Timer0_FastPWM_Init(E_Prescaler prescaler,u8DutyCyle Duty_Cycle)
{

	E_Timer0ErrorType error;
	if(TIMER0_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else
	{

		TCNT0 = 0;
		OCR0 = Duty_Cycle;
		// Define PB3 to Output as it's the signal which genrates pwm by timer0
		SET_BIT(TIMER0_PWM_PORT,TIMER0_PWM_PIN);

		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode)  COM01=1
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */

		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM11);
		SET_BIT(TCCR0,COM01);

		switch (prescaler)
		{
		case 0:
			SET_BIT(TCCR0,CS00);

			break;

		case 1:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case 2:
			SET_BIT(TCCR0,CS02);
			break;
		case 3:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);

			break;
		default:

			break;
		}

	}


	return 0;
}

/* Description:
 * The PWM resolution for the phase correct PWM mode is fixed to eight bits. In phase correct
 * Put our desired Duty Cycle to generate a PWM Signal On Pin PB3
 * F_PWM=(F_CPU)/(256*N) = (16^6)/(256*1024) = 61
 * Duty Cycle can be changed be update the value in The Compare Register
 */


E_Timer0ErrorType MCAL_Timer0_PCPWM_Init(E_Prescaler prescaler,u8DutyCyle Duty_Cycle)
{
	E_Timer0ErrorType error;

	if(TIMER0_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else
	{
		TCNT0 = 0;
		OCR0 = Duty_Cycle;
		SET_BIT(TIMER0_PWM_PORT,TIMER0_PWM_PIN);

		/* Configure timer control register
		 * 1. Phase Correct PWM mode FOC0=0
		 * 2. Phase Correct Mode WGM00=1
		 * 3. Clear OC0 when match occurs COM01=1
		 * . prescaler 1024 CS00=1  CS02=1
		 * . prescaler 256  CS02=1
		 * . prescaler 64   CS00=1  CS0=1
		 * . prsecaler 8    CS00=1
		 */

		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,COM01);
		switch (prescaler)
		{
		case 0:
			SET_BIT(TCCR0,CS00);

			break;

		case 1:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			break;
		case 2:
			SET_BIT(TCCR0,CS02);
			break;
		case 3:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);

			break;
		default:

			break;
		}
	}
	return error;
}













