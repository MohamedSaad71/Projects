/*
 * lcd_Interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Registers.h"
#include "LCD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

/* Function set */

/* Function to initialize the LCD */
E_LCD_ErrorType HAL_LCD_init();

/* Function to send command to LCD */
E_LCD_ErrorType HAL_LCD_sendCommand(LCD_commandType command);

/* Function to display a character on the LCD */
E_LCD_ErrorType HAL_LCD_sendCharacter(LCD_dataType data);

/* Function to display a string on the LCD */
E_LCD_ErrorType HAL_LCD_sendString(const char *str);

/* Function to clear the LCD screen */
E_LCD_ErrorType HAL_LCD_clearScreen();

/* Function to display a string on a certain row and column on the LCD screen */
E_LCD_ErrorType HAL_LCD_displaystringRowColumn(const char *Str ,LCD_row row,LCD_column col);

/* Function to move the cursor to a certain row and column on the LCD screen */
E_LCD_ErrorType HAL_LCD_goToRowColumn(LCD_row row, LCD_column col);

/* Function to convert an integer to string */
E_LCD_ErrorType HAL_LCD_integerToString(LCD_integer num);

/* Function to display an integer on a certain row and column on the LCD screen */
E_LCD_ErrorType HAL_LCD_displayIntegerRowColumn(LCD_integer num, LCD_row row, LCD_column col);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
