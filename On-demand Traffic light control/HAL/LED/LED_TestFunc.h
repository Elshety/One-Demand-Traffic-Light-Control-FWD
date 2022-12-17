/*
 * LED_Test.h
 *
 *  Created on: 10/12/2022
 *      Author: Ahmed Elshety
 */

#ifndef LED_TEST_H_
#define LED_TEST_H_
#include"LED_interface.h"
#include"LED_config.h"
#include"util/delay.h"

/*Test case LED ON*/
void LED_Test1(void){
	LED_u8TurnOnLed(1,7);
}

/*Test case LED OFF*/
void LED_Test2(void){
	LED_u8TurnOnLed(1,7);
	_delay_ms(1000);
	LED_u8TurnOffLed(1,7);
}

/*Test case LED TOGGLE*/
void LED_Test3(void){
	for(short i=0;i<10;i++){
	LED_u8ToggleLed(1,7);
	_delay_ms(500);
	LED_u8ToggleLed(1,7);
	_delay_ms(500);
	}
}


#endif /* LED_TEST_H_ */
