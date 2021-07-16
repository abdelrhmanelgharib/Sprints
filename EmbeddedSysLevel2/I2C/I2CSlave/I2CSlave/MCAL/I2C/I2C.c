/**
 * @file I2C.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-15
 * 
 */

#include "I2C_int.h"
#include "Memmap.h"

/**
 * @brief Initialize Master
 * 
 */
void I2C_voidInitMaster(void)
{
   /* Fcpu 8MHz */
   /* SCL=Fcpu/(16+(2xTWBRx4^TWPS)) = 100 KHz */
   TWBR = 32;

   TWSR &= 0xFC;
   TWSR |= Prescaler;
   /* Enable TWI */
   SETBIT(TWCR, TWEN);
   /* Enable ACK */
   SETBIT(TWCR, TWEA);
}

void I2C_voidInitSlave(void)
{
   /* Fcpu 8MHz */
   /* SCL=Fcpu/(16+(2xTWBRx4^TWPS)) = 100 KHz */
   TWBR = 32;

   TWSR &= 0xFC;
   TWSR |= Prescaler;

   //set slave address &&diable globale calling
   TWAR = 2;

   /* Enable TWI */
   SETBIT(TWCR, TWEN);
}



/**
 * @brief Send Start condition 
 * Enable TWI And TWEN 
 *    
 */
EN_ErrorI2c_t I2C_voidMasterStart(uint8_t SlaveAddress)
{
   /* Start Condition */
   /* Becmome a master */
   SETBIT(TWCR, TWSTA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   /* wait to CLR TWI Flag */
   while (!(GETBIT(TWCR, TWINT)))
      ;
   if (CheckStatus(0x08) == E_ERROR)
   {
      return E_ERROR;
   }
   TWDR = ((SlaveAddress - 1) << 1);

   CLRBIT(TWDR, 0);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);
   /* CLR Start Condition */
   CLRBIT(TWCR, TWSTA);

   while (!(GETBIT(TWCR, TWINT)))
      ;
   if (CheckStatus(0x18) == E_ERROR)
   {
      return E_ERROR;
   }

   return E_OK;
}

void I2C_voidMasterStop(void)
{
   /* Enable Stop Condition */
   SETBIT(TWCR, TWSTO);
   SETBIT(TWCR, TWINT);

   while (!(GETBIT(TWCR, TWINT)))
      ;
}

uint8_t I2C_u8ReceiveACK(void)
{
   /* Enable ACK */
   SETBIT(TWCR, TWEA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   while (!(GETBIT(TWCR, TWINT)))
      ;
   return TWDR;
}

void I2C_voidSendData(uint8_t Data)
{
   TWDR = Data;
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   while (!(GETBIT(TWCR, TWINT)))
      ;
}

uint8_t I2C_u8ReceiveNoACK(void)
{
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   while (!(GETBIT(TWCR, TWINT)))
      ;
   return TWDR;
}



EN_ErrorI2c_t CheckStatus(uint8_t status)
{
   if (status != (TWSR & 0XF8))
   {
      return E_ERROR;
   }
   else
   {
      return E_OK;
   }
}