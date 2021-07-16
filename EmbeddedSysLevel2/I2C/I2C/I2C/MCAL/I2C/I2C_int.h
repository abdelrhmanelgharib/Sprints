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

#include "I2C_private.h"
#include "I2C_config.h"


typedef enum
{
    E_ERROR,
    E_OK
}EN_ErrorI2c_t;

/**
 * @brief Initialize Master
 * 
 */
void I2C_voidInitMaster(void);
void I2C_voidInitSlave(void);
EN_ErrorI2c_t I2C_voidMasterStart(void);
void I2C_voidMasterStop(void);
EN_ErrorI2c_t I2C_voidSLA(uint8_t SlaveAddress);

uint8_t I2C_u8ReceiveACK(void);
void I2C_voidSendData(uint8_t Data);

uint8_t I2C_u8ReceiveNoACK(void);

EN_ErrorI2c_t CheckStatus(uint8_t status);



#endif  /* I2C_INT_H_ */