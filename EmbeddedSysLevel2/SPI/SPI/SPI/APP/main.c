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
	SER_SPIvoidInitPinMaster();
	
    SPI_ENMasterInit();
	
	SPI_u8SendReceive('a');
		
	
	
    while (1)
    {
		
    }
}
