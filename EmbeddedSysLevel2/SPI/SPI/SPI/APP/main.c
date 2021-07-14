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
    DIO_voidSetPinDirection(PORT_B, PIN4, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN5, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN6, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN7, OUTPUT);
	DIO_voidSetPinValue(PORT_B, PIN7, LOW);
    SPI_ENMasterInit();
	SPI_u8SendReceive('a');
	
	
    while (1)
    {
		
    }
}
