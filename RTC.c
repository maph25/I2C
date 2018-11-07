/*
 * RTC.c
 *
 *  Created on: Nov 7, 2018
 *      Author: Andy
 */
#include "RTC.h"
#include "I2C.h"
#include "Bits.h"

void set_second(){
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
	/*Data*/
	I2C_write_byte(RTC_SECONDS_MASK); /*Oscillator enable, 59s*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void set_minutes(){
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
	/*Data*/
	I2C_write_byte(RTC_MINUTES_MASK); /*Oscillator enable, 59s*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void set_hours(){
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
	/*Data*/
	I2C_write_byte(RTC_HOURS_MASK); /*Oscillator enable, 59s*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void set_weekday(){

}

void set_day(){

}

void set_month(){

}

void set_year(){

}
