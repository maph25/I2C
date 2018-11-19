#include "I2C.h"
#include "UART.h"
#include "NVIC.h"
#include "Buttons.h"
#include "TeraTerm.h"
#include "Bits.h"
#include "MK64F12.h"
#include "RTC.h"

#define SYSTEM_CLOCK (21000000u)
#define BAUDRATE (9600)
uint8 button_selection;
int main(void) {
	I2C_init(I2C_0, SYSTEM_CLOCK, BAUDRATE);
	UART_init(UART_0, SYSTEM_CLOCK,BD_115200);
	RTC_init();
	BUTTONS_init();
	/*UART interruption enable*/
	NVIC_enableInterruptAndPriotity(UART0_IRQ, PRIORITY_10);
	UART_interrupt_enable(UART_0);

    while(1) {
    	TERATERM_print_menu();
    	button_selection = BUTTONS_decode();
    	switch(button_selection){
    	/*Return to menu, clear screen*/
    	case B0:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_print_menu();
    		break;
    	/*Set Time*/
    	case B1:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_write_clock();
    		break;
    	/*Set Date*/
    	case B2:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_write_date();
    	   break;
    	/*Print Time*/
    	case B3:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_print_clock();
    	   break;
    	/*Print Date*/
    	case B4:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_print_calendar();
    	   break;
    	/*Write in memory*/
    	case B5:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_write_memory();
    	   break;
    	/*Print message from memory*/
    	case B6:
    		UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
    		TERATERM_print_memory();
    	   break;
    	default:
    		break;
    	}/*Switch*/

    }
    return 0 ;
}
