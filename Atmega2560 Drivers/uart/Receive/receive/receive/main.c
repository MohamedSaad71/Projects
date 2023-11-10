
#define F_CPU 8000000UL

#include <avr/io.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "UART.h"

uint8 str[100];
uint8 received;
int main(void)
{
	UART0_init(); // Initialize UART0 communication
	LCD_init();
	LCD_displayString("GPS: ");
	
	
	while(1)
	{
		received = UART0_ReceiveData();
		LCD_displayCharacter((char)received);
	
		
	}
}