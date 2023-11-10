/*
 * DisplayDateTime.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */


#include "DisplayDateTime.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "../../HAL/LCD/lcd_Interface.h"
//extern RTCData;
//extern buffer;
u8Data buffer[20];
void SERVICE_DisplayDateTime(S_RTCData* RTCData)
{
	//Display date and time
	HAL_RTC_ReadTime(&RTCData);
	HAL_LCD_sendString("YES");
	sprintf(buffer, "%02x:%02x:%02x  ", RTCData->hours, RTCData->minutse, RTCData->seconds);
	HAL_LCD_displaystringRowColumn(buffer ,0, 0);

	HAL_RTC_ReadDate(&RTCData);
	sprintf(buffer, "%02x/%02x/%02x", RTCData->day_num, RTCData->month, RTCData->year);
	HAL_LCD_displaystringRowColumn(buffer ,1, 0);
}
