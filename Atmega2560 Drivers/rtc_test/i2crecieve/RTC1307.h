/*
 * RTC1307.h
 *
 * Created: 6/26/2023 11:20:32 AM
 *  Author: khaled waleed
 */ 


#ifndef RTC1307_H_
#define RTC1307_H_

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "twi.h"

#define Device_Write_address	0xD0	/* Define RTC DS1307 slave write address */
#define Device_Read_address	    0xD1	/* Make LSB bit high of slave address for read */
#define TimeFormat12		    0x40	/* Define 12 hour format */
#define hour_12_AM				0x40
#define hour_12_PM				0x60
#define hour_24					0x00
#define AMPM			        0x20

int second,minute,hour,day,date,month,year;

bool IsItPM(char hour_);
void RTC_Read_Clock(char read_clock_address);
void RTC_Read_Calendar(char read_calendar_address);
void RTC_Clock_Write(char _hour, char _minute, char _second);
void RTC_Calendar_Write(char _day, char _date, char _month, char _year);



#endif /* RTC1307_H_ */