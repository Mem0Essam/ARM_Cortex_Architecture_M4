/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : EXTI_interface.h                                        */
/*Description : This file contains EXTI interface functions             */
/*Date        : 22 May 2023                                             */
/************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*16 Macro for EXTI lines*/

/*3 macros for sense signal*/
#define FALLING_EDGE           1
#define RISING_EDGE            2
#define ON_CHANGE              3

void EXTI_voidEnableInt(u8 Copy_u8IntId, void(*Copy_ptrToFunc)(void));
void EXTI_voidDisableInt(u8 Copy_u8IntId);
void EXTI_voidSetSenseSignal(u8 Copy_u8IntId,u8 Copy_u8SenseSignal);
void EXTI_voidSetLinePort(u8 Copy_u8IntId,u8 Copy_u8PortId);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
