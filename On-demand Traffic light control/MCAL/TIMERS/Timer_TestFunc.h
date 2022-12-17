/*
 * Timer_TestFunc.h
 *
 *  Created on: 10/12/2022
 *      Author: Ahmed Elshety
 */

#ifndef TIMER_TESTFUNC_H_
#define TIMER_TESTFUNC_H_

#include"../DIO/DIO_interface.h"
#include"Timer.h"

void Timer_Test(void){

		DIO_u8TogglePin(1,7);
		Timer0_mDelay(500);

}

#endif /* TIMER_TESTFUNC_H_ */
