/*
 * functions.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Marii
 */

#ifndef SERVICE_FUNCTIONS_H_
#define SERVICE_FUNCTIONS_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/SERVO/SERVO.h"
#include "../CurtainsSetFlag/configs.h"

void SERVICE_Set_Flag(void);
void SERVICE_Curtain_Control(void);

#endif /* SERVICE_FUNCTIONS_H_ */
