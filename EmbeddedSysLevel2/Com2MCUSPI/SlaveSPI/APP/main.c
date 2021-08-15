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
    SER_SPIvoidInitPinSlave();

    DIO_voidSetPinDirection(PORT_D, PIN0, INPUT);
    DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);

    UART_ENInit();
    SPI_ENSlaveInit();

    uint8_t str[256];

    /* Replace with your application code */
    while (1)
    {
        SER_SPIvoidReceiveString(str);
        SER_UARTvoidSendString(str);
    }
}
