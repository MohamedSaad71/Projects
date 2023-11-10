
#include "Button_interface.h"
#include "Button_config.h"



/* Initialize the Button */
E_ErrorType HAL_BUTTON_init( )
{
	E_ErrorType u8LocalReturn =E_NOT_OK;
	S_Dio Button_interface;
	Button_interface.port_num=Button_port;
	Button_interface.pin_num=Button_pin;
	Button_interface.Direction=INPUT;
	u8LocalReturn=MCAL_Dio_Init(&Button_interface);
	return E_OK;
}

/* Read the button */
E_ErrorType HAL_BUTTON_read(u8PinValue *btn_state)
{
	E_ErrorType u8LocalReturn =E_NOT_OK;
		S_Dio Button_interface;
		Button_interface.port_num=Button_port;
		Button_interface.pin_num=Button_pin;
		u8LocalReturn= MCAL_Dio_ReadSinglePin(&Button_interface, Button_interface.pin_num, btn_state);
		return E_OK;
}

/* Set button as pull up */
E_ErrorType HAL_BUTTON_set_pullup()
{
	E_ErrorType u8LocalReturn =E_NOT_OK;
	S_Dio Button_interface;
	Button_interface.port_num=Button_port;
	Button_interface.pin_num=Button_pin;
	u8LocalReturn=MCAL_Dio_WriteSinglePin(&Button_interface, Button_interface.pin_num,PIN_HIGH);
	return E_OK;
}

