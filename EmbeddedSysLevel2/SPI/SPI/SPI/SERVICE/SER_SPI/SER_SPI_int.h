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

#include "../MCAL/SPI/SPI_int.h"

/**
 * @brief SendString
 * 
 * @param PStr 
 */
void SER_SPIvoidSendString(uint8_t *PStr);


/**
 * @brief Receive String
 * 
 * @param Str 
 */
void SER_SPIvoidReceiveString(uint8_t *Str);



#endif  /* SER_SPI_INT_H_ */