/*
 * Buttons.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */

#include "GPIO.h"
#include "Bits.h"
#include "Buttons.h"
#include "NVIC.h"

void BUTTONS_init(){
	gpio_pin_control_register_t config = GPIO_MUX1 | GPIO_PE | GPIO_PS | INTR_FALLING_EDGE;

	GPIO_clock_gating(GPIO_C);

	/*Pin configuration for push buttons*/
	GPIO_pin_control_register(GPIO_C, BIT5, &config); /*B0*/
	GPIO_pin_control_register(GPIO_C, BIT7, &config); /*B1*/
	GPIO_pin_control_register(GPIO_C, BIT0, &config); /*B2*/
	GPIO_pin_control_register(GPIO_C, BIT9, &config); /*B3*/
	GPIO_pin_control_register(GPIO_C, BIT8, &config); /*B4*/
	GPIO_pin_control_register(GPIO_C, BIT3, &config); /*B5*/

	/*Input configuration for push buttons*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT5); /*B0*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT7); /*B1*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT0); /*B2*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT9); /*B3*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT8); /*B4*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, BIT3); /*B5*/

	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
	NVIC_setBASEPRI_threshold(PRIORITY_15);
	/*Enables and sets a particular interrupt and its priority*/
	NVIC_enableInterruptAndPriotity(PORTC_IRQ, PRIORITY_3);
	/*Enables all interruptions*/
	EnableInterrupts;
}

uint8 BUTTONS_decode(){
	if(GPIO_read_pin(GPIO_C, BIT5) == FALSE)
		return B0;
	else if(GPIO_read_pin(GPIO_C, BIT7) == FALSE)
		return B1;
	else if(GPIO_read_pin(GPIO_C, BIT0) == FALSE)
		return B2;
	else if(GPIO_read_pin(GPIO_C, BIT9) == FALSE)
		return B3;
	else if(GPIO_read_pin(GPIO_C, BIT8) == FALSE)
		return B4;
	else if(GPIO_read_pin(GPIO_C, BIT3) == FALSE)
		return B5;
	else
		return BUTTONS_NULL;
}
