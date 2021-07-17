/*
 * I2C.c
 *
 * Created: 7/15/2021 7:47:58 PM
 * Author : 2bdoa
 */

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "UART_int.h"
#include "SPI_int.h"
#include "I2C_int.h"
#include "SER_UART_int.h"
#include "SER_SPI_int.h"
#include "SER_I2C_int.h"
#include "EEPROM_int.h"

int main(void)
{
    UART_ENInit();
    SPI_ENMasterInit();
    I2C_voidInitMaster();

    SER_SPIvoidInitPinMaster();
    // I2C_voidMasterStart(2);
    // I2C_voidSendData('a');
    // I2C_voidMasterStop();
    uint8_t *Write= "write";
    uint8_t Data[255];
    while (1)
    {
        SER_UARTvoidReceiveString(Data);
        if(String_u8Comp(Data, Write) == STRING_EQUL)
        {
            /* Receive Slave address */
            SER_UARTvoidReceiveString(Data);
            SER_UARTvoidSendString("OK");
            I2C_voidSLA(dd)
            SER_I2C_voidSendString(Data);
            /* delay 3Us */
            SER_UARTvoidSendString("OK");
            /* Receive 1 letter*/
            uint8_t b1 =UART_u8ReceiveData();
            /* EEPROM Write data b1 in address */
            SER_UARTvoidSendString("OK");

        }
    }
}
