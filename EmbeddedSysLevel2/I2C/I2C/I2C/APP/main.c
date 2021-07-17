/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "I2C_int.h"

int main(void)
{
    I2C_voidInitMaster();
    I2C_voidMasterStart(2);
    I2C_voidSendData('a');
    I2C_voidMasterStop();

        /* Replace with your application code */
        while (1)
    {
    }
}
