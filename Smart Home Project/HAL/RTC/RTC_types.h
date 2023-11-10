/*
 * RTC_types.h
 *
 *  Created on: Nov 4, 2023
 *      Author: pc
 */

#ifndef RTC_TYPES_H_
#define RTC_TYPES_H_





#define RTC_INITIALIZED 1
#define RTC_NOTINITIALIZED 0


#define RTC_STATUS_ERROR RTC_E_OK

typedef unsigned char u8day;
typedef unsigned char u16day_num;
typedef unsigned char u16month;
typedef unsigned char u16year;
typedef unsigned char u16seconds;
typedef unsigned char u16minutes;
typedef unsigned char u16hours;

typedef unsigned short u16Time;
typedef unsigned short u16Date;

typedef unsigned char u8Data;

typedef enum
{
	RTC_E_OK,
	RTC_E_NOT_OK,
	RTC_E_DATE_FORMAT,

}E_RTC_ErrorType;


typedef struct
{
	u16day_num day_num;
	u16month month;
	u16year year;
	u8day day;
	u16hours hours;
	u16minutes minutse;
	u16seconds seconds;


}S_RTCData;




#endif /* RTC_TYPES_H_ */
