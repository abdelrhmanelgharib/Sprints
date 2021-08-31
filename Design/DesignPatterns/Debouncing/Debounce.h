/**
 * @file Debounce.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEBOUNCE_DEBOUNCE_H_
#define DEBOUNCE_DEBOUNCE_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "Interrupts_cfg.h"
#include "Interrupts_Lcfg.h"
#include "Interrupts.h"
#include "Timer.h"


#define READY		(uint8_t)(0)
#define WAIT		(uint8_t)(1)
#define RUNNING		(uint8_t)(2)

void App(void);

void Event_Receive(void);
void Delay(uint32_t Delay_us);

void Event_Receive(void);
void Device_EventReceive(uint8_t Hamda);

#endif /* DEBOUNCE_DEBOUNCE_H_ */
