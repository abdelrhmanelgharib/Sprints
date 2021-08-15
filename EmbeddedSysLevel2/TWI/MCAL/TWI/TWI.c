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
EN_ErrorTWI_t TWI_voidStartBit(void)
{
   /* CLR TWI Flag, Enable TWI, Enable Start Condition */
   TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

   while ((!(TWCR & (1 << TWINT))) || (((TWSR & 0xF8) != START_CONDITION) && ((TWSR & 0xF8) != REPEATED_START)))
      ;
}

EN_ErrorTWI_t TWI_voidStopBit(void)
{
   /* CLR TWI Flag, Enable TWI, Enable STOP Condition */
   TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWI_voidSLVAddress(uint8_t Address)
{
   TWAR = (Address << 1);
}

/* write slave address to send data */
void TWI_voidSLV_Write(unsigned char SLV_W)
{
   /* CLR Bit zero to write  address*/
   CLRBIT(TWDR, TWD0);
   TWDR = ((SLV_W << 1) & 0xFE);

   /* CLr TWI Flag and En TWI */
   TWI_voidEnable();
   while ((!(TWCR & (1 << TWINT))) || ((TWSR & 0xF8) != SLV_W_TRANSMIT_ACK_RECEIVD))
      ;
}

void TWI_voidSLV_Read(uint8_t SLV_R)
{
   /* Enable Read in fram */
   SETBIT(TWDR, TWD0);

   /* shift data Right 1 */
   TWDR = (SLV_R << 1);

   TWI_voidEnable();
   /* Enable ACK */
   SETBIT(TWCR, TWEA);
}

void TWI_voidSendData(uint8_t Data)
{
   TWDR = Data;
   TWI_voidEnable();
   while ((!(TWCR & (1 << TWINT))) || ((TWSR & 0xF8) != DATA_M_TRANSMIT_ACK_RECEIVD && (TWSR & 0xF8) != DATA_S_TRANSMIT_ACK_SEND))
      ;
}

uint8_t TWI_u8ReceiveData(void)
{
   /* For slave */
   while ((!(TWCR & (1 << TWINT))) || ((TWSR & 0xF8) != STOP_OR_REPEATED_CONDITION && (TWSR & 0xF8) != DATA_S_RECEIVD_ACK_SEND && (TWSR & 0xF8) != SLA_W_RECEIVD_ACK_SEND))
      ;

   TWI_voidEnable();
   /* Enable ACK */
   SETBIT(TWCR, TWEA);

   return TWDR;
}
