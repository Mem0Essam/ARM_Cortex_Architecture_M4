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


/************************Global variables*******************************/
/*Array of global pointers to functions to set call back of EXTI sources*/
void (*Global_PtrToFunc_EXTI[16])(void)={NULL};







/************************Functions implementations ******************/

void EXTI_voidEnableInt(u8 Copy_u8IntId, void(*Copy_ptrToFunc)(void)){

	if(Copy_ptrToFunc!= NULL)
	{
		/*Set Call back function*/
		Global_PtrToFunc_EXTI[Copy_u8IntId] = Copy_ptrToFunc ;
	}
	else
	{
		/*Do Nothing*/
	}
	/*Enable Interrupt*/
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
		CLEAR_BIT(EXTI->RTSR,Copy_u8IntId);
		SET_BIT(EXTI->FTSR,Copy_u8IntId);
		break;
	case ON_CHANGE :
		SET_BIT(EXTI->RTSR,Copy_u8IntId);
		SET_BIT(EXTI->FTSR,Copy_u8IntId);
		break;
	}

}
void EXTI_voidSetLinePort(u8 Copy_u8IntId,u8 Copy_u8PortId){
	/*system configuration peripheral*/
	/*1)Clear target bits to set new configurations(bit masking)*/
	SYSCFG->EXTICR[Copy_u8IntId/4] &= ~(0b1111<<((Copy_u8IntId%4)*4));
	/*2)Set the new configurations*/
	SYSCFG->EXTICR[Copy_u8IntId/4] |= Copy_u8PortId<<((Copy_u8IntId%4)*4);
}
static void EXTI_voidClearPendingFlag(u8 Copy_u8IntId){
	/*clear the interrupt flag after executing interrupt ISR*/
	SET_BIT(EXTI->PR,Copy_u8IntId);
}
/*********************************************ISR implementations*********************************************/

/*ISR for EXTI0*/
void EXTI0_IRQHandler(void){
	Global_PtrToFunc_EXTI[0]();
	EXTI_voidClearPendingFlag(EXTI_LINE0);
}
/*ISR for EXTI1*/
void EXTI1_IRQHandler(void){
	Global_PtrToFunc_EXTI[1]();
	EXTI_voidClearPendingFlag(EXTI_LINE1);
}
/*ISR for EXTI2*/
void EXTI2_IRQHandler(void){
	Global_PtrToFunc_EXTI[2]();
	EXTI_voidClearPendingFlag(EXTI_LINE2);
}
/*ISR for EXTI3*/
void EXTI3_IRQHandler(void){
	Global_PtrToFunc_EXTI[3]();
	EXTI_voidClearPendingFlag(EXTI_LINE3);
}
/*ISR for EXTI4*/
void EXTI4_IRQHandler(void){
	Global_PtrToFunc_EXTI[4]();
	EXTI_voidClearPendingFlag(EXTI_LINE4);
}
/*ISR for EXTI5*/
void EXTI5_IRQHandler(void){
	Global_PtrToFunc_EXTI[5]();
	EXTI_voidClearPendingFlag(EXTI_LINE5);
}
/*ISR for EXTI6*/
void EXTI6_IRQHandler(void){
	Global_PtrToFunc_EXTI[6]();
	EXTI_voidClearPendingFlag(EXTI_LINE6);
}
/*ISR for EXTI7*/
void EXTI7_IRQHandler(void){
	Global_PtrToFunc_EXTI[7]();
	EXTI_voidClearPendingFlag(EXTI_LINE7);
}
/*ISR for EXTI8*/
void EXTI8_IRQHandler(void){
	Global_PtrToFunc_EXTI[8]();
	EXTI_voidClearPendingFlag(EXTI_LINE8);
}
/*ISR for EXTI9*/
void EXTI9_IRQHandler(void){
	Global_PtrToFunc_EXTI[9]();
	EXTI_voidClearPendingFlag(EXTI_LINE9);
}
/*ISR for EXTI10*/
void EXTI10_IRQHandler(void){
	Global_PtrToFunc_EXTI[10]();
	EXTI_voidClearPendingFlag(EXTI_LINE10);
}
/*ISR for EXTI11*/
void EXTI11_IRQHandler(void){
	Global_PtrToFunc_EXTI[11]();
	EXTI_voidClearPendingFlag(EXTI_LINE11);
}
/*ISR for EXTI12*/
void EXTI12_IRQHandler(void){
	Global_PtrToFunc_EXTI[12]();
	EXTI_voidClearPendingFlag(EXTI_LINE12);
}
/*ISR for EXTI13*/
void EXTI13_IRQHandler(void){
	Global_PtrToFunc_EXTI[13]();
	EXTI_voidClearPendingFlag(EXTI_LINE13);
}
/*ISR for EXTI14*/
void EXTI14_IRQHandler(void){
	Global_PtrToFunc_EXTI[14]();
	EXTI_voidClearPendingFlag(EXTI_LINE14);
}
/*ISR for EXTI15*/
void EXTI15_IRQHandler(void){
	Global_PtrToFunc_EXTI[15]();
	EXTI_voidClearPendingFlag(EXTI_LINE15);
}

