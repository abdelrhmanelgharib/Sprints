/**
 * @file main.c
 * @author Elgharib
 * @brief This is a main File 
 * @version 0.1
 * @date 2021-07-07
 * 
 */

#include "DIO_Interface.h"
#include <avr/delay.h>

int main()
{
  /**
   * @brief Set Direction of LED PIN to Output
   */
  DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);

  /**
   * @brief Set Direction of Button Pin to Input
   */
  DIO_voidSetPinDirection(PORT_B, PIN1, INPUT);

  /**
   * @brief Make Button Pin a Pull up Resistor
   */
  DIO_voidInpullUp(PORT_B, PIN1);

  while (1)
  {
    if (DIO_u8GetPinValue(PORT_B, PIN1) == 0)
    {
      
      DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
      _delay_ms(500);

    }
    else if (DIO_u8GetPinValue(PORT_B, PIN1))
    {
     
      DIO_voidSetPinValue(PORT_A, PIN0, LOW);
    }
  }
}
