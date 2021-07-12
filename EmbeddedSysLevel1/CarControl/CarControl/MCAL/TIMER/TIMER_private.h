/**
 * @file TIMER_private.h
 * @author Vicious
 * @brief 
 * @version 0.1
 * @date 2021-07-11
 * 
 */
#ifndef TIMER_PRIVAT_H_
#define TIMER_PRIVAT_H_

#define  TIMER0_REG_CAPACITY		256

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



#endif	/* TIMER_PRIVAT_H_ */