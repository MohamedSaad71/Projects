/*
 * RTC1307.c
 *
 * Created: 6/26/2023 11:20:49 AM
 *  Author: khaled waleed
 */ 
#include "RTC1307.h"

bool IsItPM(char hour_)
{
	if(hour_ & (AMPM))
	return 1;
	else
	return 0;
}

void RTC_Read_Clock(char read_clock_address)
{
	I2C_Start(Device_Write_address);				/* Start I2C communication with RTC */
	TWI_writeByte(read_clock_address);					/* Write address to read */
	twi_Repeated_Start(Device_Read_address);		/* Repeated start with device read address */

	second = TWI_readByteWithACK();						/* Read second */
	minute = TWI_readByteWithACK();						/* Read minute */
	hour = TWI_readByteWithNACK();							/* Read hour with Nack */
	TWI_stop();										/* Stop i2C communication */
}

void RTC_Read_Calendar(char read_calendar_address)
{
	I2C_Start(Device_Write_address);				/* Start I2C communication with RTC */
	TWI_writeByte(read_calendar_address);
	twi_Repeated_Start(Device_Read_address);

	day = TWI_readByteWithACK();							/* Read day */
	date = TWI_readByteWithACK();							/* Read date */
	month = TWI_readByteWithACK();							/* Read month */
	year = TWI_readByteWithNACK();							/* Read the year with Nack */
	TWI_stop();										/* Stop i2C communication */
}


void RTC_Clock_Write(char _hour, char _minute, char _second)
{
	_hour |= AMPM;
	I2C_Start(Device_Write_address);			/* Start I2C communication with RTC */
	TWI_writeByte(0);								/* Write on 0 location for second value */
	TWI_writeByte(_second);							/* Write second value on 00 location */
	TWI_writeByte(_minute);							/* Write minute value on 01 location */
	TWI_writeByte(_hour);							/* Write hour value on 02 location */
	TWI_stop();									/* Stop I2C communication */
}

void RTC_Calendar_Write(char _day, char _date, char _month, char _year)
	/* function for calendar */
{
	I2C_Start(Device_Write_address);			/* Start I2C communication with RTC */
	TWI_writeByte(3);								/* Write on 3 location for day value */
	TWI_writeByte(_day);							/* Write day value on 03 location */
	TWI_writeByte(_date);							/* Write date value on 04 location */
	TWI_writeByte(_month);							/* Write month value on 05 location */
	TWI_writeByte(_year);							/* Write year value on 06 location */
	TWI_stop();									/* Stop I2C communication */
}