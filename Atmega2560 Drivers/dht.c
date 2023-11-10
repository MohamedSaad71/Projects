/******************************************************************************
 *
 * Module: dht
 *
 * File Name: dht.c
 *
 * Description: Source file for  dht sensor Driver
 *
 * Author: Mohamed Saad
 *
 *******************************************************************************/

#include "dht.h"
#include "lcd.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void Request()						/* Microcontroller send start pulse or request */
{
	
	/*This functions responbible for sending a request to the sensor to begin 
	* set the data pin as out put, set it low for about 30:50 ms then set it high
	*/
	SENSOR_DDR |= (1<<DHT_PIN);
	SENSOR_PORT &= ~(1<<DHT_PIN);		/* set to low pin */
	_delay_ms(40);					/* wait for 100ms */
	PORTD |= (1<<DHT_PIN);		/* set to high pin */
		_delay_us(20);
}


void Response()						/* receive response from DHT11 */
{
	
	DDRD &= ~(1<<DHT_PIN);
	while(PIND & (1<<DHT_PIN));
	while((PIND & (1<<DHT_PIN))==0);
	while(PIND & (1<<DHT_PIN));
	
	
}

uint16_t get_Humadity()
{
	/*
	Data being sent from the sensor as 40bits each 8 bits at a time 
	1st send is the Humadity high 8 bits then H-low 8 bits
	3rd send is the Temp.high 8 bits then T_low 8 bits
	last is the checksum
	*/
	
	uint8_t m = 0;
	
	for(int j=0;j<2;j++)
	{
		for (int q=0; q<8; q++)
		{
			
			while((SENSOR_PIN & (1<<DHT_PIN)) == 0);	/* check received bit 0 or 1 */
			_delay_us(50);
			if(SENSOR_PIN & (1<<DHT_PIN))				/* if high pulse is greater than 30ms */
			m = (m<<1)|(0x01);						/* then its logic HIGH */
			else									/* otherwise its logic LOW */
			m = (m<<1);
			
			while(SENSOR_PIN & (1<<DHT_PIN));
		}
		if(j==0)
		{
			H_high=m;
		}
		else if(j==1)
		{
			H_low=m;
		}
		else
		{
			/*Do Noothing*/
		}
		
		
	}
	
	hum = (H_high << 8) | H_low ;
	hum = hum/10;
	
	return hum;
}


uint16_t get_Temp()
{
	/*
	Data being sent from the sensor as 40bits each 8 bits at a time 
	1st send is the Humadity high 8 bits then H-low 8 bits
	3rd send is the Temp.high 8 bits then T_low 8 bits
	last is the checksum
	*/
	
	uint8_t n = 0;
	
	for(int j=0;j<4;j++)
	{
		for (int q=0; q<8; q++)
		{
			
			while((SENSOR_PIN & (1<<DHT_PIN)) == 0);	/* check received bit 0 or 1 */
			_delay_us(50);
			if(SENSOR_PIN & (1<<DHT_PIN))				/* if high pulse is greater than 30ms */
			n = (n<<1)|(0x01);						/* then its logic HIGH */
			else									/* otherwise its logic LOW */
			n = (n<<1);
			
			while(SENSOR_PIN & (1<<DHT_PIN));
		}
		if(j == 2)
		{
			T_high = n;
		}
		else if(j == 3)
		{
			T_low = n;
		}
		else
		{
			/*Do Noothing*/
		}
		
		
	}
	
	temp = (T_high<<8) | (T_low);
	temp = temp/10;
	
	
	
	
	return temp;
}