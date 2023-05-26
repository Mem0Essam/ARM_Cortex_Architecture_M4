/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : EXTI_interface.h                                        */
/*Description : This file contains EXTI interface functions             */
/*Date        : 22 May 2023                                             */
/************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*16 Macro for EXTI lines*/
#define EXTI_LINE0      0
#define EXTI_LINE1      1
#define EXTI_LINE2      2
#define EXTI_LINE3      3
#define EXTI_LINE4      4
#define EXTI_LINE5      5
#define EXTI_LINE6      6
#define EXTI_LINE7      7
#define EXTI_LINE8      8
#define EXTI_LINE9      9
#define EXTI_LINE10     10
#define EXTI_LINE11     11
#define EXTI_LINE12     12
#define EXTI_LINE13     13
#define EXTI_LINE14     14
#define EXTI_LINE15     15

/*3 macros for sense signal*/
#define FALLING_EDGE           1
#define RISING_EDGE            2
#define ON_CHANGE              3

void EXTI_voidEnableInt(u8 Copy_u8IntId, void(*Copy_ptrToFunc)(void));
void EXTI_voidDisableInt(u8 Copy_u8IntId);
void EXTI_voidSetSenseSignal(u8 Copy_u8IntId,u8 Copy_u8SenseSignal);
void EXTI_voidSetLinePort(u8 Copy_u8IntId,u8 Copy_u8PortId);
static void EXTI_voidClearPendingFlag(u8 Copy_u8IntId);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
