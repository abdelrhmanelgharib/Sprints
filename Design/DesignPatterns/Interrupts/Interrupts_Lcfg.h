/**
 * @file Interrupts_Lcfg.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INTERRUPTS_LCFG_H_
#define INTERRUPTS_LCFG_H_


#define INT0_VECTOR_NUMBER      (uint8_t)(0)
#define INT1_VECTOR_NUMBER      (uint8_t)(1)
#define INT2_VECTOR_NUMBER      (uint8_t)(2)
#define TIMER0_VECTOR_NUMBER	(uint8_t)(3)


#define VECTOR_SIZE          ((TIMER0_VECTOR_NUMBER - INT0_VECTOR_NUMBER) + 1)

#endif  /* INTERRUPTS_LCFG_H_ */
