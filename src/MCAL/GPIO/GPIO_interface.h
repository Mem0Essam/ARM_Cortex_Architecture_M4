/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : GPIO_interface.h                                        */
/*Description : This file contains GPIO interface functions             */
/*Date        : 11 May 2023                                             */
/************************************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/*Microcontroller's Port*/
#define GPIO_PORTA         1
#define GPIO_PORTB         2
#define GPIO_PORTC         3

/*Microcontroller's Pin*/
#define GPIO_PIN0          0
#define GPIO_PIN1          1
#define GPIO_PIN2          2
#define GPIO_PIN3          3
#define GPIO_PIN4          4
#define GPIO_PIN5          5
#define GPIO_PIN6          6
#define GPIO_PIN7          7
#define GPIO_PIN8          8
#define GPIO_PIN9          9
#define GPIO_PIN10         10
#define GPIO_PIN11         11
#define GPIO_PIN12         12
#define GPIO_PIN13         13
#define GPIO_PIN14         14
#define GPIO_PIN15         15


/*Output pin Types*/
#define GPIO_PUSH_PULL     0
#define GPIO_OPEN_DRAIN    1

/*Output pin speed*/
#define GPIO_LOW_SPEED            0
#define GPIO_MED_SPEED            1
#define GPIO_HIGH_SPEED           2
#define GPIO_VERY_HIGH_SPEED      3

/*Output pin value*/
#define GPIO_OUTPUT_HIGH          1
#define GPIO_OUTPUT_LOW           0

/*Input pin type*/
#define GPIO_INPUT_NO_PULL_UP_NO_PULL_DOWN          0
#define GPIO_INPUT_PULL_UP                          1
#define GPIO_INPUT_PULL_DOWN                        2

/*Alternative Function Pin Macros*/
#define GPIO_AF0          0
#define GPIO_AF1          1
#define GPIO_AF2          2
#define GPIO_AF3          3
#define GPIO_AF4          4
#define GPIO_AF5          5
#define GPIO_AF6          6
#define GPIO_AF7          7
#define GPIO_AF8          8
#define GPIO_AF9          9
#define GPIO_AF10         10
#define GPIO_AF11         11
#define GPIO_AF12         12
#define GPIO_AF13         13
#define GPIO_AF14         14
#define GPIO_AF15         15


/*This function is to initialize any pin to be an output pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PinType, u8 Copy_u8PinSpeed);
/*This function is to initialize any pin to be an input pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PullMode );
/*This function is to set the value of any output pin [High-Low]*/
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Value);
/*This function is to get the value of any input pin*/
u8 GPIO_u8GetIntputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID );
/*This function is to set the value of any output pin [High-Low] using atomic access*/
void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Value);
/*This function is to set the value of Port*/
void GPIO_voidSetOutPortValue(u8 Copy_u8PortID , u16 Copy_u16PortValue);
/*This function is to Initialize Port as Output*/
void GPIO_voidInitOutPutPort(u8 Copy_u8PortID, u8 Copy_u8PortType , u8 Copy_u8PortSpeed);
/*This function is to initialize any pin to be Alternative Function*/
void GPIO_voidSetAlternativeFunction (u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8AlternativeFunction);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
