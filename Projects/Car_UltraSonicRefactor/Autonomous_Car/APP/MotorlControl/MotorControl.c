/**
 * @file MotorControl.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MotorContorl.h"

extern uint16_t gDistance;

EN_ERRORSTATE_t MOTOR_mainFunction(void)
{
    EN_ERRORSTATE_t state;
    state = E_OK;
    
    if (gDistance < MIN_DISTANCE)
    {
        PWM_ENDutyCycle(20);
        MOTOR_voidRotateAntiClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_ON);
    }
    else if ((MIN_DISTANCE < gDistance) && (gDistance <= MAX_DISTANCE))
    {
        PWM_ENDutyCycle(40);

        MOTOR_voidRotateClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_OFF);
    }
    else if (gDistance > MAX_DISTANCE)
    {
        PWM_ENDutyCycle(20);
        MOTOR_voidRotateClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_ON);
    }
    else
    {
        state = E_ERROR;
    }
    return state;
}
