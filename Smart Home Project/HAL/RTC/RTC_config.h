/*
 * RTC_config.h
 *
 *  Created on: Nov 4, 2023
 *      Author: pc
 */

#ifndef RTC_CONFIG_H_
#define RTC_CONFIG_H_


#define Device_Write_address	0xD0				/* Define RTC DS1307 slave address for write operation */
#define Device_Read_address		0xD1				/* Make LSB bit high of slave address for read operation */
#define TimeFormat12			0x40				/* Define 12 hour format */
#define AMPM					0x20


#define MAX_DAY_NUMBER       31
#define MAX_MONTH_NUMBER     12
#define MAX_MINUTE_NUMBER    60
#define MAX_SECOND_NUMBER    60
#define MAX_HOUR_NUMBER      12
#define READ_CLOCK_ADDRESS   0
#define READ_DATE_ADDRESS    3
#endif /* RTC_CONFIG_H_ */
