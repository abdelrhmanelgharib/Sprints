/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "TWI_int.h"

int main(void)
{
     TWI_voidInit();
     TWI_voidStartBit();
	 TWI_voidSLV_Write(0x02);
	 TWI_voidSendData('a');
	 TWI_voidStopBit();

    uint8_t i;

    /* Replace with your application code */
    while (1)
    {

    }
}
