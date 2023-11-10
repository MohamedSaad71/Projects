/*
 * App.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */

#include "App.h"
S_DCMOTOR S_DC={'B','B','B',3,5,6,1};

S_RTCData RTCData = {6,11,23,7,11,46,50};
//char udata=0;
// void u_receive()
// {
// 	udata =	MCAL_UART_receive_sysch();
// }
extern unsigned char lockedFlag;
extern unsigned char onFlag ;

void App_init()
{
	TWI_init();
	MCAL_ADC_INIT();
	HAL_LCD_init();

	HAL_DCMOTOR_Einit(&S_DC);
	HAL_IR_Init();
	HAL_BUZZER_INIT(DIO_PORTC, 6);
	I2C_Init();
	HAL_RTC_Init(&RTCData);

	HAL_Solenoid_init();
	HAL_LDR_Init();
	MCAL_UART_init(9600);
	//MCAL_UART_setCAllBACK(u_receive,receive_complete);
	HAL_SERVO_INIT(PIN_D4);
	HAL_SERVO_INIT(PIN_D5);
	SET_BIT(DIO_DDRD, 4);
	SET_BIT(DIO_DDRD, 5);
	HAL_LED_INIT(AC_LED_PORT, AC_LED_PIN);
	HAL_LED_OFF(AC_LED_PORT,AC_LED_PIN);
	HAL_LED_INIT(LIVING_LED_PORT, LIVING_LED_PIN);
	HAL_LED_OFF(LIVING_LED_PORT, LIVING_LED_PIN);
}
void App_start()
{
	HAL_LCD_displaystringRowColumn("Welcome",0,1);
	HAL_LCD_displaystringRowColumn("Open door 'O'",1,1);
	HAL_LCD_displaystringRowColumn("Lock the house 'L'",2,1);
	HAL_LCD_displaystringRowColumn("Turn features on'N'",3,1);
	char h = MCAL_UART_receive_sysch();
	switch(h)
	{
	case 'O':
		HAL_LCD_clearScreen();
		HAL_LCD_sendCharacter('O');
		//char p = Login();
		//		HAL_LCD_displaystringRowColumn("P:",0,0);
		//		HAL_LCD_integerToString(p);
		//		_delay_ms(3000);

		SERVICE_OPEN_DOOR();
		break;
	case 'L':
		HAL_LCD_clearScreen();
		HAL_LCD_sendCharacter('L');
		lockHouse();
		break;
	case 'N':
		HAL_LCD_clearScreen();
		HAL_LCD_sendCharacter('N');
		SERVICE_SET_ON_FLAG();
		break;
	case 'C':
		HAL_LCD_clearScreen();
		HAL_LCD_sendCharacter('C');
		Enter_Password();
		break;
	default:
		HAL_LCD_clearScreen();
		HAL_LCD_sendString("Wrong Entry");
		break;

	}

	//	SERVICE_TempControl();
	//	SERVICE_LEDS_Control();
	//	SERVICE_Curtain_Control();
	//SERVICE_Check_IR();
	//SERVICE_DisplayDateTime(&RTCData);
}
