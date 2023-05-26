/****************************************************************************/
/*Author      : Mohammed Essam										        */
/*File Name   : KEY_PAD_interface.h                                         */
/*Description : This file contains KEY_PAD interfacing macros and functions */
/*Date        : 26 May 2023                                                 */
/****************************************************************************/

#ifndef HAL_KEY_PAD_KEY_PAD_INTERFACE_H_
#define HAL_KEY_PAD_KEY_PAD_INTERFACE_H_

/*This function is to initialize key pad*/
void KEY_PAD_voidInit(KEY_PAD_t * Copy_Ptr_KEY_PAD_t);

/*This function return the value of pressed Key_PAD_Button*/
u8 KEY_PAD_u8PressedKEY_PAD_Button(KEY_PAD_t * Copy_Ptr_KEY_PAD_t);

#endif /* HAL_KEY_PAD_KEY_PAD_INTERFACE_H_ */
