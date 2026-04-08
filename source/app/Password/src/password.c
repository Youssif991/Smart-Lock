/*
 * password.c
 *
 * Created: 7/24/2025 8:08:41 PM
 * Author: Youssif
 */ 

#include "Password.h"
#include "eeprom.h"
#include "keypad.h"
#include <util/delay.h>

/*Separate function to configure writing from the keypad*/
static void read_password_from_keypad(u8 *password_buffer)
 {
	for (u8 i = 0; i < MAX_PASSWORD_LEN; i++)
	 {
		while (!keypad_keyIsPressed());
		password_buffer[i] = keypad_getKeyPressed();
		while (keypad_keyIsPressed());
		_delay_ms(200);
		lcd_displayChr('*');
	}
}

/*The function to set password*/
void setpassword(void) 
{
	u8 first[MAX_PASSWORD_LEN];
	read_password_from_keypad(first);

	// Save to EEPROM
	for (u8 i = 0; i < MAX_PASSWORD_LEN; i++)
    {
		eeprom_write(PASSWORD_EEPROM_ADDR + i, first[i]);
		_delay_ms(5);
	}
	eeprom_write(PASSWORD_FLAG_ADDR, PASSWORD_SET);
	_delay_ms(5);
}

/* Checks entered password against EEPROM */
bool checkpassword(void) 
{
	u8 entered[MAX_PASSWORD_LEN];
	read_password_from_keypad(entered);

	for (u8 i = 0; i < MAX_PASSWORD_LEN; i++) 
	{
		u8 stored = eeprom_read(PASSWORD_EEPROM_ADDR + i);
		if (entered[i] != stored) return false;
	}
	return true;
}

/*Checks if password is set in EEPROM*/
bool is_password_set(void) 
{
	return (eeprom_read(PASSWORD_FLAG_ADDR) == PASSWORD_SET);
}

