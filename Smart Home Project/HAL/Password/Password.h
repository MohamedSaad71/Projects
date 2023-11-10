/*
 * Password.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "Password._types.h"

#define Max 1
#define PASSWORD_LENGTH 4
#define EEPROM_ADDR  0x80
#define EEPROM2_ADDR 0xF0
#define EEPROM3_ADDR 0x0311
#define EEPROM4_ADDR 0x0321
#define EEPROM5_ADDR 0x0331
#define EEPROM6_ADDR 0x0341
#define EEPROM7_ADDR 0x03
#define EEPROM8_ADDR 0x04
#define Size 5  //(Number of users * password Length)+1


u8Value first;
u8Value second;
u8Value third;
u8Value fourth;

u8Value temp;

u8Value temp_password[Max]; //the array which holds the first trial of entering the password as signup
u8Value  temp2_password[Max]; // the array which holds the second trial of entering the password

u8Value Set_flag; // Flag that indicate the user has entered the password two times identical
u8Value login_flag; // flag that indicate that this password ias already defined for a user

u8Value Get_character;


u8Value Enter_Password(void);
u8Value Login();

#endif /* PASSWORD_H_ */
