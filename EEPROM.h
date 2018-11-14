/*
 * EPROM.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */

#ifndef EEPROM_H_
#define EEPROM_H_

/*EEPROM address, control byte*/
#define EEPROM_ADDRESS 0x0A
/*Shift for obtaining high address*/
#define EEPROM_SHIFT (8u)
/*Mask for obtaining low address*/
#define EEPROM_LOW_MASK 0xFF


/*Writes the wanted data in a certain address in the ROM*/
void EEPROM_write_data(uint16 address, uint8 data);
/*Reads the contain data in a certain address*/
uint8 EEPROM_read_data(uint16 address);


#endif /* EEPROM_H_ */
