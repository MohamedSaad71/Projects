//ATMEGA16
#ifndef DIO_H_
#define DIO_H_

void write_nibble(char port,char nibble,char data);
void DIO_vsetbitdir(unsigned char port,unsigned char pin, char dir);
void DIO_vsetportdir(unsigned char port, char dir);
void DIO_vpinwrite(char port, char pin, char data);
void DIO_vportwrite(char port, char data);
unsigned char DIO_u8pinread(char port, char pin);
unsigned char DIO_u8portread(char port);
void Pullup_enable(char port, char pin, char enable);
	
#endif 