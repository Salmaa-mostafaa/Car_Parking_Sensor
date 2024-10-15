/*
 * led.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostafa
 */

#include"gpio.h"
#include"led.h"

void LEDS_init(void){
	GPIO_setupPinDirection(RED_PORT_ID,RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_PORT_ID,GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_PORT_ID,BLUE_PIN_ID,PIN_OUTPUT);

	 GPIO_writePin(RED_PORT_ID,RED_PIN_ID,LED_OFF);
	 GPIO_writePin(GREEN_PORT_ID,GREEN_PIN_ID,LED_OFF);
	 GPIO_writePin(BLUE_PORT_ID,BLUE_PIN_ID,LED_OFF);
}


void LED_on(LED_ID id){
	switch (id){
	case RED:
		 GPIO_writePin(RED_PORT_ID,RED_PIN_ID,LED_ON);
		break;
	case GREEN:
		 GPIO_writePin(GREEN_PORT_ID,GREEN_PIN_ID,LED_ON);
			break;
	case BLUE:
		GPIO_writePin(BLUE_PORT_ID,BLUE_PIN_ID,LED_ON);
			break;
	}
}

void LED_off(LED_ID id){
	switch (id){
		case RED:
			 GPIO_writePin(RED_PORT_ID,RED_PIN_ID,LED_OFF);
			break;
		case GREEN:
			 GPIO_writePin(GREEN_PORT_ID,GREEN_PIN_ID,LED_OFF);
				break;
		case BLUE:
			GPIO_writePin(BLUE_PORT_ID,BLUE_PIN_ID,LED_OFF);
				break;
		}
}

