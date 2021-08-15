/**
 * @file TestCases.c
 * @author your name (you@domain.com)
 * @brief Test UART
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../UART/UART/lib/DataTypes.h"
#include "../../UART/UART/lib/BIT_Math.h"
#include "../../UART/UART/MCAL/UART/UART_private.h"
#include "../../UART/UART/MCAL/UART/UART_config.h"
#include "assert.h"
#include "stdio.h"



#define RXC        7
#define TXC        6
#define UDRE       5
#define FE         4
#define DOR        3
#define PE         2
#define U2X        1
#define MPCM       0


/* UCSRB REGISTER*/
#define RXCIE      7
#define TXCIE      6
#define UDRIE      5
#define RXEN       4
#define TXEN       3
#define UCSZ2      2
#define RXB8       1
#define TXB8       0		


#define URSEL      7
#define UMSEL      6
#define UPM1       5
#define UPM0       4
#define USBS       3
#define UCSZ1      2
#define UCSZ0      1
#define UCPOL      0


uint8_t UDR;
uint8_t UCSRA;
uint8_t UCSRB;
uint8_t UBRRL;
uint8_t UBRRH;
uint8_t UCSRC;


EN_ERRORSTATE_t UART_ENInit(void)
{
    EN_ERRORSTATE_t Enstate;
    Enstate = E_OK;
    /* Clear  URSEL to update UBRRH*/
    CLRBIT(UCSRC, URSEL);
    /* Boud Rate */
    UBRRH = HIGHUBRR;
    UBRRL = LOWUBRR;

/* UART Double Speed */
#if UART_SPEED == DOUBLE
    SETBIT(UCSRA, U2X);

/* UART NORMAL Speed */
#elif UART_SPEED == NORMAL
    CLRBIT(UCSRA, U2X);
#endif

/* Select STOP Bit */
#if STOPBIT == _1BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    CLRBIT(UCSRC, USBS);

#elif STOPBIT == _2BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    SETBIT(UCSRC, USBS);
#endif

/* Disable Parity */
#if UART_PARITY == DISABLED

    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);

    CLRBIT(UCSRC, UPM0);
    CLRBIT(UCSRC, UPM1);
    /* Parity is Odd */

#elif UART_PARITY == ODD
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    SETBIT(UCSRC, UPM0);
    SETBIT(UCSRC, UPM1);

/* Parity is Even */
#elif UART_PARITY == EVEN
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    CLRBIT(UCSRC, UPM0);
    SETBIT(UCSRC, UPM1);

#endif

/* Data Fram */
#if DATAFRAM == _5BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    CLRBIT(UCSRC, UCSZ0);
    CLRBIT(UCSRC, UCSZ1);
    CLRBIT(UCSRB, UCSZ2);
#elif DATAFRAM == _6BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    SETBIT(UCSRC, UCSZ0);
    CLRBIT(UCSRC, UCSZ1);
    CLRBIT(UCSRB, UCSZ2);
#elif DATAFRAM == _7BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    CLRBIT(UCSRC, UCSZ0);
    SETBIT(UCSRC, UCSZ1);
    CLRBIT(UCSRB, UCSZ2);
#elif DATAFRAM == _8BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    SETBIT(UCSRC, UCSZ0);
    SETBIT(UCSRC, UCSZ1);
    CLRBIT(UCSRB, UCSZ2);
#elif DATAFRAM == _9BIT
    /* Set URSEL to update UCSRC*/
    SETBIT(UCSRC, URSEL);
    SETBIT(UCSRC, UCSZ0);
    SETBIT(UCSRC, UCSZ1);
    SETBIT(UCSRB, UCSZ2);
#else
    Enstate = E_ERROR;
#endif

    /**
     * @brief Receiver Enable
     * 
     */
    SETBIT(UCSRB, RXEN);
    /**
     * @brief Transmitter Enable
     * 
     */
    SETBIT(UCSRB, TXEN);

    return Enstate;
} /* UART_ENInit */



EN_ERRORSTATE_t UART_ENSendData(uint8_t Data)
{
    UDR = Data;
    return E_OK;
}


uint8_t UART_u8ReceiveData(void)
{
    uint8_t data;
    data = UDR;
    return data;
}



void UART_InitTest(void)
{
    assert(UART_ENInit() == E_OK);
    assert(UBRRL == 51);
    assert(UCSRC == 0x86);
    assert(UCSRB == 0x18);   
}



void UART_SendDataTest(void)
{
    assert(UART_ENSendData('A') == E_OK);
}


void UART_ReceiveTest(void)
{
    assert(UART_u8ReceiveData() == 'A');
}




int main()
{
    UART_InitTest();
    UART_SendDataTest();
    UART_ReceiveTest();
    printf("All TestCase is Passed");
}