/*
 * GccApplication1.c
 *
 * Created: 6/11/2023 3:18:49 PM
 * Author : pc
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt.h"
#include "common_macros.h"
#include "GPIO.h"
#include "std_types.h"
#include "micros_config.h"


ISR(INT0_vect)
{
	TOGGLE_BIT(PORTC,0); //Toggle value of PIN 0 in PORTC (Led Toggle)
}

int main(void)
{
	sei();
	INT0_Init();              // Enable external INT0
	GPIO_setupPortDirection(2,PORT_OUTPUT);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

