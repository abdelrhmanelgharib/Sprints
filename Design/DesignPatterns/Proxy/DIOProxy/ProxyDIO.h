/**
 * @file ProxyDIO.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PROXYDIO_H_
#define PROXYDIO_H_
typedef enum
{
    PROXY_PORT_A = 0,
    PROXY_PORT_B ,
    PROXY_PORT_C ,
    PROXY_PORT_D
}EN_Proxy_port_t;

typedef enum
{
    PROXY_PIN0 = 0,
    PROXY_PIN1 ,
    PROXY_PIN2 ,
    PROXY_PIN3 ,
    PROXY_PIN4 ,
    PROXY_PIN5 ,
    PROXY_PIN6 ,
    PROXY_PIN7
}EN_Proxypin_t;

typedef enum
{
    PROXY_INPUT = 0 ,
    PROXY_OUTPUT ,
    PROXY_PRTOUTPUT = 0xFF,
    PROXY_PRTINPUT = 0x00    
}EN_Proxydirection_t;

typedef enum
{
    PROXY_LOW = 0 ,
    PROXY_HIGH ,
    PROXY_PRTHIGH = 0xFF,
    PROXY_PRTLOW = 0
}EN_ProxyValue_t;

/**
 * @brief This Function to change DIrection of Pins
 * 
 * @param port PORT Name
 * @param Pin PIN Number
 * @param Direction Direction of the Pin INPUT | OUTPUT
 * @return EN_ERRORSTATE_t EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_ERRORSTATE_t Proxy_DIOPinDirection(EN_Proxy_port_t port, EN_Proxypin_t Pin, EN_Proxydirection_t Direction);

/**
 * @brief This Function to change Pin value HIGH | LOW
 * 
 * @param port PORT Name
 * @param Pin PIN Number
 * @param Value  HIGH or LOW
 * @return EN_ERRORSTATE_t EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_ERRORSTATE_t Proxy_DIOPinValue(EN_Proxy_port_t port, EN_Proxypin_t Pin, EN_ProxyValue_t Value);

/**
 * @brief 
 * 
 * @param port 
 * @param Direction 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t Proxy_DIOPortDirection(EN_Proxy_port_t port, EN_Proxydirection_t Direction);

/**
 * @brief 
 * 
 * @param port 
 * @param Direction 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t Proxy_DIOPortValue(EN_Proxy_port_t port, EN_ProxyValue_t Direction);



#endif  /* PROXYDIO_H_ */