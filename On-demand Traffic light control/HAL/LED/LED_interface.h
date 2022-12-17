/********************		Author: Ahmed Elshety	**************/
/********************		Layer: HAL				**************/
/********************		SWC	 : LED				**************/
/********************		Date : 29-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include"LED_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include"../../MCAL/EXTI/EXTI_interface.h"
#include"../../MCAL/GIE/GIE_interface.h"
#include"../../MCAL/TIMERS/Timer.h"



u8 LED_u8TurnOffLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);

u8 LED_u8TurnOnLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);

u8 LED_u8ToggleLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);

#endif
