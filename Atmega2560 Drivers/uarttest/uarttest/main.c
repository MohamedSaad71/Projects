/*
 * uarttest.c
 *
 * Created: 6/13/2023 12:30:56 PM
 * Author : pc
 */ 


#include <avr/io.h>
#include "common_macros.h"
#include "UART.h"
#include "std_types.h"
#include "gpio.h"
#include "micros_config.h"
#include "MemMap.h"

int main(void)
{
	UART0_init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		UART0_sendString("abcde#");
    }
}

