/**
 * @file LED_prog.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#include "LED_int.h"


/**
 * @brief initialized Led Direction and connection Type
 * 
 */
void LED_voidInitialize(void)
{
    DIO_voidSetPinDirection(LED_0_PORT, LED_0_PIN, OUTPUT);
    DIO_voidSetPinDirection(LED_1_PORT, LED_0_PIN, OUTPUT);
    DIO_voidSetPinDirection(LED_2_PORT, LED_0_PIN, OUTPUT);
}



/**
 * @brief Turn on Led
 * 
 * @param led_num Led Numb
 */
void LED_voidLedOn(uint8_t led_num)
{
    if (led_num == LED0)
    {
#if (LED_0_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_0_PORT, LED_0_PIN, HIGH);
        }
#else
        {
            DIO_voidSetPinValue(LED_0_PORT, LED_0_PIN, LOW);
        }
#endif
    }

    if (led_num == LED1)
    {
#if (LED_1_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_1_PORT, LED_1_PIN, HIGH);
        }
#else
        {
            DIO_voidSetPinValue(LED_1_PORT, LED_1_PIN, LOW);
        }
#endif
    }

    if (led_num == LED2)
    {
#if (LED_2_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_2_PORT, LED_2_PIN, HIGH);
        }
#else
        {
            DIO_voidSetPinValue(LED_2_PORT, LED_2_PIN, LOW);
        }
#endif
    }
}



/**
 * @brief Turn Off Led
 * 
 * @param led_num Led Numb
 */
void LED_voidLedOff(uint8_t led_num)
{
    if (led_num == LED0)
    {
#if (LED_0_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_0_PORT, LED_0_PIN, LOW);
        }
#else
        {
            DIO_voidSetPinValue(LED_0_PORT, LED_0_PIN, HIGH);
        }
#endif
    }

    if (led_num == LED1)
    {
#if (LED_1_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_1_PORT, LED_1_PIN, LOW);
        }
#else
        {
            DIO_voidSetPinValue(LED_1_PORT, LED_1_PIN, HIGH);
        }
#endif
    }

    if (led_num == LED2)
    {
#if (LED_2_CONNECTION == FORWARD)
        {
            DIO_voidSetPinValue(LED_2_PORT, LED_2_PIN, LOW);
        }
#else
        {
            DIO_voidSetPinValue(LED_2_PORT, LED_2_PIN, HIGH);
        }
#endif
    }
}



/**
 * @brief Toggle Led
 * 
 * @param led_num Len Numb
 */
void LED_voidLedToggle(uint8_t led_num)
{
    if (led_num == LED0)
    {
        DIO_voidTogPin(LED_0_PORT, LED_0_PIN);
    }

    else if (led_num == LED1)
    {
        DIO_voidTogPin(LED_1_PORT, LED_1_PIN);
    }

    else if (led_num == LED2)
    {
        DIO_voidTogPin(LED_2_PORT, LED_2_PIN);
    }
}