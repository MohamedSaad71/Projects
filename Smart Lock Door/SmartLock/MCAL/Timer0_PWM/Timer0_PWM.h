/*
 * Timer0_PWM.h
 *
 * Created: 7/8/2023 4:28:09 PM
 */ 


#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_

#include "std_types.h"

#define TIMER0_OCO_PORT_ID    1
#define TIMER0_OCO_PIN_ID     3


/***********************************************************************
*                         Function Prototype
*************************************************************************/
/*
 * Description :
 * Initialize the PWM module by:
 * 1. Trigger Timer0 with PWM Mode.
 * 2. Setup the PWM mode with Non-Inverting.
 * 3. Setup the precaler with F_CPU/8
 * 4. Setup the compare value based on the required input duty cycle
 * 5. Setup the direction for OC0 as output pin
 */
void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* TIMER0_PWM_H_ */