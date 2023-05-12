/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : GPIO_private.h                                          */
/*Description : This file contains GPIO private registers               */
/*Date        : 11 May 2023                                             */
/************************************************************************/

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_



typedef struct
{
	u32 MODER   ;//This register is to set the mode of any pin.
	u32 OTYPER  ;//This register is to set the type of any output pins[PP/DD].
	u32 OSPEEDR ;//This register is to set the speed of any output pin.
	u32 PUPDR   ;//This register is to select whether pull up or pull down input pin.
	u32 IDR     ;//This register is to get the value of input pin.
	u32 ODR     ;//This register is to set the value of any output pin.
}GPIO_REG_t;


/*Pointer to struct*/
#define GPIOA   ((volatile GPIO_REG_t*)(0x40020000))
#define GPIOB   ((volatile GPIO_REG_t*)(0x40020400))
#define GPIOC   ((volatile GPIO_REG_t*)(0x40020800))


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */

