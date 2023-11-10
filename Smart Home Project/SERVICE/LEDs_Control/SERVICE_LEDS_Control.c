/*
 * SERVICE_LEDS_Control.c

 *
 *  Created on: Nov 7, 2023
 *      Author: dell
 */

#include "SERVICE_LEDS_Controls.h"
void SERVICE_LEDS_Control()
{
	/* func_ext_int_0  function passed to the MCAL_Ext_INT_0_init_setCllBack function */
	void func_ext_int_0()
	{
		/* u8LcaliReturn is local variable check return from function is OK or not */
		E_ErrorType u8LocalReturn =NOT_OK;
		/* LED initialization */
		u8LocalReturn = HAL_LED_INIT(PORTA_ID, PIN6_ID);
		/* Turn on led if PIR is sensed motion */
		u8LocalReturn= HAL_LED_ON(PORTA_ID, PIN6_ID);
	}

	/* u8LcaliReturn is local variable check return from function is OK or not */
	E_ErrorType u8LocalReturn =NOT_OK;
	/* btn_state is local variable is used to get the value of button's pin */
	unsigned char btn_state;
	/* PIR sensor initialization */
	u8LocalReturn=HAL_PIR_Init();
	/* Button initialization */
	u8LocalReturn=HAL_BUTTON_init();
	/* External interrupt 0 initialization and make interrupt sense rising edge sense */
	u8LocalReturn =MCAL_EXT_INT_0_init(rising_edge_sense);
	/* Set call back function is used to take the address of the function that will passed to ISR function */
	u8LocalReturn=MCAL_Ext_INT_setCallBack(func_ext_int_0,ext_int_0);
	/* Read the value of the pin button */
	u8LocalReturn=HAL_BUTTON_read(&btn_state);
	/* Check if button is pressed or not */
	if(btn_state==1)
	{
		/* when the button is pressed, read the value of the button pin */
		while(btn_state==1)
		{
			/* Read the value of the button pin while button is pressed */
			u8LocalReturn=HAL_BUTTON_read(&btn_state);
			/* Turn off the led while button is pressed */
			u8LocalReturn= HAL_LED_OFF(PORTA_ID, PIN6_ID);
		}
	}

}
