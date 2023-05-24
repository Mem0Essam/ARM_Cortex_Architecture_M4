/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : EXTI_program.c                                          */
/*Description : This file contains EXTI  functions implementation       */
/*Date        : 22 May 2023                                             */
/************************************************************************/
#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_voidEnableInt(u8 Copy_u8IntId, void(*Copy_ptrToFunc)(void)){
	SET_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidDisableInt(u8 Copy_u8IntId){
	CLEAR_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidSetSenseSignal(u8 Copy_u8IntId,u8 Copy_u8SenseSignal){
	switch(Copy_u8SenseSignal){
	case RISING_EDGE :
		CLEAR_BIT(EXTI->FTSR,Copy_u8IntId);
		SET_BIT(EXTI->RTSR,Copy_u8IntId);
		break;
	case FALLING_EDGE :
		SET_BIT(EXTI->FTSR,Copy_u8IntId);
		CLEAR_BIT(EXTI->RTSR,Copy_u8IntId);
		break;
	case ON_CHANGE :
		SET_BIT(EXTI->RTSR,Copy_u8IntId);
		SET_BIT(EXTI->FTSR,Copy_u8IntId);
		break;
	}

}
void EXTI_voidSetLinePort(u8 Copy_u8IntId,u8 Copy_u8PortId){
	u8 extiPinSource = Copy_u8IntId % 4;
	u8 extiPort = Copy_u8IntId / 4;
	switch (extiPort)
	{
	case 0:
		SYSCFG->EXTICR1 |= (Copy_u8PortId << (extiPinSource * 4));
		break;
	case 1:
		SYSCFG->EXTICR2 |= (Copy_u8PortId << (extiPinSource * 4));
		break;
	case 2:
		SYSCFG->EXTICR3 |= (Copy_u8PortId << (extiPinSource * 4));
		break;
	case 3:
		SYSCFG->EXTICR4 |= (Copy_u8PortId << (extiPinSource * 4));
		break;
	}
}
