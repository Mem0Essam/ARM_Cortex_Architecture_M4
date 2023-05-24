 /************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : NVIC_interface.h                                        */
/*Description : This file contains NVIC interface functions             */
/*Date        : 22 May 2023                                             */
/************************************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#define GROUP4_SUB0         (0)   //support 16 groups (nesting level up to 16)
#define GROUP3_SUB1         (4)   //support 8 groups and 2 subpriorities
#define GROUP2_SUB2         (5)   //support 4 groups and 4 subpriorities
#define GROUP1_SUB3         (6)   //support 2 groups and 8 subpriorities
#define GROUP0_SUB4         (7)   //support 0 groups and 16 subpriorities ( no nesting )

/*This function is to initialize NVIC , sets priority configurations*/
void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8INTID);

void NVIC_voidDisableInterrupt(u8 Copy_u8INTID);

void NVIC_voidSetPendingFlag(u8 Copy_u8INTID);

void NVIC_voidClearPendingFlag(u8 Copy_u8INTID);

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8INTID);

void NVIC_voidSetSoftwarePriority(u8 Copy_u8SWPriority , u8 Copy_u8INTID);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
