/**
 * @file UART_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-13
 * 
 */


#ifndef UART_INT_H_
#define UART_INT_H_

#include "../../lib/DataTypes.h"
#include "../../lib/BIT_Math.h"
#include "UART_config.h"
#include "UART_private.h"

#include "../../lib/Memmap.h"


typedef enum
{
    E_ERROR,
    E_OK
}EN_ERRORSTATE_t;


/**
 * @brief Initialized UART 
 * 
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENInit(void);


/**
 * @brief Send One Character
 * 
 * @param Data char want to send
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENSendData(uint8_t Data);


/**
 * @brief Send Without Polling On Data Register Flag 
 * 
 * @param Data char want to send
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENSendNoBlock(uint8_t Data);


/**
 * @brief Receive Data From another device
 * 
 * @return uint8_t Data From Register
 */
uint8_t UART_u8ReceiveData(void);


/**
 * @brief Receive Data without Polling
 * 
 * @param Data 
 * @return uint8_t Data From Register
 */
uint8_t UART_u8ReceiveNoBlock(uint8_t *Data);



#endif  /* UART_INT_H_ */