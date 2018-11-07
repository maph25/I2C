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
#define RTC_SECONDS
#define RTC_MINUTES
#define RTC_HOURS
#define RTC_WEEKDAY
#define RTC_DAY
#define RTC_MONTH
#define RTC_YEAR

/*Set Time and Date*/
void set_seconds();
void set_minutes();
void set_hours();
void set_weekday();
void set_day();
void set_month();
void set_year();

#endif /* RTC_H_ */
