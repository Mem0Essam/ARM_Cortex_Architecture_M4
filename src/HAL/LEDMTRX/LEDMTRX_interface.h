/*
 * LEDMTRX_interface.h
 *
 *  Created on: May 27, 2023
 *      Author: moham
 */

#ifndef HAL_LEDMTRX_LEDMTRX_INTERFACE_H_
#define HAL_LEDMTRX_LEDMTRX_INTERFACE_H_


/***************************Functions Prototypes******************************/
/*This function to Initialize LED Matrix*/
void LEDMTRX_voidInit(void);
/*This function to Display a specific pattern over LED Matrix*/
void LEDMTRX_voidDisplayPattern(u8 Copy_au8PatternArray[]);
/*This function is to deactivate all columns and rows*/
void LEDMTRX_voidTurnOFF(void);



#endif /* HAL_LEDMTRX_LEDMTRX_INTERFACE_H_ */
