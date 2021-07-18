/**
 * @file EEPROM.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "DataTypes.h"
#include "I2C_int.h"


/**
 * @brief Init EEPROM
 * @param void
 * @return void
 */
void EEPROM_voidInit(void)
{
    I2C_voidInitMaster();
}


/**
 * @brief Write Data on EEPROM 
 * 
 * @param Data Data Write
 * @param Address Write Data on Specific Address
 */
void EEPROM_voidWriteByte(uint8_t Data, uint8_t Address)
{
    I2C_voidMasterStart();
    I2C_void_M_AddressSLV_Write(0b10100000);
    I2C_voidSendData(Address);
    I2C_voidSendData(Data);
    I2C_voidMasterStop();
}




/**
 * @brief Read Data On EEPROM
 * 
 * @param Address Read Data On Specific Address
 * @return uint8_t Data Read
 */
uint8_t EEPROM_voidReadByte(uint8_t Address)
{
    I2C_voidMasterStart();
    I2C_void_M_AddressSLV_Write(0b10100000);
    I2C_voidSendData(Address);//00000101
    I2C_voidMasterStart();
    I2C_void_M_AddressSLV_Read(0b10100000);
    uint8_t data = I2C_u8ReceiveNoACK();
    I2C_voidMasterStop();
    return data;
    
}


