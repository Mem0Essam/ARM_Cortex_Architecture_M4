/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : EXTI_private.h                                          */
/*Description : This file contains EXTI private registers               */
/*Date        : 22 May 2023                                             */
/************************************************************************/

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t*)(0x40013C00))

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t*)(0x40013800))




#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
