/*
 * lcd_cfg.h
 *
 * Created: 7/24/2025 7:52:45 PM
 *  Author: Youssif
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "dio.h"

#define LCD_DATA_PORT		DIO_PORTD

#define LCD_RS_PORT			DIO_PORTC
#define LCD_RS_PIN          DIO_PIN0

#define LCD_RW_PORT			DIO_PORTC
#define LCD_RW_PIN			DIO_PIN1

#define LCD_EN_PORT			DIO_PORTC
#define LCD_EN_PIN			DIO_PIN2



#endif /* LCD_CFG_H_ */