/**
 * @file PWM.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2021-08-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PWM_H_
#define PWM_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "Memmap.h"
#include "PWM_cfg.h"


/**
 * @brief Initailze Phase Correct PWM
 * 
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t PWM_ENInitPhaseCorrect(void);


/**
 * @brief DutyCycle
 * 
 * @param DutyCycle Speed
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t PWM_ENDutyCycle(uint8_t DutyCycle);


#endif /* PWM_H_ */
