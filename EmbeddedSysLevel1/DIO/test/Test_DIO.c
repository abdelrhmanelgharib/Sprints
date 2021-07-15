/**
 * @file Test_DIO.c
 * @author Elgharib
 * @brief Unit Test on DIO Functions
 * @version 0.1
 * @date 2021-07-13
 * 
 */
#include "DIO_Interface.h"

void TestPinValue(void)
{
    /* Test LOW */
    if (DIO_voidSetPinValue(PORT_B, PIN3, HIGH) == E_OK)
    {
        /* Led on */
        PORTB = 0x01;
    }
    else
    {
        /* Led Off */
    }

    /* Test HIGH */
    if (DIO_voidSetPinValue(PORT_B, PIN4, HIGH) == E_OK)
    {
        /* Led on */
        PORTB = 0x10;
    }
    else
    {
        /* Led Off */
    }
}

void TestPinDirection(void)
{
    if (DIO_voidSetPinDirection(PORT_B, PIN0, INPUT) == E_OK)
    {
        /* Led on */
        PORTB = 0x01;
    }
    else
    {
        /* Led Off */
    }

    if (DIO_voidSetPinDirection(PORT_B, PIN1, OUTPUT) == E_OK)
    {
        /* Led on */
        PORTB = 0x02;
    }
    else
    {
        /* Led Off */
    }
}

void TestTogPin(void)
{
    if (DIO_voidTogPin(PORT_C, PIN2) == E_OK)
    {
        PORTC = 0x04;
    }
}