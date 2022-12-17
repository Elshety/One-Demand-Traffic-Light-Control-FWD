/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : EXTI				**************/
/********************		Date : 22-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define EXTI_INT0		0

#define LOW_LEVEL			1
#define ON_CHANGE			2
#define FALLING_EDGE		3
#define RISING_EDGE			4

#define ENABLED				1
#define DISABLED			2


void EXTI_voidINT0Init(void);

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNumber);

u8 EXTI_u8INT0SetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif
