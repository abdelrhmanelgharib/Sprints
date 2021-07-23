/**
 * @file TestCases.c
 * @author your name (you@domain.com)
 * @brief Test UART
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "UART_int.h"

/**
 * @brief Test Send data
 * 
 */
void TestSendChar(void)
{
    UART_ENSendData('t');
}


/**
 * @brief Test Send No Block
 * 
 */
void TestSendNoBlock(void);
{
    UART_ENSendNoBlock('e');
}


/**
 * @brief Test Receive data
 * 
 * @return uint8_t 
 */
uint8_t TestReceiveChar(void)
{
    return UART_u8ReceiveData();
}

