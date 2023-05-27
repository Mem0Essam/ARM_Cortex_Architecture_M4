/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : RCC_interface.h                                         */
/*Description : This file contains interfacing parameters of RCC module */
/*Date        : 04 May 2023                                             */
/************************************************************************/
#ifndef RCC_INTERFACE_H_H
#define RCC_INTERFACE_H_H

/*************Error_Status_Enum************************/
typedef enum
{

	ok,
	InvalidBitNumber,
	InvalidGPIOEntred,
	InvalidDMAEntred,
	InvalidTIMEREntred
}Error_Status;
/*****************Interfacing_Macros********************/

#define RCC_AHB1          1
#define RCC_AHB2          2
#define RCC_APB1          3
#define RCC_APB2          4

#define GPIOA             1
#define GPIOB             2
#define GPIOC             3
#define GPIOD             4
#define GPIOE             5
#define GPIOH             6

#define DMA1              1
#define DMA2              2

#define TIMER1            1
#define TIMER2            2
#define TIMER3            3
#define TIMER4            4
#define TIMER5            5
#define TIMER8            6
#define TIMER9            7
#define TIMER10           8
#define TIMER11           9

Error_Status RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);
Error_Status RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);
void RCC_voidSetSystemClock(void);
//Error_Status RCC_voidGPIOEnable(u8 Copy_u8GPIOID);
//void RCC_voidCRCEnable(void);
//Error_Status RCC_voidDMAEnable(u8 Copy_u8DMAID);
//void RCC_voidOTGFSEnable(void);
//Error_Status RCC_voidTIMEREnable(u8 Copy_u8TIMERID);

#endif
