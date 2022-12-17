/********************		Author: Ahmed Elshety	**************/
/********************		Layer: MCAL				**************/
/********************		SWC	 : GIE				**************/
/********************		Date : 24-11-2022		**************/
/*****************************************************************/
/*****************************************************************/


#include "GIE_interface.h"
#include "GIE_register.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


void GIE_voidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);
}
