/*
 * eeprom_registers.h
 *
 * Created: 7/24/2025 8:02:56 PM
 *  Author: Youssif
 */ 


#ifndef EEPROM_REGISTERS_H_
#define EEPROM_REGISTERS_H_

#include "std_types.h"

#define EEPROM_EEARH_REG   (*(volatile u8*)(0x3F))
#define EEPROM_EEARL_REG   (*(volatile u8*)(0x3E))

#define EEPROM_EEDR_REG    (*(volatile u8*)(0x3D))

#define EEPROM_EECR_REG    (*(volatile u8*)(0x3C))

#define EERE_BIT_NO			(0)
#define EEWE_BIT_NO			(1)
#define EEMWE_BIT_NO		(2)


#endif /* EEPROM_REGISTERS_H_ */