
#include "BUZZER_INTERFACE.h"

__EErrorType HAL_BUZZER_INIT(E_DioPort BUZZERPORT, E_DioPin BUZZERPin){
	S_Dio P2 = {BUZZERPORT, BUZZERPin, OUTPUT};
	__EErrorType u8LocalReturn = __E_NOT_OK ;
	u8LocalReturn = MCAL_Dio_Init(&P2);
	return u8LocalReturn;
}

__EErrorType HAL_BUZZER_ON(E_DioPort BUZZERPORT, E_DioPin BUZZERPin){
	S_Dio P2 = {BUZZERPORT, BUZZERPin, PIN_LOW};
	__EErrorType u8LocalReturn = __E_NOT_OK;
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_HIGH);
	return u8LocalReturn;

}

__EErrorType HAL_BUZZER_OFF(E_DioPort BUZZERPORT, E_DioPin BUZZERPin){
	S_Dio P2 = {BUZZERPORT, BUZZERPin, PIN_LOW};
	__EErrorType u8LocalReturn = __E_NOT_OK;
	u8LocalReturn = MCAL_Dio_WritePin(&P2, PIN_LOW);
	return u8LocalReturn;

}
