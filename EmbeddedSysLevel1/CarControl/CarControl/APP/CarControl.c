/**
 * @file CarControl
 * @author Vicious
 * @brief This is a Main File
 * @version 0.1
 * @date 2021-07-11
 * 
 */ 

#include "DIO_Interface.h"
#include "Timer.h"
#include "EXTI_int.h"
#include "SWITCH_int.h"
#include "MOTOR_Interface.h"
#include "CarControl_int.h"

static volatile uint8_t gPWMState = 0;
static volatile uint8_t gPWMButton = 0;

static volatile uint8_t gMotorState = 0;
static volatile sint8_t gMotorButton = -1;


void PWMButton(void)
{
	if(gPWMButton == 0)
	{
		gPWMState = 1;
		gPWMButton++;
	}
	else if(gPWMButton == 1)
	{
		gPWMState = 2;
		gPWMButton++;
	}
	else if(gPWMButton == 2)
	{
		gPWMState = 3;
		gPWMButton++;
	}
	else if(gPWMButton == 3)
	{
		gPWMState = 4;
		gPWMButton=0;
	}
}


void MotorButton(void)
{
	if(gMotorButton == 0)
	{
		gMotorState = 1;
		
	}
	else if(gMotorButton == 1)
	{
		gMotorState = 2;
	}
}


void Car_init(void)
{
	/* for switch0 */
	DIO_voidSetPinDirection(PORT_D, PIN2, INPUT);
	DIO_voidInpullUp(PORT_D, PIN2);
	/* Switch1 */
	DIO_voidSetPinDirection(PORT_D, PIN3, INPUT);
	DIO_voidInpullUp(PORT_D, PIN3);
	
	/* switch 2*/
	DIO_voidSetPinDirection(PORT_C, PIN0, INPUT);
	DIO_voidInpullUp(PORT_C, PIN0);
	
	/* switch 3*/
	DIO_voidSetPinDirection(PORT_C, PIN1, INPUT);
	DIO_voidInpullUp(PORT_C, PIN1);
	
	
	DIO_voidSetPinDirection(PORT_B, PIN3, OUTPUT);

	
	EXTI_ENEnable(EXTI_INT0);
	EXTI_ENTriggerEdge(EXTI_INT0, FALLING_EDGE);
	EXTI_ENEnable(EXTI_INT1);
	EXTI_ENTriggerEdge(EXTI_INT1, FALLING_EDGE);
	
	EXTI_SetCallBack(EXTI_INT0, PWMButton);
	EXTI_SetCallBack(EXTI_INT1, MotorButton);
	
	Timer0_Init(TIMER0_PHASECORRECT_MODE, TIMER0_SCALER_8, OCO_INVERTING);
	
	MOTOR_voidInit();
}

void Car_Control(void)
{
	if(SWITCH_u8GetState(SWITCH0))
	{
		if(gPWMState == FORWARD_30)
		{
			MOTOR_voidGeneratePWM(30);
			gMotorButton = MOTOR_FORWARD;
		}
		else if(gPWMState == FORWARD_60)
		{
			MOTOR_voidGeneratePWM(60);
			gMotorButton = MOTOR_FORWARD;
		}
		else if(gPWMState == FORWARD_90)
		{
			MOTOR_voidGeneratePWM(90);
			gMotorButton = MOTOR_FORWARD;
		}
		else if(gPWMState == BACKWARD_30)
		{
			MOTOR_voidGeneratePWM(30);
			gMotorButton = MOTOR_BACKWARD;
		}
	}
	while(SWITCH_u8GetState(SWITCH1) == PRESSED && gMotorState >= 0)
	{
		if(gMotorState == 1)
		{
			MOTOR_voidRotateClkWise(RIGHTMOTOR_ON, LEFTMOTOR_ON);
			gMotorButton = MOTOR_FORWARD;
		}
		else if(gMotorState == 2)
		{
			MOTOR_voidRotateAntiClkWise(RIGHTMOTOR_ON, LEFTMOTOR_ON);
			gMotorButton= MOTOR_BACKWARD ;
		}
	}
	while(SWITCH_u8GetState(SWITCH2) == PRESSED && gMotorState > 0)
	{
		MOTOR_voidGeneratePWM(30);
		if(gMotorState == 1)
		{
			MOTOR_voidRotateClkWise(RIGHTMOTOR_ON, LEFTMOTOR_OFF);
		}
		else if(gMotorState == 2)
		{
			MOTOR_voidRotateAntiClkWise(RIGHTMOTOR_ON, LEFTMOTOR_OFF);
		}
	}
	while(SWITCH_u8GetState(SWITCH3) == PRESSED && gMotorState > 0 )
	{
		MOTOR_voidGeneratePWM(30);
		if(gMotorState == 1)
		{
			MOTOR_voidRotateClkWise(RIGHTMOTOR_OFF, LEFTMOTOR_ON);
		}
		else if(gMotorState == 2)
		{
			MOTOR_voidRotateAntiClkWise(RIGHTMOTOR_OFF, LEFTMOTOR_ON);
		}

	}
	MOTOR_voidStop();
	
	
}
