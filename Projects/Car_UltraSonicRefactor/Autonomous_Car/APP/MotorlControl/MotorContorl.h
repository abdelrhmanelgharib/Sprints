/**
 * @file MotorContorl.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include "DataTypes.h"
#include "MOTOR.h"
#include "PWM.h"

#define MIN_DISTANCE  47
#define MAX_DISTANCE  52

EN_ERRORSTATE_t MOTOR_mainFunction(void);




#endif  /* MOTORCONTROL_H_ */
