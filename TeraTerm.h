/*
 * TeraTerm.h
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#ifndef TERATERM_H_
#define TERATERM_H_

#include "Bits.h"

typedef struct{
	uint8 hours;
	uint8 minutes;
	uint8 seconds;
}TERATERM_clock_t;

typedef struct{
	uint8 weekday;
	uint8 day;
	uint8 month;
	uint8 year;
}TERATERM_calendar_t;

void TERATERM_get_clock();
#endif /* TERATERM_H_ */
