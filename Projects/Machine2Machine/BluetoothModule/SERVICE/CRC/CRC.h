/*
 * CRC.h
 *
 *  Created on: Sep 11, 2021
 *      Author: 2bdoa
 */

#ifndef SERVICE_CRC_CRC_H_
#define SERVICE_CRC_CRC_H_


#define INITIAL_CRC_CC3         0x1D0F
#define CRC_CCITT_POLY			0x1021 	//CRC-CCITT, polynormial 0x1021.

uint16_t CRC16(uint8_t *ptr, uint16_t count, uint16_t initCRC);


#endif /* SERVICE_CRC_CRC_H_ */
