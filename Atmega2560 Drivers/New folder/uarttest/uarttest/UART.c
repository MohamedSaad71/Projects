
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(long USART_BAUDRATE)
{
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);/* Turn on transmission and reception */
	UCSR0C |= (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);/* Use 8-bit character sizes */
	UBRR0L = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRR0H = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

unsigned char UART_RxChar()
{
	while ((UCSR0A & (1 << RXC0)) == 0);/* Wait till data is received */
	return(UDR0);			/* Return the byte*/
}

void UART_TxChar(char ch)
{
	while (! (UCSR0A & (1<<UDRE0)));	/* Wait for empty transmit buffer*/
	UDR0 = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

int main()
{
	char c;
	UART_init(9600);
	
	UART_SendString("\n\t Echo Test ");
	while(1)
	{
		c=UART_RxChar();
		UART_TxChar(c);
	}
}