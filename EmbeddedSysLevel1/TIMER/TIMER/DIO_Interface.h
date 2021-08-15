/**
 * @file DIO_Interface.h
 * @author Elgharib
 * @brief   This a DIO Interface File
 * @version 0.1
 * @date 2021-07-07
 * 
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DataTypes.h"
#include "BIT_Math.h"

#include "Memmap.h"

typedef enum
{
    PORT_A = 0,
    PORT_B ,
    PORT_C ,
    PORT_D

}EN_port_num;

typedef enum
{
    PIN0 = 0,
    PIN1 ,
    PIN2 ,
    PIN3 ,
    PIN4 ,
    PIN5 ,
    PIN6 ,
    PIN7
}EN_pin_num;

typedef enum
{
    INPUT = 0 ,
    OUTPUT
}EN_direction_type;

typedef enum
{
    LOW = 0 ,
    HIGH
}EN_value_type;


void DIO_voidSetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin, EN_value_type EN_Value);
void DIO_voidSetPinDirection(EN_port_num EN_port, EN_pin_num EN_Pin, EN_direction_type EN_Direction);
EN_value_type DIO_u8GetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin);

void DIO_voidTogPin(EN_port_num EN_Port, EN_pin_num EN_Pin);

void DIO_voidSetPortDirection(EN_port_num EN_Port, EN_direction_type EN_Direction);
void DIO_voidSetPortValue(EN_port_num EN_Port, EN_value_type EN_Value);
void DIO_voidInpullUp(EN_port_num EN_Port, EN_pin_num EN_Pin);

#endif /* DIO_INTERFACE_H_ */
