/*
 *  Author: Vicious
 *  Created on: 11/7/2021
 */
#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_

/*choose num of motors*/



#define CONNECT_TWO_MOTOR    0
#define CONNECT_ONE_MOTOR    1
#define  MOTOR_Generate_pwm  2
#define  MOTOR_STATE  MOTOR_Generate_pwm
#define NUM_OF_MOTORS  CONNECT_TWO_MOTOR


/* top MOTOR */
#define MOTOR1_PORT PORT_D
#define MOTOR1_PIN1 PIN2
#define MOTOR1_PIN2 PIN3
#define MOTOR1_ENABLE PIN4


/*down MOTOR*/
#define MOTOR2_PORT   PORT_D
#define MOTOR2_PIN1   PIN6
#define MOTOR2_PIN2   PIN7
#define MOTOR2_ENABLE PIN5


/*MOTOR GENERATE PWM*/
#define MOTOR_PORT   PORT_D
#define MOTOR_PIN1   PIN5
#define MOTOR_PIN2   PIN6
#define MOTOR_ENABLE PIN7

#define LEFT_MOTOR_ON             1
#define LEFT_MOTOR_OFF            0
#define RIGHT_MOTOR_ON            1
#define RIGHT_MOTOR_OFF           0


#endif /* MOTOR_CONFIG_H_ */
