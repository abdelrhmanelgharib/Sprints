/*
 * I2C.c
 *
 * Created: 7/15/2021 7:47:58 PM
 * Author : 2bdoa
 */

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "I2C_int.h"

int main(void)
{
    I2C_voidInitMaster();
    I2C_voidMasterStart();
    I2C_voidSLA(1);
    I2C_voidSendData('a');
    I2C_voidMasterStop();

        /* Replace with your application code */
        while (1)
    {
    }
}
