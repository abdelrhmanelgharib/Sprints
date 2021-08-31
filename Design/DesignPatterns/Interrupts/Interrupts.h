/**
 * @file Interrupts.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_







void Install(void (*LocalPtr)(void), uint8_t InterruptType);
void DeInstall(void (*LocalPtr)(void), uint8_t InterruptType);
void Interrupt_ENEnable(void);
void Interrupt_ENDisable(void);









#endif
