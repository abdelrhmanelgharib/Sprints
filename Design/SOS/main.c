/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "DIO.h"
#include "Timer.h"
#include "OS.h"
#include "Tasks.h"
#include "avr/delay.h"

volatile static uint16_t u16_100UsCount = 0;
volatile static uint16_t u16_MsCount = 0;

void OS_Init(void)
{
    OS_TaskCreate(Task_2S_Blink, 2, IDLE);
    OS_TaskCreate(Task_1S_Blink, 1, IDLE);
    OS_TaskCreate(Task_3S_Blink, 3, IDLE);
}

void App(void)
{
    u16_100UsCount++;

    if (u16_100UsCount % 10 == 0)
    {
        u16_100UsCount = 0;
        u16_MsCount++;
    }
    if (u16_MsCount >= 1000)
    {
        u16_MsCount = 0;
        /* call task the scheduler handler */
        OS_Task_Handler();
    }
}

int main()
{
    DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);
    DIO_voidSetPinDirection(PORT_A, PIN1, OUTPUT);
    DIO_voidSetPinDirection(PORT_A, PIN2, OUTPUT);

    Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
    Timer0_OV_InterruptEnable();
    Timer0_SetCallBack(App);
    OS_Init();

    while (1)
    {
        OS_TaskExecution();
    }
}
