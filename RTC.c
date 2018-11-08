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
	I2C_write_byte(RTC_MINUTES_MASK); /*19m*/
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
	I2C_write_byte(RTC_HOURS_MASK); /*17h*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void set_weekday(){
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
	/*Data*/
	I2C_write_byte(RTC_WEEKDAY_MASK); /*Wednesday*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();

}

void set_day(){
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
	/*Data*/
	I2C_write_byte(RTC_DAY_MASK); /*07*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();
}

void set_month(){
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
	/*Data*/
	I2C_write_byte(RTC_MONTH_MASK); /*11, November*/
	I2C_wait();
	I2C_get_ack();
	/*Stop*/
	I2C_stop();

}

void set_year(){

}
