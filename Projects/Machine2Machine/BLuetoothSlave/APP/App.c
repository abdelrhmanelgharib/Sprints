/*
 * App.c
 *
 *  Created on: Sep 8, 2021
 *      Author: 2bdoa
 */

#include "EEPROM_interface.h"
#include "Timer.h"
#include "PWM.h"
#include "SER_UART_int.h"
#include "App.h"
/*shayf an feeh moshkla ana bstep wna tal3 sa7 bs 1- msh bnzl
 * 												  2- lazm anzl bstep brdo
 * 												  2aah ra2yak ???????
 * 												  w rag3 el 7sabat waraya 3shan ana nayam 4 sa3at bs
 * 												  ;(((((((( */

/*w bos 3la 2l app.h 3ayzeen nsbt address ll mac msln w address ll bd w ndwr f dah bs */
static void Device_SearchPattern_app(void)
{
	static volatile uint16_t Count = 0;

	Count++;

	if (Count == 3000)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 4000)
	{
		PWM_ENDutyCycle(100);
	}
	else if (Count == 5000)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 6000)
	{
		PWM_ENDutyCycle(0);
		Count = 0;
	}
}

static void VAR_SearchPattern_app(void)
{
	static volatile uint16_t Count = 0;

	Count++;

	if (Count == 2400)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 2800)
	{
		PWM_ENDutyCycle(100);
	}
	else if (Count == 3600)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 4000)
	{
		PWM_ENDutyCycle(0);
		Count = 0;
	}
}
static void MalFunction_SearchPattern_app(void)
{
	static volatile uint16_t Count = 0;

	Count++;

	if (Count == 6000)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 8000)
	{
		PWM_ENDutyCycle(100);
	}
	else if (Count == 10000)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 12000)
	{
		PWM_ENDutyCycle(0);
		Count = 0;
	}
}
static void Connection_OnSearchPattern_app(void)
{
	static volatile uint16_t Count = 0;

	Count++;

	if (Count == 600)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 800)
	{
		PWM_ENDutyCycle(100);
	}
	else if (Count == 1000)
	{
		PWM_ENDutyCycle(50);
	}
	else if (Count == 1200)
	{
		PWM_ENDutyCycle(0);
		Count = 0;
	}
}
EN_ERRORSTATE_t Check_MACADD(void)
{

	char str[100];

	eeprom_recieve_string(str, MAC_ADRESS);

	if (str[0] == 'f')
	{
		/*fadya mfeesh mac address*/
		//advirtising mode
	}
	else
	{

		/*connect bl mac address el gbto*/
	}
}

EN_ERRORSTATE_t GET_BDADD(void)
{

	char str[6];

	eeprom_recieve_string(str, BD_ADRESS);

	if (str[0] == 'f')
	{
		/*fadya mfeesh bd saved*/
		//jumb 3la check bd
	}
	else
	{

		// bd recived from eeprom
		// SER_UARTvoidSendString("AT+UART=4800,0,0\r\n");

		SER_UARTvoidSendString("AT+UART=");
		SER_UARTvoidSendString(str); //the length of character
		SER_UARTvoidSendString("\r\n");

		/*dah han3ml zayo nshof 2l gbnah bl eeprom w n7to k variable*/
		//		MUSART1_voidTransmit(  "AT+CIPSEND=" );
		//		MUSART1_voidTransmit( Copy_u8Length );//the length of character
		//		MUSART1_voidTransmit(  "\r\n" );
	}
}

EN_ERRORSTATE_t Check_BaudRate(void)
{
	uint8_t ARR[10] = "OK";
	uint8_t BaudRFLag = 0;

	uint8_t Str[100] = {0};

	//UART_voidReceiveString_Ashync(Str);

	SER_UARTvoidSendString("AT\r\n");
	SER_UARTvoidSendString("AT+UART=4800,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{
		BaudRFLag = 1;
	}
	else
	{
	}

	SER_UARTvoidSendString("AT+UART=9600,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{

		BaudRFLag = 2;
	}
	else
	{
	}

	SER_UARTvoidSendString("AT+UART=38400,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{
		BaudRFLag = 3;
	}
	else
	{
	}

	/*after i found the correct BD i save it in the specific address of BD*/
	if (BaudRFLag == 1)
	{
		eeprom_send_string("4800", BD_ADRESS);
	}
	else if (BaudRFLag == 2)
	{
		eeprom_send_string("9600", BD_ADRESS);
	}
	else if (BaudRFLag == 3)
	{
		eeprom_send_string("38400", BD_ADRESS);
	}
}

EN_ERRORSTATE_t Device_SearchPattern(void)
{
	Timer0_OV_InterruptEnable();
	Timer0_SetCallBack(MalFunction_SearchPattern_app);
}

EN_ERRORSTATE_t handshake_data(void)
{

	/*lazm nt2kd hna anna bnb3t data msh command*/
	SER_UARTvoidSendString("handshake");

	/*here should recieve data */
	/*w at2kd an 3da 200ms wla hab3t tany lmodt 5 mrat*/
}


/**
 * @brief Compare two string
 *
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2)
{
	uint8_t i = 0, Flag = 0;

	while (Str1[i] || Str2[i])
	{
		if (Str1[i] != Str2[i])
		{
			Flag = 1;
			break;
		}
		i++;
	}
	return Flag;
}



