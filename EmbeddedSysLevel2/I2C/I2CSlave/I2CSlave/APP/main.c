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
	DIO_voidSetPortDirection(PORT_A, PRTOUTPUT);
    I2C_voidInitSlave();
	 I2C_u8ReceiveNoACK();
	uint8_t x = I2C_u8ReceiveNoACK();
	DIO_voidSetPortValue(PORT_A, x);
	
        /* Replace with your application code */
        while (1)
    {
    }
}
