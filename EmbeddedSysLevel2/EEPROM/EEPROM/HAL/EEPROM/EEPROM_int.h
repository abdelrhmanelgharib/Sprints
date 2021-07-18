/**
 * @file EEPROM_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_




/**
 * @brief Init EEPROM
 * @param void
 * @return void
 */
void EEPROM_voidInit(void);


/**
 * @brief Write Data on EEPROM 
 * 
 * @param Data Data Write
 * @param Address Write Data on Specific Address
 */
void EEPROM_voidWriteByte(uint8_t Data, uint8_t Address);


/**
 * @brief Read Data On EEPROM
 * 
 * @param Address Read Data On Specific Address
 * @return uint8_t Data Read
 */
uint8_t EEPROM_voidReadByte(uint8_t Address);

#endif  /* EEPROM_INT_H_ */