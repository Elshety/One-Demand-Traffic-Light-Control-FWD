/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : DIO				**************/
/********************		Date : 20-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"

u8 DIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Port)
				{
				case DIO_u8PORTA: TOGGLE_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: TOGGLE_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: TOGGLE_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: TOGGLE_BIT(PORTD,Copy_u8Pin); break;
				default: Local_u8ErrorState=NOK; break;
				}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		if(Copy_u8Value==DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK; break;
			}
		}
		else if(Copy_u8Value==DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK; break;
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Value=0;

	if((Copy_u8Pin<= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: Local_u8Value= GET_BIT(PINA,Copy_u8Pin); break;
		case DIO_u8PORTB: Local_u8Value= GET_BIT(PINB,Copy_u8Pin); break;
		case DIO_u8PORTC: Local_u8Value= GET_BIT(PINC,Copy_u8Pin); break;
		case DIO_u8PORTD: Local_u8Value= GET_BIT(PIND,Copy_u8Pin); break;
		default:  break;
		}
	}

	return Local_u8Value;
}
