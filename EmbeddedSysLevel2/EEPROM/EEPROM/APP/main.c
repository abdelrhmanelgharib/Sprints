/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "APP_int.h"

int main(void)
{

    APP_voidInit();

    uint8_t *Write = (uint8_t *)"write";
    uint8_t *Read = (uint8_t *)"read";
    uint8_t Data[6];

    while (1)
    {
        SER_UARTvoidReceiveString(Data);
        if (String_u8Comp(Data, Write) == STRING_EQUL)
        {
            APP_voidWrite();
        }
        else if (String_u8Comp(Data, Read) == STRING_EQUL)
        {
            APP_voidRead();            
        }
        else if (String_u8Comp(Data, Read) == 1)
        {
            SER_UARTvoidSendString((uint8_t *)"Wrong Enter");
        }
    }
}
