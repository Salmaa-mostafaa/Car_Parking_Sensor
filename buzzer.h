/*
 * buzzer.h
 *
 *  Created on: Oct 12, 2024
 *      Author: Salma Mostafa
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"

#define PORT_BUZZER_ID       PORTC_ID
#define PIN_BUZZER_ID        PIN5_ID

#define BUZZER_ON            LOGIC_HIGH
#define BUZZER_OFF           LOGIC_LOW

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);



#endif /* BUZZER_H_ */
