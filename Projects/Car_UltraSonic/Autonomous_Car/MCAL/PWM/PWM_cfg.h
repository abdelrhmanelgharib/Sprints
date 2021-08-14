/**
 * @file PWM_cfg.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2021-08-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PWM_CFG_H_
#define PWM_CFG_H_

#define OCRA_NON_INVERTING_MODE     1
#define OCRA_INVERTING_MODE         2

#define OCRB_NON_INVERTING_MODE     3
#define OCRB_INVERTING_MODE         4

#define PWM_STOP                    0
#define PWM_SCALER_1                1
#define PWM_SCALER_8                2
#define PWM_SCALER_64               3
#define PWM_SCALER_256              4
#define PWM_SCALER_1024             5


/*
 *   choose OCRA, OCRB form
 *   OCRA_NON_INVERTING_MODE - OCRA_INVERTING_MODE - OCRB_NON_INVERTING_MODE - OCRB_INVERTING_MODE 
 */
#define OCRA_MODE     OCRA_NON_INVERTING_MODE  
#define OCRB_MODE     OCRB_NON_INVERTING_MODE

/*
 *   choose prescaler form
 *   PWM_STOP - PWM_SCALER_1 - PWM_SCALER_8 - PWM_SCALER_64 - PWM_SCALER_256
 *   PWM_SCALER_1024
 */
#define PWM_SCALER    PWM_SCALER_8


/* Change ICR TOP CAPACITY */
#define TIMER1_ICR_TOP_CAPACITY     12500


#endif /* PWM_CFG_H_ */
