/********************		Author: Ahmed Elshety	**************/
/********************		Layer: HAL				**************/
/********************		SWC	 : LED				**************/
/********************		Date : 29-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef CODING_HAL_LED_LED_CONFIG_H_
#define CODING_HAL_LED_LED_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include "../../LIB/STD_TYPES.h"


/* Configure LEDs port and pins for cars traffic light */
/* Port */
#define CAR_LED_PORT       DIO_u8PORTA
/* Pins */
#define CAR_LED_RED 	    DIO_u8PIN0
#define CAR_LED_YELLOW  	DIO_u8PIN1
#define CAR_LED_GREEN   	DIO_u8PIN2

/* Configure LEDs port and pins for pedestrians traffic light */
/* Port */
#define HUMAN_LED_PORT       DIO_u8PORTB
/* Pins */
#define HUMAN_LED_RED 		 DIO_u8PIN0
#define HUMAN_LED_YELLOW	 DIO_u8PIN1
#define HUMAN_LED_GREEN      DIO_u8PIN2


#endif /* CODING_HAL_LED_LED_CONFIG_H_ */
