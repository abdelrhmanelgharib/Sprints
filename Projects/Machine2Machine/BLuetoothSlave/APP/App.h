/*
 * App.h
 *
 *  Created on: Sep 8, 2021
 *      Author: 2bdoa
 */

#ifndef APP_APP_H_
#define APP_APP_H_

EN_ERRORSTATE_t Check_BaudRate(void);
EN_ERRORSTATE_t Device_SearchPattern(void);


/**
 * @brief Compare two string
 *
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2);


#define BD_ADRESS		0b00001000
#define MAC_ADRESS      0xdf
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS

#endif /* APP_APP_H_ */
