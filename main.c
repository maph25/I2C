#include "I2C.h"
#include "MK64F12.h"
#include "RTC.h"


int main(void) {
	uint8_t temp_s;
	uint8_t temp_m;
	uint8_t temp_h;

	I2C_init(I2C_0, 21000000, 9600);
	RTC_init();

    while(1) {
      	temp_s = get_seconds();
    	temp_m = get_minutes();
    	temp_h = get_hours();
    	get_weekday();
    	get_day();
    	get_month();
    	get_year();
    }
    return 0 ;
}
