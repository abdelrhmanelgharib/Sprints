/**
 * @file SPI.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#include "SPI_int.h"

/**
 * @brief initialized  Master
 * 
 * @return EN_ERRORSTATE_t E_ERROR | E_OK
 */
EN_ERRORSTATE_t SPI_ENMasterInit(void)
{
    EN_ERRORSTATE_t En_state;
    En_state = E_OK;

    /* Master Select */
    SETBIT(SPCR, MSTR);

/* Clock Polarity */
#if CLK_IDLE == CLK_LOW
    CLRBIT(SPCR, CPOL);
#elif CLK_IDLE == CLK_HIGH
    SETBIT(SPCR, CPOL);
#endif

/* CLK PHASE */
#if CLK_PHASE == LEADING
    CLRBIT(SPCR, CPHA);
#elif CLK_PHASE == TRAILING
    SETBIT(SPCR, CPHA);
#endif

#if SPI_SPEED == F_CPU_2
    SETBIT(SPSR, SPI2X);
    CLRBIT(SPCR, SPR0);
    CLRBIT(SPCR, SPR1);
#elif SPI_SPEED == F_CPU_4
    CLRBIT(SPSR, SPI2X);
    CLRBIT(SPCR, SPR0);
    CLRBIT(SPCR, SPR1);
#elif SPI_SPEED == F_CPU_8
    SETBIT(SPSR, SPI2X);
    SETBIT(SPCR, SPR0);
    CLRBIT(SPCR, SPR1);
#elif SPI_SPEED == F_CPU_16
    CLRBIT(SPSR, SPI2X);
    SETBIT(SPCR, SPR0);
    CLRBIT(SPCR, SPR1);
#elif SPI_SPEED == F_CPU_32
    SETBIT(SPSR, SPI2X);
    CLRBIT(SPCR, SPR0);
    SETBIT(SPCR, SPR1);
#elif SPI_SPEED == F_CPU_64
    SETBIT(SPSR, SPI2X);
    SETBIT(SPCR, SPR0);
    SETBIT(SPCR, SPR1);

#elif SPI_SPEED == F_CPU_128
    CLRBIT(SPSR, SPI2X);
    SETBIT(SPCR, SPR0);
    SETBIT(SPCR, SPR1);
#endif

    /* SPI Enable */
    SETBIT(SPCR, SPE);

    return En_state;
}

/**
 * @brief initialized Slave
 * 
 * @return EN_ERRORSTATE_t E_ERROR | E_OK
 */
EN_ERRORSTATE_t SPI_ENSlaveInit(void)
{
    /* Slave Select */
   CLRBIT(SPCR, MSTR);

    /* SPI Enable */
    SETBIT(SPCR, SPE);
}

/**
 * @brief Send char and Receive char at the same time
 * 
 * @param Data Send char
 * @return uint8_t Receive char
 */
uint8_t SPI_u8SendReceive(uint8_t Data)
{
    SPDR = Data;
    while (!GETBIT(SPSR, SPIF))
        ;

    /* Flag will clear when read it */
    return SPDR;
}

/**
 * @brief Send Data wihout Check Buffer is Empty
 * 
 * @param Data Data send
 */
void SPI_ENSendNoBlock(uint8_t Data)
{
    SPDR = Data;
}

/**
 * @brief Receive Data Without Check Buffer is Empty
 * 
 * @return uint8_t Data Received
 */
uint8_t SPI_u8ReceiveNoBlock(void)
{
    return SPDR;
}

/**
 * @brief Receive Data without Polling and When Buffer is Empty
 * 
 * @param Pdata Store Received data 
 * @return uint8_t is data Received 
 */
uint8_t SPI_u8ReceivePerodic(uint8_t *Pdata)
{
    if (GETBIT(SPSR, SPIF))
    {
        *Pdata = SPDR;
        return 1;
    }
    else
    {
        return 0;
    }
}




void SPI_voidSendData(uint8_t data)
{
    SPDR = data;  
    while (!(GETBIT(SPSR, SPIF)));
     
}

uint8_t SPI_u8Receive(void)
{
    SPDR = GARBAGE;
    while (!(GETBIT(SPSR, SPIF)));  
    return SPDR;
}