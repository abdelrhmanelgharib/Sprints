/*
 * APP.C
 *
 *  Created on: Aug 13, 2021
 *      Author: Al Mohamed
 */

#include "APP.h"

extern volatile uint32_t count_flag;
extern volatile uint32_t count_lcd;

extern uint8_t flag;
extern uint16_t gDistance;

/**
 * @brief call back funcion
 *
 * @param LocalFptr pointer to function
 */
void Update_State(void)
{
	/*flag="first state delay 35ms";*/
	if (count_flag == delay_35ms)
	{
		flag++;
	}
	/*flag="second state delay 1ms";*/
	else if (count_flag == delay_36ms)
	{

		flag++;
	}
	/*flag="third state delay 1ms";*/
	else if (count_flag == delay_37ms)
	{
		flag++;
	}
	/*flag="forth state delay 1ms";*/
	else if (count_flag == delay_38ms)
	{
		flag++;
	}
	/*"fifth state delay 1ms"*/
	else if (count_flag == delay_39ms)
	{
		flag++;
	}
	/*"sixth state delay 3ms"*/
	else if (count_flag == delay_42ms)
	{
		flag++;
	}
	if (count_lcd == 2000)
	{
		if (Get_State() == sixth_state_delay_3ms)
		{
			LCD_voidGoto(ROW, COL);
			LCD_voidCLRDisplay();
			LCD_voidPrintUnsignedInteger(gDistance);
			count_lcd = 0;
		}
	}
}

void APP_Init(void)
{

	/* Initialization of LCD */
	LCD_voidInit();
	while (Get_State() != sixth_state_delay_3ms);

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


