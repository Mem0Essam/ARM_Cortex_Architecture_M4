/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : LED_interface.h                                         */
/*Description : This file contains LED interfacing macros and functions */
/*Date        : 20 May 2023                                             */
/************************************************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*This function is used to Initialize LED PINS*/
void LED_voidInit(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed);
/*This function is used to set LED ON */
void LED_voidON(u8 Copy_u8PortID,u8 Copy_u8PinID);
/*This function is used to set LED OFF */
void LED_voidOFF(u8 Copy_u8PortID,u8 Copy_u8PinID);

#endif /* HAL_LED_LED_INTERFACE_H_ */
