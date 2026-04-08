/*
 * keypad.c
 *
 * Created: 7/24/2025 7:50:34 PM
 *  Author: Youssif
 */ 
#define F_CPU  16000000UL

#include <util/delay.h>
#include "keypad.h"
#include "dio.h"


#define ROW_NO  4
#define COL_NO	4

u8 keypad_keyLayout[ROW_NO][COL_NO] =
{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};



static u8 keypad_getColumn(void)
{
	u8 loc_col = 255 ;
	if (dio_readPin(KPAD_COL0_PORT, KPAD_COL0_PIN) == LOW)
	{
		loc_col =0;
	}
	else if (dio_readPin(KPAD_COL1_PORT, KPAD_COL1_PIN) == LOW)
	{
		loc_col =1;
	}
	else if (dio_readPin(KPAD_COL2_PORT, KPAD_COL2_PIN) == LOW)
	{
		loc_col =2;
	}
	else if (dio_readPin(KPAD_COL3_PORT, KPAD_COL3_PIN) == LOW)
	{
		loc_col =3;
	}
	else
	{
		/* do nothing*/
	}
	return loc_col;
}

static u8 keypad_getRow(u8 loc_col)
{
	u8 loc_row =255;
	dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, LOW);
	dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
	dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
	dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
	if (keypad_getColumn() == loc_col)
	{
		loc_row =0;
	}
	else
	{
		dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
		dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, LOW);
		dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
		dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
		if (keypad_getColumn() == loc_col)
		{
			loc_row =1;
		}
		else
		{
			dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
			dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
			dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, LOW);
			dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
			if (keypad_getColumn() == loc_col)
			{
				loc_row =2;
			}
			else
			{
				dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
				dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
				dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
				dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, LOW);
				if (keypad_getColumn() == loc_col)
				{
					loc_row =3;
				}
				else
				{
					loc_row =255;
				}
			}
		}
	}
	return loc_row;
}

static void Keypad_reset(void)
{
	dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, LOW);
	dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, LOW);
	dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, LOW);
	dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, LOW);
}
void keypad_init(void)
{
	dio_setPinDirection(KPAD_ROW0_PORT, KPAD_ROW0_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW1_PORT, KPAD_ROW1_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW2_PORT, KPAD_ROW2_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW3_PORT, KPAD_ROW3_PIN, OUTPUT);
	
	dio_setPinDirection(KPAD_COL0_PORT, KPAD_COL0_PIN, INPUT);
	dio_setPinDirection(KPAD_COL1_PORT, KPAD_COL1_PIN, INPUT);
	dio_setPinDirection(KPAD_COL2_PORT, KPAD_COL2_PIN, INPUT);
	dio_setPinDirection(KPAD_COL3_PORT, KPAD_COL3_PIN, INPUT);
	
	Keypad_reset();
}


boolean keypad_keyIsPressed(void)
{
	if (
	dio_readPin(KPAD_COL0_PORT, KPAD_COL0_PIN) == LOW ||
	dio_readPin(KPAD_COL1_PORT, KPAD_COL1_PIN) == LOW ||
	dio_readPin(KPAD_COL2_PORT, KPAD_COL2_PIN) == LOW ||
	dio_readPin(KPAD_COL3_PORT, KPAD_COL3_PIN) == LOW
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

u8 keypad_getKeyPressed(void)
{
	u8 loc_row=0;
	u8 loc_col=0;
	u8 loc_key =0;
	
	loc_col = keypad_getColumn();
	loc_row = keypad_getRow(loc_col);
	
	Keypad_reset();
	if ((loc_row < ROW_NO) && (loc_col < COL_NO))
	{
		loc_key = keypad_keyLayout[loc_row][loc_col];
	}
	else
	{
		loc_key = 255;
	}
	_delay_ms(50);
	return loc_key;
}