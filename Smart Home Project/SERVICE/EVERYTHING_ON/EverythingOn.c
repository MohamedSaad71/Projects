/*
 * EverythingOn.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#include "EverythingOn.h"
//extern udata;
//void u_receive()
//{
//	udata =	MCAL_UART_receive_sysch();
//}
char udata =0;
void SERVICE_EVERYTHING_ON()
{

//	MCAL_UART_setCAllBACK(u_receive,receive_complete);
	while((lockedFlag == 0) && (udata != 'S'))
	{
		//MCAL_UART_RXC_Enable();
		SERVICE_TempControl();
		SERVICE_Curtain_Control();
		SERVICE_LEDS_Control();
		SERVICE_DisplayDateTime(&RTCData);
		//udata = MCAL_UART_receive_sysch();
		Uart_ReceiveByte_Unblock(&udata);
	}
	udata = 0;
}

