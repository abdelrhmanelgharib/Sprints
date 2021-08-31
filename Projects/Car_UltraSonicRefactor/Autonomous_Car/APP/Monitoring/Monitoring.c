/**
 * @file Monitoring.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Monitoring.h"

EN_ERRORSTATE_t Sensor_mainFunction(void)
{
    Ultrasonic_u16GetDistance();
}

