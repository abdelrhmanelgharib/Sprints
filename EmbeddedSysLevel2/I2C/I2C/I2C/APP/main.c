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
	DIO_voidSetPortDirection(PORT_B,PRTOUTPUT);
	DIO_voidSetPortValue(PORT_B, PRTHIGH);
    I2C_voidInitMaster();
    I2C_voidMasterStart();
	I2C_void_M_AddressSLV_Write((uint8_t)110);
    I2C_voidSendData('a');
    I2C_voidMasterStop();

        /* Replace with your application code */
        while (1)
    {
    }
}
