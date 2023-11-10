/*
 * TempControl.c
 *
 *  Created on: 6 Nov 2023
 *      Author: Ayaya
 */

#include "TempControl.h"
#include "../../HAL/LCD/lcd_Interface.h"
#include "../../HAL/LED/LED_interface.h"
//#include "../../HAL/DC TRIAL/DC TRIAL/DCMOTOR_Interface.h"
//S_DCMOTOR S_DC={'B','B','B',3,5,6,1};
extern S_DCMOTOR S_DC;
void SERVICE_TempControl(void)
{

	uint16_t ADC_value = 0;
	uint8_t t_current = 0;
	ADC_value = MCAL_ADC_READ(CH1);
	t_current = HAL_LM35_readTemp(ADC_value);

	if(t_current < LOW_TEMP)
	{
		//Fan off
		HAL_DCMOTOR_stop(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if((t_current >= LOW_TEMP) && (t_current< MED_TEMP))
	{
		//Fan low speed
		HAL_DCMOTOR_Ehalfspeed(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if((t_current >= MED_TEMP) && (t_current < HIGH_TEMP))
	{
		//Fan high speed
		HAL_DCMOTOR_Efullspeed(&S_DC);
		//AC off
		HAL_LED_OFF(AC_LED_PORT, AC_LED_PIN);
	}
	else if(t_current >= HIGH_TEMP)
	{
		//Fan off
		HAL_DCMOTOR_stop(&S_DC);
		//AC on
		HAL_LED_ON(AC_LED_PORT, AC_LED_PIN);
	}
	else
	{
		//Do nothing
	}
}
