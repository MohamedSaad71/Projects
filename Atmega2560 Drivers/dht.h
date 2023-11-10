/******************************************************************************
 *
 * Module: dht
 *
 * File Name: dht.h
 *
 * Description: Header file for  dht sensor Driver
 *
 * Author: Mohamed Saad
 *
 *******************************************************************************/

#ifndef DHT_H_
#define DHT_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"
#include "MemMap.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_DDR				DDRD_REG
#define SENSOR_PORT				PORTD_REG
#define SENSOR_PIN				PIND_REG
#define DHT_PIN                     7

uint8_t H_high,H_low,T_high,T_low,CheckSum;
uint16_t temp,hum;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Request(void);						/* Microcontroller send start pulse or request */

void Response();						/* receive response from DHT Sensor */

uint16_t get_Temp();                      /*Get the temperature value from DHT*/

uint16_t get_Humadity();                  /*Get the humadity value from DHT*/


#endif /* DHT_H_ */