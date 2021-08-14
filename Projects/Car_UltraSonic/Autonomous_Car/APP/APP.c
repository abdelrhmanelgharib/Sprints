/*
 * APP.C
 *
 *  Created on: Aug 13, 2021
 *      Author: Al Mohamed
 */
#include "DataTypes.h"
#include "DIO.h"
#include "LCD.h"
#include "MOTOR.h"
#include "PWM.h"
#include "Ultrasonic.h"
#include "APP.h"


void APP_Init(void){

	/* Initialization of LCD */
	LCD_voidInit();

	/* Set Pin 2 of Port A OUTPUT */
	DIO_voidSetPinDirection(PORT_A, PIN2, OUTPUT);

	/* Set Pin 2 of Port A LOW */
	DIO_voidSetPinValue(PORT_A, PIN2, LOW);

	/* Set Pin 6 of port D INPUT */
	DIO_voidSetPinDirection(PORT_D, PIN6, INPUT);

	/* Initialization of UltraSonic Sensor */
	Ultrasonic_init();

	/* Initialization of TIMER0 in Normal Mode With perscaler 8 */
	Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);

	/* Enable Interrupt OverFlow for TIMER0 */
	Timer0_OV_InterruptEnable();

	/* SetCallBack function for TIMER0 */
	Timer0_SetCallBack(Update_State);

	/* Initialization of PHASE CORRECT */
	PWM_ENInitPhaseCorrect();

	/* Initialization of MOTOR */
	MOTOR_voidInit();
}


void APP_Start(void)
{

	LCD_voidInit();
	uint16_t Dis;
	if (Get_State()==6)
	{
		Timer0_OV_InterruptDisable();
		Ultrasonic_u16GetDistance(&Dis);
		LCD_voidGoto(ROW,COL);
		LCD_voidCLRDisplay();
		LCD_voidPrintUnsignedInteger(Dis);
		if(Dis<48)
		{
			PWM_ENDutyCycle(20);
			MOTOR_voidRotateAntiClkWise(LEFT_MOTOR_ON,RIGHT_MOTOR_ON);
		}
		else if((48<=Dis)&&(Dis<=52))
		{
			PWM_ENDutyCycle(25);

			MOTOR_voidRotateClkWise(LEFT_MOTOR_ON,RIGHT_MOTOR_OFF);

		}
		else if(Dis>52)
		{
			PWM_ENDutyCycle(20);
			MOTOR_voidRotateClkWise(LEFT_MOTOR_ON,RIGHT_MOTOR_ON);

		}


	}
}
