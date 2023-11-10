/*
 * SERVO_CFG.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Marii
 */

#ifndef SERVO_SERVO_CFG_H_
#define SERVO_SERVO_CFG_H_
#include "SERVO.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"
static Timer1Mode_type mode = TIMER1_FASTPWM_ICR_TOP_MODE;
static Timer1Scaler_type pscaler = TIMER1_SCALER_64;

#endif /* SERVO_SERVO_CFG_H_ */
