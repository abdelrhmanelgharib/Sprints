/**
 * @file UART.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-13
 * 
 */

#include "UART_int.h"

/**
 * @brief Initialized UART 
 * 
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENInit(void)
{
    EN_ERRORSTATE_t state;
    state = E_OK;

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
    SETBIT(UCSRB, RXEN);
} /* UART_ENInit */

/**
 * @brief Send One Character
 * 
 * @param Data char want to send
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENSendData(uint8_t Data)
{
    /* Wait to Data Register Empty */
    while (!GETBIT(UCSRA, UDRE))
        ;

    UDR = Data;
}

/**
 * @brief Send Without Polling On Data Register Flag 
 * 
 * @param Data char want to send
 * @return EN_ERRORSTATE_t E_OK | E_ERROR
 */
EN_ERRORSTATE_t UART_ENSendNoBlock(uint8_t Data)
{
    UDR = Data;
}

/**
 * @brief Receive Data From another device
 * 
 * @return uint8_t Data From Register
 */
uint8_t UART_u8ReceiveData(void)
{
    while(!GETBIT(UCSRA, RXC));
    return UDR;
}

/**
 * @brief Receive Data without Polling
 * 
 * @param Data 
 * @return uint8_t Data From Register
 */
uint8_t UART_u8ReceiveNoBlock(uint8_t *Data)
{
    uint8_t Status = 0;
    if(GETBIT(UCSRA, RXC))
    {
        *Data = UDR;
        Status = 1;
    }
    else
    {
        /* do nothing */
    }
    return Status;
}