/**
 * @file TWI.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-16
 * 
 */

#include "TWI_int.h"

/**
 * @brief This Function to Enable TWI
 *        and Clear TWI Flag
 * @param void
 * @return void
 */
void TWI_voidEnable(void)
{
   /* CLR TWI Flag, Enable Twi */
   TWCR = (1 << TWINT) | (1 << TWEN);
}

/**
 * @brief initialize TWI
 * @param void
 * @return void
 */
void TWI_voidInit(void)
{
   /* Fcpu 8MHz */
   /* SCL=Fcpu/(16+(2xTWBRx4^TWPS)) = 100 KHz */
   TWBR = 32;
   TWSR &= 0xFC;
   TWSR |= Prescaler;

   TWI_voidEnable();

   /* Enable ACK */
   TWCR |= (1 << TWEA);
}

/**
 * @brief start Condition For Master MCU
 * 
 * @return EN_ErrorTWI_t Error status
 */
EN_ErrorTWI_t TWI_voidStartBit();
