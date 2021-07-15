/**
 * @file SER_SPI.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */
#include "SER_SPI_int.h"

/**
 * @brief Initialize Pin for Master
 * 
 */
void SER_SPIvoidInitPinMaster(void)
{
    DIO_voidSetPinDirection(PORT_B, PIN4, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN5, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN6, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN7, OUTPUT);
}

/**
 * @brief Initialize Pin for Slave
 * 
 */
void SER_SPIvoidInitPinSlave(void)
{
    DIO_voidSetPinDirection(PORT_B, PIN4, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN5, INPUT);
    DIO_voidSetPinDirection(PORT_B, PIN6, OUTPUT);
    DIO_voidSetPinDirection(PORT_B, PIN7, INPUT);
}

/**
 * @brief Send String using SPI
 * 
 * @param PStr Address of the string to send
 */
void SER_SPIvoidSendString(uint8_t *PStr)
{
    uint8_t i = 0;
    SPI_voidSendData(PStr[i]);
    while (PStr[i])
    {
        i++;
        SPI_voidSendData(PStr[i]);
    }
    PStr[i] = 0;
}

/**
 * @brief Receive String using SPI
 * 
 * @param Str 
 */
void SER_SPIvoidReceiveString(uint8_t *Str)
{
    uint8_t i = 0;
    Str[i] = SPI_u8ReceiveData();
    while (Str[i])
    {
        i++;
        Str[i] = SPI_u8ReceiveData();
    }
    /* replace to NULL */
    Str[i] = 0;
}
