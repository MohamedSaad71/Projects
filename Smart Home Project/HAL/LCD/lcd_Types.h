/*
 * lcd_Types.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_LCD_TYPES_H_
#define HAL_LCD_TYPES_H_



typedef enum
{
	LCD_E_OK,
	LCD_E_NOT_OK
}E_LCD_ErrorType;

typedef signed char LCD_commandType;
typedef signed char LCD_dataType;
typedef unsigned char LCD_row;
typedef unsigned char LCD_column;
typedef unsigned long int LCD_integer;
typedef const signed char *LCD_string;


#endif /* HAL_LCD_TYPES_H_ */
