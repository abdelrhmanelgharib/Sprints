/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */
#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include "SPI_int.h"
#include "SER_SPI_int.h"

int main(void)
{
    DIO_voidSetPinDirection(PORT_B, PIN4, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN5, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN6, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN7, INPUT);
	
	
    SPI_ENSlaveInit();
	
    uint8_t x = SPI_u8ReceiveData();
	
	DIO_voidSetPortValue(PORT_A, x);


    while (1)
    {
		
    }
}
