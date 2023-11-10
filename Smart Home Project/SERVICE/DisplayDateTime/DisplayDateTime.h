/*
 * DisplayDateTime.h
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#ifndef SERVICE_DISPLAYDATETIME_DISPLAYDATETIME_H_
#define SERVICE_DISPLAYDATETIME_DISPLAYDATETIME_H_


#include "../../HAL/LCD/lcd_Interface.h"
#include "../../HAL/RTC/RTC_interface.h"

S_RTCData RTCData;


void SERVICE_DisplayDateTime(S_RTCData *RTCData);

#endif /* SERVICE_DISPLAYDATETIME_DISPLAYDATETIME_H_ */
