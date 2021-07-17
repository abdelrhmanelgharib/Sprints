/**
 * @file SER_I2C.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-16
 * 
 */


#include "SER_I2C_int.h"


void SER_I2C_voidSendString(uint8_t* Str)
{
    uint8_t i =0;
    while (Str[i])
    {
        I2C_voidSendData(Str[i]);
        i++;
    }
    
}

