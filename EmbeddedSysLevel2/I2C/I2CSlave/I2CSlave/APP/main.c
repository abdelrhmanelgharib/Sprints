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
	uint8_t status=0;
	DIO_voidSetPortDirection(PORT_A, PRTOUTPUT);
    I2C_voidInitSlave((uint8_t)110);
	
	// I2C_u8ReceiveACK();
	uint8_t x = I2C_u8ReceiveACK();
	DIO_voidSetPortValue(PORT_A, x);

	
        /* Replace with your application code */
        while (1)
    {
    }
}
