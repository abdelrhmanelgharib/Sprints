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

EN_ERRORSTATE_t handshake_data(void);
uint8_t Check_HandShake(void);
void HandShake_Handler(void);
EN_ERRORSTATE_t device_data(void);

#define BD_ADRESS		0b00001000
#define MAC_ADRESS      0xdf
#define DD_ADRESS		0b00001111
#define HEADER          0xAA
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS
//#define BD_ADRESS

#endif /* APP_APP_H_ */
