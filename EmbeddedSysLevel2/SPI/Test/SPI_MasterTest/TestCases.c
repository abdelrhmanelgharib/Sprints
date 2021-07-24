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

#include "../../SPI/SPI/lib/DataTypes.h"
#include "../../SPI/SPI/lib/BIT_Math.h"
#include "assert.h"
#include "stdio.h"

#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF 7
#define WCOL 6
#define SPI2X 0

uint8_t SPDR;
uint8_t SPSR;
uint8_t SPCR;

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

EN_ERRORSTATE_t SPI_ENSlaveInit(void)
{
    /* Slave Select */
    CLRBIT(SPCR, MSTR);

    /* SPI Enable */
    SETBIT(SPCR, SPE);
    return E_OK;
}

EN_ERRORSTATE_t SPI_voidSendData(uint8_t data)
{
    SPDR = data;
    return E_OK;
}

uint8_t SPI_u8ReceiveData(void)
{
    return SPDR;
}


void TEST_voidSPIMasterInit(void)
{
    assert(SPI_ENMasterInit() == E_OK);
    assert(SPCR == 0x50);
    assert(SPSR == 0x01);
}


void TEST_voidSPISlaveInit(void)
{
    assert(SPI_ENSlaveInit() == E_OK);
    assert(SPCR == 0x40);
}

void TEST_voidSPISendData(void)
{
    assert(SPI_voidSendData('A') == E_OK);
}

void TEST_voidSPIReceiveData(void)
{
    assert(SPI_u8ReceiveData() == 'A');
}



int main()
{
    TEST_voidSPIMasterInit();
    TEST_voidSPISendData();
    TEST_voidSPIReceiveData();
    printf("All TestCases is Passed");
}