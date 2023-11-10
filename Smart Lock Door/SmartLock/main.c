#include <avr/io.h>
#include <avr/eeprom.h>

#include "MCAL/Dio/Dio.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/Timer0_PWM/Timer0_PWM.h"
#include "HAL/DC_Motor/DC_Motor.h"
#include "MCAL/UART/uart.h"


/*Functions Prototypes*/
void Enter_Password();
void Login();


#define Max 10 
#define PASSWORD_LENGTH 4 
#define EEPROM_ADDR  0x80 
#define EEPROM2_ADDR 0xF0 
#define EEPROM3_ADDR 0xFF 
#define EEPROM4_ADDR 0x00
#define EEPROM5_ADDR 0x06
#define EEPROM6_ADDR 0x02
#define EEPROM7_ADDR 0x03
#define EEPROM8_ADDR 0x04
#define Size 41  //(Number of users * password Length)+1



uint8 temp;

static password[Size]; //Array of password saved in EEPROM
unsigned char  temp1_password[Max]; //the array which holds the first trial of entering the password as signup
unsigned char  temp2_password[Max]; // the array which holds the second trial of entering the password 
unsigned char first;
unsigned char second;
unsigned char third;
unsigned char fourth;

int Data[2]; //0 index holds the number of users, index 1 holds the password index 
uint8 Set_flag=0; // Flag that indicate the user has entered the password two times identical
uint8 login_flag=0; // flag that indicate that this password ias already defined for a user 
unsigned char password_index;
unsigned char  NumOfUsers;
char c;
uint8 wrong_flag=0; // flag that indicates how many timer the user enter wrong password
uint8 users_flag=0; // flag that indicates number of users excedd the mas or not
uint8 flag=0;

int main(void)
{
	
		
	Dio_init();
	LCD_Init();
	DcMotor_Init();
	UART_init(9600);
	DDRA=0xff;
	DDRD |= (1<<4); // pin for the selonoid
	DDRA |=(1<<1);
	PORTA =0xFF;

 	DDRB |=(1<<6); // GREEN LED
 	DDRB |= (1<<7); //Red LED
 	PORTB &= ~(1<<6); //Disable the buzzer at the beginning
 	PORTB &= ~(1<<7);
   // NumOfUsers=0;

	int i=0;
	
	
	while(1)
	{
	
		
				

		eeprom_read_block((const uint8*)Data, (void*)0, 2);
 		eeprom_read_block((const void*)&password, (void*)0, sizeof(password));
 		flag=eeprom_read_byte(EEPROM4_ADDR);
 		temp =Data[0];
 		if(temp ==0 )
 		{
 			password_index=1;
 			flag=1;
 			
 		}
 
 		else
 		{
 			password_index = ((temp *4)+1);
 		}
 		if(temp >Size+10)
 		{
 			password_index=0;
 		}
 		eeprom_write_byte(EEPROM2_ADDR,password_index);
 		LCD_Send_String_Pos(" Sign Up press:1",1,1);
 		LCD_Send_String_Pos("log in Press:2",2,1);
 		

 		_delay_ms(5000);
 		 c =UART_RxChar();
 		_delay_ms(50);
 		if((int)c!=0 )
 		{

 			if(c == '1')
 			{
 				if(NumOfUsers>=10)
 				{
 					LCD_Send_Command(_LCD_CLEAR);
 					_delay_ms(50);
 					LCD_Send_String_Pos(" Exceed Num",1,1);
 					LCD_Send_String_Pos("of users",2,2);
 					_delay_ms(5000);
 					users_flag=1;
 					_delay_ms(2000);
 				}
 				if(users_flag==0)
 				{
 					Enter_Password();
 					if(Set_flag == 1)
 					{
 						LCD_Send_Command(_LCD_CLEAR);
 						_delay_ms(50);
 						LCD_Send_String_Pos(" Again",1,1);
 						_delay_ms(5000);
 					}
 					else if(Set_flag == 0)
 					{
 						LCD_Send_Command(_LCD_CLEAR);
 						_delay_ms(50);
 						LCD_Send_String_Pos(" Done",1,1);
 						_delay_ms(5000);
 					
 						
 					}
 				}
 				
 			}
 			
 			else if(c == '2')
 			{
 				Login();
 				if(login_flag == 1)
 				{
 					_delay_ms(1000);
 					LCD_Send_Command(_LCD_CLEAR);
 					_delay_ms(50);
 					LCD_Send_String_Pos(" Welcome",1,1);
 					
 					PORTD |=(1<<4);
 					_delay_ms(8000);
 					DcMotor_Rotate(DC_MOTOR_CW,100);
 					_delay_ms(8000);
 					DcMotor_Rotate(DC_MOTOR_ACW,100);
 					_delay_ms(8000);
 					DcMotor_Rotate(DC_MOTOR_STOP,0);
 					_delay_ms(7000);
 					LCD_Send_Command(_LCD_CLEAR);
 					_delay_ms(50);
 					PORTD &= ~(1<<4);
 				}
 				else
 				{
 					LCD_Send_Command(_LCD_CLEAR);
 					_delay_ms(50);
 					LCD_Send_String_Pos(" Wrong Password",1,1);
 					wrong_flag++;
 					PORTB |=(1<<7);
 					_delay_ms(5000);
 					uint8 stop=0;
 					while(wrong_flag!=3 && stop==0)
 					{
 						LCD_Send_Command(_LCD_CLEAR);
 						_delay_ms(50);
 						Login();
 						if(login_flag!=1)
 						{
 							wrong_flag++;
 							
						}
 						else
 						{
 							stop=1;
 						}
 					}
 					PORTB &= ~(1<<7);
 					if(wrong_flag==3)
 					{
 						wrong_flag=0;
 						LCD_Send_Command(_LCD_CLEAR);
 						_delay_ms(50);
 						LCD_Send_String_Pos("Exceeded Number of ",1,1);
 						LCD_Send_String_Pos("Trials ",2,1);
						 PORTB |=(1<<7);
 						_delay_ms(5000);
 						Dio_Write(PORTB_6,HIGH);
 						_delay_ms(8000);
 						Dio_Write(PORTB_6,LOW);
 						_delay_ms(8000);
 						Dio_Write(PORTB_6,HIGH);
 						_delay_ms(8000);
 						Dio_Write(PORTB_6,LOW);
 						_delay_ms(8000);
 					}
 				}
 				
 				
 			}
 			
 		}
 		
 		
 	}

}



void Enter_Password(void)
{
	Set_flag=0;
	
	int i=0;
	int j=0;
	LCD_Send_Command(_LCD_CLEAR);
	_delay_ms(50);
	LCD_Send_String_Pos("EnterPassword",1,1);
	_delay_ms(5000);
	

for(i=0;i<4;i++)
{
	c= UART_RxChar();
	_delay_ms(100);
	temp1_password[i]=c;
	LCD_Send_Char_Pos('*',2,i+1);
	_delay_ms(500);
}

	_delay_ms(5000);
	LCD_Send_Command(_LCD_CLEAR);
	_delay_ms(50);
	j=0;
	LCD_Send_String_Pos(" Enter Pass.again:",1,1);
	_delay_ms(5000);
	while(j<PASSWORD_LENGTH)
	{
		c= UART_RxChar();
		_delay_ms(100);
		
		if(c!='0' )
		{
			temp2_password[j] = c;
			LCD_Send_Char_Pos('*',2,j+1);
			
			_delay_ms(50);
			j++;
			
		}
		
		
	}
	
	for(int x=0;x<PASSWORD_LENGTH;x++)
	{
		if(temp1_password[x]!=temp2_password[x])
		{
			Set_flag=1;
		}
	}
	
	if(Set_flag == 0)
	{
		if(NumOfUsers==0)
		{
			first=temp1_password[0];
			second=temp1_password[1];
			third =temp1_password[2];
			fourth=temp1_password[3];
			eeprom_write_byte(EEPROM5_ADDR,first);
			eeprom_write_byte(EEPROM6_ADDR,second);
			eeprom_write_byte(EEPROM7_ADDR,third);
			eeprom_write_byte(EEPROM8_ADDR,fourth);
		}
		else
		{
			for(int x=0;x<PASSWORD_LENGTH;x++)
			{
				password[password_index] = (char)temp1_password[x];
				
				password_index++;
				eeprom_write_block((const void*)&password, (void*)0, sizeof(password));
				eeprom_write_byte(EEPROM2_ADDR,password_index);
				
				
			}
		}
		
	

		
		
		NumOfUsers = Data[0];
		NumOfUsers++;
		eeprom_write_byte(EEPROM3_ADDR,NumOfUsers);
		if(NumOfUsers == 0)
		{
			NumOfUsers=1;
		}
		Data[0]=NumOfUsers;
		eeprom_write_block((const uint8*)Data, (void*)0, 2);
		
	}
	_delay_ms(5000);
}

void Login()
{
	
	unsigned char user;
	login_flag=0;
	first=eeprom_read_byte(EEPROM5_ADDR);
	second = eeprom_read_byte(EEPROM6_ADDR);
	third=eeprom_read_byte(EEPROM7_ADDR);
	fourth =eeprom_read_byte(EEPROM8_ADDR);
	NumOfUsers= eeprom_read_byte(EEPROM3_ADDR);
	
	LCD_Send_Command(_LCD_CLEAR);
	_delay_ms(50);
	LCD_Send_String_Pos("User Number: ",1,1);
	_delay_ms(50);
	user= UART_RxChar();
	_delay_ms(100);
	LCD_Send_Char_Pos(user,1,14);
	_delay_ms(1500);
	LCD_Send_Command(_LCD_CLEAR);
	
	_delay_ms(50);
	LCD_Send_String_Pos("Enter Password: ",1,1);
	_delay_ms(50);
	int j=0;
	while(j<PASSWORD_LENGTH)
	{
		
		c= UART_RxChar();
		_delay_ms(100);
		
		if(c!='0' )
		{
			temp1_password[j] = c;
			LCD_Send_Char_Pos('*',2,j+1);
			_delay_ms(50);
			j++;
			
		}
		_delay_ms(500);
		
	}
	
	if(user == '0')
	{
		if(first==temp1_password[0]&&second==temp1_password[1]&&third==temp1_password[2]&&fourth==temp1_password[3])
		{
			login_flag=1;
		}
	}
	
	else
	{
		
		
		char x= user ;
		int v=(int)x;
		v=v-49;
		int m=0;
		for(int i=0;i<=v;i++)
		{
			
			m=m+4;
		}
		m=m+1;
		
		



		_delay_ms(5000);
		uint8 index=0;
		
		if((char)password[m]== (char)temp1_password[index] && (char)password[m+1] == (char)temp1_password[index+1] && (char)password[m+2] == (char)temp1_password[index+2] && (char)password[m+3] == (char)temp1_password[index+3])
		{
			login_flag =1;
			
		}
		
		
		
	}
	
	
		
	
	
	
	
}
	
	
