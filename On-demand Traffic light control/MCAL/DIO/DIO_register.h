/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : DIO				**************/
/********************		Date : 20-11-2022		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA		 *((volatile u8*)0x3B)
#define PINA 		 *((volatile u8*)0x39)

#define PORTB		 *((volatile u8*)0x38)
#define PINB 		 *((volatile u8*)0x36)

#define PORTC		 *((volatile u8*)0x35)
#define PINC 		 *((volatile u8*)0x33)

#define PORTD		 *((volatile u8*)0x32)
#define PIND 		 *((volatile u8*)0x30)


#endif
