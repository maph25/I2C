/*
 * TeraTerm.c
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#include "TeraTerm.h"
#include "Bits.h"
#include "RTC.h"

TERATERM_clock_t Clock;
TERATERM_calendar_t Calendar;

void TERATERM_get_clock(){
	Clock.hours = RTC_get_hours();
	Clock.minutes = RTC_get_minutes();
	Clock.seconds = RTC_get_seconds();
}

void TERATERM_get_calendar(){
	Calendar.weekday = RTC_get_weekday();
	Calendar.day = RTC_get_day();
	Calendar.month = RTC_get_month();
	Calendar.year = RTC_get_year();
}
