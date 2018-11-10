/*
 * TeraTerm.h
 *
 *  Created on: Nov 10, 2018
 *      Author: Andy
 */

#ifndef TERATERM_H_
#define TERATERM_H_

#include "Bits.h"

/*Structure to save current time*/
typedef struct{
	uint8 hours;
	uint8 minutes;
	uint8 seconds;
}TERATERM_clock_t;

/*Structure to save current date*/
typedef struct{
	uint8 weekday;
	uint8 day;
	uint8 month;
	uint8 year;
}TERATERM_calendar_t;

/*Save current status*/
void TERATERM_get_clock();
void TERATERM_get_calendar();

#endif /* TERATERM_H_ */
