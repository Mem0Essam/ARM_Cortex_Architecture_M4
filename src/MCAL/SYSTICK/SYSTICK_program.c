/*
 * SYSTICK_program.c
 *
 *  Created on: May 26, 2023
 *      Author: moham
 */

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"



#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void (*Global_PtrToFunc)(void) = NULL;

u8 Global_u8AsyncRepition = SINGLE ;

void SYSTICK_voidInit(void){

	/*Disable Interrupt , Clock Source = AHB/8*/
	/*System clock =HSI -> tick time =0.5 microsecond*/
	SYSTICK->CTRL = 0 ;

	/*Reset LOAD and VAl registers*/
	SYSTICK->LOAD = 0 ;
	SYSTICK->VAL  = 0 ;
}

void SYSTICK_voidDelaySync(u32 Copy_u32Delay_us){

	/*1)Disable Interrupt*/
	CLEAR_BIT( SYSTICK->CTRL , 1 );

	/*2)Set LOAD register Value to get the target delay*/
	SYSTICK->LOAD = Copy_u32Delay_us * 16 ;

	/*3)RUN SYSTICK*/
	SET_BIT( SYSTICK->CTRL , 0 );

	/*4)Polling till end of target time*/
	/*5)Clear Flag*/
	while( GET_BIT( SYSTICK->CTRL , 16 ) == 0 );

	/*6)Stop Timer*/
	CLEAR_BIT( SYSTICK->CTRL , 0 );

	/*7)Reset LOAD and VAl registers*/
	SYSTICK->LOAD = 0 ;
	SYSTICK->VAL  = 0 ;
}
void SYSTICK_voidDelaySyncms(u32 Copy_u32Delay_ms){

	Copy_u32Delay_ms = Copy_u32Delay_ms *1000;
	/*1)Disable Interrupt*/
	CLEAR_BIT( SYSTICK->CTRL , 1 );

	/*2)Set LOAD register Value to get the target delay*/
	SYSTICK->LOAD = Copy_u32Delay_ms * 16 ;

	/*3)RUN SYSTICK*/
	SET_BIT( SYSTICK->CTRL , 0 );

	/*4)Polling till end of target time*/
	/*5)Clear Flag*/
	while( GET_BIT( SYSTICK->CTRL , 16 ) == 0 );

	/*6)Stop Timer*/
	CLEAR_BIT( SYSTICK->CTRL , 0 );

	/*7)Reset LOAD and VAl registers*/
	SYSTICK->LOAD = 0 ;
	SYSTICK->VAL  = 0 ;
}
void SYSTICK_voidDelayAsyncSingle(u32 Copy_u32Delay_us ,void (*Copy_ptrToFunc)(void)){


	/*Set Global Flag value */
	Global_u8AsyncRepition = SINGLE;
	/*1)Enable Interrupt*/
	SET_BIT( SYSTICK->CTRL , 1 );

	/*2)Set LOAD register Value to get the target delay*/
	SYSTICK->LOAD = Copy_u32Delay_us * 2 ;

	/*3)Set Call Back*/
	if(Copy_ptrToFunc != NULL){
		Global_PtrToFunc = Copy_ptrToFunc ;
	}

	else{
		/*Do Nothing*/
	}

	/*4)RUN SYSTICK*/
	SET_BIT( SYSTICK->CTRL , 0 );

}

void SYSTICK_voidDelayAsyncPeriodic(u32 Copy_u32Delay_us ,void (*Copy_ptrToFunc)(void)){

	/*Set Global Flag value */
	Global_u8AsyncRepition = PERIODIC;
	/*1)Enable Interrupt*/
	SET_BIT( SYSTICK->CTRL , 1 );

	/*2)Set LOAD register Value to get the target delay*/
	SYSTICK->LOAD = Copy_u32Delay_us * 2 ;
	/*Rester value register*/
	SYSTICK->VAL =0;
	/*3)Set Call Back*/
	if(Copy_ptrToFunc != NULL){
		Global_PtrToFunc = Copy_ptrToFunc ;
	}

	else{
		/*Do Nothing*/
	}

	/*4)RUN SYSTICK*/
	SET_BIT( SYSTICK->CTRL , 0 );

}

u32 SYSTICK_u32GetRemainingTime(void){
	return SYSTICK->VAL;
}

u32 SYSTICK_u32ElapsedTime(void){
	return (SYSTICK->LOAD - SYSTICK->VAL);
}
/******************************************ISRs implementation*********************************/


/*Systick ISR*/
void Systick_Handle(void){

	switch(Global_u8AsyncRepition){
	case SINGLE :
		/*Calling Application Function*/
		Global_PtrToFunc();

		/*Stop Counting*/
		CLEAR_BIT( SYSTICK->CTRL , 0);
		break;
	case PERIODIC :

		/*Calling Application Function*/
		Global_PtrToFunc();

		break;
	}

	/*Calling Application Function*/
	Global_PtrToFunc();

	/*Stop Counting*/
	CLEAR_BIT( SYSTICK->CTRL , 0);

}
