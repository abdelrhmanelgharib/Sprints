/**
 * @file SPI_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

#include "../../lib/DataTypes.h"
#include "../../lib/BIT_Math.h"
#include "../../lib/Memmap.h"
#include "SPI_private.h"
#include "SPI_config.h"



typedef enum
{
    E_ERROR ,
    E_OK
}EN_ERRORSTATE_t;

#define GARBAGE 0


/**
 * @brief initialized  Master
 * 
 * @return EN_ERRORSTATE_t E_ERROR | E_OK
 */
EN_ERRORSTATE_t SPI_ENMasterInit(void);


/**
 * @brief initialized Slave
 * 
 * @return EN_ERRORSTATE_t E_ERROR | E_OK
 */
EN_ERRORSTATE_t SPI_ENSlaveInit(void);



/**
 * @brief Send char and Receive char at the same time
 * 
 * @param Data Send char
 * @return uint8_t Receive char
 */
uint8_t SPI_u8SendReceive(uint8_t Data);

/**
 * @brief Send Data wihout Check Buffer is Empty
 * 
 * @param Data Data send
 */
void SPI_ENSendNoBlock(uint8_t Data);



/**
 * @brief Receive Data Without Check Buffer is Empty
 * 
 * @return uint8_t Data Received
 */
uint8_t SPI_u8ReceiveNoBlock(void);



/**
 * @brief Receive Data without Polling and When Buffer is Empty
 * 
 * @param Pdata Store Received data 
 * @return uint8_t is data Received 
 */
uint8_t SPI_u8ReceivePerodic(uint8_t *Pdata);

/**
 * @brief Send Data
 * 
 * @param data 
 */
void SPI_voidSendData(uint8_t data);


/**
 * @brief Receive Data
 * 
 * @return uint8_t 
 */
uint8_t SPI_u8ReceiveData(void);










#endif  /* SPI_INT_H_ */