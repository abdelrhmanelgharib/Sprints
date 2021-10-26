
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
extern uint8_t gHandShakeFlag;

int main()
{
	/* Timer */
	DIO_voidSetPinDirection(PORT_D,PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORT_D,PIN5, OUTPUT);

	/* Uart */
	DIO_voidSetPinDirection(PORT_D,PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_D,PIN1, OUTPUT);

	/* Enable Pin HC05 */
	DIO_voidSetPinDirection(PORT_C,PIN7, OUTPUT);
	DIO_voidSetPinValue(PORT_C, PIN7, HIGH);

	Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
	Timer2_init(TIMER2_NORMAL_MODE, TIMER2_SCALER_8);


	PWM_ENInitPhaseCorrect();

	UART_ENInit();
	LCD_voidInit();

	//
	//	SER_UARTvoidSendString("AT\r\n");
	SER_UARTvoidSendString((uint8_t*)"AT\r\n");

	SER_UARTvoidSendString((uint8_t*)"AT+UART?");
	UART_voidReceiveString_Ashync(Str);
	GET_BDADD();

	Device_SearchPattern();
	Check_MACADD();

	DIO_voidSetPinValue(PORT_C, PIN7, LOW);


	handshake_data();


	while(1)
	{
		LCD_voidGoto(1, 0);
		LCD_voidWriteString(Str);
	}
	return 0;
}

