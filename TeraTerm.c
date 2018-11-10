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
uint8 time[6];
uint8 date[8];

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

void TERATERM_get_decode_clock(TERATERM_clock_t clock_t){
	 time[0] = (clock_t.hours & DECIMAL_MASK)>> SHIFT_DECIMAL;
	 time[1] = (clock_t.hours & UNIT_MASK);
	 time[2] = (clock_t.minutes & DECIMAL_MASK)>>SHIFT_DECIMAL;
	 time[3] = (clock_t.minutes & UNIT_MASK);
	 time[4] = (clock_t.seconds & DECIMAL_MASK)>>SHIFT_DECIMAL;
	 time[5] = (clock_t.hours & UNIT_MASK);
}
