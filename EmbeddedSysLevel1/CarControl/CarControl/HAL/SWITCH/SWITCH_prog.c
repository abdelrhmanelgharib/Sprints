/*
 *  Author: Team_3
 *  Created on: 11/7/2021
 */

#include "SWITCH_int.h"



uint8_t SWITCH_u8GetState(uint8_t switch_num)
{
    uint8_t x, ret;

    if (switch_num == SWITCH0)
    {
        #if (SWITCH_0_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPinValue(SWITCH_0_PORT, SWITCH_0_PIN);
            if (x == LOW)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPinValue(SWITCH_0_PORT, SWITCH_0_PIN);
            if (x == HIGH)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
        }
        #endif
    }
    else if (switch_num == SWITCH1)
    {
        #if (SWITCH_1_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPinValue(SWITCH_1_PORT, SWITCH_1_PIN);
            if (x == LOW)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPinValue(SWITCH_1_PORT, SWITCH_1_PIN);
            if (x == HIGH)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
        }
        #endif
    }
	else if (switch_num == SWITCH2)
	{
		#if (SWITCH_2_CONNECTION == PULLUP)
		{
			x=DIO_u8GetPinValue(SWITCH_2_PORT, SWITCH_2_PIN);
			if (x == LOW)
			{
				ret= PRESSED;
			}
			else
			{
				ret= NOT_PRESSED;
			}
			
		}
		#else
		{
			x=DIO_u8GetPinValue(SWITCH_2_PORT, SWITCH_2_PIN);
			if (x == HIGH)
			{
				ret= PRESSED;
			}
			else
			{
				ret= NOT_PRESSED;
			}
		}
		#endif
	}
	else if (switch_num == SWITCH3)
	{
		#if (SWITCH_2_CONNECTION == PULLUP)
		{
			x=DIO_u8GetPinValue(SWITCH_3_PORT, SWITCH_3_PIN);
			if (x == LOW)
			{
				ret= PRESSED;
			}
			else
			{
				ret= NOT_PRESSED;
			}
			
		}
		#else
		{
			x=DIO_u8GetPinValue(SWITCH_3_PORT, SWITCH_3_PIN);
			if (x == HIGH)
			{
				ret= PRESSED;
			}
			else
			{
				ret= NOT_PRESSED;
			}
		}
		#endif
	}
    return ret;
    
}
