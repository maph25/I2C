/*
 * EPROM.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */

#ifndef EEPROM_H_
#define EEPROM_H_

/*Writes the wanted data in a certain address in the ROM*/
void EEPROM_write_data(uint16 address, uint8 data);
/*Reads the contain data in a certain address*/
uint8 EEPROM_read_data(uint16 address);


#endif /* EEPROM_H_ */
