/*
 * SYSTICK_private.h
 *
 *  Created on: May 26, 2023
 *      Author: moham
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

typedef struct{
volatile	u32 CTRL ;
volatile	u32 LOAD ;
volatile	u32 VAL  ;
}SYSTICK_t;


#define  SYSTICK ((SYSTICK_t*)(0xE000E010))

#define  SINGLE    0

#define  PERIODIC  1

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
