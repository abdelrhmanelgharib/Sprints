/**
 * @file Bluetooth.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Bluetooth.h"
#include "LCD.h"
#include "avr/delay.h"

EN_ERRORSTATE_t Bluetooth_Init(void)
{
	/* Initialize Uart Pins */
	DIO_voidSetPinDirection(PORT_D, PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);

	/* Enable Pin */
	DIO_voidSetPinDirection(PORT_D, PIN4, OUTPUT);

	UART_ENInit();


	return 0;
}


EN_ERRORSTATE_t Bluetooth_InitMaster(void)
{

	uint8_t Str[100]={0};

	DIO_voidSetPinValue(PORT_B, PIN4, HIGH);


//	str = UART_u8ReceiveNoBlock();
	// SER_UARTvoidReceiveString(str);
    // LCD_voidGoto(1, 1);
    // LCD_voidWriteString(str);
//    SER_UARTvoidSendString("AT\r\n");
//    SER_UARTvoidSendString("AT\r\n");
//
//    SER_UARTvoidSendString("AT+ADDR?\r\n");
//
//    SER_UARTvoidSendString("at\r\n");




	return 0;
}
