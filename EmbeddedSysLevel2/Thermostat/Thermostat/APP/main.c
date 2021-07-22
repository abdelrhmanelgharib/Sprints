/**
 * @file main.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DataTypes.h"
#include "DIO_Interface.h"
#include "ADC_int.h"
#include "LCD_Interface.h"
#include "Sensor_int.h"



int main()
{
    DIO_voidSetPinDirection(PORT_A, PIN0, INPUT);
    LCD_voidInit();
    ADC_enInit(ADC_prescaler_64, ADC_AVCC);

    uint16_t Temp;

    while (1)
    {
        Temp = Temp_u16Read();
        LCD_voidGoto(0, 0);
        LCD_voidPrintSignedInteger(Temp);

    }
    
}
