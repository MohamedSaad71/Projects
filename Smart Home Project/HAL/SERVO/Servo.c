/*
 * Servo.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Marii
 */


#include "SERVO.h"
#include "util/delay.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_Types.h"
#include "../../MCAL/DIO/DIO_registers.h"
#include "../../MCAL/DIO/commons_macros.h"


ERR_TYPE HAL_SERVO_INIT(servo_pin_num pin){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn =  Timer1_Init(mode,pscaler);
	TCNT1 = 0;
	ICR1 = 2499;
	if(pin == PIN_D5){
		S_Dio P2 = {PORTD_ID, PIN5_ID, OUTPUT};
		u8LocalReturn = MCAL_Dio_Init(&P2);
		OCR1A = 0;
		//u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_HIGH);
	}
	else if(pin == PIN_D4){
		S_Dio P3 = {PORTD_ID, PIN4_ID, OUTPUT};
		u8LocalReturn = MCAL_Dio_Init(&P3);
		OCR1B = 0;
		//u8LocalReturn = MCAL_Dio_WritePin(&P3, PIN_HIGH);
	}
	else{
		u8LocalReturn = _E_NOT_OK ;
	}

		return u8LocalReturn;

}


ERR_TYPE HAL_SERVO_Write(servo_pin_num pin, servo_pose pos){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	if(pin == PIN_D5){
	u8LocalReturn = Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	switch (pos){
	case 1:
		OCR1A = 65;	//Set servo -90	position
		break;
	case 2:
	OCR1A = 175;	//Set servo shaft at 0° position
		break;

	case 3:
		OCR1A = 300;	//Set servo +90	position
		break;
	}
	}
	else if(pin == PIN_D4){
		u8LocalReturn = Timer1_OCRB1Mode(OCRB_NON_INVERTING);
		switch (pos){
			case 1:
				OCR1B = 65;	//Set servo -90	position
				break;
			case 2:
				OCR1B = 175;	//Set servo shaft at 0° position
				break;

			case 3:
				OCR1B = 300;	//Set servo +90	position
				break;
		}

	}
	else{
		u8LocalReturn = _E_NOT_OK;
	}
	return u8LocalReturn;
}



ERR_TYPE HAL_SERVO_Increment(servo_pin_num pin, int num){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	if(pin == PIN_D5){
	u8LocalReturn = Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	OCR1A = 160 + (num);
	}
	else if(pin == PIN_D4){
	u8LocalReturn = Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	OCR1B = 65 + (num);
	}
	else{
		u8LocalReturn = _E_NOT_OK;
	}

		return u8LocalReturn;

}

ERR_TYPE HAL_SERVO_Write_CW(servo_pin_num pin){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = HAL_SERVO_Write(pin, 1);
	return u8LocalReturn;
}

ERR_TYPE HAL_SERVO_Write_CCW(servo_pin_num pin){
	ERR_TYPE u8LocalReturn = _E_NOT_OK ;
	u8LocalReturn = HAL_SERVO_Write(pin, 3);
	return u8LocalReturn;
}
