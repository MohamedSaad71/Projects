

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "commons_macros.h"
#include "DIO_registers.h"
#include "DIO_Types.h"
#include "DIO_private.h"
#include "DIO_config.h"


/****************************************Functions Prototypes******************************/

E_ErrorType MCAL_Dio_Init(S_Dio *Dio_Config);

E_ErrorType MCAL_Dio_SetPortDirection(S_Dio *Dio_ConfigPort);
E_ErrorType MCAL_Dio_SetPinDirection(S_Dio *Dio_ConfigPin);

E_ErrorType MCAL_Dio_ReadPort(S_Dio *Dio_ReadPort,u8PortValue *Port_Value);
E_ErrorType MCAL_Dio_ReadPins(S_Dio *Dio_ReadPin,u8PinValue *Pin_Value);

E_ErrorType MCAL_Dio_ReadSinglePin(S_Dio *Dio_ReadPin,E_DioPin Pin_Num,u8PinValue *Pin_Value);

E_ErrorType MCAL_Dio_WritePort(S_Dio *Dio_WritePort,u8PortValue Port_Value);
E_ErrorType MCAL_Dio_WritePin(S_Dio *Dio_WritePin,u8PinValue Pin_value);

E_ErrorType MCAL_Dio_WriteSinglePin(S_Dio *Dio_WritePin,E_DioPin Pin_Num,u8PinValue Pin_value);


E_ErrorType MCAL_Dio_TogglePin(S_Dio *Dio_TogglePin,E_DioPin Pin_Num);

#endif /* DIO_INTERFACE_H_ */
