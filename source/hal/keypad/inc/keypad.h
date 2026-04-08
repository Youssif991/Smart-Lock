/*
 * keypad.h
 *
 * Created: 7/24/2025 7:48:13 PM
 *  Author: Youssif
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "keypad_cfg.h"

void keypad_init(void);
boolean keypad_keyIsPressed(void);
u8 keypad_getKeyPressed(void);


#endif /* KEYPAD_H_ */