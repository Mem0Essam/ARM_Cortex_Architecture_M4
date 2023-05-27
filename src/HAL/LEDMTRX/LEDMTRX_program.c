/*
 * LEDMTRX_program.c
 *
 *  Created on: May 27, 2023
 *      Author: moham
 */

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"


#include "LEDMTRX_interface.h"
#include "LEDMTRX_config.h"
#include "LEDMTRX_private.h"


/*Global Array to iterate over led Matrix rows*/
u8 Global_u8RowsArray[ROW_NUM][2]={{ROW0},{ROW1},{ROW2},{ROW3},{ROW4},{ROW5},{ROW6},{ROW7}};
/*Global Array to iterate over led Matrix columns*/
u8 Global_u8ColsArray[COL_NUM][2]={{COL0},{COL1},{COL2},{COL3},{COL4},{COL5},{COL6},{COL7}};
void LEDMTRX_voidInit(void){

	/*Local iterator to loop over rows and columns*/
	u8 Local_u8Iterator = 0 ;


	/*(1),(2) Set all rows and columns pins to be output , push pull , low speed */
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++){
		GPIO_voidInitOutputPin(Global_u8RowsArray[Local_u8Iterator][0],Global_u8RowsArray[Local_u8Iterator][1],GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	}
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++){
		GPIO_voidInitOutputPin(Global_u8ColsArray[Local_u8Iterator][0],Global_u8ColsArray[Local_u8Iterator][1],GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	}
	/*(3) Deactivate all Columns */
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++){
		GPIO_voidSetOutputPinValue(Global_u8ColsArray[Local_u8Iterator][0],Global_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}
	/*(4)set all LEDS OFF*/
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++){
		GPIO_voidSetOutputPinValue(Global_u8RowsArray[Local_u8Iterator][0],Global_u8RowsArray[Local_u8Iterator][1],GPIO_OUTPUT_LOW);
	}
}
void LEDMTRX_voidTurnOFF(void){
	/*Local iterator to loop over rows and columns*/
	u8 Local_u8Iterator = 0 ;
	/*(1) Deactivate all Columns */
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++){
		GPIO_voidSetOutputPinValue(Global_u8ColsArray[Local_u8Iterator][0],Global_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}
	/*(2)set all LEDS OFF*/
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++){
		GPIO_voidSetOutputPinValue(Global_u8RowsArray[Local_u8Iterator][0],Global_u8RowsArray[Local_u8Iterator][1],GPIO_OUTPUT_LOW);
	}
}
void LEDMTRX_voidDisplayPattern(u8 Copy_au8PatternArray[]){

	/*Local iterator to loop over columns*/
	u8 Local_u8ColsIterator = 0 ;
	/*Local iterator to loop over rows*/
	u8 Local_u8RowsIterator = 0 ;
	/*Local over columns to activate one by one*/
	for(Local_u8ColsIterator=0 ; Local_u8ColsIterator<COL_NUM ;Local_u8ColsIterator++){
		/*Activate the current Column -> Set it's pin to be low output*/
		GPIO_voidSetOutputPinValue(Global_u8ColsArray[Local_u8ColsIterator][0],Global_u8ColsArray[Local_u8ColsIterator][1],GPIO_OUTPUT_LOW);
		/*Loop over all rows to set the corresponding value -> either 0 or 1 from the pattern array*/
		for(Local_u8RowsIterator=0; Local_u8RowsIterator<ROW_NUM;Local_u8RowsIterator++){
			/*Set the value of the rows to be the value of the corresponding bit for the row the corresponding pattern index for the activated columns*/
			GPIO_voidSetOutputPinValue(Global_u8RowsArray[Local_u8RowsIterator][0],Global_u8RowsArray[Local_u8RowsIterator][1],GET_BIT(Copy_au8PatternArray[Local_u8ColsIterator],Local_u8RowsIterator));
		}
		/*Set delay = 2.5 msec between every activation*/
		SYSTICK_voidDelaySync(2500);
		/*Led matrix reset before the new activation*/
		LEDMTRX_voidTurnOFF();
	}
}


