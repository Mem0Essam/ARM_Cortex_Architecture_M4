/*
 * SYSTICK_interface.h
 *
 *  Created on: May 26, 2023
 *      Author: moham
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

/*This function is to initialize SYSTICK*/
void SYSTICK_voidInit(void);

void SYSTICK_voidDelaySync(u32 Copy_u32Delay_us);

void SYSTICK_voidDelayAsync(u32 Copy_u32Delay_us ,void (*Copy_ptrToFunc)(void));

u32 SYSTICK_u32GetRemainingTime(void);

u32 SYSTICK_u32ElapsedTime(void);

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
