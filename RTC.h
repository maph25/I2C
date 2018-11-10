/*
 * RTC.h
 *
 *  Created on: Nov 7, 2018
 *      Author: Andy
 */

#ifndef RTC_H_
#define RTC_H_

#include "Bits.h"

/*Addresses*/
#define RTC_ADDRESS 		0xDE
#define RTC_SLAVE_ADDRESS	0xDF
#define RTC_SECONDS 		0x00
#define RTC_MINUTES 		0x01
#define RTC_HOURS			0x02
#define RTC_WEEKDAY 		0x03
#define RTC_DAY 			0x04
#define RTC_MONTH 			0x05
#define RTC_YEAR 			0x06
/*Init mask*/
#define RTC_INIT 			0x80

/*Enable oscillator*/
void RTC_init();


/*Set Time and Date*/
void RTC_set_seconds(uint8 second);
void RTC_set_minutes(uint8 minute);
void RTC_set_hours(uint8 hour);
void RTC_set_weekday(uint8 weekday);
void RTC_set_day(uint8 day);
void RTC_set_month(uint8 month);
void RTC_set_year(uint8 year);

/*Get Time and Date*/
uint8 RTC_get_seconds();
uint8 RTC_get_minutes();
uint8 RTC_get_hours();
uint8 RTC_get_weekday();
uint8 RTC_get_day();
uint8 RTC_get_month();
uint8 RTC_get_year();

#endif /* RTC_H_ */
