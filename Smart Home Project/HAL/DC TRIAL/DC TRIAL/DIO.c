#include "DIO.h"
#include "std_macros.h"
#include <avr/io.h>

void write_nibble(char port,char nibble,char data)
{	//nibble=1 ->higher nibble
	//nibble=0 ->lower nibble
	
	switch (nibble)
	{
		case 1: switch (port)
			{	
				case 'A':
				case 'a':data=data<<4;
						 PORTA&=0x0F;//clear higher nibble
						 PORTA|=data;//write higher nibble
						 break;
				case 'B':
				case 'b':data=data<<4;
						 PORTB&=0x0F;//clear higher nibble
						 PORTB|=data;//write higher nibble
						 break;
				case 'C':
				case 'c':data=data<<4;
						 PORTC&=0x0F;//clear higher nibble
						 PORTC|=data;//write higher nibble
						 break;
				case 'D':
				case 'd':data=data<<4;
						 PORTD&=0x0F;//clear higher nibble
			 			 PORTD|=data;//write higher nibble
			  			 break;
			}
			break;
		case 0:switch (port)
			{	
				case 'A':
				case 'a':data&=0x0F;//clear higher nibble
						 PORTA&=0xF0;//clear lower nibble
						 PORTA|=data;//write lower nibble
						 break;
				case 'B':
				case 'b':data&=0x0F;//clear higher nibble
						 PORTB&=0xF0;//clear lower nibble
						 PORTB|=data;//write lower nibble
						 break;
				case 'C':
				case 'c':data&=0x0F;//clear higher nibble
						 PORTC&=0xF0;//clear lower nibble
						 PORTC|=data;//write lower nibble
						 break;
				case 'D':
				case 'd':data&=0x0F;//clear higher nibble
						 PORTD&=0xF0;//clear lower nibble
						 PORTD|=data;//write lower nibble
						 break;
			}
			break;
		
	}
}

void DIO_vsetbitdir(unsigned char port,unsigned char pin, char dir)
{//dir=0 means input else means output
	switch (port)
	{
		case 'A':
		case 'a':	if (dir==0)
		CLR_BIT(DDRA,pin);
		else
		SET_BIT(DDRA,pin);
		break;
		case 'B':
		case 'b':	if (dir==0)
		CLR_BIT(DDRB,pin);
		else
		SET_BIT(DDRB,pin);
		break;
		case 'C':
		case 'c':	if (dir==0)
		CLR_BIT(DDRC,pin);
		else
		SET_BIT(DDRC,pin);
		break;
		case 'D':
		case 'd':	if (dir==0)
		CLR_BIT(DDRD,pin);
		else
		SET_BIT(DDRD,pin);
		break;
	}
}

void DIO_vsetportdir(unsigned char port, char dir)
{	//dir=0 means input else means output
	switch (port)
	{
		case 'A':
		case 'a': if (dir==0)
		CLR_PORT(DDRA);
		else
		SET_PORT(DDRA);
		break;
		case 'B':
		case 'b': if (dir==0)
		CLR_PORT(DDRB);
		else
		SET_PORT(DDRB);
		break;
		case 'C':
		case 'c':	if (dir==0)
		CLR_PORT(DDRC);
		else
		SET_PORT(DDRC);
		break;
		case 'D':
		case 'd':	if (dir==0)
		CLR_PORT(DDRD);
		else
		SET_PORT(DDRD);
		break;
	}
}
void DIO_vpinwrite(char port, char pin, char data)
{
	switch(port)
	{	case 'A':
		case 'a':	if (data==0)
		CLR_BIT(PORTA,pin);
		else
		SET_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':	if (data==0)
		CLR_BIT(PORTB,pin);
		else
		SET_BIT(PORTB,pin);
		break;
		case 'C':
		case 'c':	if (data==0)
		CLR_BIT(PORTC,pin);
		else
		SET_BIT(PORTC,pin);
		break;
		case 'D':
		case 'd':	if (data==0)
		CLR_BIT(PORTD,pin);
		else
		SET_BIT(PORTD,pin);
		break;
	}
}
void DIO_vportwrite(char port, char data)
{	switch (port)
	{
		case 'A':
		case 'a':	PORTA=data;
		break;
		
		case 'B':
		case 'b':	PORTB=data;
		break;
		case 'C':
		case 'c':	PORTC=data;
		break;
		case 'D':
		case 'd':	PORTD=data;
		break;
	}
}
unsigned char DIO_u8pinread(char port, char pin)
{	char data;
	switch(port)
	{	case 'A':
		case 'a':	data=READ_BIT(PINA,pin);
		break;
		case 'B':
		case 'b':	data=READ_BIT(PINB,pin);
		break;
		case 'C':
		case 'c':	data=READ_BIT(PINC,pin);
		break;
		case 'D':
		case 'd':	data=READ_BIT(PIND,pin);
		break;
	}
	return data;
}
unsigned char DIO_u8portread(char port)
{
	char data;
	switch(port){
		case 'A':
		case 'a':	data=PINA;
		break;
		case 'B':
		case 'b':	data=PINB;
		break;
		case 'C':
		case 'c':	data=PINC;
		break;
		case 'D':
		case 'd':	data=PIND;
		break;
	}
	return data;
}

void Pullup_enable(char port, char pin, char enable)
{	//your pin is an input
	if (enable)
	{
		CLR_BIT(SFIOR,2);//Clears PUDisable bit for all
		switch (port)
		{
			case 'A':
			case 'a':	CLR_BIT(DDRA,pin);//make sure the pin is input
			SET_BIT(PORTA,pin);//set your port pin to enable PU for that specific pin
			break;
			
			case 'B':
			case 'b':	CLR_BIT(DDRB,pin);//make sure the pin is input
			SET_BIT(PORTB,pin);//set your port pin to enable PU for that specific pin
			break;
			
			case 'C':
			case 'c':	CLR_BIT(DDRC,pin);//make sure the pin is input
			SET_BIT(PORTC,pin);//set your port pin to enable PU for that specific pin
			break;
			case 'D':
			case 'd':	CLR_BIT(DDRD,pin);//make sure the pin is input
			SET_BIT(PORTD,pin);//set your port pin to enable PU for that specific pin
			break;
			break;
		}
	}
	else
	{
		switch (port)
		{
			case 'A':
			case 'a':	CLR_BIT(PORTA,pin);// disable PU for that specific bit only
			break;
			
			case 'B':
			case 'b':	CLR_BIT(PORTB,pin);// disable PU for that specific bit only
			break;
			
			case 'C':
			case 'c':	CLR_BIT(PORTC,pin);// disable PU for that specific bit only
			break;
			case 'D':
			case 'd':	CLR_BIT(PORTD,pin);// disable PU for that specific bit only
			break;
		}
	}
}
	
	
	
