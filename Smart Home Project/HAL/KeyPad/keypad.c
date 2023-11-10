/*
 * Keypad.c

 *
 *  Created on: Oct 25, 2023
 *      Author: dell
 */

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include <util/delay.h>

/* Initialization function for keypad */
E_ErrorType HAL_KPD_init(void)
{
	/* Set all rows as output */

	E_ErrorType u8LocalReturn =E_NOT_OK;
	S_Dio Keypad_interface_rows;
	Keypad_interface_rows.port_num=KEYPAD_ROWS_PORT;
	Keypad_interface_rows.pin_num=(KEYPAD_ROW0|KEYPAD_ROW1|KEYPAD_ROW2|KEYPAD_ROW3);
	Keypad_interface_rows.Direction=OUTPUT;
	u8LocalReturn=MCAL_Dio_Init(&Keypad_interface_rows);




	/* Set all columns as inputs */
	S_Dio Keypad_interface_cols;
	Keypad_interface_cols.port_num=KEYPAD_COLUMNS_PORT;
	Keypad_interface_cols.pin_num=(KEYPAD_COLUMN0|KEYPAD_COLUMN1|KEYPAD_COLUMN2|KEYPAD_COLUMN3);
	Keypad_interface_cols.Direction=INPUT;
	u8LocalReturn=MCAL_Dio_Init(&Keypad_interface_cols);



	/* Set all inputs as internal pull up and all outputs as HIGH */

	u8LocalReturn=  MCAL_Dio_WritePin(&Keypad_interface_cols,PIN_HIGH);
	u8LocalReturn=   MCAL_Dio_WritePin(&Keypad_interface_rows,PIN_HIGH);

	return E_OK;
}


/* Function to get the pressed key */
u8PinValue HAL_KPD_getKey(void)
{
	u8PinValue key_status = PIN_HIGH;
	E_ErrorType u8LocalReturn =E_NOT_OK;
	S_Dio Keypad_interface_rows[NO_ROWS];
	Keypad_interface_rows[0].port_num=KEYPAD_ROWS_PORT;
	Keypad_interface_rows[0].pin_num=KEYPAD_ROW0;
	Keypad_interface_rows[0].Direction=OUTPUT;

	Keypad_interface_rows[1].port_num=KEYPAD_ROWS_PORT;
	Keypad_interface_rows[1].pin_num=KEYPAD_ROW1;
	Keypad_interface_rows[1].Direction=OUTPUT;

	Keypad_interface_rows[2].port_num=KEYPAD_ROWS_PORT;
	Keypad_interface_rows[2].pin_num=KEYPAD_ROW2;
	Keypad_interface_rows[2].Direction=OUTPUT;

	Keypad_interface_rows[3].port_num=KEYPAD_ROWS_PORT;
	Keypad_interface_rows[3].pin_num=KEYPAD_ROW3;
	Keypad_interface_rows[3].Direction=OUTPUT;

	S_Dio Keypad_interface_cols[NO_COLS];
	Keypad_interface_cols[0].port_num=KEYPAD_COLUMNS_PORT;
	Keypad_interface_cols[0].pin_num=KEYPAD_COLUMN0;
	Keypad_interface_cols[0].Direction=INPUT;

	Keypad_interface_cols[1].port_num=KEYPAD_COLUMNS_PORT;
	Keypad_interface_cols[1].pin_num=KEYPAD_COLUMN1;
	Keypad_interface_cols[1].Direction=INPUT;

	Keypad_interface_cols[2].port_num=KEYPAD_COLUMNS_PORT;
	Keypad_interface_cols[2].pin_num=KEYPAD_COLUMN2;
	Keypad_interface_cols[2].Direction=INPUT;

	Keypad_interface_cols[3].port_num=KEYPAD_COLUMNS_PORT;
	Keypad_interface_cols[3].pin_num=KEYPAD_COLUMN3;
	Keypad_interface_cols[3].Direction=INPUT;


	for(u8PinValue i =0;i<NO_ROWS;i++)
	{
		u8LocalReturn=MCAL_Dio_WritePin(&(Keypad_interface_rows[i]),PIN_LOW);
		for(u8PinValue j=0;j<NO_COLS;j++)
		{
			u8LocalReturn =MCAL_Dio_ReadSinglePin(&(Keypad_interface_cols[j]),Keypad_interface_cols[j].pin_num ,&key_status);
			if(key_status== PIN_LOW)
			{

				_delay_ms(20);
				while(key_status==PIN_LOW)
				{
					u8LocalReturn =MCAL_Dio_ReadSinglePin(&(Keypad_interface_cols[j]),Keypad_interface_cols[j].pin_num,&key_status);
				}
				return keypad_keys[i][j];
			}
		}
		u8LocalReturn=	MCAL_Dio_WritePin(&(Keypad_interface_rows[i]),PIN_HIGH);
	}


}
