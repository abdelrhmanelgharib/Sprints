/*
 * APP.h
 *
 *  Created on: Aug 13, 2021
 *      Author: Al Mohamed
 */

#ifndef AUTONOMOUS_CAR_APP_APP_H_
#define AUTONOMOUS_CAR_APP_APP_H_

#include "DataTypes.h"
#include "DIO.h"
#include "LCD.h"
#include "MOTOR.h"
#include "PWM.h"
#include "Ultrasonic.h"
#include "MotorContorl.h"
#include "Monitoring.h"

void APP_Init(void);

void APP_Start(void);

#define delay_35ms  140
#define delay_36ms  144
#define delay_37ms  148
#define delay_38ms  152
#define delay_39ms  156
#define delay_42ms  158


#define state_on  1
#define state_off 0



#endif /* AUTONOMOUS_CAR_APP_APP_H_ */
