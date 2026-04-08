/*
 * lcd.h
 *
 * Created: 7/24/2025 7:52:35 PM
 *  Author: Youssif
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "lcd_types.h"
#include "lcd_cfg.h"

void lcd_init(void);
void lcd_sendCmd(lcd_cmd_t cmd);
void lcd_displayChr(u8 chr);
void lcd_displaystr(u8 str[]);
void lcd_gotoRowColumn(u8 row, u8 col);
void lcd_displayNum_u8(u8 num);
void lcd_displayNum_u16(u16 num);


#endif /* LCD_H_ */