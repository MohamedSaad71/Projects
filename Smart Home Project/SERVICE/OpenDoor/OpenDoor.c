/*
 * OpenDoor.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */


#include "OpenDoor.h"


void SERVICE_OPEN_DOOR()
{
	char p=5;
	p= Login();
	//PAssword
	if(p==0)
	{
		//Check IR
		HAL_Solenoid_Open();
		SERVICE_Check_IR();

	}
	else
	{

		//Do nothing
	}


}
