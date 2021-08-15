/**
 * @file main.c
 * @author Vicious
 * @brief This is a Main File
 * @version 0.1
 * @date 2021-07-11
 * 
 */

#include "DIO_Interface.h"
#include "Timer.h"
#include "EXTI_int.h"
#include "SWITCH_int.h"
#include "MOTOR_Interface.h"

#include "CarControl_int.h"




int main(void)
{
	Car_init();
	
    while (1) 
    {
		Car_Control();
	}
}

