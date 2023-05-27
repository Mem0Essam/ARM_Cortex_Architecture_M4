/*
 * LEDMTRX_config.h
 *
 *  Created on: May 27, 2023
 *      Author: moham
 */

#ifndef HAL_LEDMTRX_LEDMTRX_CONFIG_H_
#define HAL_LEDMTRX_LEDMTRX_CONFIG_H_
/************Configuration Parameters***********/

/*Size of led matrix*/
#define COL_NUM     8
#define ROW_NUM     8

/*Available options for port value : GPIO_PORTA , GPIO_PORTB , GPIO_PORTC*/
/*Available options for pin value :0->15 */
/*NOTE!!! : Avoid forbidden pins A13,A14,A15 B2,B3,B4*/

#define COL0     GPIO_PORTA,0
#define COL1     GPIO_PORTA,1
#define COL2     GPIO_PORTA,2
#define COL3     GPIO_PORTA,3
#define COL4     GPIO_PORTA,4
#define COL5     GPIO_PORTA,5
#define COL6     GPIO_PORTA,6
#define COL7     GPIO_PORTA,7

#define ROW0     GPIO_PORTB,0
#define ROW1     GPIO_PORTB,1
#define ROW2     GPIO_PORTB,5
#define ROW3     GPIO_PORTB,6
#define ROW4     GPIO_PORTB,7
#define ROW5     GPIO_PORTB,8
#define ROW6     GPIO_PORTB,9
#define ROW7     GPIO_PORTB,10







#endif /* HAL_LEDMTRX_LEDMTRX_CONFIG_H_ */
