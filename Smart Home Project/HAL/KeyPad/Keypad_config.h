/*
 * Keypad_config.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_








/* Keypad configuration */

#define KEYPAD_ROWS_PORT  PORTC_ID
#define KEYPAD_ROW0 PIN5_ID
#define KEYPAD_ROW1 PIN4_ID
#define KEYPAD_ROW2 PIN3_ID
#define KEYPAD_ROW3 PIN2_ID


#define KEYPAD_COLUMNS_PORT  PORTD_ID
#define KEYPAD_COLUMN0 PIN7_ID
#define KEYPAD_COLUMN1 PIN6_ID
#define KEYPAD_COLUMN2 PIN5_ID
#define KEYPAD_COLUMN3 PIN3_ID

#define NO_ROWS 4
#define NO_COLS 4

/* Keypad keys */

//#define KEYPAD4X3

#ifdef KEYPAD4X3
#define KEYS_VALUES {{'1','2','3'},\
{'4','5','6'},\
{'7','8','9'},\
{'*','0','#'}}
#else
#define KEYS_VALUES {{'7','8','9','/'},\
{'4','5','6','*'},\
{'1','2','3','-'},\
{'c','0','=','+'}}
#endif

u8PinValue keypad_keys[NO_ROWS][NO_COLS]= KEYS_VALUES;

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
