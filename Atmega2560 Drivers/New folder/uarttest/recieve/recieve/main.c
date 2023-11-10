#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "UART.h"
#include "lcd.h"

uint8 recieved=0;
int main() {
	// Initialize the USART
	UART0_init();
	LCD_init();

	// Enable global interrupts
	sei();
	//LCD_displayString("Welcome");
	while (1) {
		// Wait for a complete sentence to be received
		recieved=UART0_ReceiveData();
		LCD_moveCursor(0,0);
		LCD_intgerToString(recieved);
		
	}

	return 0;
}

// USART receive interrupt handler
