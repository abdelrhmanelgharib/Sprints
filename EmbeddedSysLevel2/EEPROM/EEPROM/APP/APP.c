/**
 * @file APP.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "APP_int.h"

/**
 * @brief This Function Initialize All Peripheral need in the app
 * @param void 
 * @return void
 **/
void APP_voidInit(void)
{
    /* Direction for UaRT PINS */
    /* UART RX PIN */
    DIO_voidSetPinDirection(PORT_D, PIN0, INPUT);
    /* UART TX PIN */
    DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);

    UART_ENInit();
    I2C_voidInitMaster();
    EEPROM_voidInit();
}

/**
 * @brief Compare two string
 * 
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1 
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2)
{
    uint8_t i = 0, Flag = 0;

    while (Str1[i] || Str2[i])
    {
        if (Str1[i] != Str2[i])
        {
            Flag = 1;
            break;
        }
        i++;
    }
    return Flag;
}

uint32_t String_u8ToNumb(uint8_t *Str)
{
    uint8_t i;
    uint32_t Result = 0;
    for (i = 0; Str[i]; i++)
    {
        Result = Result * 10 + Str[i] - '0';
    }
    return Result;
}

uint8_t Binary_u8ToNumb(uint32_t u32_Binary)
{
    uint32_t Dec = 0, base = 1, rem;

    while (u32_Binary > 0)
    {
        rem = u32_Binary % 10;
        Dec += rem * base;
        u32_Binary = u32_Binary / 10;
        base = base * 2;
    }
    return Dec;
}

void APP_voidWrite(void)
{
    uint8_t Data[255], binary_add;
    uint32_t address = 0;

    /* Receive EEPROM address of byte  */
    SER_UARTvoidReceiveString(Data);
    /* convert string to Numb */
    address = String_u8ToNumb(Data);
    /* convert Number to Decimal */
    binary_add = Binary_u8ToNumb(address);
    SER_UARTvoidSendString((uint8_t*)"OK");
    /* Receive 1 letter*/
    uint8_t b1 = UART_u8ReceiveData();
    uint8_t b2 = UART_u8ReceiveData();
    if (b2 == '\r')
    {
        EEPROM_voidWriteByte(b1, binary_add);
        SER_UARTvoidSendString((uint8_t*)"OK");
    }
}

void APP_voidRead(void)
{
    uint8_t Data[255], binary_add;
    uint32_t address = 0;
    /* Receive EEPROM address of byte  */
    SER_UARTvoidReceiveString(Data);
    /* Change string to Numb */
    address = String_u8ToNumb(Data);
    binary_add = Binary_u8ToNumb(address);
    SER_UARTvoidSendString((uint8_t*)"OK");
    uint8_t b_read = EEPROM_voidReadByte(binary_add);
    UART_ENSendData(b_read);
    UART_ENSendData('\r');
    SER_UARTvoidSendString((uint8_t*)"OK");
}
