/*
 * TeraTerm.c
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#include "TeraTerm.h"
#include "Bits.h"
#include "UART.h"
#include "RTC.h"

TERATERM_clock_t Clock;
TERATERM_calendar_t Calendar;
uint8 time[6];
uint8 date[7];

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

void TERATERM_get_decode_calendar(TERATERM_calendar_t calendar_t){
	 date[0] = (calendar_t.weekday & UNIT_MASK);
	 date[1] = (calendar_t.day & DECIMAL_MASK)>> SHIFT_DECIMAL;
	 date[2] = (calendar_t.day & UNIT_MASK);
	 date[3] = (calendar_t.month & DECIMAL_MASK)>>SHIFT_DECIMAL;
	 date[4] = (calendar_t.month & UNIT_MASK);
	 date[5] = (calendar_t.year & DECIMAL_MASK)>>SHIFT_DECIMAL;
	 date[6] = (calendar_t.year & UNIT_MASK);
}

void TERATERM_print_clock(){
	/*Print hour*/
	time[0] = time[0] + ADD;
	UART_putChar(UART_0, time[0]);
	time[1] = time[1] + ADD;
	UART_putChar(UART_0, time[1]);
	UART_putChar(UART_0, ':');
	/*Print minutes*/
	time[2] = time[2] + ADD;
	UART_putChar(UART_0, time[2]);
	time[3] = time[2] + ADD;
	UART_putChar(UART_0, time[3]);
	UART_putChar(UART_0, ':');
	/*Print seconds*/
	time[4] = time[2] + ADD;
	UART_putChar(UART_0, time[4]);
	time[5] = time[2] + ADD;
	UART_putChar(UART_0, time[5]);
}
