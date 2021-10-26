
#include "DataTypes.h"
#include "Bluetooth.h"
#include "LCD.h"

#include "I2C.h"
#include "Timer.h"
#include "PWM.h"
#include "EEPROM_interface.h"
#include "App.h"

uint8_t Str[100] = {0};
extern uint8_t Flag;

int main()
{
	DIO_voidSetPinDirection(PORT_D,PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORT_D,PIN5, OUTPUT);

	DIO_voidSetPinDirection(PORT_D,PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_D,PIN1, OUTPUT);

	Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
	PWM_ENInitPhaseCorrect();

	UART_ENInit();
	LCD_voidInit();

//	LCD_voidWriteString("Started....");

//	SER_UARTvoidSendString("AT\r\n");
//	SER_UARTvoidSendString("AT\r\n");

//	SER_UARTvoidSendString("AT+UART?");


	UART_voidReceiveString_Ashync(Str);
//	LCD_voidGoto(1, 0);


//	Check_BaudRate();
//	Device_SearchPattern();
	while(1)
	{
		if(String_u8Comp(Str, "HandShake") == 0)
		{
			SER_UARTvoidSendString("Ok");
		}
		LCD_voidGoto(1, 0);
		LCD_voidWriteString(Str);
	}
	return 0;
}

