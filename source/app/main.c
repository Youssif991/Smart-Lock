/*
 * NTI_PASSWORD_ASSIGNMENT.c
 *
 * Created: 7/24/2025 7:04:09 PM
 * Author : Youssif
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Password.h"
#include "led.h"
#include "lcd.h"

int main(void)
 {
	 /*a line to reset the password*/
	// eeprom_write(PASSWORD_FLAG_ADDR, 0x00);
	lcd_init();
	keypad_init();
	led_init();

	u8 correct[] = "Correct";
	u8 notcorrect[] = "Wrong";

	if (!is_password_set()) 
	{
		bool matched = false;
		while (!matched)
		 {
			CLEAR_DISPLAY;
			lcd_displaystr("Set Password:");
			lcd_gotoRowColumn(1, 0);
			setpassword();

			CLEAR_DISPLAY;
			lcd_displaystr("Confirm Password:");
			lcd_gotoRowColumn(1, 0);
			matched = checkpassword();  

			CLEAR_DISPLAY;
			if (matched)
			
			 {
				lcd_displaystr("Password Saved");
				led_on(LED2);
			 } 
			 
			else 
			
			{
				lcd_displaystr("Mismatch");
				led_on(LED1);
		    }
			
			_delay_ms(1000);
			led_off(LED1);
			led_off(LED2);
		}
	}


	bool check = false;
	while (!check)
	 {
		CLEAR_DISPLAY;
		lcd_displaystr("Enter Password:");
		lcd_gotoRowColumn(1, 0);
		check = checkpassword();

		CLEAR_DISPLAY;
		if (check)
		{
			lcd_displaystr(correct);
			led_on(LED2);
			
		}
		
		else 
		
		{
			lcd_displaystr(notcorrect);
			led_on(LED1);
		}
		_delay_ms(1000);
		led_off(LED1);
		led_off(LED2);
	}

	while (1) 
	{ 
		
    }
}

