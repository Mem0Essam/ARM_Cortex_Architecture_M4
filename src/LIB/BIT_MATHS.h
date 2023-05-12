#ifndef BIT_MATHS_H
#define BIT_MATHS_H

//this function is to set a specific bit in a variable
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
//this function is to clear a specific bit in a variable
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
//this function is to Get a specific bit in a variable
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)
//this function is to Toggle a specific bit in a variable
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
//this function is to Write a specific bit in a variable
#define WRITE_BIT(REG,BIT,BIT_VALUE) (REG = (BIT_VALUE<<BIT) | (REG &= (~(1<<BIT))))

#endif
