/*
 * SERVO_Types.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Marii
 */

#ifndef SERVO_SERVO_TYPES_H_
#define SERVO_SERVO_TYPES_H_

#define prescaler Prescaler_8

typedef enum {
	_E_OK,
	_E_NOT_OK
}ERR_TYPE;

typedef enum{
	PIN_D4,
	PIN_D5

}servo_pin_num;

typedef enum{
	pose_neg_90 =1,
	pose_0,
	pose_pos_90
}servo_pose;


#endif /* SERVO_SERVO_TYPES_H_ */
