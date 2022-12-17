/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : GIE				**************/
/********************		Date : 24-11-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_


#define SREG		*((volatile u8*)0x5F)			/*Status register*/
#define SREG_I		7								/*Global Interrupt enable bit*/

#endif
