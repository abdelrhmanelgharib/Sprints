/**
 * @file APP._int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef APP_INT_H_
#define APP_INT_H_

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "UART_int.h"
#include "I2C_int.h"
#include "SER_UART_int.h"
#include "EEPROM_int.h"

#define STRING_EQUL 0

/**
 * @brief This Function Initialize All Peripheral need in the app
 * @param void 
 * @return void
 **/
void APP_voidInit(void);


/**
 * @brief Compare two string
 * 
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1 
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2);


/**
 * @brief 
 * 
 * @param Str 
 * @return uint32_t 
 */
uint32_t String_u8ToNumb(uint8_t *Str);

uint8_t Binary_u8ToNumb(uint32_t u32_Binary);


void APP_voidWrite(void);
void APP_voidRead(void);

#endif  /* APP_INT_H_ */