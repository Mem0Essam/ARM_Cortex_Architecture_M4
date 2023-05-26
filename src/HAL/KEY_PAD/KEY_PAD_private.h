/************************************************************************/
/*Author      : Mohammed Essam										    */
/*File Name   : KEY_PAD_private.h                                       */
/*Description : This file contains KEY_PAD private files                */
/*Date        : 26 May 2023                                             */
/************************************************************************/

#ifndef HAL_KEY_PAD_KEY_PAD_PRIVATE_H_
#define HAL_KEY_PAD_KEY_PAD_PRIVATE_H_


/*PIN of KEY_PAD*/
typedef struct {
	u8 KEY_PAD_ROW1;
	u8 KEY_PAD_ROW2;
	u8 KEY_PAD_ROW3;
	u8 KEY_PAD_ROW4;
	u8 KEY_PAD_COLUMN1;
	u8 KEY_PAD_COLUMN2;
	u8 KEY_PAD_COLUMN3;
	u8 KEY_PAD_COLUMN4;
}KEY_PAD_t;



#endif /* HAL_KEY_PAD_KEY_PAD_PRIVATE_H_ */
