/**
 * @file main.c
 * @author  Elgharib
 * @brief   This is a main file
 * @version 0.1
 * @date 2021-07-7
 * 
 */

#include "DIO_Interface.h"
#include "Timer.h"
#include <avr/delay.h>

void APP(void)
{
  DIO_voidTogPin(PORT_A, PIN0);
}

int main()
{

  DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);

  Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
  Timer0_SetCallBack(APP);
  Timer0_delay(2000000);
  Timer0_OV_InterruptEnable();

  while (1)
  {
    _delay_ms(100);
    DIO_voidTogPin(PORT_B, PIN1);
    _delay_ms(100);

   
  }
   return 0;
}