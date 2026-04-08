/*
 * led.c
 *
 * Created: 7/25/2025 3:24:55 PM
 *  Author: Youssif
 */ 
#include "dio.h"
#include "led_types.h"
#include "led_cfg.h"

void led_init(void)
{
	dio_setPinDirection(LED1_PORT, LED1_PIN,OUTPUT);
	dio_setPinDirection(LED2_PORT, LED2_PIN,OUTPUT);
}

void led_on(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_writePin(LED1_PORT, LED1_PIN, HIGH);
		break;
		
		case LED2:
		dio_writePin(LED2_PORT, LED2_PIN, HIGH);
		break;
	}
}

void led_off(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_writePin(LED1_PORT, LED1_PIN, LOW);
		break;
		
		case LED2:
		dio_writePin(LED2_PORT, LED2_PIN, LOW);
		break;
	}
}

void led_toggle(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_flipPin(LED1_PORT, LED1_PIN);
		break;

		case LED2:
		dio_flipPin(LED2_PORT, LED2_PIN);
		break;
	}
}