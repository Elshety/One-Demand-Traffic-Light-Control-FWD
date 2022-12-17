/*
 * DIO_TestFunc.h
 *
 *  Created on: 10/12/2022
 *      Author: Ahmed Elshety
 */

#ifndef DIO_TESTFUNC_H_
#define DIO_TESTFUNC_H_

#include"util/delay.h"
#include"DIO_interface.h"

/* Test DIO_u8SetPinValue Function*/
void DIO_Test1(void){
	DIO_u8SetPinValue(1,7,1);
}
/***********************************************************/

/* Test DIO_u8TogglePin Function*/
void DIO_Test2(void){
	for(short i =0;i<5;i++){
	DIO_u8TogglePin(1,7);
	_delay_ms(500);
	}
}
/***********************************************************/

/* Test DIO_u8GetPinValue Function*/
void DIO_Test3(void){
	DIO_u8SetPinValue(1,6,1);
	if( DIO_u8GetPinValue(1,6) == 1){
		DIO_u8SetPinValue(1,7,1);
	}
}
/***********************************************************/
#endif /* DIO_TESTFUNC_H_ */
