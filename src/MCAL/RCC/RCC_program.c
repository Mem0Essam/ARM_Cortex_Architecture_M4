/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : RCC_program.c                                           */
/*Description : This file contains function Implementation of RCC module*/
/*Date        : 04 May 2023                                             */
/************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "RCC_inteface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Error_Status RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	Error_Status Local_Error = ok ;
	switch(Copy_u8BusID)
	{
	case RCC_AHB1 :
		SET_BIT(RCC_AHB1ENR , Copy_u8PeripheralID);
		break;
	case RCC_AHB2 :
		SET_BIT(RCC_AHB2ENR , Copy_u8PeripheralID);
		break;
	case RCC_APB1 :
		SET_BIT(RCC_APB1ENR , Copy_u8PeripheralID);
		break;
	case RCC_APB2 :
		SET_BIT(RCC_APB2ENR , Copy_u8PeripheralID);
		break;
//	default :
//		Error_Status Local_Error = InvalidBitNumber;
//		break;
	}
	return Local_Error ;
}
Error_Status RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{

	Error_Status Local_Error = ok ;
	switch(Copy_u8BusID)
	{
	case RCC_AHB1 :
		CLEAR_BIT(RCC_AHB1ENR , Copy_u8PeripheralID);
		break;
	case RCC_AHB2 :
		CLEAR_BIT(RCC_AHB2ENR , Copy_u8PeripheralID);
		break;
	case RCC_APB1 :
		CLEAR_BIT(RCC_APB1ENR , Copy_u8PeripheralID);
		break;
	case RCC_APB2 :
		CLEAR_BIT(RCC_APB2ENR , Copy_u8PeripheralID);
		break;
//	default :
//		Error_Status Local_Error = InvalidBitNumber;
//		break;
	}
	return Local_Error ;
}
void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLOCK_SRC == HSI

	SET_BIT(RCC_CR , HSION); //Enable HSI
	CLEAR_BIT(RCC_CFGR,SW0); //Select HSI as System Clock source
	CLEAR_BIT(RCC_CFGR,SW1);

#elif SYSTEM_CLOCK_SRC == HSE_RC
	SET_BIT(RCC_CR , HSEON); //Enable HSE clock
	SET_BIT(RCC_CR , HSEBYP); //Choose RC external(Enable by Pass Mode )
	SET_BIT(RCC_CFGR,SW0); //Select HSE_RC as System Clock source
	CLEAR_BIT(RCC_CFGR,SW1);

#elif SYSTEM_CLOCK_SRC == HSE_CRYSTAL
	SET_BIT(RCC_CR , HSEON); //Enable HSE clock
	CLEAR_BIT(RCC_CR , HSEBYP); //Choose RC external(Disable by Pass Mode )
	SET_BIT(RCC_CFGR,SW0); //Select HSE_CRYSTAL as System Clock source
	CLEAR_BIT(RCC_CFGR,SW1);

#elif SYSTEM_CLOCK_SRC == PLL
	SET_BIT(RCC_CR , PLLON); //Enable PLL clock

#else
#error ("Wrong System Clock Configuration")

#endif

}
//Error_Status RCC_voidGPIOEnable(u8 Copy_u8GPIOID)
//{
//
//	Error_Status Local_Error = ok ;
//	switch(Copy_u8GPIOID)
//	{
//	case GPIOA :
//		SET_BIT(RCC_AHB1ENR , GPIOAEN);
//		break;
//	case GPIOB :
//		SET_BIT(RCC_AHB1ENR , GPIOBEN);
//		break;
//	case GPIOC :
//		SET_BIT(RCC_AHB1ENR , GPIOCEN );
//		break;
//	case GPIOD :
//		SET_BIT(RCC_AHB1ENR , GPIODEN);
//		break;
//	case GPIOE :
//		SET_BIT(RCC_AHB1ENR , GPIOEEN );
//		break;
//	case GPIOH :
//		SET_BIT(RCC_AHB1ENR , GPIOHEN);
//		break;
//	default :
//		Error_Status Local_Error = InvalidGPIOEntred;
//	}
//	return Local_Error ;
//}
//void RCC_voidCRCEnable(void)
//{
//	SET_BIT(RCC_AHB1ENR,CRCEN);
//}
//Error_Status RCC_voidDMAEnable(u8 Copy_u8DMAID)
//{
//	Error_Status Local_Error = ok ;
//	switch(Copy_u8DMAID)
//	{
//	case DMA1 :
//		SET_BIT(RCC_AHB1ENR , DMA1EN);
//		break;
//	case DMA2 :
//		SET_BIT(RCC_AHB1ENR , DMA2EN);
//		break;
//	default :
//		Error_Status Local_Error = InvalidDMAEntred;
//	}
//	return Local_Error ;
//}
//void RCC_voidOTGFSEnable(void)
//{
//	SET_BIT(RCC_AHB2ENR,OTGFSEN);
//}
//Error_Status RCC_voidTIMEREnable(u8 Copy_u8TIMERID)
//{
//	Error_Status Local_Error = ok ;
//	switch(Copy_u8TIMERID)
//	{
//	case TIMER1 :
//		SET_BIT(RCC_APB2ENR , TIM1EN);
//		break;
//	case TIMER2 :
//		SET_BIT(RCC_APB1ENR , TIM2EN);
//		break;
//	case TIMER3 :
//		SET_BIT(RCC_APB1ENR , TIM3EN);
//		break;
//	case TIMER4 :
//		SET_BIT(RCC_APB1ENR , TIM4EN);
//		break;
//	case TIMER5 :
//		SET_BIT(RCC_APB1ENR , TIM5EN);
//		break;
//	case TIMER9 :
//		SET_BIT(RCC_APB2ENR , TIM9EN);
//		break;
//	case TIMER10 :
//		SET_BIT(RCC_APB2ENR , TIM10EN);
//		break;
//	case TIMER11 :
//		SET_BIT(RCC_APB2ENR , TIM11EN);
//		break;
//	default :
//		Error_Status Local_Error = InvalidTIMEREntred;
//	}
//	return Local_Error ;
//}
