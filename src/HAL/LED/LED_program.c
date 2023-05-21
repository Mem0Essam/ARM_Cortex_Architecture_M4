/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : LED_program.c                                           */
/*Description : This file contains LED functions implementation         */
/*Date        : 20 May 2023                                             */
/************************************************************************/
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/RCC/RCC_inteface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidInit(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed)
{
	GPIO_voidInitOutputPin(Copy_u8PortID,Copy_u8PinID,Copy_u8PinType,Copy_u8PinSpeed);
}
void LED_voidON(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8PinID,GPIO_OUTPUT_HIGH);
}
void LED_voidOFF(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8PinID,GPIO_OUTPUT_LOW);
}

