/*
 * EPROM.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */
#include "Bits.h"
#include "I2C.h"
#include "EEPROM.h"

uint8 addressHigh;
uint8 addressLow;

void EEPROM_write_data(uint16 address, uint8 data){
	addressHigh = (address>>EEPROM_SHIFT);
	addressLow = (address & EEPROM_LOW_MASK);

	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(EEPROM_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*High address byte*/
	I2C_write_byte(addressHigh);
	I2C_wait();
	I2C_get_ack();
	/*Low address byte*/
	I2C_write_byte(addressLow);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(data);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

uint8 EEPROM_read_data(uint16 address){
	uint8 data;
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(EEPROM_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*High address byte*/
	I2C_write_byte(addressHigh);
	I2C_wait();
	I2C_get_ack();
	/*Low address byte*/
	I2C_write_byte(addressLow);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(EEPROM_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Change to receiver mode*/
	I2C_tx_rx_mode(I2C_RX_MODE);
	I2C_nack();
	/*Dummy read*/
	data = I2C_read_byte();
	I2C_wait();
	/*Stop*/
	I2C_stop();
	data = I2C_read_byte();
	/*Data return*/
	return (data);
}

