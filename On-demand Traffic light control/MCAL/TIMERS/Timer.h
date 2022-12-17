/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : Timer			**************/
/********************		Date : 27-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER_H_
#define TIMER_H_
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#define TIFR			*((volatile u8*)0x58)
#define TIFR_TOV0		0

#define TCCR0           *((volatile u8*)0x53)			/*Timer counter control register 0*/
#define TCCR0_WGM00		6								/*Waveform generation mode bit 0*/
#define TCCR0_WGM01		3								/*Waveform generation mode bit 1*/

#define TCNT0           *((volatile u8*)0x52)			/*Timer counter 0 register*/


void Timer0Int(void);

void Timer0_mDelay(u16 Copy_u16TimeInMSec);

#endif /* TIMER_H_ */
