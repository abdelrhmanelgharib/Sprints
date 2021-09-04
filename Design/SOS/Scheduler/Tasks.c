/**
* @file Tasks.c
* @author Elgharib
* @brief
* @version 0.1
* @date 2021-08-29
*
* @copyright Copyright (c) 2021
*
*/

#include "DataTypes.h"
#include "Tasks.h"
#include "DIO.h"
#include "Memmap.h"

void Task_2S_Blink(void)
{
    DIO_voidTogPin(PORT_A, PIN0);
}

void Task_1S_Blink(void)
{
    DIO_voidTogPin(PORT_A, PIN1);
}

void Task_3S_Blink(void)
{
    DIO_voidTogPin(PORT_A, PIN2);
}
