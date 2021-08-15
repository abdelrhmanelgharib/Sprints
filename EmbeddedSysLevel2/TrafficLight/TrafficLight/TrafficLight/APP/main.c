/**
 * @file main.c
 * @author Elgharib
 * @brief Main File
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include "UART_int.h"
#include "SER_UART_int.h"
#include "TrafficLight_int.h"





int main(void)
{
    TrafficLight_voidInit();


    while (1) 
    {
        TrafficLight_voidStart();
    }
}

