/*
 * TeraTerm.c
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#include "TeraTerm.h"
#include "Delay.h"
#include "EEPROM.h"
#include "Bits.h"
#include "UART.h"
#include "RTC.h"
#include "Buttons.h"

TERATERM_clock_t Clock;
TERATERM_calendar_t Calendar;
uint8 time[6];
uint8 date[7];
/*Variable that will increase array size*/
uint8 size;

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
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;37;44m"); /*Text in white and background in blue */
	UART_put_string(UART_0,"\033[8;10H"); /*X and Y position*/
	UART_put_string(UART_0, "1.- Set Time \r");
	UART_put_string(UART_0,"\033[9;10H"); /*X and Y position*/
	UART_put_string(UART_0, "2.- Set Date \r");
	UART_put_string(UART_0,"\033[10;10H"); /*X and Y position*/
	UART_put_string(UART_0, "3.- Read Time \r");
	UART_put_string(UART_0,"\033[11;10H"); /*X and Y position*/
	UART_put_string(UART_0, "4.- Read Date \r");
	UART_put_string(UART_0,"\033[12;10H"); /*X and Y position*/
	UART_put_string(UART_0, "5.- Write in memory \r");
	UART_put_string(UART_0,"\033[13;10H"); /*X and Y position*/
	UART_put_string(UART_0, "6.- Read from memory \r");
}

void TERATERM_print_clock(){
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[8;10H"); /*X and Y position*/
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
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;30;47m"); /*Text in black and background in white*/
	UART_put_string(UART_0,"\033[8;10H"); /*X and Y position*/
	UART_put_string(UART_0, "Today is: \r");
	/*Print weekday*/
	switch(date[0]){
		case SUNDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Sunday \r");
			break;
		}
		case MONDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Monday \r");
			break;
		}
		case TUESDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Tuesday \r");
			break;
		}
		case WEDNESDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Wednesday \r");
			break;
		}
		case THURSDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Thursday \r");
			break;
		}
		case FRIDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
			UART_put_string(UART_0, "Friday \r");
			break;
		}
		case SATURDAY:{
			UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
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

void TERATERM_write_clock(){
	uint8 flag;
	uint8 mailbox;
	uint8 scan;
	uint8 hours;
	uint8 minutes;
	uint8 seconds;
	uint8 secondsDecimals;
	uint8 secondsUnits;
	uint8 minutesDecimals;
	uint8 minutesUnits;
	uint8 hoursDecimals;
	uint8 hoursUnits;
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
	UART_put_string(UART_0, "Type in the time in the format hhmmss \r");
	flag = UART_flag_return();
	mailbox = UART_mailbox_return();
	while(flag == TRUE){
		for(scan = 0; scan == 6; scan++){
			time[scan] = mailbox;
		}
	}
		if(mailbox == ENTER_MASK){
		/*Set seconds*/
		time[4] = time[4] - HEX_MASK;
		secondsDecimals = time[4] << DECIMAL_SHIFTER;
		secondsUnits = time[5] - HEX_MASK;
		seconds = (ST_MASK | secondsDecimals | secondsUnits);
		RTC_set_seconds(seconds);
		/*Set minutes*/
		time[2] = time[2] - HEX_MASK;
		minutesDecimals = time[2] << DECIMAL_SHIFTER;
		minutesUnits = time[3] - HEX_MASK;
		minutes = (minutesDecimals | minutesUnits);
		RTC_set_minutes(minutes);
		/*Set hours*/
		time[2] = time[2] - HEX_MASK;
		hoursDecimals = time[2] << DECIMAL_SHIFTER;
		hoursUnits = time[3] - HEX_MASK;
		hours = (hoursDecimals | hoursUnits);
		RTC_set_hours(hours);
	}
}

void TERATERM_write_memory(){
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[10;10H"); /*X and Y position*/
	UART_put_string(UART_0, "1.-Write message one \r");
	UART_put_string(UART_0,"\033[11;10H"); /*X and Y position*/
	UART_put_string(UART_0, "2.- Write message two \r");
	UART_put_string(UART_0,"\033[12;10H"); /*X and Y position*/
	UART_put_string(UART_0, "5.- Write message three \r");
	/*Value to scan the array size*/
	uint8 scan;
	/*Variable for message selection*/
	uint8 messageSelect;
	/*Variable for getting UART mailbox content*/
	uint8 flag;
	uint8 mailbox;
	/*Address variable for writing*/
	uint8 address;
	/*Variable initialization*/
	size = 0;
	scan = 0;
	messageSelect = BUTTONS_decode();
	flag = UART_flag_return();
	mailbox = UART_mailbox_return();
	/*Array to save message*/
	uint8 message[size];

	while(flag == TRUE){
		size++;
		message[size] = mailbox;
		if(mailbox == ENTER_MASK){
			switch(messageSelect){
			case MESSAGE_ONE:{
				UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
				UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
				UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
				UART_put_string(UART_0,"Type your message\r"); /*X and Y position*/
				address = ADDRESS_MESSAGE_ONE;
				for(; scan < 0; scan--){
					EEPROM_write_data(address, message[scan]);
					delay(WRITE_DELAY);
					address++;
					}/*For*/
			}
				break;
			case MESSAGE_TWO:{
				UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
				UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
				UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
				UART_put_string(UART_0,"Type your message\r"); /*X and Y position*/
				address = ADDRESS_MESSAGE_TWO;
				for(; scan < 0; scan--){
					EEPROM_write_data(address, message[scan]);
					delay(WRITE_DELAY);
					address++;
					}/*For*/
			}
				break;
			case MESSAGE_THREE:{
				UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
				UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
				UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
				UART_put_string(UART_0,"Type your message\r"); /*X and Y position*/
				address = ADDRESS_MESSAGE_TWO;
				for(; scan < 0; scan--){
					EEPROM_write_data(address, message[scan]);
					delay(WRITE_DELAY);
					address++;
					}/*For*/
			}
				break;
			default:
				break;
			}/*Switch*/

		}/*If*/
	}
}

void TERATERM_print_memory(){
	uint8 scan = 0;
	uint8 address;
	sint8 message[size];
	uint8 messageSelect;
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;30;47m");/*Text in black and background in white*/
	UART_put_string(UART_0,"\033[9;15H"); /*X and Y position*/
	UART_put_string(UART_0,"Which message do you want to show\r"); /*X and Y position*/
	messageSelect = BUTTONS_decode();
	switch(messageSelect){
	case MESSAGE_ONE:{
		address = ADDRESS_MESSAGE_ONE;
		for(scan = 0; scan == size; scan++){
			message[scan] = EEPROM_read_data(address);
			UART_put_char(UART_0, message[scan]);
		}/*For*/
	}
		break;
	case MESSAGE_TWO:{
		address = ADDRESS_MESSAGE_TWO;
		for(scan = 0; scan == size; scan++){
			message[scan] = EEPROM_read_data(address);
			UART_put_char(UART_0, message[scan]);
		}/*For*/
	}
		break;
	case MESSAGE_THREE:{
		address = ADDRESS_MESSAGE_TWO;
		for(scan = 0; scan == size; scan++){
			message[scan] = EEPROM_read_data(address);
			UART_put_char(UART_0, message[scan]);
		}/*For*/
	}
		break;
	default:
		break;
	}/*Switch*/
}


