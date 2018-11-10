/*
 * TeraTerm.c
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#include "TeraTerm.h"
#include "Bits.h"
#include"RTC.h"

void TERATERM_get_clock(){
	TERATERM_clock_t.hours = RTC_get_hours();
	TERATERM_clock_t.minutes = RTC_get_minutes();
	TERATERM_clock_t.seconds = RTC_get_seconds();

}
