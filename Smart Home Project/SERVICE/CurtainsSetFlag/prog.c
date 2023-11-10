/*
 * prog.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Marii
 */

#include "../CurtainsSetFlag/configs.h"
#include "../CurtainsSetFlag/functions.h"

bool_t LockedFlag = TRUE;

bool_t GlobalFlag = FALSE;

bool_t Check_LDR(){
	bool_t check=FALSE;
	char LDR_VAL;

		HAL_LDR_Read(&LDR_VAL);

		if(LDR_VAL>value){
			check=TRUE;

		}
		else{
			check=FALSE;

		}
		return check;
}


void SERVICE_Set_Flag(void){

	if(LockedFlag == 0){
		GlobalFlag = 1;
		//SERVICE_EVERYTHING_ON();
	}
	else GlobalFlag = 0;


}
void SERVICE_Curtain_Control(void){

	bool_t curt_control = Check_LDR();

	if(curt_control == TRUE){

		HAL_SERVO_Write_CCW(PIN_D5);
	}
	else{

		HAL_SERVO_Write_CW(PIN_D5);

	}


}



