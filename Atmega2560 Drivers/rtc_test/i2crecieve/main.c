/*
 * rtcproject.c
 *
 * Created: 6/26/2023 11:09:32 AM
 * Author : pc
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "twi.h"
#include "common_macros.h"
#include "GPIO.h"
#include "MemMap.h"
#include "micros_config.h"
#include "std_types.h"
#include "lcd.h"
#include "RTC1307.h"

int main(void)
{
	char buffer[20];
	LCD_init();
	TWI_init();
	TWI_start();
	
		
    /* Replace with your application code */
    while (1) 
    {
		RTC_Read_Clock(0);							/* Read the clock with second address i.e location is 0 */
		if (hour & TimeFormat12)
		{
			sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
			if(IsItPM(hour))
			strcat(buffer, "PM");
			else
			strcat(buffer, "AM");
			LCD_moveCursor(0,0);
			LCD_displayString(buffer);
		}
		
		else
		{
			sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
			LCD_moveCursor(0,0);
			LCD_displayString(buffer);
		}
		RTC_Read_Calendar(3);						/* Read the calender with day address i.e location is 3 */
		sprintf(buffer, "%02x/%02x/%02x ", date, month, year);
		LCD_moveCursor(1,0);
		LCD_displayString(buffer);

    }
}

/*
int main(void)
{
	TWI_Init();
	RTC_Clock_Write(0x11, 0x59, 0x00, hour_12_PM); Write Hour Minute Second Format 
	RTC_Calendar_Write(0x07, 0x31, 0x12, 0x16);	 Write day date month and year 
	while(1);
}
*/

