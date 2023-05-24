/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : NVIC_program.c                                          */
/*Description : This file contains NVIC  functions implementation       */
/*Date        : 22 May 2023                                             */
/************************************************************************/
#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"


#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

void NVIC_voidInit(void)
{
	/*local variable for the value of AIRCR register*/
	u32 Local_u32RegisterValue;
	/*set configuration of system software priority*/
	Local_u32RegisterValue = VECT_KEY | (PRIORITY_CONFIG <<8);

	/*Assign the value to AIRCR register*/
	SCB_AIRCR = Local_u32RegisterValue ;

}

void NVIC_voidEnableInterrupt(u8 Copy_u8INTID)
{
	NVIC -> ISER [Copy_u8INTID/32]=(1<<(Copy_u8INTID%32));
}
void NVIC_voidDisableInterrupt(u8 Copy_u8INTID)
{
	NVIC -> ICER [Copy_u8INTID/32]=(1<<(Copy_u8INTID%32));
}

void NVIC_voidSetPendingFlag(u8 Copy_u8INTID)
{
	NVIC -> ISPR [Copy_u8INTID/32]=(1<<(Copy_u8INTID%32));
}

void NVIC_voidClearPendingFlag(u8 Copy_u8INTID)
{
	NVIC -> ICPR [Copy_u8INTID/32]=(1<<(Copy_u8INTID%32));
}

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8INTID)
{
	u8 Local_u8ActiveFlag= 0 ;
	Local_u8ActiveFlag=GET_BIT(NVIC -> IABR[Copy_u8INTID/32],(Copy_u8INTID%32));
	return	Local_u8ActiveFlag;
}
void NVIC_voidSetSoftwarePriority(u8 Copy_u8SWPriority , u8 Copy_u8INTID)
{
	/*Setting both group and subpriorites into high four bits*/
	NVIC -> IPR[Copy_u8INTID] = Copy_u8SWPriority <<4;

	//TODO -> enchance the function !!!!!!!!!!!
}
