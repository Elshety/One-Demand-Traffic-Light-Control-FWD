/********************		Author: Ahmed Elshety	**************/
/********************		Layer: HAL				**************/
/********************		SWC	 : LED				**************/
/********************		Date : 29-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include"LED_interface.h"
#include"LED_config.h"

u8 LED_u8TurnOffLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin){

	u8 Local_u8Status = OK;
	if((Copy_u8LEDPort >= DIO_u8PORTA && Copy_u8LEDPort <= DIO_u8PORTD )||(Copy_u8LEDPin >= DIO_u8PIN0 && Copy_u8LEDPin <= DIO_u8PIN7 ))
	{
		DIO_u8SetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8Status = NOK ;
	}
	return Local_u8Status;
}


u8 LED_u8TurnOnLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin){

	u8 Local_u8Status = OK;
	if((Copy_u8LEDPort >= DIO_u8PORTA && Copy_u8LEDPort <= DIO_u8PORTD )||(Copy_u8LEDPin >= DIO_u8PIN0 && Copy_u8LEDPin <= DIO_u8PIN7 ))
	{
		DIO_u8SetPinValue(Copy_u8LEDPort,Copy_u8LEDPin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8Status = NOK ;
	}
	return Local_u8Status;
}


u8 LED_u8ToggleLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin){

	u8 Local_u8Status = OK;
	if((Copy_u8LEDPort >= DIO_u8PORTA && Copy_u8LEDPort <= DIO_u8PORTD )||(Copy_u8LEDPin >= DIO_u8PIN0 && Copy_u8LEDPin <= DIO_u8PIN7 ))
	{
		DIO_u8TogglePin(Copy_u8LEDPort,Copy_u8LEDPin);
	}
	else
	{
		Local_u8Status = NOK ;
	}
	return Local_u8Status;


}
