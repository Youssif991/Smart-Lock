/*
 * eeprom.h
 *
 * Created: 7/24/2025 8:02:38 PM
 *  Author: Youssif
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

u8 eeprom_read(u16 addr);
void eeprom_write(u16 addr, u8 data);


#endif /* EEPROM_H_ */