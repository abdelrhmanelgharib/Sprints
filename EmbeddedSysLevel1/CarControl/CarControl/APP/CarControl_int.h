/**
 * @file CarControl_int.h
 * @author Vicious
 * @brief 
 * @version 0.1
 * @date 2021-07-11
 * 
 */


#ifndef MAIN_H_
#define MAIN_H_


#define  MOTOR_FORWARD	0
#define  MOTOR_BACKWARD	1

#define  FORWARD_30	1
#define  FORWARD_60	2
#define  FORWARD_90	3

#define  BACKWARD_30	4

void Car_init(void);
void Car_Control(void);


#endif /* MAIN_H_ */