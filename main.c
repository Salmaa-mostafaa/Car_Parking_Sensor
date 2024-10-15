/*
 * main.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostafa
 */

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include "ultrasonic.h"
#include "avr/io.h"
#include <avr/interrupt.h>
#include "std_types.h"

uint16 distance;

int main(void){
	SET_BIT(SREG,7);
	LCD_init();
	Buzzer_init();
	LEDS_init();
	Ultrasonic_init();
	LCD_displayStringRowColumn(0,0,"Distance=    cm");
	while(1){
		distance=Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		LCD_intgerToString(distance);
		if(distance>20){
			 Buzzer_off();
			 LED_off(RED);
			 LED_off(GREEN);
			 LED_off(BLUE);
		}
		else if ((distance >= 16) && (distance <= 20)) {
			Buzzer_off();
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		} else if ((distance >= 11) && (distance <= 16)) {
			Buzzer_off();
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		} else if ((distance >= 6) && (distance <= 10)) {
			LCD_displayCharacter(' ');
			Buzzer_off();
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		} else if (distance <= 5) {
			Buzzer_on();
			LCD_displayStringRowColumn(1,5,"STOP!!");
			while (distance <= 5) {
				distance=Ultrasonic_readDistance();
				LCD_moveCursor(0,10);
				LCD_intgerToString(distance);
				LED_on(RED);
				LED_on(GREEN);
				LED_on(BLUE);
				_delay_ms(200);
				LED_off(RED);
				LED_off(GREEN);
				LED_off(BLUE);
				_delay_ms(200);
			}
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "Distance=    cm");
			distance = Ultrasonic_readDistance();
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			Buzzer_off();
		}
	}
}

