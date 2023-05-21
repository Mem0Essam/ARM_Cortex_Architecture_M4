/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : SSD_program.c                                           */
/*Description : This file contains SSD functions implementation         */
/*Date        : 20 May 2023                                             */
/************************************************************************/
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"


#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/RCC/RCC_inteface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"



void SSD_voidInit(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PinType, u8 Copy_u8PinSpeed  )
{
	GPIO_voidInitOutPutPort(Copy_u8PortID,Copy_u8PinType,Copy_u8PinSpeed);
	GPIO_voidInitOutputPin(Copy_u8PortID,Copy_u8PinID,Copy_u8PinType,Copy_u8PinSpeed);
}
void SSD_voidON(u8 Copy_u8SSD_Type , u8 Copy_u8Pin , u8 Copy_u8PortID)
{
	if(Copy_u8SSD_Type== Common_Cathode)
	{
		GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8Pin,GPIO_OUTPUT_LOW);
	}
	else if(Copy_u8SSD_Type== Common_Anode)
	{
		GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8Pin,GPIO_OUTPUT_HIGH);
	}
}
void SSD_voidOFF(u8 Copy_u8SSD_Type , u8 Copy_u8Pin , u8 Copy_u8PortID)
{
	if(Copy_u8SSD_Type== Common_Cathode)
	{
		GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8Pin,GPIO_OUTPUT_HIGH);
	}
	else if(Copy_u8SSD_Type== Common_Anode)
	{
		GPIO_voidSetOutputPinValue(Copy_u8PortID,Copy_u8Pin,GPIO_OUTPUT_LOW);
	}
}
void SSD_voidShowValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	GPIO_voidSetOutPortValue(Copy_u8PortID,Copy_u8Value);
}
