/*
 * I2C.c
 *
 *  Created on: Nov 5, 2018
 *      Author: Andy
 */

#include "GPIO.h"
#include "Bits.h"
#include "Delay.h"
#include "I2C.h"

void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate){
	GPIO_clock_gating (GPIO_B);
	GPIO_pin_control_register(GPIO_B, BIT2, GPIO_MUX2);
	GPIO_pin_control_register(GPIO_B, BIT3, GPIO_MUX2);

		switch (channel){
		case I2C_0:{
			SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
			I2C0->C1 |= I2C_C1_IICEN_MASK;
			I2C0->F |= I2C_F_ICR_MASK;
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

void I2C_mst_or_slv_mode(uint8_t mst_or_slv){
	if(mst_or_slv == I2C_SLV_MODE) {
		I2C0->C1 &= ~(I2C_C1_MST_MASK);
	}
	else if(mst_or_slv == I2C_MST_MODE){
		I2C0->C1 |= (I2C_C1_MST_MASK);
	}
}

void I2C_tx_rx_mode(uint8_t tx_or_rx){
	if(I2C_RX_MODE == tx_or_rx){
		I2C0->C1 &= ~(I2C_C1_TX_MASK);
	}
	else if(I2C_TX_MODE == tx_or_rx){
		I2C0->C1 |= I2C_C1_TX_MASK;
	}

}

void I2C_NACK(void){
	I2C0->C1 |= I2C_C1_TXAK_MASK;
}

void I2C_repeted_start(void){
	I2C0->C1 |= I2C_C1_RSTA_MASK;
	delay(5000);
}

void I2C_write_byte(uint8_t data){
	delay(5000);
	I2C0->D = data;
}
