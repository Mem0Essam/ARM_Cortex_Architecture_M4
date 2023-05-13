/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : GPIO_program.c                                          */
/*Description : This file contains GPIO  functions implementation       */
/*Date        : 11 May 2023                                             */
/************************************************************************/
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PinType, u8 Copy_u8PinSpeed)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :
		/*Stopping Any process to be performed on Forbidden pins */
		if(Copy_u8PinID == GPIO_PIN13 || Copy_u8PinID == GPIO_PIN14 || Copy_u8PinID == GPIO_PIN15)
		{
			/*do noting*/
		}
		else
		{
			/*Set direction of the pin to be output*/
			/*bit Masking*/
			GPIOA->MODER &=~ (0b11<<(Copy_u8PinID*2));
			GPIOA->MODER |=  (0b01<<(Copy_u8PinID*2));

			/*Set speed of the output pin*/
			/*bit Masking*/
			GPIOA->OSPEEDR &=~ (0b11<<(Copy_u8PinID*2));
			GPIOA->OSPEEDR |=  (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/*Set Type of output pin*/
			WRITE_BIT( GPIOA -> OTYPER ,  Copy_u8PinID , Copy_u8PinType );
		}
		break;
	case GPIO_PORTB :
		/*Stopping Any process to be performed on Forbidden pins */
		if(Copy_u8PinID == GPIO_PIN2 || Copy_u8PinID == GPIO_PIN3 ||Copy_u8PinID == GPIO_PIN4)
		{
			/*do noting*/
		}
		else
		{
			/*Set direction of the pin to be output*/
			/*bit Masking*/
			GPIOB->MODER &=~ (0b11<<(Copy_u8PinID*2));
			GPIOB->MODER |=  (0b01<<(Copy_u8PinID*2));

			/*Set speed of the output pin*/
			/*bit Masking*/
			GPIOB->OSPEEDR &=~ (0b11<<(Copy_u8PinID*2));
			GPIOB->OSPEEDR |=  (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/*Set Type of output pin*/
			WRITE_BIT( GPIOB -> OTYPER ,  Copy_u8PinID , Copy_u8PinType );
		}
		break;
	case GPIO_PORTC :
		/*Allowing Initialization process only on available pins*/
		if(Copy_u8PinID == GPIO_PIN13 || Copy_u8PinID == GPIO_PIN14 ||Copy_u8PinID == GPIO_PIN15)
		{
			/*Set direction of the pin to be output*/
			/*bit Masking*/
			GPIOC->MODER &=~ (0b11<<(Copy_u8PinID*2));
			GPIOC->MODER |=  (0b01<<(Copy_u8PinID*2));

			/*Set speed of the output pin*/
			/*bit Masking*/
			GPIOC->OSPEEDR &=~ (0b11<<(Copy_u8PinID*2));
			GPIOC->OSPEEDR |=  (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/*Set Type of output pin*/
			WRITE_BIT( GPIOC -> OTYPER ,  Copy_u8PinID , Copy_u8PinType );
		}
		else
		{
			/*do noting*/
		}
		break;
	}
}
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PullMode )
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :
		/*Stopping Any process to be performed on Forbidden pins */
		if(Copy_u8PinID == GPIO_PIN13 || Copy_u8PinID == GPIO_PIN14 ||Copy_u8PinID == GPIO_PIN15)
		{
			/*do noting*/
		}
		else
		{
			/*Set direction of the pin to be Input*/
			/*bit Masking*/
			GPIOA -> MODER &=~(0b11<<(Copy_u8PinID*2));
			/*Set Pull Mode of input pin*/
			GPIOA -> PUPDR &=~(0b11<<(Copy_u8PinID*2));
			GPIOA -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID*2));
		}
		break;
	case GPIO_PORTB :
		/*Stopping Any process to be performed on Forbidden pins */
		if(Copy_u8PinID == GPIO_PIN2 || Copy_u8PinID == GPIO_PIN3 ||Copy_u8PinID == GPIO_PIN4)
		{
			/*do noting*/
		}
		else
		{
			/*Set direction of the pin to be Input*/
			/*bit Masking*/
			GPIOB -> MODER &=~(0b11<<(Copy_u8PinID*2));
			/*Set Pull Mode of input pin*/
			GPIOB -> PUPDR &=~(0b11<<(Copy_u8PinID*2));
			GPIOB -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID*2));
		}
		break;
	case GPIO_PORTC :
		/*Allowing Initialization process only on available pins*/
		if(Copy_u8PinID == GPIO_PIN13 || Copy_u8PinID == GPIO_PIN14 ||Copy_u8PinID == GPIO_PIN15)
		{
			/*Set direction of the pin to be Input*/
			/*bit Masking*/
			GPIOC -> MODER &=~(0b11<<(Copy_u8PinID*2));
			/*Set Pull Mode of input pin*/
			GPIOC -> PUPDR &=~(0b11<<(Copy_u8PinID*2));
			GPIOC -> PUPDR |= (Copy_u8PullMode << (Copy_u8PinID*2));
		}
		break;
	}
}
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :
		/*Set Pin to a certain value*/
		WRITE_BIT(GPIOA->ODR , Copy_u8PinID , Copy_u8Value);
		break;
	case GPIO_PORTB :
		/*Set Pin to a certain value*/
		WRITE_BIT(GPIOB->ODR , Copy_u8PinID , Copy_u8Value);
		break;
	case GPIO_PORTC :
		/*Set Pin to a certain value*/
		WRITE_BIT(GPIOC->ODR , Copy_u8PinID , Copy_u8Value);
		break;
	}
}
u8 GPIO_u8GetIntputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID )
{
	u8 Local_u8Value = 0 ;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		/*Getting value of a certain Pin */
		Local_u8Value=GET_BIT(GPIOA->IDR ,Copy_u8PinID);
		break;
	case GPIO_PORTB:
		/*Getting value of a certain Pin */
		Local_u8Value=GET_BIT(GPIOB->IDR,Copy_u8PinID);
		break;
	case GPIO_PORTC:
		/*Getting value of a certain Pin */
		Local_u8Value=GET_BIT(GPIOC->IDR,Copy_u8PinID);
		break;
	}
	return Local_u8Value ;
}
void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	u32 Local_u32RegisterValue =0 ;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		switch (Copy_u8Value)
		{
		case GPIO_OUTPUT_HIGH:
			/*Set value of a certain Pin using Atomic access in one assembly instruction */
			Local_u32RegisterValue = 1<<Copy_u8PinID ;
			break;
		case GPIO_OUTPUT_LOW:
			/*Clear value of a certain Pin using Atomic access in one assembly instruction */
			Local_u32RegisterValue = 1<<(Copy_u8PinID+16) ;
			break;
		}
		GPIOA->BSRR =Local_u32RegisterValue ;
		break;
		case GPIO_PORTB:
			switch (Copy_u8Value)
			{
			case GPIO_OUTPUT_HIGH:
				/*Set value of a certain Pin using Atomic access in one assembly instruction */
				Local_u32RegisterValue = 1<<Copy_u8PinID ;
				break;
			case GPIO_OUTPUT_LOW:
				/*Set value of a certain Pin using Atomic access in one assembly instruction */
				Local_u32RegisterValue = 1<<(Copy_u8PinID+16) ;
				break;
			}
			GPIOB->BSRR =Local_u32RegisterValue ;
			break;
			case GPIO_PORTC:
				switch (Copy_u8Value)
				{
				case GPIO_OUTPUT_HIGH:
					/*Set value of a certain Pin using Atomic access in one assembly instruction */
					Local_u32RegisterValue = 1<<Copy_u8PinID ;
					break;
				case GPIO_OUTPUT_LOW:
					/*Set value of a certain Pin using Atomic access in one assembly instruction */
					Local_u32RegisterValue = 1<<(Copy_u8PinID+16) ;
					break;
				}
				GPIOC->BSRR =Local_u32RegisterValue ;
				break;
	}
}
void GPIO_voidSetOutPortValue(u8 Copy_u8PortID , u16 Copy_u16PortValue)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA -> ODR = Copy_u16PortValue ;
		break;
	case GPIO_PORTB:
		GPIOB -> ODR = Copy_u16PortValue ;
		break;
	case GPIO_PORTC:
		GPIOC -> ODR = Copy_u16PortValue ;
		break;
	}
}
void GPIO_voidInitOutPutPort(u8 Copy_u8PortID, u8 Copy_u8PortType , u8 Copy_u8PortSpeed)
{
	u8 GPIO_PIN[16] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for(u8 i =0 ; i < 16 ; i++)
	{
		GPIO_voidInitOutputPin(Copy_u8PortID , GPIO_PIN[i] ,Copy_u8PortType ,Copy_u8PortSpeed);
	}
}
void GPIO_voidSetAlternativeFunction (u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8AlternativeFunction)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :
		/*Set direction of the pin to be in alternative function mode*/
		/*bit Masking*/
		GPIOA->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOA->MODER |=  (0b10<<(Copy_u8PinID*2));
		if( GPIO_PIN0 <= Copy_u8PinID && Copy_u8PinID <= GPIO_PIN7)
		{
			GPIOA->AFRL &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOA->AFRL |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		else
		{
			GPIOA->AFRH &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOA->AFRH |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		break;
	case GPIO_PORTB :
		/*Set direction of the pin to be in alternative function mode*/
		/*bit Masking*/
		GPIOB->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOB->MODER |=  (0b10<<(Copy_u8PinID*2));
		if( GPIO_PIN0 <= Copy_u8PinID && Copy_u8PinID <= GPIO_PIN7)
		{
			GPIOB->AFRL &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOB->AFRL |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		else
		{
			GPIOB->AFRH &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOB->AFRH |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		break;
	case GPIO_PORTC :
		/*Set direction of the pin to be in alternative function mode*/
		/*bit Masking*/
		GPIOC->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOC->MODER |=  (0b10<<(Copy_u8PinID*2));
		if( GPIO_PIN0 <= Copy_u8PinID && Copy_u8PinID <= GPIO_PIN7)
		{
			GPIOC->AFRL &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOC->AFRL |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		else
		{
			GPIOC->AFRH &=~ (0b1111<<(Copy_u8PinID*4));
			GPIOC->AFRH |=  (Copy_u8AlternativeFunction<<(Copy_u8PinID*4));
		}
		break;
	}
}
