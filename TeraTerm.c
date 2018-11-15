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
/*Print menu of options*/
void TERATERM_print_menu(){
	/*Text in white and background in blue */
	UART_put_string(UART_0,"\033[0;37;44m");
	UART_put_string(UART_0, "1.- Set Time \r");
	UART_put_string(UART_0, "2.- Set Date \r");
	UART_put_string(UART_0, "3.- Read Time \r");
	UART_put_string(UART_0, "4.- Read Date \r");
	UART_put_string(UART_0, "5.- Write in memory \r");
	UART_put_string(UART_0, "6.- Read from memory \r");
}

void TERATERM_print_clock(){
	/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[0;30;47m");
	UART_put_string(UART_0, "Current time is: \r");
	/*Print hour*/
	time[0] = time[0] + ADD;
	UART_put_char(UART_0, time[0]);
	time[1] = time[1] + ADD;
	UART_put_char(UART_0, time[1]);
	UART_put_char(UART_0, ':');
	/*Print minutes*/
	time[2] = time[2] + ADD;
	UART_put_char(UART_0, time[2]);
	time[3] = time[2] + ADD;
	UART_put_char(UART_0, time[3]);
	UART_put_char(UART_0, ':');
	/*Print seconds*/
	time[4] = time[2] + ADD;
	UART_put_char(UART_0, time[4]);
	time[5] = time[2] + ADD;
	UART_put_char(UART_0, time[5]);
}

void TERATERM_print_calendar(){
	/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[0;30;47m");
	UART_put_string(UART_0, "Today is: \r");
	/*Print weekday*/
	switch(date[0]){
		case SUNDAY:{
			UART_put_string(UART_0, "Sunday \r");
			break;
		}
		case MONDAY:{
			UART_put_string(UART_0, "Monday \r");
			break;
		}
		case TUESDAY:{
			UART_put_string(UART_0, "Tuesday \r");
			break;
		}
		case WEDNESDAY:{
			UART_putString(UART_0, "Wednesday \r");
			break;
		}
		case THURSDAY:{
			UART_put_string(UART_0, "Thursday \r");
			break;
		}
		case FRIDAY:{
			UART_put_string(UART_0, "Friday \r");
			break;
		}
		case SATURDAY:{
			UART_put_string(UART_0, "Saturday \r");
			break;
		}
	}
	UART_put_char(UART_0, ',');
	/*Print day*/
	date[1] = date[1] + ADD;
	UART_put_char(UART_0, date[1]);
	date[2] = date[2] + ADD;
	UART_put_char(UART_0, date[2]);
	UART_put_char(UART_0, '/');
	/*Print month*/
	date[3] = date[3] + ADD;
	UART_put_char(UART_0, date[3]);
	date[4] = date[4] + ADD;
	UART_put_char(UART_0, date[4]);
	UART_put_char(UART_0, '/');
	/*Print year*/
	date[5] = date[5] + ADD;
	UART_put_char(UART_0, date[5]);
	date[6] = date[6] + ADD;
	UART_put_char(UART_0, date[6]);

}
