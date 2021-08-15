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

extern volatile uint32_t count_flag;
extern volatile uint32_t count_lcd;
extern volatile uint32_t count_button;

extern uint8_t flag;
volatile uint16_t Dis;
static volatile uint16_t state = 0;
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
		LCD_voidGoto(ROW, COL);
		LCD_voidCLRDisplay();
		LCD_voidPrintUnsignedInteger(Dis);
		count_lcd = 0;
	}
}

void APP_Init(void)
{

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

	DIO_voidSetPinDirection(PORT_C, PIN5, INPUT);
	DIO_voidSetPinValue(PORT_C, PIN5, HIGH);
	DIO_voidSetPinDirection(PORT_C, PIN2, OUTPUT);
	DIO_voidSetPinValue(PORT_C, PIN2, LOW);
}

void APP_Start(void)
{
	LCD_voidInit();
	if (Get_State() == sixth_state_delay_3ms)
	{

		Ultrasonic_u16GetDistance(&Dis);

		if (Dis < MIN_DISTANCE)
		{

			PWM_ENDutyCycle(20);
			MOTOR_voidRotateAntiClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_ON);
		}
		else if ((MIN_DISTANCE < Dis) && (Dis <= MAX_DISTANCE))
		{
			PWM_ENDutyCycle(40);

			MOTOR_voidRotateClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_OFF);
		}
		else if (Dis > MAX_DISTANCE)
		{
			PWM_ENDutyCycle(20);
			MOTOR_voidRotateClkWise(LEFT_MOTOR_ON, RIGHT_MOTOR_ON);
		}
	}
}
