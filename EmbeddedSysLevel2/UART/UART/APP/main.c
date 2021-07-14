/**
 * @file main.c
 * @author Elgharib
 * @brief This is the Main
 * @version 0.1
 * @date 2021-07-13
 * 
 */
#include "DataTypes.h"
#include "BIT_Math.h"
#include "UART_int.h"
#include "SER_UART_int.h"

int main(void)
{
	
	UART_ENInit();
	
	uint8_t u8Str[100];

	
    while (1) 
    {

		SER_UARTvoidReceiveString(u8Str);

		SER_UARTvoidSendString(u8Str);

    }
}

