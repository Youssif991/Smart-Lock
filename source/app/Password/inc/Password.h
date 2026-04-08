/*
 * Password.h
 *
 * Created: 7/24/2025 8:06:43 PM
 *  Author: Youssif
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_

/* Includes section */
#include "std_types.h"
#include "eeprom.h"
#include "keypad.h"
#include <stdbool.h>

/*Macros section*/
#define MAX_PASSWORD_LEN 5
#define PASSWORD_FLAG_ADDR 0xFF
#define PASSWORD_SET 0xAA
#define PASSWORD_EEPROM_ADDR  0x00
#define CLEAR_DISPLAY lcd_sendCmd(0x01)

/*Functions definitions section*/
void setpassword(void);
bool checkpassword(void);
bool is_password_set(void);

#endif /* PASSWORD_H_ */
