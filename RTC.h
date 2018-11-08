/*
 * RTC.h
 *
 *  Created on: Nov 7, 2018
 *      Author: Andy
 */

#ifndef RTC_H_
#define RTC_H_

/*Addresses*/
#define RTC_ADDRESS 0xDE
#define RTC_SECONDS 0x00
#define RTC_MINUTES 0x01
#define RTC_HOURS	0x02
#define RTC_WEEKDAY 0x03
#define RTC_DAY 	0x04
#define RTC_MONTH 	0x05
#define RTC_YEAR 	0x06

/*Predetermine set values*/
#define RTC_SECONDS_MASK 0xD9
#define RTC_MINUTES_MASK 0x19
#define RTC_HOURS_MASK	 0x17
#define RTC_WEEKDAY_MASK 0x24
#define RTC_DAY_MASK 	 0x07

/*Set Time and Date*/
void set_seconds();
void set_minutes();
void set_hours();
void set_weekday();
void set_day();
void set_month();
void set_year();

#endif /* RTC_H_ */
