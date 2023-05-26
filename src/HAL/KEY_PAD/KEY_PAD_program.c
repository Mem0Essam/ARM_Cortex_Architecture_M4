/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : KEY_PAD_program.c                                       */
/*Description : This file contains KEY_PAD functions implementation     */
/*Date        : 26 May 2023                                             */
/************************************************************************/
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"


#include "../../MCAL/GPIO/GPIO_interface.h"

#include "KEY_PAD_interface.h"
#include "KEY_PAD_private.h"
#include "KEY_PAD_config.h"


void KEY_PAD_voidInit(KEY_PAD_t * Copy_Ptr_KEY_PAD_t){
	GPIO_voidInitInputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW1,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW2,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW3,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW4,GPIO_INPUT_PULL_UP);

	GPIO_voidInitOutputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN1,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN2,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN3,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN4,GPIO_OUTPUT_HIGH);
}


u8 KEY_PAD_u8PressedKEY_PAD_Button(KEY_PAD_t * Copy_Ptr_KEY_PAD_t){
	u8 Local_u8ColumnIterator;
	u8 Local_u8RowIterator;
	u8 Local_u8PressdKEY_PAD_Value=255;
	for(Local_u8ColumnIterator = 0 ; Local_u8ColumnIterator < 4 ; Local_u8ColumnIterator++)
	{
		if (Local_u8ColumnIterator == 0 )
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN1,GPIO_OUTPUT_LOW);
		else if (Local_u8ColumnIterator == 1)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN2,GPIO_OUTPUT_LOW);
		else if (Local_u8ColumnIterator == 2)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN3,GPIO_OUTPUT_LOW);
		else if (Local_u8ColumnIterator == 3)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN4,GPIO_OUTPUT_LOW);

		if ((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW1)) == 0)
		{
			Local_u8PressdKEY_PAD_Value = KEY_PAD_u8Mapping[0][Local_u8ColumnIterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW1)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW2)) == 0)
		{
			Local_u8PressdKEY_PAD_Value = KEY_PAD_u8Mapping[1][Local_u8ColumnIterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW2)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW3)) == 0)
		{
			Local_u8PressdKEY_PAD_Value = KEY_PAD_u8Mapping[2][Local_u8ColumnIterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW3)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW4)) == 0)
		{
			Local_u8PressdKEY_PAD_Value = KEY_PAD_u8Mapping[3][Local_u8ColumnIterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_ROW4)) == 0);
		}
		else
		{

		}

		if (Local_u8ColumnIterator == 0 )
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN1,GPIO_OUTPUT_HIGH);
		else if (Local_u8ColumnIterator == 1)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN2,GPIO_OUTPUT_HIGH);
		else if (Local_u8ColumnIterator == 2)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN3,GPIO_OUTPUT_HIGH);
		else if (Local_u8ColumnIterator == 3)
			GPIO_voidSetOutputPinValue(Copy_Ptr_KEY_PAD_t->KEY_PAD_COLUMN4,GPIO_OUTPUT_HIGH);
	}
	return Local_u8PressdKEY_PAD_Value;

}

