/*
 * led.h
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostafa
 */

#ifndef LED_H_
#define LED_H_
#include"std_types.h"

typedef enum{
	RED,GREEN,BLUE
}LED_ID;

#define RED_PORT_ID  PORTC_ID
#define RED_PIN_ID   PIN0_ID

#define GREEN_PORT_ID  PORTC_ID
#define GREEN_PIN_ID   PIN1_ID

#define BLUE_PORT_ID  PORTC_ID
#define BLUE_PIN_ID   PIN2_ID

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW


void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);


#endif /* LED_H_ */
