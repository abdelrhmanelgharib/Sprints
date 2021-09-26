/**
 * @file Bluetooth.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "DataTypes.h"
#include "DIO.h"
#include "UART.h"
#include "SER_UART_int.h"


EN_ERRORSTATE_t Bluetooth_Init(void);

EN_ERRORSTATE_t Bluetooth_InitMaster(void);

#endif  /* BLUETOOTH_H_ */
