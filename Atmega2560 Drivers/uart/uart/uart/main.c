/*
 * uart.c
 *
 * Created: 7/4/2023 11:49:25 AM
 * Author : pc
 */ 

#include <avr/io.h>
#include "uart.h"


#define Baud_Rate 9600


int main(void)
{
    UART0_init(Baud_Rate);
	
	uint8 data = 'b';
    while (1) 
    {
		UART0_sendByte(data);
    }
}

