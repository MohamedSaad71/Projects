/*
 * RTC_interface.h
 *
 *  Created on: Nov 4, 2023
 *      Author: pc
 */

#ifndef RTC_INTERFACE_H_
#define RTC_INTERFACE_H_

#include "RTC_types.h"
#include "RTC_config.h"
#include "RTC_private.h"
#include "RTC_register.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//u8Data buffer[20];

//S_RTCData RTCData;


E_RTC_ErrorType HAL_RTC_Init(S_RTCData *RTCData);
E_RTC_ErrorType HAL_RTC_ReadDate(S_RTCData *RTCData);
E_RTC_ErrorType HAL_RTC_ReadTime(S_RTCData *RTCData);

#endif /* RTC_INTERFACE_H_ */
