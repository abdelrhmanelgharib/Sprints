/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#include "DIO_Interface.h"
#include "UART_int.h"
#include "SPI_int.h"
#include "SER_UART_int.h"
#include "SER_SPI_int.h"

int main(void)
{
    uint8_t str[255];

    SER_SPIvoidInitPinMaster();
    DIO_voidSetPinValue(PORT_B, PIN7, LOW);
	
	
	DIO_voidSetPinDirection(PORT_D, PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);
	
    
    UART_ENInit();
    SPI_ENMasterInit();

    while (1)
    {
        SER_UARTvoidReceiveString(str);
		
        SER_SPIvoidSendString(str);
    }
}
