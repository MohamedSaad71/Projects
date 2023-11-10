/*
 * external_eeprom.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_EEPROM_EXTERNAL_EEPROM_H_
#define MCAL_EEPROM_EXTERNAL_EEPROM_H_

#include <avr/io.h>
#include "../I2C/twi.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8_t EEPROM_writeByte(uint16_t u16addr,uint8_t u8data);
uint8_t EEPROM_readByte(uint16_t u16addr,uint8_t *u8data);

#endif /* MCAL_EEPROM_EXTERNAL_EEPROM_H_ */
