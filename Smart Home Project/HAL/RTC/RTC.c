/*
 * RTC.prog.c
 *
 *  Created on: Nov 4, 2023
 *      Author: pc
 */

#include "RTC_interface.h"
#include "../../MCAL/I2C/I2C.h"
#include "../LCD/lcd_Interface.h"




E_RTC_ErrorType HAL_RTC_Init(S_RTCData *RTCData)
{
	uint16_t minutes,hourse,days,month,year;
	E_RTC_ErrorType error = RTC_E_OK;

	if(RTC_STATUS_ERROR== RTC_E_NOT_OK)
	{
		error = RTC_E_NOT_OK;
	}
	//	else if((RTCData->day_num > MAX_DAY_NUMBER) || (RTCData->month > MAX_MONTH_NUMBER)  || (RTCData->seconds > MAX_SECOND_NUMBER) || (RTCData->minutse > MAX_MINUTE_NUMBER) || (RTCData->hours > MAX_HOUR_NUMBER))
	//	{
	//		error = RTC_E_DATE_FORMAT;
	//
	//	}
	else
	{

		/* First Write the Time Format*/
		I2C_Start(Device_Write_address);			/* Start I2C communication with RTC */
		I2C_Write(READ_CLOCK_ADDRESS);								/* Write on 0 location for second value */
		/*converting the decimal value to hex*/

		uint16_t seconds  = ((RTCData->seconds / 10) << 4) | (RTCData->seconds % 10);
		I2C_Write(seconds);						/* Write second value on 00 location */
		minutes = ((RTCData->minutse/ 10) << 4) | (RTCData->minutse % 10);
		I2C_Write(minutes);

		hourse = ((RTCData->hours/ 10) << 4) | (RTCData->hours % 10);
		I2C_Write(hourse);

		I2C_Stop();

		/*Write the Date format*/
		I2C_Start(Device_Write_address);			/* Start I2C communication with RTC */
		I2C_Write(READ_DATE_ADDRESS);								/* Write on 3 location for day value */

		I2C_Write(RTCData->day);							/* Write day value on 03 location */
		days = ((RTCData->day_num / 10) << 4) | (RTCData->day_num % 10);
		I2C_Write(days);							//I2C_Write(_date);
		month = ((RTCData->month / 10) << 4) | (RTCData->month % 10);
		I2C_Write(month);							/* Write month value on 05 location */
		year = ((RTCData->year / 10) << 4) | (RTCData->year % 10);
		I2C_Write(year);							/* Write year value on 06 location */

		I2C_Stop();
	}

	return error;

}


E_RTC_ErrorType HAL_RTC_ReadTime(S_RTCData *RTCData)
{
	E_RTC_ErrorType error = RTC_E_OK;
	if(RTC_STATUS_ERROR== RTC_E_NOT_OK)
	{
		error = RTC_E_NOT_OK;
	}
	else
	{
		I2C_Start(Device_Write_address);				/* Start I2C communication with RTC */
		I2C_Write(READ_CLOCK_ADDRESS);					/* Write address to read */
		I2C_Repeated_Start(Device_Read_address);		/* Repeated start with device read address */
		RTCData->seconds = I2C_Read_Ack();						/* Read second */
		RTCData->minutse = I2C_Read_Ack();						/* Read minute */
		RTCData->hours = I2C_Read_Nack();							/* Read hour with Nack */
		I2C_Stop();

	}

	return error;
}

E_RTC_ErrorType HAL_RTC_ReadDate(S_RTCData *RTCData)
{
	E_RTC_ErrorType error = RTC_E_OK;
	if(RTC_STATUS_ERROR== RTC_E_NOT_OK)
	{
		error = RTC_E_NOT_OK;
	}
	else if((RTCData->day_num > MAX_DAY_NUMBER) || (RTCData->month > MAX_MONTH_NUMBER))
	{
		error = RTC_E_DATE_FORMAT;
	}
	else
	{
		I2C_Start(Device_Write_address);
		I2C_Write(READ_DATE_ADDRESS);
		I2C_Repeated_Start(Device_Read_address);

		RTCData->day = I2C_Read_Ack();							/* Read day */
		RTCData->day_num = I2C_Read_Ack();							/* Read date */
		RTCData->month = I2C_Read_Ack();							/* Read month */
		RTCData->year = I2C_Read_Nack();							/* Read the year with Nack */
		I2C_Stop();
	}

	return error;

}



