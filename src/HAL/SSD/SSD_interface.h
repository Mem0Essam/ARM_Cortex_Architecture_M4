/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : SSD_interface.h                                         */
/*Description : This file contains SSD interfacing macros and functions */
/*Date        : 20 May 2023                                             */
/************************************************************************/

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

/*Type of Seven Segment*/
#define Common_Cathode     0
#define Common_Anode       1


/*This function is to Initialize the SSD*/
void SSD_voidInit(u8 Copy_u8PortID,u8 Copy_u8PinID , u8 Copy_u8PinType, u8 Copy_u8PinSpeed);

/*This function is to turn on  SSD*/
void SSD_voidON(u8 Copy_u8SSD_Type , u8 Copy_u8Pin , u8 Copy_u8PortID);

/*This function is to turn off SSD*/
void SSD_voidOFF(u8 Copy_u8SSD_Type , u8 Copy_u8Pin , u8 Copy_u8PortID);

/*This function is to show value on SSD*/
void SSD_voidShowValue(u8 Copy_u8PortID , u8 Copy_u8Value);


#endif /* HAL_SSD_SSD_INTERFACE_H_ */
