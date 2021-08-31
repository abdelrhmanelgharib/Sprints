/**
 * @file Debounc.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include "Debounce.h"


static uint8_t Button_OldState = READY;

volatile uint8_t Flag = 0;

void App(void)
{
	Button_OldState = READY;
	Flag = RUNNING;
}

void Delay(uint32_t Delay_us)
{

	Timer0_delayUs(Delay_us);
}


void Event_Receive(void)
{
	if( (Button_OldState == READY))
	{
		Timer0_OV_InterruptEnable();
		Button_OldState = WAIT;
		Delay(1500000);
	}
	else
	{
		/**/
	}
}


void Device_EventReceive(uint8_t state)
{
	if (state == RUNNING)
	{
		DIO_voidTogPin(PORT_A, PIN3);
		Flag =READY;
		Timer0_OV_InterruptDisable();
	}
}
