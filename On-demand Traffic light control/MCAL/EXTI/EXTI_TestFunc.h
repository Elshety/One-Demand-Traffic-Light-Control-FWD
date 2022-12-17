/*
 * EXTI_TestFunc.h
 *
 *  Created on: 10/12/2022
 *      Author: Ahmed Elshety
 */

#ifndef EXTI_TESTFUNC_H_
#define EXTI_TESTFUNC_H

#include"../DIO/DIO_interface.h"
#include"util/delay.h"

// if we press the EXTI button

void EXTI_Test(void){

	DIO_u8TogglePin(1,7);
}


/***********************************************************/
#endif /* EXTI_TESTFUNC_H */
