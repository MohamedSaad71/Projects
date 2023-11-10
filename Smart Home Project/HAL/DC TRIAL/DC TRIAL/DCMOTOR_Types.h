/*
 * DCMOTOR_Types.h
 *
 * Created: 11/5/2023 7:50:52 AM
 *  Author: LENOVO
 */ 


#ifndef DCMOTOR_TYPES_H_
#define DCMOTOR_TYPES_H_


typedef struct 
{
	
	unsigned char PWM_port;
	unsigned char DIR_port;
	unsigned char EN_port;
	
	unsigned char PWM_pin;
	unsigned char DIR_pin;
	unsigned char EN_pin;
	
	unsigned char clkwise; 
	
	
	}S_DCMOTOR;

typedef enum
{
	DCMOTOR_E_OK,
	DCMOTOR_N_OK
}E_DCMOTOR_ERROR;
#endif /* DCMOTOR_TYPES_H_ */