/**
 * @file Interrupts_cfg.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

/* TIMER1_ICU_vect */
void __vector_6(void) __attribute__((signal));
/* TIMER1_OCA_vect */
void __vector_7(void) __attribute__((signal));
/* TIMER1_OCB_vect */
void __vector_8(void) __attribute__((signal));
/* TIMER1_OVF_vect */
void __vector_9(void) __attribute__((signal));

/* TIMER0_CTC_vect */
void __vector_10(void) __attribute__((signal));

/* TIMER0_OVF_vect */
void __vector_11(void) __attribute__((signal));






#endif	/* EXTI_PRIVATE_H_ */
