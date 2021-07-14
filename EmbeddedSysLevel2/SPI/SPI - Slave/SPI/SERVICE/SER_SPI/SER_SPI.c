/**
 * @file SER_SPI.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */
#include "SER_SPI_int.h"

void SER_SPIvoidSendString(uint8_t *PStr)
{
    uint8_t i = 0;
    for (i = 0; PStr[i]; i++)
    {
        SPI_voidSendData(PStr[i]);
    }
}

void SER_SPIvoidReceiveString(uint8_t *Str)
{
    uint8_t i = 0;
    Str[i] = SPI_u8ReceiveData();
    while (Str[i] != '#')
    {
        i++;
        Str[i] = SPI_u8ReceiveData();
    }
    /* replace to NULL */
    Str[i] = '\0';
}
