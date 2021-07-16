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
 * @brief Compare two string
 * 
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1 
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2)
{ 
    uint8_t i=0, Flag=0;

    while(Str1[i] || Str2[i])
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



/**
 * @brief update system while sending command "start - wait - stop"
 * 
 */
void TrafficLight_voidStart(void)
{
    uint8_t *PStart = (uint8_t*)"start";
    uint8_t *Pstop = (uint8_t*)"stop";
    uint8_t *Pwait = (uint8_t*)"wait";

    uint8_t Command[6];
    uint8_t Flag = 0;

    SER_UARTvoidReceiveString(Command);
    if (String_u8Comp(Command, PStart) == STRING_EQUL)
    {
        Flag = START;
        SER_UARTvoidSendString((uint8_t*)"Green LED is on");
    }
    else if (String_u8Comp(Command, Pstop) == STRING_EQUL)
    {
        Flag = STOP;
        SER_UARTvoidSendString((uint8_t*)"Red LED is on");
    }
    else if (String_u8Comp(Command, Pwait) == STRING_EQUL)
    {
        Flag = WAIT;
        SER_UARTvoidSendString((uint8_t*)"Yellow LED is on");
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