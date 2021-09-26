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
#include "CRC.h"
#include "LCD.h"
#include "App.h"

volatile uint8_t gHandShakeFlag = 0;
extern uint8_t Str[100];


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
		SER_UARTvoidSendString((uint8_t*)"AT+link=98d3:51:fdf835");

	}
	else
	{
		SER_UARTvoidSendString((uint8_t*)"AT+link=");
		SER_UARTvoidSendString(str);
		SER_UARTvoidSendString((uint8_t*) "\r\n");

		/*connect bl mac address el gbto*/
	}
	VAR_SearchPattern_app();
}

EN_ERRORSTATE_t GET_BDADD(void)
{

	uint8_t str[6];

	eeprom_recieve_string(str, BD_ADRESS);

	if (str[0] == 'f')
	{
		/*fadya mfeesh bd saved*/
		//jumb 3la check bd
		Check_BaudRate();

	}
	else
	{

		// bd recived from eeprom

		SER_UARTvoidSendString((uint8_t*)"AT+UART=");
		SER_UARTvoidSendString(str); //the length of character
		SER_UARTvoidSendString((uint8_t*)"\r\n");

	}
}
EN_ERRORSTATE_t Device_SearchPattern(void)
{
	EN_ERRORSTATE_t state = E_OK;
	Timer0_OV_InterruptEnable();
	Timer0_SetCallBack(Device_SearchPattern_app);
	return state;
}
EN_ERRORSTATE_t var_SearchPattern(void)
{
	Timer0_OV_InterruptEnable();
	Timer0_SetCallBack(VAR_SearchPattern_app);
}
EN_ERRORSTATE_t Mal_Pattern(void)
{
	EN_ERRORSTATE_t state = E_OK;
	Timer0_OV_InterruptEnable();
	Timer0_SetCallBack(MalFunction_SearchPattern_app);
	return state;
}
EN_ERRORSTATE_t Connection_OnPattern(void)
{
	EN_ERRORSTATE_t state = E_OK;
	Timer0_OV_InterruptEnable();
	Timer0_SetCallBack(Connection_OnSearchPattern_app);
	return state;
}

EN_ERRORSTATE_t Check_BaudRate(void)
{
	EN_ERRORSTATE_t state = E_OK;
	uint8_t ARR[10] = "OK";
	uint8_t BaudRFLag = 0;

	uint8_t Str[100] = {0};

	//UART_voidReceiveString_Ashync(Str);

	SER_UARTvoidSendString((uint8_t*)"AT\r\n");
	SER_UARTvoidSendString((uint8_t*)"AT+UART=4800,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{
		BaudRFLag = 1;
	}
	else
	{
	}

	SER_UARTvoidSendString((uint8_t*)"AT+UART=9600,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{

		BaudRFLag = 2;
	}
	else
	{
	}

	SER_UARTvoidSendString((uint8_t*)"AT+UART=38400,0,0\r\n");
	if (UART_u8ReceiveData() == ARR[0])
	{
		BaudRFLag = 3;
	}
	else
	{
		state = E_ERROR;
	}

	/*after i found the correct BD i save it in the specific address of BD*/
	if (BaudRFLag == 1)
	{
		eeprom_send_string((uint8_t*)"4800", BD_ADRESS);
	}
	else if (BaudRFLag == 2)
	{
		eeprom_send_string((uint8_t*)"9600", BD_ADRESS);
	}
	else if (BaudRFLag == 3)
	{
		eeprom_send_string((uint8_t*)"38400", BD_ADRESS);
	}
	else
	{
		Mal_Pattern();
	}
	return state;
}


EN_ERRORSTATE_t handshake_data(void)
{
	EN_ERRORSTATE_t state = E_OK;
	static uint8_t Count = 0;
	/*lazm nt2kd hna anna bnb3t data msh command*/

	SER_UARTvoidSendString((uint8_t*)"HandShake");
	HandShake_Handler();
	while(Count !=5)
	{
		while(gHandShakeFlag == 0);
		if(gHandShakeFlag ==1)
		{
			Count++;
			SER_UARTvoidSendString((uint8_t*)"HandShake");
		}
		else
		{
			LCD_voidGoto(0, 0);
			LCD_voidWriteString((uint8_t*)"Done..");
			Connection_OnPattern();
			device_data();
		}
	}



	/*here should recieve data */
	/*w at2kd an 3da 200ms wla hab3t tany lmodt 5 mrat*/


	if (Count==5)
	{
		Device_SearchPattern();
		SER_UARTvoidSendString((uint8_t*)"AT+DISC\r\n");
	}

	return state;
}
EN_ERRORSTATE_t device_data(void)
{
	uint8_t data[] = {0xAA,1}
	uint8_t Str[100] = {0};
	static uint8_t Count = 0;
	/*lazm nt2kd hna anna bnb3t data msh command*/

	SER_UARTvoidSendString(HEADER);
	UART_voidReceiveString_Ashync(Str);

	DiviceData_Handler();
	while(Count !=5)
	{
		while(gHandShakeFlag == 0);
		if(gHandShakeFlag == 1)
		{
			Count++;
			SER_UARTvoidSendString((uint8_t*)data);
		}
		else
		{
			LCD_voidGoto(0, 0);
			LCD_voidWriteString((uint8_t*)"Done..");
			eeprom_send_string(Str, DD_ADRESS);

		}
	}

	/*here should recieve data */
	/*w at2kd an 3da 200ms wla hab3t tany lmodt 5 mrat*/
	if (Count==5){

		Device_SearchPattern();
		SER_UARTvoidSendString((uint8_t*)"AT+DISC\r\n");

	}
}


uint8_t Check_200ms(void)
{
	static uint16_t Count=0;
	Count++;

	if(Count == 800)
	{
		if(Str[0] != 'O')
		{
			gHandShakeFlag = 1;
		}
		else
		{
			gHandShakeFlag = 2;
		}
	}
}


void HandShake_Handler(void)
{
	Timer2_OVF_SetCallBack(Check_200ms);
	Timer2_OV_InterruptEnable();
}
void DiviceData_Handler(void)
{
	Timer2_OVF_SetCallBack(Check_200ms);
	Timer2_OV_InterruptEnable();
}
