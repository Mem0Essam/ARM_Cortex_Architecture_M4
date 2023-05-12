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
		break;
	case GPIO_PORTB :
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
		break;
	case GPIO_PORTC :
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
		break;
	}
}
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PullMode )
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :
		/*Set direction of the pin to be input*/
		/*bit Masking*/
		GPIOA->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOA->MODER |=  (0b00<<(Copy_u8PinID*2));
		/*Set Type of input pin*/
		WRITE_BIT( GPIOA -> PUPDR ,  Copy_u8PinID , Copy_u8PullMode );
		break;
	case GPIO_PORTB :
		/*Set direction of the pin to be input*/
		/*bit Masking*/
		GPIOB->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOB->MODER |=  (0b00<<(Copy_u8PinID*2));
		/*Set Type of input pin*/
		WRITE_BIT( GPIOB -> PUPDR ,  Copy_u8PinID , Copy_u8PullMode );
		break;
	case GPIO_PORTC :
		/*Set direction of the pin to be input*/
		/*bit Masking*/
		GPIOC->MODER &=~ (0b11<<(Copy_u8PinID*2));
		GPIOC->MODER |=  (0b00<<(Copy_u8PinID*2));
		/*Set Type of input pin*/
		WRITE_BIT( GPIOC -> PUPDR ,  Copy_u8PinID , Copy_u8PullMode );
		break;
	}


}
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA :

		WRITE_BIT(GPIOA->ODR , Copy_u8PinID , Copy_u8Value);
		break;
	case GPIO_PORTB :
		WRITE_BIT(GPIOB->ODR , Copy_u8PinID , Copy_u8Value);
		break;
	case GPIO_PORTC :
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
		Local_u8Value=GET_BIT(GPIOA->IDR ,Copy_u8PinID);
		break;

	case GPIO_PORTB:
		Local_u8Value=GET_BIT(GPIOB->IDR,Copy_u8PinID);
		break;

	case GPIO_PORTC:
		Local_u8Value=GET_BIT(GPIOC->IDR,Copy_u8PinID);
		break;
	}

	return Local_u8Value ;
}
