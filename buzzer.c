/*
 * buzzer.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostafa
 */


#include "buzzer.h"
#include "gpio.h"



void Buzzer_init(void){
	GPIO_setupPinDirection(PORT_BUZZER_ID, PIN_BUZZER_ID , PIN_OUTPUT);
	GPIO_writePin(PORT_BUZZER_ID, PIN_BUZZER_ID , BUZZER_OFF);
}

void Buzzer_on(void){
	GPIO_writePin(PORT_BUZZER_ID, PIN_BUZZER_ID , BUZZER_ON);
}

void Buzzer_off(void){
	GPIO_writePin(PORT_BUZZER_ID, PIN_BUZZER_ID , BUZZER_OFF);
}
