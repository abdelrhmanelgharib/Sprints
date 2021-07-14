/*
 * SPI_int.h
 *
 * Created: 7/14/2021 2:54:43 PM
 *  Author: 2bdoa
 */ 



#ifndef SER_SPI_INT_H_
#define SER_SPI_INT_H_

#include "../lib/DataTypes.h"
#include "../lib/BIT_Math.h"
#include "../lib/Memmap.h"

#include "SPI_int.h"


void SER_SPIvoidSendString(uint8_t *PStr);

void SER_SPIvoidReceiveString(uint8_t *Str);
uint8_t *SPI_u8SendReceiveString(uint8_t *Data);
#endif  /* SER_SPI_INT_H_ */