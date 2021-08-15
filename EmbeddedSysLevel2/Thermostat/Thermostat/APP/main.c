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
#include "KeyPad_int.h"
#include "Sensor_int.h"

/* Convert string to Number */
uint8_t String_u8Numb(uint8_t *Str)
{
	uint8_t Numb = 0;
	Numb = (Str[0] - '0') * 10 + (Str[1] - '0');

	return Numb;
}

int main()
{
	DIO_voidSetPinDirection(PORT_A, PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN2, OUTPUT);
	LCD_voidInit();
	KEYPAD_voidInit();
	ADC_enInit(ADC_prescaler_64, ADC_AVCC);

	uint16_t Temp;
	uint8_t key = 0, i = 0;
	uint8_t Key_read[6];
	LCD_voidWriteString((uint8_t *)"Set Temp:");
	LCD_voidGoto(1, 0);
	LCD_voidWriteString((uint8_t*)"Press #");

	while (1)
	{
		key = KEYPAD_u8Read();
		if (key != DEFAULT_KEY)
		{
			Key_read[i] = key;
			LCD_voidGoto(0, 9+i);
			LCD_voidWriteChar(key);
			i++;
		}
		if (key == '#')
		{
			break;
		}
	}
	LCD_voidCLRDisplay();

	while (1)
	{

		key = String_u8Numb(Key_read);

		Temp = Temp_u16Read();
		LCD_voidGoto(0, 0);
		LCD_voidPrintSignedInteger(Temp);
		if (Temp > key)
		{
			DIO_voidSetPinValue(PORT_A, PIN2, HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PORT_A, PIN2, LOW);
		}
	}
}
