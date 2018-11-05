/*
 * I2C.c
 *
 *  Created on: Nov 5, 2018
 *      Author: Andy
 */

#include "GPIO.h"
#include "Bits.h"
#include "I2C.h"

void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate){
	GPIO_clock_gating (GPIO_B);
	GPIO_pin_control_register(GPIO_B, BIT2, GPIO_MUX2);
	GPIO_pin_control_register(GPIO_B, BIT3, GPIO_MUX2);

		switch (channel){
		case I2C_0:{
			SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
			I2C0->C1 |= I2C_C1_IICEN_MASK;
			I2C0->SMB &= ~I2C_SMB_FACK_MASK;
			break;
		}
		case I2C_1:
			break;
		case I2C_2:
			break;
	}/*switch*/
}

uint8_t I2C_busy(){
	uint8 busy = FALSE;
	if((I2C0->S & I2C_S_BUSY_MASK) == FALSE){

	}
	else{
		busy = TRUE;
	}
	return busy;
}
