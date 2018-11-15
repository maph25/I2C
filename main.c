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


    }
    return 0 ;
}
