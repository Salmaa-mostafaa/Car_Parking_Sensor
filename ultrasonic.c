/*
 * ultrasonic.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostfa
 */

#include "util/delay.h"
#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"

uint8 g_edgeCount = 0;
uint16 g_timePeriod = 0;

void Ultrasonic_init(void){

	ICU_ConfigType configuration ={F_CPU_8,RAISING};
	ICU_init(&configuration);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
    _delay_us(10);
    GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	uint16 DISTANCE=0;
	Ultrasonic_Trigger();
	while(g_edgeCount != 2);
	DISTANCE=(uint16)(g_timePeriod/117.6)+1;
		g_edgeCount=0;
		return DISTANCE;
}

void Ultrasonic_edgeProcessing(void){
	 g_edgeCount++;
		if(g_edgeCount == 1)
		{
			/*
			 * Clear the timer counter register to start measurements from the
			 * first detected rising edge
			 */
			ICU_clearTimerValue();
			/* Detect falling edge */
			ICU_setEdgeDetectionType(FALLING);
		}
		else if(g_edgeCount == 2)
		{
			/* Store the High time value */
			g_timePeriod = ICU_getInputCaptureValue();
			/* Detect rising edge */
			ICU_setEdgeDetectionType(RAISING);
		}

}
