

#include "util/delay.h"
#include "Timer.h"
#include "LCD.h"
#include "DIO.h"
#include "EXTI.h"
#include "Ultrasonic.h"

static volatile uint32_t t2 = ZERO;
static volatile uint8_t Flag = FALLING;
static volatile uint32_t count = ZERO;

volatile uint16_t gDistance = ZERO;
/**
 * @brief This Function is Called Inside EXTI ISR to Detect Change in Signal
 * 
 */
void Exti_ultra(void)
{
	if (Flag == FALLING)
	{
		TCNT2 = 0;
		count = ZERO;
		Flag = RISING;
		EXTI_ENTriggerEdge(EXTI_INT2, FALLING_EDGE);
		count = ZERO;
	}
	else if (Flag == RISING)
	{
		t2 = TCNT2 + (count * TIMER2_REG_CAPACITY);
		Flag = READ_DISTANCE;
		EXTI_ENTriggerEdge(EXTI_INT2, RISING_EDGE);
	}
}

/**
 * @brief this function is called inside TIMER2 ISR To count Number Of OVF
 * 
 */
void Ultra_voidtimee(void)
{
	count++;
}

/**
 * @brief Initalize Ultrasonic
 * 
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t Ultrasonic_init(void)
{
	EN_ERRORSTATE_t state;
	state = E_OK;
	/* Direction for Trig Pin */
	DIO_voidSetPinDirection(TRIG_PORT, TRIG_PIN, OUTPUT);
	/* Enable EXTI int2 */
	EXTI_ENEnable(EXTI_INT2);
	/* Direction for Trig Pin */
	DIO_voidSetPinDirection(ECHO_PORT, ECHO_PIN, INPUT);
	EXTI_ENTriggerEdge(EXTI_INT2, RISING_EDGE);

	/* initalize Timer2 for calculate time of */
	Timer2_init(TIMER2_NORMAL_MODE, TIMER2_SCALER_8);
	Timer2_OV_InterruptEnable();
	EXTI_SetCallBack(EXTI_INT2, Exti_ultra);
	Timer2_OVF_SetCallBack(Ultra_voidtimee);

	return state;
}


/**
 * @brief This function for calculate distance 
 * 
 * @param void 
 */
void Ultrasonic_u16GetDistance(void)
{
	DIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, LOW);
	_delay_us(5);
	DIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, LOW);
	
	while (Flag == READ_DISTANCE)
	{
		gDistance = (uint16_t)t2 / SOUND_VELOCITY_DIVIDED_BY_TICK_TIME;
		Flag = FALLING;
	}
}
