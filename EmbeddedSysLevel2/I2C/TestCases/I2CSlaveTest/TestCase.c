/**
 * @file TestCase.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../I2C/I2C/lib/DataTypes.h"
#include "../../I2C/I2C/lib/BIT_Math.h"
#include "../../I2C/I2C/MCAL/I2C/I2C_private.h"
#include "../../I2C/I2C/MCAL/I2C/I2C_config.h"
#include "assert.h"
#include "stdio.h"

uint8_t TWAR;
uint8_t TWCR;
uint8_t TWSR;
uint8_t TWBR;
uint8_t TWDR;

/* TWCR REG */
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0

/* TWDR */
#define TWD7 7
#define TWD6 6
#define TWD5 5
#define TWD4 4
#define TWD3 3
#define TWD2 2
#define TWD1 1
#define TWD0 0

void I2C_voidInitMaster(void)
{
   /* Fcpu 8MHz */
   /* SCL=Fcpu/(16+(2xTWBRx4^TWPS)) = 100 KHz */
   TWBR = 32;

   TWSR &= 0xFC;
   TWSR |= Prescaler;
   /* Enable TWI */
   SETBIT(TWCR, TWEN);
}

void I2C_voidInitSlave(uint8_t SlaveAddress)
{
   /* Fcpu 8MHz */
   /* SCL=Fcpu/(16+(2xTWBRx4^TWPS)) = 100 KHz */
   TWBR = 32;

   TWSR &= 0xFC;
   TWSR |= Prescaler;
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);
   /* Enable TWI */
   SETBIT(TWCR, TWEN);
   /* Enable ACK */
   SETBIT(TWCR, TWEA);

   //set slave address &&disable globale calling
   TWAR = (SlaveAddress & 0xFE);
}

EN_ERRORSTATE_t I2C_voidMasterStart(void)
{
   /* Start Condition */
   /* Becmome a master */
   SETBIT(TWCR, TWSTA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   return E_OK;
}

EN_ERRORSTATE_t I2C_void_M_AddressSLV_Write(uint8_t SlaveAddress)
{
   TWDR = (SlaveAddress & 0xFE);

   /* CLR start bit */
   CLRBIT(TWCR, TWSTA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   return E_OK;
}

EN_ERRORSTATE_t I2C_void_M_AddressSLV_Read(uint8_t SlaveAddress)
{
   TWDR = (SlaveAddress & 0xFE);
   /* Read */
   SETBIT(TWDR, TWD0);
   /* CLR Start Bit */
   CLRBIT(TWCR, TWSTA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   return E_OK;
}

void I2C_voidMasterStop(void)
{
   /* Enable Stop Condition */
   SETBIT(TWCR, TWSTO);
   /* Enable TWI */
   SETBIT(TWCR, TWEN);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);
}

uint8_t I2C_u8ReceiveACK(void)
{
   /* Enable ACK */
   SETBIT(TWCR, TWEA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   return TWDR;
}

uint8_t I2C_u8ReceiveNoACK(void)
{
   /* Disable ACK */
   CLRBIT(TWCR, TWEA);
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);

   return TWDR;
}

void I2C_voidSendData(uint8_t Data)
{
   TWDR = Data;
   /* CLR TWI Flag*/
   SETBIT(TWCR, TWINT);
}

void TEST_voidI2CIInitMaster(void)
{
   I2C_voidInitMaster();
   assert(TWCR == 0x04);
   assert(TWBR == 0x20);
   assert(TWSR == 0x0);
}

void TEST_voidI2CInitSlave(void)
{
   I2C_voidInitSlave(110);
   assert(TWBR == 0x20);
   assert(TWSR == 0x0);
   assert(TWCR == 0xC4);
}

void TEST_voidI2CStartCondition(void)
{
   I2C_voidMasterStart();
   assert(TWCR == 0xE4);
}

void TEST_voidI2CStopCondition(void)
{
   I2C_voidMasterStop();
   assert(TWCR == 0xF4);
}

void TEST_voidI2CSend(void)
{
   I2C_voidSendData('A');
}

void TEST_voidI2CReceiveACK(void)
{
   assert(I2C_u8ReceiveACK() == 'A');
}

int main()
{
   TEST_voidI2CInitSlave();
   TEST_voidI2CStartCondition();
   TEST_voidI2CStopCondition();
   TEST_voidI2CSend();
   TEST_voidI2CReceiveACK();

   printf("All TestCases is Passed");
}