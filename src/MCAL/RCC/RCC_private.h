/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : RCC_private.h                                           */
/*Description : This file contains private parameters of RCC module     */
/*Date        : 04 May 2023                                             */
/************************************************************************/
#ifndef RCC_PRIVATE_H_H
#define RCC_PRIVATE_H_H

//RCC registers
#define RCC_CR      *((volatile u32 * )(0x40023800))

#define HSION      0
#define HSIRDY     1

#define HSITRIM0   3
#define HSITRIM1   4
#define HSITRIM2   5
#define HSITRIM3   6
#define HSITRIM4   7

#define HSICAL0    8
#define HSICAL1    9
#define HSICAL2    10
#define HSICAL3    11
#define HSICAL4    12
#define HSICAL5    13
#define HSICAL6    14
#define HSICAL7    15

#define HSEON      16
#define HSERDY     17
#define HSEBYP     18
#define CSSON      19

#define PLLON      24
#define PLLRDY     25
#define PLLI2SON   26
#define PLLI2SRDY  27

#define RCC_CFGR    *((volatile u32 * )(0x40023808))

#define SW0        0
#define SW1        1

#define SWS0       2
#define SWS1       3

#define HPRE0      4
#define HPRE1      5
#define HPRE2      6
#define HPRE3      7


#define PPRE10     10
#define PPRE11     11
#define PPRE12     12

#define PPRE20     13
#define PPRE21     14
#define PPRE22     15

#define RTCPRE0    16
#define RTCPRE1    17
#define RTCPRE2    18
#define RTCPRE3    19
#define RTCPRE4    20

#define MCO10      21
#define MCO11      22

#define I2SSRC     23

#define MCO1PRE0   24
#define MCO1PRE1   25
#define MCO1PRE2   26

#define MCO2PRE0   27
#define MCO2PRE1   28
#define MCO2PRE2   29

#define MCO20      30
#define MCO21      31



#define RCC_AHB1ENR *((volatile u32 * )(0x40023830))

#define GPIOAEN      0
#define GPIOBEN      1
#define GPIOCEN      2
#define GPIODEN      3
#define GPIOEEN      4

#define GPIOHEN      7

#define CRCEN       12

#define DMA1EN      21
#define DMA2EN      22


#define RCC_AHB2ENR *((volatile u32 * )(0x40023834))

#define OTGFSEN    7

#define RCC_APB1ENR *((volatile u32 * )(0x40023840))

#define TIM2EN     0
#define TIM3EN     1
#define TIM4EN     2
#define TIM5EN     3

#define WWDGEN     11


#define SPI2EN     14
#define SPI3EN     15

#define USART2EN   17

#define I2C1EN     21
#define I2C2EN     22
#define I2C3EN     23

#define PWREN      28

#define RCC_APB2ENR *((volatile u32 * )(0x40023844))

#define TIM1EN     0

#define USART1EN   4
#define USART6EN   5

#define ADC1EN     8

#define SDIOEN     11

#define SPI1EN     12
#define SPI4EN     13

#define SYSCFGEN   14

#define TIM9EN     16
#define TIM10EN    17
#define TIM11EN    18

/*System Clock Configurations*/
#define HSI         1
#define HSE_RC      2
#define HSE_CRYSTAL 3
#define PLL         4


#endif
