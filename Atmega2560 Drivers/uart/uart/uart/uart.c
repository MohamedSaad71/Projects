 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "uart.h"
#include "avr/io.h" /* To use the UART Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

#define F_CPU 8000000UL

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART0_init(uint32 baud_rate)
{
	uint16 ubrr_value = 0;

	/* U2X = 1 for double transmission speed */
	UCSR0A = (1<<U2X0);

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/ 
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ01:00 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/ 	
	UCSR0C =  (1<<UCSZ00) | (1<<UCSZ01); 
	
	/* Calculate the UBRR register value */
	ubrr_value = (uint16)(((F_CPU / (baud_rate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRR0H = ubrr_value>>8;
	UBRR0L = ubrr_value;
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART0_sendByte(const uint8 data)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(BIT_IS_CLEAR(UCSR0A,RXC0)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR0 = data;

	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transmission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART0_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSR0A,RXC0)){}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
    return UDR0;		
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART0_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART0_sendByte(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}		
	*******************************************************************/
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART0_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART0_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART0_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
