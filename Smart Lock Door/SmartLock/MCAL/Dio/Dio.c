#include "Dio.h"


void Dio_init()
{
	uint8 counter=0;
	for(counter=0;counter<PIN_COUNT;counter++)
	{
		if(pin[counter].port == PORT_A)
		{
			if(pin[counter].direction == OUTPUT)
				SET_BIT(DDRA,pin[counter].pin);
			else
				CLEAR_BIT(DDRA,pin[counter].pin);
		}
		else if(pin[counter].port == PORT_B)
		{
			if(pin[counter].direction == OUTPUT)
				SET_BIT(DDRB,pin[counter].pin);
			else
				CLEAR_BIT(DDRB,pin[counter].pin);
		}
		else if(pin[counter].port == PORT_C)
		{
			if(pin[counter].direction == OUTPUT)
				SET_BIT(DDRC,pin[counter].pin);
			else
				CLEAR_BIT(DDRC,pin[counter].pin);
		}
		else if(pin[counter].port == PORT_D)
		{
			if(pin[counter].direction == OUTPUT)
				SET_BIT(DDRD,pin[counter].pin);
			else
				CLEAR_BIT(DDRD,pin[counter].pin);
		}
	}
}
void Dio_Write(channel_t ch,Dio_state_t state)
{
	Dio_port_t port = ch / 8;
	Dio_pin_t pin = ch % 8;

	if(port == PORT_A)
	{
		if(state == HIGH)
		{
			SET_BIT(PORTA,pin);
		}
		else if(state == LOW)
		{
			CLEAR_BIT(PORTA,pin);
		}
	}
	else if(port == PORT_B)
	{
		if(state == HIGH)
		{
			SET_BIT(PORTB,pin);
		}
		else if(state == LOW)
		{
			CLEAR_BIT(PORTB,pin);
		}
	}
	else if(port == PORT_C)
	{
		if(state == HIGH)
		{
			SET_BIT(PORTC,pin);
		}
		else if(state == LOW)
		{
			CLEAR_BIT(PORTC,pin);
		}
	}
	else if(port == PORT_D)
	{
		if(state == HIGH)
		{
			SET_BIT(PORTD,pin);
		}
		else if(state == LOW)
		{
			CLEAR_BIT(PORTD,pin);
		}
	}


}
Dio_state_t Dio_Read(channel_t ch)
{
	Dio_state_t state = LOW;
	Dio_port_t port = ch / 8;
	Dio_pin_t pin = ch % 8;
	if(port == PORT_A)
	{
		if(BIT_IS_SET(PINA,pin))
		{
			state = HIGH;
		}
		else
		{
			state = LOW;
		}
		
	}
	else if(port == PORT_B)
	{
		if(BIT_IS_SET(PINB,pin))
		{
			state = HIGH;
		}
		else
		{
			state = LOW;
		}
	}
	else if(port == PORT_C)
	{
		if(BIT_IS_SET(PINC,pin))
		{
			state = HIGH;
		}
		else
		{
			state = LOW;
		}
	}
	else if(port == PORT_D)
	{
		if(BIT_IS_SET(PIND,pin))
		{
			state = HIGH;
		}
		else
		{
			state = LOW;
		}
	}

	return state;
}
