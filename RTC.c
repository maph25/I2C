/*
 * RTC.c
 *
 *  Created on: Nov 7, 2018
 *      Author: Andy
 */
#include "RTC.h"
#include "I2C.h"
#include "Bits.h"

static uint8_t data;

void RTC_init(){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_SECONDS);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(RTC_INIT);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();

}

void RTC_set_seconds(uint8 second){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_SECONDS);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(second);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void RTC_set_minutes(uint8 minute){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_MINUTES);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(minute);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void RTC_set_hours(uint8 hour){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_HOURS);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(hour);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void RTC_set_weekday(uint8 weekday){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_WEEKDAY);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(weekday);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();

}

void RTC_set_day(uint8 day){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_DAY);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(day);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void RTC_set_month(uint8 month){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_MONTH);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(month);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();

}

void RTC_set_year(uint8 year){
	/*Start*/
	I2C_start();
	I2C_tx_rx_mode(I2C_TX_MODE);
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_YEAR);
	I2C_wait();
	I2C_get_ack();
	/*Data*/
	I2C_write_byte(year);
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

uint8 RTC_get_seconds(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_SECONDS);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_minutes(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_MINUTES);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_hours(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_HOURS);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_weekday(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_WEEKDAY);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_day(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_DAY);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_month(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_MONTH);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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

uint8 RTC_get_year(){
	/*Start*/
	I2C_start();
	/*Control byte*/
	I2C_write_byte(RTC_ADDRESS);
	I2C_wait();
	I2C_get_ack();
	/*Address byte*/
	I2C_write_byte(RTC_YEAR);
	I2C_wait();
	I2C_get_ack();
	/*Restart*/
	I2C_repeted_start();
	/*Control byte*/
	I2C_write_byte(RTC_SLAVE_ADDRESS);
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
