/*
 * testing1.c
 *
 * Created: 6/21/2023 9:17:50 AM
 * Author : pc
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include "dht.h"


uint16_t T,H;

int main(void)
{
	
	LCD_init();
    
	LCD_moveCursor(0,0);
	LCD_displayString("Humadity:");
	LCD_moveCursor(0,12);
	LCD_displayString("%");
	
	LCD_moveCursor(1,0);
	LCD_displayString("Temp:");
	LCD_moveCursor(1,12);
	LCD_displayString("C");
	
	
	
    while (1) 
    {
		Request();
		Response();
		

 		uint16_t t = get_Temp();
		 Request();
		 Response();
		 
 		uint16_t h = get_Humadity();
		 
		 LCD_moveCursor(0,9);
		 LCD_intgerToString(h);
		 
		 LCD_moveCursor(1,9);
		 LCD_intgerToString(t);
		 
		 


    }
}

