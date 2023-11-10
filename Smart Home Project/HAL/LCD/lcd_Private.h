/*
 * lcd_Private.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
/* Display on/off control */
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
/* Display clear */
#define CLEAR_COMMAND 0x01
/* Entry mode set */
#define SHIFT_CURSOR_RIGHT 0x06
/* Set cursor location at position 0 */
#define SET_CURSOR_LOCATION 0x80

#define SHIFT_LEFT_LCD 0x18
#define SHIFT_RIGHT_LCD 0x1c

#define row1col1	0x40
#define row2col1	0x14
#define row3col1	0x54

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
