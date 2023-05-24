/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : NVIC_private.h                                          */
/*Description : This file contains NVIC private registers               */
/*Date        : 22 May 2023                                             */
/************************************************************************/

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

typedef struct
{
	u32 ISER[8];
	u32 Reserved[24];
	u32 ICER[32];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[64];
	u8  IPR[240];  //instead of 8 registers , each has 4bytes.
}NVIC_t;


#define NVIC       ((NVIC_t*)(0xE000E100))

#define SCB_AIRCR  (*(volatile u32* )(0xE000ED0C))  //reg to config how to divide software priority between groups and sub groups for the system

#define VECT_KEY        (0x05FA0000)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
