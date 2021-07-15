/**
 * @file TrafficLight.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */
#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include "UART_int.h"
#include "SER_UART_int.h"
#include "LED_int.h"
#include "TrafficLight_int.h"
#include <string.h>

/**
 * @brief initialized LED, UART And DIo
 * 
 */
void TrafficLight_voidInit(void)
{
    LED_voidInitialize();
    UART_ENInit();
}

/**
 * @brief update system while sending command "start - wait - stop"
 * 
 */
void TrafficLight_voidStart(void)
{
    uint8_t *PStart = "start";
    uint8_t *Pstop = "stop";
    uint8_t *Pwait = "wait";

    uint8_t Command[6];
    uint8_t Flag = 0;

    SER_UARTvoidReceiveString(Command);
    if (strcmp(Command, PStart) == 0)
    {
        Flag = START;
		SER_UARTvoidSendString("Green LED is on");
    }
    else if (strcmp(Command, Pstop) == 0)
    {
        Flag = STOP;
		SER_UARTvoidSendString("Red LED is on");
    }
    else if (strcmp(Command, Pwait) == 0)
    {
        Flag = WAIT;
		SER_UARTvoidSendString("Yellow LED is on");
    }
    else
    {
        // state = E_ERROR;
    }

    switch (Flag)
    {
    case 1:
        LED_voidLedOff(LED0);
        LED_voidLedOff(LED1);
        LED_voidLedOn(LED2);

        break;
    case 2:
        LED_voidLedOff(LED1);
        LED_voidLedOff(LED2);
        LED_voidLedOn(LED0);

        break;
    case 3:
        LED_voidLedOff(LED0);
        LED_voidLedOff(LED2);
        LED_voidLedOn(LED1);

        break;
    default:
        break;
    }
}