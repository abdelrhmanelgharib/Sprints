/**
 * @file TestCases.c
 * @author Elgharib
 * @brief Test SPI
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "SPI_int.h"


/**
 * @brief Test Initialize Master
 * 
 */
void TestInit(void)
{
    EN_ERRORSTATE_t state;
    state = SPI_ENMasterInit();
}


/**
 * @brief Test Send Data
 * 
 */
void TestSendChar(void)
{
    SPI_voidSendData('x');
}

/**
 * @brief Test Receive Data
 * 
 * @return uint8_t Data Received
 */
uint8_t TestReceiveChar(void)
{
    uint8_t data = SPI_u8ReceiveData();
    return data;
}


/**
 * @brief Test Receive No Block
 * 
 * @return uint8_t Data Received
 */
uint8_t TestReceiveNoBlock(void)
{
    uint8_t data;
    data = SPI_u8ReceiveNoBlock();
    return data;
}