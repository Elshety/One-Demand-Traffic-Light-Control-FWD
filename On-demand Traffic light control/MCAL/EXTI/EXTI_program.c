/********************		Author: Ahmed Elshety		**************/
/********************		Layer: MCAL					**************/
/********************		SWC: EXTI				    **************/
/********************		Date: 22-11-2022			**************/
/*********************************************************************/
/*********************************************************************/
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


/*Define Global array of 3 pointers to functions to carry ISR application addresses*/
static void (*EXTI_pvINTCallBackFunc)(void)= NULL;

void EXTI_voidINT0Init(void)
{
	/*Check on INT0 Sense control*/
#if EXTI_INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong EXTI_INT0_SENSE configuration option"
#endif

	/*Check INT0 PIE initial state*/
#if EXTI_INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error " Wrong EXTI_INT0_INITIAL_STATE configuration option"
#endif
}

u8 EXTI_u8SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState= OK;

	 		/*In case INT0*/
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL:   CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case ON_CHANGE:   SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		default: Local_u8ErrorState = NOK;			break;
		}
		/*Break INT0 case*/


	return Local_u8ErrorState;
}

u8 EXTI_u8INT0SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		EXTI_pvINTCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}

/*ISR of INT0*/
void  __vector_1 (void)	__attribute__((signal));
void  __vector_1 (void)
{
	if(EXTI_pvINTCallBackFunc != NULL)
	{
		EXTI_pvINTCallBackFunc ();
	}
	else
	{
		/*Do nothing*/
	}


}
