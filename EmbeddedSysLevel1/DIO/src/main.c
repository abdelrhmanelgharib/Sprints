/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 */


#include "DIO_Interface.h"


int main()
{
  DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);
  DIO_voidSetPinDirection(PORT_A, PIN1, OUTPUT);

  while (1)
  {
    DIO_voidSetPinValue(PORT_A, PIN6, HIGH);

    DIO_voidSetPinValue(PORT_A, PIN1, HIGH);
  }
}
