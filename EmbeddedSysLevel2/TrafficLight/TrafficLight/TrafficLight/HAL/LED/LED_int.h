/**
 * @file LED_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */


#ifndef LED_INT_H_
#define LED_INT_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"

#include "LED_priv.h"
#include "LED_config.h"

/**
 * @brief initialized Led Direction and connection Type
 * 
 */
void LED_voidInitialize(void);

/**
 * @brief Turn on Led
 * 
 * @param led_num Led Numb
 */
void LED_voidLedOn(uint8_t led_num);


/**
 * @brief Turn Off Led
 * 
 * @param led_num Led Numb
 */
void LED_voidLedOff(uint8_t led_num);


/**
 * @brief Toggle Led
 * 
 * @param led_num Len Numb
 */
void LED_voidLedToggle(uint8_t led_num);



#define LED0  0
#define LED1  1
#define LED2  2



#endif  /* LED_INT_H_ */