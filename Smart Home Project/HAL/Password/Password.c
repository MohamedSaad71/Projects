/*
 * Password.c
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */


#include "Password.h"
#include "../../MCAL/UART/Uart_interface.h"
#include "../LCD/lcd_Interface.h"
#include "../../MCAL/EEPROM/external_eeprom.h"
#include "util/delay.h"

u8Value Enter_Password(void)
{
	Set_flag=0;

	int i=0;
	int j=0;
	HAL_LCD_clearScreen();
	_delay_ms(50);

	HAL_LCD_displaystringRowColumn("EnterPassword", 1, 1);
	_delay_ms(5000);

	for(i=0;i<4;i++)
	{
		HAL_LCD_integerToString(51);
		Get_character= MCAL_UART_receive_sysch();
		temp_password[i]=Get_character;
		HAL_LCD_goToRowColumn(2, i+1);
		HAL_LCD_sendCharacter('*');
		//LCD_Send_Char_Pos('*',2,i+1);
	}
	_delay_ms(50);
	j=0;
	HAL_LCD_clearScreen();
	HAL_LCD_displaystringRowColumn("EnterPasswordagain", 1, 1);
	_delay_ms(5000);
	while(j<PASSWORD_LENGTH)
	{
		Get_character= MCAL_UART_receive_sysch();
		_delay_ms(100);
		temp2_password[j] = Get_character;
		HAL_LCD_goToRowColumn(2, j+1);
		HAL_LCD_sendCharacter('*');

		_delay_ms(50);
		j++;
	}
	_delay_ms(500);

	for(int x=0;x<PASSWORD_LENGTH;x++)
	{
		if(temp_password[x]!=temp2_password[x])
		{

			Set_flag=1;
		}
	}

	if(Set_flag == 1)
	{
		first=temp_password[0];
		second=temp_password[1];
		third =temp_password[2];
		fourth=temp_password[3];
		EEPROM_writeByte(EEPROM3_ADDR,first);
		EEPROM_writeByte(EEPROM4_ADDR,second);
		EEPROM_writeByte(EEPROM5_ADDR,third);
		EEPROM_writeByte(EEPROM6_ADDR,fourth);

		HAL_LCD_clearScreen();
		HAL_LCD_displaystringRowColumn("Done", 1, 1);
		_delay_ms(500);


	}


	return Set_flag;
}

u8Value Login()
{
	//int m=0;

	HAL_LCD_clearScreen();
	_delay_ms(50);
	HAL_LCD_displaystringRowColumn("EnterPassword", 1, 1);
	_delay_ms(50);
	int j=0;
	while(j<PASSWORD_LENGTH)
	{

		Get_character= MCAL_UART_receive_sysch();

		//LCD_moveCursor(1,1);
		temp_password[j] = Get_character;
		HAL_LCD_sendCharacter('*');
		j++;
		_delay_ms(100);
	}
	EEPROM_readByte(EEPROM3_ADDR, &first);
	EEPROM_readByte(EEPROM3_ADDR, &second);
	EEPROM_readByte(EEPROM3_ADDR, &third);
	EEPROM_readByte(EEPROM3_ADDR, &fourth);
	if(first== (char)temp_password[0] && second == (char)temp_password[1] && third == (char)temp_password[2] && fourth == (char)temp_password[1])
	{
		login_flag =1;

	}

	return login_flag;

}
