/**
 * @file ProxyDIO.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "DataTypes.h"
#include "DIO.h"
#include "BIT_Math.h"
#include "Memmap.h"
#include "ProxyDIO.h"

EN_ERRORSTATE_t Proxy_DIOPinDirection(EN_Proxy_port_t port, EN_Proxypin_t Pin, EN_Proxydirection_t Direction)
{
    DIO_voidSetPinDirection(port, Pin, Direction);
}

/**
 * @brief This Function to change Pin value HIGH | LOW
 * 
 * @param port PORT Name
 * @param Pin PIN Number
 * @param Value  HIGH or LOW
 * @return EN_ERRORSTATE_t EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_ERRORSTATE_t Proxy_DIOPinValue(EN_Proxy_port_t port, EN_Proxypin_t Pin, EN_ProxyValue_t Value)
{
    DIO_voidSetPinValue(port, Pin, Value);
}
EN_ERRORSTATE_t Proxy_DIOPortDirection(EN_Proxy_port_t port, EN_Proxydirection_t Direction)
{
    DIO_voidSetPortDirection(port, Direction);
}
EN_ERRORSTATE_t Proxy_DIOPortValue(EN_Proxy_port_t port, EN_ProxyValue_t Value)
{
    DIO_voidSetPortValue(port, Value);
}
