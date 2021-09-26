/*
 * CRC.c
 *
 *  Created on: Sep 11, 2021
 *      Author: 2bdoa
 */

#include "DataTypes.h"
#include "CRC.H"
uint16_t CRC16(uint8_t *ptr, uint16_t count, uint16_t initCRC)
{
    uint16_t crc;
    uint8_t i;

    crc = initCRC;
    while(--count >= 0 )
    {
        crc = crc ^ ((uint16_t) (*ptr++ << 8));
        for(i = 0; i < 8; i++)
        {
            if( crc & 0x8000 )
            {
                crc = (crc << 1) ^ CRC_CCITT_POLY;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }

    return crc;
}
