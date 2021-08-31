/*
 * Ultrasonic_cfg.h
 *
 *  Created on: Aug 13, 2021
 *      Author: Al Badr
 */

#ifndef AUTONOMOUS_CAR_HAL_ULTRA_SONIC_ULTRASONIC_CFG_H_
#define AUTONOMOUS_CAR_HAL_ULTRA_SONIC_ULTRASONIC_CFG_H_


#define FALLING		    0
#define RISING		    1
#define READ_DISTANCE	2
#define ZERO		    0
#define SOUND_VELOCITY_DIVIDED_BY_TICK_TIME		58


#define TRIG_PORT       PORT_B
#define TRIG_PIN        PIN3

#define ECHO_PORT       PORT_B
#define ECHO_PIN        PIN2

#endif /* AUTONOMOUS_CAR_HAL_ULTRA_SONIC_ULTRASONIC_CFG_H_ */
