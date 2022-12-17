/*
 *  Created on: 03/12/2022
 *  Author: Ahmed Elshety
 */

#include"LIB/STD_TYPES.h"
#include"APPLICATION/Application.h"

// ------------ For Testing -------------//
#include"MCAL/DIO/DIO_TestFunc.h"
#include"MCAL/EXTI/EXTI_TestFunc.h"
#include"MCAL/TIMERS/Timer_TestFunc.h"
#include"HAL/LED/LED_TestFunc.h"
// ------------------------------------//


/// the main application ///

int main()
{

	AppInit();

	while(1){
		AppStart();
	}

	return 0;
}


//---------------------------- DIO Test Functions ---------------------------//
/*
int main(){

	//Test DIO_u8SetPinValue Function//
	DIO_Test1();


	//Test DIO_u8TogglePin Function//
	DIO_Test2();


	// Test DIO_u8GetPinValue Function//
	DIO_Test3();

	while(1);

	return 0;
}
*/
//----------------------------------------------------------------------------//


//---------------------------- EXTI Test Functions ---------------------------//
/*
int main(){

	PORT_voidInit();
	EXTI_voidINT0Init();
	GIE_voidEnableGlobal();
	EXTI_u8INT0SetCallBack(&EXTI_Test);

	while (1);

	return 0;
}
*/
//----------------------------------------------------------------------------//


//---------------------------- Timer Test Functions ---------------------------//
/*
int main(){


	PORT_voidInit();
	Timer0Int();

	while (1){
		Timer_Test();
	}
	return 0;
}
*/
//----------------------------------------------------------------------------//


//---------------------------- LED Test Functions ---------------------------//
/*
int main(){

	//Test LED_u8TurnOnLed Function//
	LED_Test1();


	//Test LED_u8TurnOffLed Function//
	LED_Test2();


	// Test LED_u8ToggleLed Function//
	LED_Test3();

	while(1);

	return 0;
}
*/
//----------------------------------------------------------------------------//


