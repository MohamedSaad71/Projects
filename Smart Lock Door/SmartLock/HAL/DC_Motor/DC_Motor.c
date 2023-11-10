/*
 * DC_Motor.c
 *
 * Created: 7/8/2023 4:38:26 PM
 *
 */ 

#include "dc_motor.h"
#include "Dio.h"
#include "Timer0_PWM.h"

/*
 * Description :
 * Initialize the DC Motor by:
 * 1. Setup the direction of the two motor pins as output by send the request to GPIO driver.
 * 2. Stop the motor at the beginning
 */
void DcMotor_Init(void)
{
	/* Setup the two motor pins as output pins */
	
	DDRB |= (1<<DC_MOTOR_PIN1_ID);
	DDRB |= (1<<DC_MOTOR_PIN2_ID);
	

	/* Motor is stopped at the beginning */
	Dio_Write(DC_MOTOR_PIN1_ID,LOW);
	Dio_Write(DC_MOTOR_PIN2_ID,LOW);
}

/*
 * Description :
 * 1. Rotate  or Stop the motor according to the state input variable.
 * 2. Control the motor speed 0 --> 100% from its maximum speed by sending to PWM driver.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == DC_MOTOR_CW)
	{
		/* Rotates the Motor CW */
		
		
		DC_MOTOR_PORT1_ID &= ~(1<<DC_MOTOR_PIN1_ID);
		DC_MOTOR_PORT2_ID |= (1<<DC_MOTOR_PIN2_ID);
		
		PWM_Timer0_Start(speed);
	}
	else if(state == DC_MOTOR_ACW)
	{
		/* Rotates the Motor A-CW */
		DC_MOTOR_PORT1_ID |= (1<<DC_MOTOR_PIN1_ID);
		DC_MOTOR_PORT2_ID &= ~(1<<DC_MOTOR_PIN2_ID);
		PWM_Timer0_Start(speed);
	}
	else if(state == DC_MOTOR_STOP)
	{
		/* Stop the Motor */
		DC_MOTOR_PORT1_ID &= ~(1<<DC_MOTOR_PIN1_ID);
		DC_MOTOR_PORT2_ID &= ~(1<<DC_MOTOR_PIN2_ID);
		PWM_Timer0_Start(speed);
	}
	else
	{
		/* Invalid Input State - Do Nothing */
	}
}
