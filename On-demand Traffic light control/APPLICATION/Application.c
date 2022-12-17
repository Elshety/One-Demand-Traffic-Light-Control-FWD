/********************		Author: Ahmed Elshety	**************/
/********************		Layer: Application		**************/
/********************		SWC	 : Application		**************/
/********************		Date : 01-12-2022		**************/
/*****************************************************************/
/*****************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include"../HAL/LED/LED_interface.h"
#include"Application.h"


static u8 YellowLedState =TurnOFF ;
static u8 GreenLedState =TurnOFF;
static u8 RedLedState =TurnOFF;


/**********************************************************************************/
/* 		Description     : A function to initialize the application               	  */
void AppInit(void){
	PORT_voidInit();
	EXTI_voidINT0Init();
	GIE_voidEnableGlobal();
	Timer0Int();
	EXTI_u8INT0SetCallBack(&APP_voidNormalHumanMode);
}
/**********************************************************************************/


/**********************************************************************************/
/* 		Description     : A function to start the application               	  */
void AppStart(void){
	APP_voidNormalCarMode();
}
/**********************************************************************************/

/**********************************************************************************/
/* 		Description     : A function to blink yellow led of car traffic light	  */
void APP_voidBlinkYellowCarLed(void){

	/* Set Car Yellow LED Current State */
	YellowLedState = TurnON;

	/* Blink Yellow Led of Car Traffic for 5 Secs */
	for(u8 Local_u8SecCounter = 0 ; Local_u8SecCounter < 5 ; Local_u8SecCounter++)
	{
		LED_u8TurnOnLed(CAR_LED_PORT , CAR_LED_YELLOW);
		Timer0_mDelay(500);
		LED_u8TurnOffLed(CAR_LED_PORT , CAR_LED_YELLOW);
		Timer0_mDelay(500);
	}
	/* Set Car Yellow LED Current State */
	YellowLedState = TurnOFF;
}
/**********************************************************************************/



/**********************************************************************************/
/* Description     : A function to blink yellow led of both car and pedestrians   */
void APP_voidBlinkYellowCarAndHumanLed(void)
{
	/* Blink Yellow Led of Car Traffic for 5 Secs */
	for(u8 Local_u8SecCounter = 0 ; Local_u8SecCounter < 5 ; Local_u8SecCounter++)
	{
		LED_u8TurnOnLed(CAR_LED_PORT , CAR_LED_YELLOW);
		LED_u8TurnOnLed(HUMAN_LED_PORT , HUMAN_LED_YELLOW);
		Timer0_mDelay(500);
		LED_u8TurnOffLed(CAR_LED_PORT , CAR_LED_YELLOW);
		LED_u8TurnOffLed(HUMAN_LED_PORT , HUMAN_LED_YELLOW);
		Timer0_mDelay(500);

	}
}
/**********************************************************************************/



/**********************************************************************************/
/* Description     : A function to either turn on or off green led of car traffic */
/* 					 light based on state passed to the function				  */
void APP_voidCarTurnOnOffGreenLed(u8 Copy_u8State)
{
	if(Copy_u8State == TurnON)
	{
		LED_u8TurnOnLed(CAR_LED_PORT , CAR_LED_GREEN);
	}
	else
	{
		LED_u8TurnOffLed(CAR_LED_PORT , CAR_LED_GREEN);
	}
	/* Set Car Green LED Current State */
	GreenLedState = Copy_u8State;
}
/**********************************************************************************/



/**********************************************************************************/
/* Description     : A function to either turn on or off red led of car traffic   */
/* 					 light based on state passed to the function				  */
void APP_voidCarTurnOnOffRedLed(u8 Copy_u8State)
{
	if(Copy_u8State == TurnON)
	{
		LED_u8TurnOnLed(CAR_LED_PORT , CAR_LED_RED);
	}
	else
	{
		LED_u8TurnOffLed(CAR_LED_PORT , CAR_LED_RED);
	}
	/* Set Car Red LED Current State */
	RedLedState = Copy_u8State;
}
/**********************************************************************************/



/**********************************************************************************/
/* Description     : A function to either turn on or off green led of Pedestrians */
/* 					 traffic light based on state passed to the function	   	  */
void APP_voidHumanTurnOnOffGreenLed(u8 Copy_u8State)
{
	if(Copy_u8State == TurnON)
	{
		LED_u8TurnOnLed(HUMAN_LED_PORT , HUMAN_LED_GREEN);
	}
	else
	{
		LED_u8TurnOffLed(HUMAN_LED_PORT , HUMAN_LED_GREEN);
	}
}
/**********************************************************************************/



/**********************************************************************************/
/* Description     : A function to either turn on or off red led of Pedestrians   */
/* 					 traffic light based on state passed to the function	   	  */
void APP_voidHumanTurnOnOffRedLed(u8 Copy_u8State){

	if(Copy_u8State == TurnON)
	{
		LED_u8TurnOnLed(HUMAN_LED_PORT , HUMAN_LED_RED);
	}
	else
	{
		LED_u8TurnOffLed(HUMAN_LED_PORT , HUMAN_LED_RED);
	}
}
/**********************************************************************************/




/**********************************************************************************/
/* Description     : A function to start Normal Mode (Car Traffic Lights)		  */
void APP_voidNormalCarMode(void){



	/* Turn On Car Green Led for 5 Secs */
	APP_voidCarTurnOnOffGreenLed(TurnON); // GREEN LED FOR CARS
	Timer0_mDelay(5000);
	APP_voidCarTurnOnOffGreenLed(TurnOFF); // GREEN LED FOR CARS


	/* Blink Car Yellow Led for 5 Secs */
	APP_voidBlinkYellowCarLed();



	APP_voidCarTurnOnOffRedLed(TurnON); // Red LED FOR CARS
	Timer0_mDelay(5000);
	APP_voidCarTurnOnOffRedLed(TurnOFF); // Red LED FOR CARS


	/* Blink Car Yellow Led for 5 Secs */
	APP_voidBlinkYellowCarLed();

}
/**********************************************************************************/




void APP_voidNormalHumanMode(void){

	// if human made a double press on the crosswalk button
	// I expect that the first press will do the action and nothing to be done after the second press.
	GIE_voidDisableGlobal();



	/********************** FIRST CASE *****************************/

	if(RedLedState == TurnON)
	{

		// Turn On Pedestrians Green LED for 5 Secs //
		APP_voidCarTurnOnOffRedLed(TurnON);
		APP_voidHumanTurnOnOffGreenLed(TurnON);
		Timer0_mDelay(5000);
	}

	/********************** SECOND CASE *****************************/


	else if( (GreenLedState == TurnON) || (YellowLedState == TurnON) )
	{
		APP_voidCarTurnOnOffGreenLed(TurnOFF);
		APP_voidHumanTurnOnOffRedLed(TurnON);

		APP_voidBlinkYellowCarAndHumanLed();
		APP_voidHumanTurnOnOffRedLed(TurnOFF);
		APP_voidCarTurnOnOffGreenLed(TurnOFF);

		APP_voidCarTurnOnOffRedLed(TurnON);
		APP_voidHumanTurnOnOffGreenLed(TurnON);
		Timer0_mDelay(5000);
	}

	/******************** End of the two states ********************/

	APP_voidCarTurnOnOffRedLed(TurnOFF);

	APP_voidBlinkYellowCarAndHumanLed();

	APP_voidHumanTurnOnOffGreenLed(TurnOFF);
	APP_voidHumanTurnOnOffRedLed(TurnON);
	APP_voidCarTurnOnOffGreenLed(TurnON);
	Timer0_mDelay(5000);
	APP_voidHumanTurnOnOffRedLed(TurnOFF);
	APP_voidCarTurnOnOffGreenLed(TurnOFF);

	GIE_voidEnableGlobal();
}













