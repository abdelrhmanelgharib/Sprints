/**
 * @file I2c_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-15
 * 
 */


#ifndef I2C_INT_H_
#define I2C_INT_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "Memmap.h"
#include "I2C_private.h"
#include "I2C_config.h"



/**
 * @brief Initialize Master
 *        
 */
void I2C_voidInitMaster(void);



/**
 * @brief Initialize slave address
 * 
 * @param SlaveAddress device address
 */
void I2C_voidInitSlave(uint8_t SlaveAddress);



/**
 * @brief send start Condition  
 * 
 * @return EN_ErrorI2c_t error status
 */
EN_ErrorI2c_t I2C_voidMasterStart(void);

/**
 * @brief master send address of the slave to Write
 * 
 * @param SlaveAddress address of device to Write data 
 * @return EN_ErrorI2c_t error status
 */
EN_ErrorI2c_t I2C_void_M_AddressSLV_Write(uint8_t SlaveAddress);



/**
 * @brief master send address of the slave to Read
 * 
 * @param SlaveAddress address of device to Read data
 * @return EN_ErrorI2c_t 
 */
EN_ErrorI2c_t I2C_void_M_AddressSLV_Read(uint8_t SlaveAddress);




/**
 * @brief send Stop Condition
 * 
 */
void I2C_voidMasterStop(void);


/**
 * @brief Receive data and enable ACK
 * 
 * @return uint8_t Data
 */
uint8_t I2C_u8ReceiveACK(void);



/**
 * @brief Send Data
 * 
 * @param Data 
 */
void I2C_voidSendData(uint8_t Data);




/**
 * @brief Receive data and Disable ACK
 * 
 * @return uint8_t data
 */
uint8_t I2C_u8ReceiveNoACK(void);




/**
 * @brief 
 * 
 * @param status 
 * @return EN_ErrorI2c_t 
 */
EN_ErrorI2c_t CheckStatus(uint8_t status);



#endif  /* I2C_INT_H_ */