
#include "DIO_interface.h"
#include "DIO_Types.h"
#include "../Common_Files/common_macros.h"


E_ErrorType MCAL_Dio_Init(S_Dio *Dio_Config)
{
	E_ErrorType error = E_OK;
	u8RegisterValue Mask1,Mask2;


	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_Config->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{

		Mask2 = ((Dio_Config->pin_num) & (Dio_Config->Direction));
		switch(Dio_Config->port_num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_DDRA) & (~(Dio_Config->pin_num)));
			DIO_DDRA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_DDRB) & (~(Dio_Config->pin_num)));
			DIO_DDRB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_DDRC) & (~(Dio_Config->pin_num)));
			DIO_DDRC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_DDRD) & (~(Dio_Config->pin_num)));
			DIO_DDRD = Mask1 | Mask2;
			break;

		}
	}

	return error;
}

E_ErrorType MCAL_Dio_SetPortDirection(S_Dio *Dio_ConfigPort)
{
	E_ErrorType error = E_OK;

	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_ConfigPort->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{
		switch(Dio_ConfigPort->port_num)
		{
		case PORTA_ID:
			DIO_DDRA = Dio_ConfigPort->Direction;
			break;
		case PORTB_ID:
			DIO_DDRB = Dio_ConfigPort->Direction;
			break;
		case PORTC_ID:

			DIO_DDRC = Dio_ConfigPort->Direction;
			break;
		case PORTD_ID:
			DIO_DDRD = Dio_ConfigPort->Direction;
			break;

		}
	}

	return error;
}

E_ErrorType MCAL_Dio_SetPinDirection(S_Dio *Dio_ConfigPin)
{
	E_ErrorType error = E_OK;
	u8RegisterValue Mask1,Mask2;

	if(DIO_STATUS_ERROR == E_NOT_OK)
	{

		error = E_NOT_OK;
	}
	else if(Dio_ConfigPin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{
		Mask2 = ((Dio_ConfigPin->pin_num) & (Dio_ConfigPin->Direction));
		switch(Dio_ConfigPin->port_num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_DDRA) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_DDRB) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_DDRC) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_DDRD) & (~(Dio_ConfigPin->pin_num)));
			DIO_DDRD = Mask1 | Mask2;
			break;

		}
	}

	return error;

}


E_ErrorType MCAL_Dio_ReadPort(S_Dio *Dio_ReadPort,u8PortValue *Port_Value)
{
	E_ErrorType error = E_OK;
	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_ReadPort->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{
		switch (Dio_ReadPort->port_num )
		{
		case PORTA_ID:
			*Port_Value = DIO_PINA;
			break;
		case PORTB_ID:
			*Port_Value = DIO_PINB;
			break;
		case PORTC_ID:
			*Port_Value = DIO_PINC;
			break;
		case PORTD_ID:
			*Port_Value = DIO_PIND;
			break;

		}
	}
	return error;
}

E_ErrorType MCAL_Dio_ReadPin(S_Dio *Dio_ReadPin,u8PinValue *Pin_Value)
{
	E_ErrorType error = E_OK;

	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_ReadPin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;

	}
	else
	{

		switch(Dio_ReadPin->port_num)
		{
		case PORTA_ID:
			*Pin_Value = GET_BIT(DIO_PINA,Dio_ReadPin->pin_num);
			break;
		case PORTB_ID:
			*Pin_Value = GET_BIT(DIO_PINB,Dio_ReadPin->pin_num);
			break;
		case PORTC_ID:
			*Pin_Value = GET_BIT(DIO_PINC,Dio_ReadPin->pin_num);
			break;
		case PORTD_ID:
			*Pin_Value = GET_BIT(DIO_PIND,Dio_ReadPin->pin_num);
			break;
		}
	}
	return error;
}


E_ErrorType MCAL_Dio_WritePort(S_Dio *Dio_WritePort,u8PortValue Port_Value)
{
	E_ErrorType error = E_OK;


	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_WritePort->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{
		switch (Dio_WritePort->port_num)
		{
		case PORTA_ID:
			DIO_PORTA = Port_Value;
			break;
		case PORTB_ID:
			DIO_PORTB = Port_Value;
			break;
		case PORTC_ID:
			DIO_PORTC = Port_Value;
			break;
		case PORTD_ID:
			DIO_PORTD = Port_Value;
			break;
		}
	}
	return error;
}


E_ErrorType MCAL_Dio_WritePin(S_Dio *Dio_WritePin,u8PinValue Pin_value)
{
	E_ErrorType error = E_OK;
	u8RegisterValue Mask1,Mask2;
	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;
	}
	else if(Dio_WritePin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{

		Mask2 = ((Dio_WritePin->pin_num) & (Pin_value));
		switch(Dio_WritePin->port_num)
		{
		case PORTA_ID:
			Mask1 = ((DIO_PORTA) & (~(Dio_WritePin->pin_num)));
			DIO_PORTA = Mask1 | Mask2;
			break;
		case PORTB_ID:
			Mask1 = ((DIO_PORTB) & (~(Dio_WritePin->pin_num)));
			DIO_PORTB = Mask1 | Mask2;
			break;
		case PORTC_ID:
			Mask1 = ((DIO_PORTC) & (~(Dio_WritePin->pin_num)));
			DIO_PORTC = Mask1 | Mask2;
			break;
		case PORTD_ID:
			Mask1 = ((DIO_PORTD) & (~(Dio_WritePin->pin_num)));
			DIO_PORTD = Mask1 | Mask2;
			break;

		}
	}
	return error;
}

E_ErrorType MCAL_Dio_WriteSinglePin(S_Dio *Dio_WritePin,E_DioPin Pin_Num,u8PinValue Pin_value)
{
		E_ErrorType error = E_OK;
		u8PinNumber bitNumber;
		if(DIO_STATUS_ERROR == E_NOT_OK)
		{
			error = E_NOT_OK;
		}
		else if(Dio_WritePin->port_num >= DIO_CONFIGURED_PORTS)
		{

			error = E_NOT_OK;
		}
		else
		{
			for (int i = 0; i < DIO_CONFIGURED_PINS; i++) {
						if (Pin_Num & (1 << i)) {
							bitNumber = i;
							break;
						}
					}
			switch(Dio_WritePin->port_num)
					{
					case PORTA_ID:
						if(Pin_value == 1) // compare with one as i define LOGIC_HIGH 1 in DIO_std but ican't use it
						{
							SET_BIT(DIO_PORTA,bitNumber);
						}
						else
						{
							CLEAR_BIT(DIO_PORTA,bitNumber);
						}
						break;
					case PORTB_ID:
						if(Pin_value == 1)
						{
							SET_BIT(DIO_PORTB,bitNumber);
						}
						else
						{
							CLEAR_BIT(DIO_PORTB,bitNumber);
						}
						break;
					case PORTC_ID:
						if(Pin_value == 1)
						{
							SET_BIT(DIO_PORTC,bitNumber);
						}
						else
						{
							CLEAR_BIT(DIO_PORTC,bitNumber);
						}
						break;
					case PORTD_ID:
						if(Pin_value == 1)
						{
							SET_BIT(DIO_PORTD,bitNumber);
						}
						else
						{
							CLEAR_BIT(DIO_PORTD,bitNumber);
						}
						break;
		}

		}

		return error;

}

E_ErrorType MCAL_Dio_ReadSinglePin(S_Dio *Dio_ReadPin,E_DioPin Pin_Num,u8PinValue *Pin_Value)
{
	E_ErrorType error = E_OK;
	u8PinNumber bitNumber;

	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;


	}
	else if(Dio_ReadPin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;

	}
	else
	{
		for (int i = 0; i < DIO_CONFIGURED_PINS; i++) {
			if (Pin_Num & (1 << i)) {
				bitNumber = i;
				break;
			}
		}
		switch(Dio_ReadPin->port_num)
				{
				case PORTA_ID:
					*Pin_Value = GET_BIT(DIO_PINA,bitNumber);
					break;
				case PORTB_ID:
					*Pin_Value = GET_BIT(DIO_PINB,bitNumber);
					break;
				case PORTC_ID:
					*Pin_Value = GET_BIT(DIO_PINC,bitNumber);
					break;
				case PORTD_ID:
					*Pin_Value = GET_BIT(DIO_PIND,bitNumber);
					break;
				}
	}
	return error;
}

E_ErrorType MCAL_Dio_TogglePin(S_Dio *Dio_TogglePin,E_DioPin Pin_Num)
{

	E_ErrorType error = E_OK;
	u8PinNumber bitNumber;

	if(DIO_STATUS_ERROR == E_NOT_OK)
	{
		error = E_NOT_OK;


	}
	else if(Dio_TogglePin->port_num >= DIO_CONFIGURED_PORTS)
	{

		error = E_NOT_OK;

	}
	else
	{
		for (int i = 0; i < DIO_CONFIGURED_PINS; i++) {
			if (Pin_Num & (1 << i)) {
				bitNumber = i;
				break;
			}
		}

		switch (Dio_TogglePin->port_num)
		{
		case PORTA_ID:
			DIO_PORTA = DIO_PORTA ^ (1<<bitNumber);
			break;
		case PORTB_ID:
			DIO_PORTB = DIO_PORTB ^ (1<<bitNumber);
			break;
		case PORTC_ID:
			DIO_PORTB = DIO_PORTC ^ (1<<bitNumber);
			break;
		case PORTD_ID:
			DIO_PORTB = DIO_PORTD ^ (1<<bitNumber);


			break;
		}
	}

	return error;

}
