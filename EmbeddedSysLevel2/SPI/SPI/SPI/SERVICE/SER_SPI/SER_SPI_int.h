/**
 * @file SER_SPI_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-15
 * 
 */



#ifndef SER_SPI_INT_H_
#define SER_SPI_INT_H_

#include "../lib/DataTypes.h"
#include "../lib/BIT_Math.h"
#include "../lib/Memmap.h"
#include "DIO_Interface.h"
#include "../MCAL/SPI/SPI_int.h"


/**
 * @brief Initialize Pin for Master
 * 
 */
void SER_SPIvoidInitPinMaster(void);



/**
 * @brief Initialize Pin for Slave
 * 
 */
void SER_SPIvoidInitPinSlave(void);



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