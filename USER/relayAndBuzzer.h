#ifndef RELAY_BUZZER_H
#define RELAY_BUZZER_H

#include "stm32f10x.h"



/*	PB12:buzzer
	PB13:relay	*/


void relayAndBuzzer_init();
void Buzz(uint8_t isBuzz);
void Relay(uint8_t isOn);

#endif
