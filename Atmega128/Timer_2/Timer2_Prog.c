/*
 * Timer2_Prog.c
 *
 *  Created on: Nov 25, 2023
 *      Author: EVA
 */

#ifndef TIMER_2_TIMER2_PROG_C_
#define TIMER_2_TIMER2_PROG_C_

#include "Timer2_Interface.h"

Timer2_Error ERROR_Status=TIMER2_OK;

Timer2_Error TIMER2_INIT(Prescaler_Value PRE,DutyCycle Duty)
{
	if(Duty>=100)
	{
		TCNT2=0;
			DutyCycle duty_cal;
			duty_cal=(255*Duty)/100;
			OCR2=duty_cal;
			SET_BIT(TIMER2_PORT,TIMER2_PIN);

					SET_BIT(TCCR2,WGM20);
					SET_BIT(TCCR2,WGM21);

					SET_BIT(TCCR2,COM21);
					CLEAR_BIT(TCCR2,COM20);

					if(PRE==Prescaler_8)
					{
						SET_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS22);
					}
					else if(PRE==Prescaler_64)
					{
						SET_BIT(TCCR2,CS20);
						SET_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS22);
					}
					else if(PRE==Prescaler_256)
					{
						CLEAR_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);
					}
					else if(PRE==Prescaler_1024)
					{
						SET_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);
					}
					else
					{
						ERROR_Status=TIMER2_NOT_OK;
					}
	}
	else
	{
		ERROR_Status=TIMER2_NOT_OK;

	}




return ERROR_Status;
}

#endif /* TIMER_2_TIMER2_PROG_C_ */
