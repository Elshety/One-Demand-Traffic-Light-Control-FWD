/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : Timer			**************/
/********************		Date : 27-11-2022		**************/
/*****************************************************************/
/*****************************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"Timer.h"
#include <math.h>

static void (*Timer0_pvCallBackFunc)(void) = NULL;


void Timer0Int(void){

	//TCCR0=0x00;  // normal mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	TCNT0 =0X00; // timer set initial value

}

void Timer0_mDelay(u16 Copy_u16TimeInMSec){

	u16 overflowCounter=0;
	u16 Local_u16TotOverflows;
	u16 Local_u16PreloadValue;
	f32 Local_f32MaxDelay=0 ,Local_f32TickTime=0;

	TCCR0 |= (1<<0) | (1<<2); //start timer -> by setting prescaler value 1024

	Local_f32TickTime = 1024.0 / 1000.0; // milLi second at Frequency 1MHZ & prescaler 1024
	Local_f32MaxDelay = Local_f32TickTime * 256; // milli seconds (8-bit timer)


	if(Copy_u16TimeInMSec < Local_f32MaxDelay)
	{
		Local_u16PreloadValue = (Local_f32MaxDelay-Copy_u16TimeInMSec)/Local_f32TickTime;
		Local_u16TotOverflows = 1;

	}

	else if(Copy_u16TimeInMSec == (u32) Local_f32MaxDelay)
	{
		Local_u16PreloadValue=0;
		Local_u16TotOverflows=1;
	}

	else
	{
		Local_u16TotOverflows = ceil((f32)Copy_u16TimeInMSec/Local_f32MaxDelay);
		Local_u16PreloadValue = 256 - ((f32)Copy_u16TimeInMSec/Local_f32TickTime)/Local_u16TotOverflows;

	}

	TCNT0 = Local_u16PreloadValue;

	while (overflowCounter < Local_u16TotOverflows){
		while (( TIFR & (1<<0) )==0 );
		TIFR |= (1<<0); //clear the overflow flag
		overflowCounter++;
	}
	overflowCounter =0;
	//TCCR0 = 0x00; // timer stop


}



u8 Timer0_voidSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_ErrorState =OK;
	if ( Copy_pvCallBackFunc != NULL){
		Timer0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else{
		Local_ErrorState =NULL_POINTER;
	}
	return Local_ErrorState;

}


void __vector_11 (void)     __attribute__((signal));
void __vector_11 (void)
{
	if ( Timer0_pvCallBackFunc != NULL){
		Timer0_pvCallBackFunc();
	}
	else {
		/* Do Nothing*/
	}

}
