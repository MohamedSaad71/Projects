/*
 * lcd.c
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#include "lcd.h"

static void Trigger_Enable();
static void Set_Cursor_Pos(uint8 row,uint8 column);
void LCD_Init(void)
{
	_delay_ms(20);
	LCD_Send_Command(0x33);
	LCD_Send_Command(0x32);
	LCD_Send_Command(_LCD_4BIT_MODE_2_LINE);
	LCD_Send_Command(_LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF);
	LCD_Send_Command(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
	LCD_Send_Command(_LCD_DDRAM_START);
	LCD_Send_Command(_LCD_CLEAR);
}
void LCD_Send_Command(uint8 command)
{
	Dio_Write(RS, LOW);
	Dio_Write(RW, LOW);

	(BIT_IS_SET(command,7)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(BIT_IS_SET(command,6)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(BIT_IS_SET(command,5)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(BIT_IS_SET(command,4)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
	(BIT_IS_SET(command,3)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(BIT_IS_SET(command,2)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(BIT_IS_SET(command,1)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(BIT_IS_SET(command,0)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
}
void LCD_Send_Char(uint8 _char)
{
	Dio_Write(RS, HIGH);
	Dio_Write(RW, LOW);

	(BIT_IS_SET(_char,7)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(BIT_IS_SET(_char,6)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(BIT_IS_SET(_char,5)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(BIT_IS_SET(_char,4)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
	(BIT_IS_SET(_char,3)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(BIT_IS_SET(_char,2)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(BIT_IS_SET(_char,1)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(BIT_IS_SET(_char,0)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
}
void LCD_Send_Char_Pos(uint8 _char,uint8 row,uint8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_Char(_char);
}
void LCD_Send_String(uint8 *string)
{
	while(*string !='\0')
	{
		LCD_Send_Char(*string++);
	}
}
void LCD_Send_String_Pos(uint8 *string,uint8 row,uint8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_String(string);
}

void LCD_Send_Number(uint32 num)
{
	 uint8 arr[10],i=0,j=0;
		   if(num == 0)
		   {
			   LCD_Send_Char('0');
		   }
		   else
		   {
			   while(num)
			   {
					arr[i]=num%10+'0';
					num/=10;
					i++;
			   }
			   for(j=i;j>0;j--)
			   {
				   LCD_Send_Char(arr[j-1]);
			   }
		   }
}
void LCD_Send_Number_Pos(uint32 num,uint8 row,uint8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_Number(num);
}

static void Trigger_Enable()
{
	Dio_Write(EN,HIGH);
	_delay_us(10);
	Dio_Write(EN,LOW);
	_delay_us(2000);
}
static void Set_Cursor_Pos(uint8 row,uint8 column)
{
	column--;
	switch(row){
	            case ROW1: LCD_Send_Command((0x80 + column)); break;
	            case ROW2: LCD_Send_Command((0xc0 + column)); break;
	            default:;
	        }
}
