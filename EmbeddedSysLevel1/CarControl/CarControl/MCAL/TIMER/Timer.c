/**
 * @file Timer.c
 * @author Vicious
 * @brief  TIMER
 * @version 0.1
 * @date 2021-07-8
 * 
 */

#include "Timer.h"

/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr)(void) = NULLPTR;
static void (*Timer1_OCA_Fptr)(void) = NULLPTR;
static void (*Timer1_OCB_Fptr)(void) = NULLPTR;
static void (*Timer1_ICU_Fptr)(void) = NULLPTR;

static void (*Timer0_OVF_Fptr)(void) = NULLPTR;

static uint16_t gPrescal = 1;
static volatile uint32_t gOVFNUM = 1;

/**************************************************************************/

/**
 * @brief Initialize Timer0
 * 
 * @param mode TIMER0 Modes
 * @param scaler TIMER Prescaler
 * @param oc_mode OC0 mode
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t Timer0_Init(EN_Timer0Mode_t mode, EN_Timer0Scaler_t scaler, EN_OC0Mode_t oc_mode)
{
	EN_ERRORSTATE_t state;
	state = E_OK;

	switch (mode)
	{
	case TIMER0_NORMAL_MODE:
		CLRBIT(TCCR0, WGM00);
		CLRBIT(TCCR0, WGM01);
		break;
	case TIMER0_PHASECORRECT_MODE:
		SETBIT(TCCR0, WGM00);
		CLRBIT(TCCR0, WGM01);
		break;
	case TIMER0_CTC_MODE:
		CLRBIT(TCCR0, WGM00);
		SETBIT(TCCR0, WGM01);
		break;
	case TIMER0_FASTPWM_MODE:
		SETBIT(TCCR0, WGM00);
		SETBIT(TCCR0, WGM01);
		break;
	default:
		state = E_ERROR;
		break;
	}

	TCCR0 &= 0XF8; //0b11111000
	TCCR0 |= scaler;
	gPrescal = scaler;

	switch (oc_mode)
	{
	case OCO_DISCONNECTED:
		CLRBIT(TCCR0, COM00);
		CLRBIT(TCCR0, COM01);
		break;
	case OCO_TOGGLE:
		SETBIT(TCCR0, COM00);
		CLRBIT(TCCR0, COM01);
		break;
	case OCO_NON_INVERTING:
		CLRBIT(TCCR0, COM00);
		SETBIT(TCCR0, COM01);
		break;
	case OCO_INVERTING:
		SETBIT(TCCR0, COM00);
		SETBIT(TCCR0, COM01);
		break;
	default:
		state = E_ERROR;
		break;
	}
	return state;
}


/**
 * @brief take dutycycle and OCO pin mode
 * 
 * @param DutyCycle speed
 * @param ocomode OCO_INVERTING - OCO_NON_INVERTING
 */
void TIMER0_voidPhaseCorrect(uint8_t DutyCycle, EN_OC0Mode_t ocomode)
{
	if (ocomode == OCO_INVERTING )
	{
		OCR0 = 255 - ((TIMER0_REG_CAPACITY * DutyCycle)/100);
	}
	
	else if (ocomode == OCO_NON_INVERTING)
	{
		OCR0 = (255 * DutyCycle)/100;
	}
}


/**
 * @brief take dutycycle and OCO pin mode
 * 
 * @param DutyCycle speed
 * @param ocomode OCO_INVERTING - OCO_NON_INVERTING
 */
void TIMER0_voidFastPWM(uint8_t DutyCycle, EN_OC0Mode_t ocomode)
{
	if (ocomode == OCO_INVERTING)
	{
		OCR0 = ((TIMER0_REG_CAPACITY * DutyCycle)/100)-1;
	}
	else if (ocomode == OCO_NON_INVERTING)
	{
		OCR0 = 255 - ((TIMER0_REG_CAPACITY * DutyCycle)/100);
	}
}

/**
 * @brief Enable Over FLow Interrupt 
 * 
 */
void Timer0_OV_InterruptEnable(void)
{
	SETBIT(SREG, I_BIT);
	SETBIT(TIMSK, TOIE0);
}

/**
 * @brief Disable Over FLow Interrupt
 * 
 */
void Timer0_OV_InterruptDisable(void)
{
	CLRBIT(TIMSK, TOIE0);
}

/**
 * @brief Enable CTC Interrupt
 * 
 */
void Timer0_OC_InterruptEnable(void)
{
	SETBIT(TIMSK, OCIE0);
}

/**
 * @brief Disable CTC Interrupt
 * 
 */
void Timer0_OC_InterruptDisable(void)
{
	CLRBIT(TIMSK, OCIE0);
}

/**
 * @brief call back funcion
 * 
 * @param LocalFptr pointer to function 
 */
void Timer0_SetCallBack(void (*LocalFptr)(void))
{
	Timer0_OVF_Fptr = LocalFptr;
}

/**
 * @brief  delay using timer
 * 
 * @param Time desired time
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t Timer0_delayUs(uint32_t Time)
{
	EN_ERRORSTATE_t state;
	state = E_OK;

	if (gPrescal == TIMER0_SCALER_8)
	{
		gPrescal = 8;
	}
	else if (gPrescal == TIMER0_SCALER_64)
	{
		gPrescal = 64;
	}
	else if (gPrescal == TIMER0_SCALER_256)
	{
		gPrescal = 256;
	}
	else if (gPrescal == TIMER0_SCALER_1024)
	{
		gPrescal = 1024;
	}
	else
	{
		state = E_ERROR;
	}

	float TickTime = gPrescal / F_CPU;
	uint32_t numbOfTick = Time / TickTime;
	gOVFNUM = numbOfTick / 250;

	return state;
}

void __vector_11(void)
{
	TCNT0 = 6;
	static volatile uint32_t count = 0;
	count++;
	if (Timer0_OVF_Fptr != NULLPTR)
	{
		if (count == gOVFNUM)
		{
			Timer0_OVF_Fptr();
			count = 0;
		}
	}
}

/****************************************Timer 1 **********************************************/

/**
 * @brief Initialize Timer1
 * 
 * @param mode TIMER1 Modes
 * @param scaler TIMER1 Prescaler
 * @param oc1a_mode 
 * @param oc1b_mode 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler, OC1A_Mode_type oc1a_mode, OC1B_Mode_type oc1b_mode)
{
	EN_ERRORSTATE_t state;
	state = E_OK;

	switch (mode)
	{
	case TIMER1_NORMAL_MODE:
		CLRBIT(TCCR1A, WGM10);
		CLRBIT(TCCR1A, WGM11);
		CLRBIT(TCCR1B, WGM12);
		CLRBIT(TCCR1B, WGM13);
		break;
	case TIMER1_CTC_ICR_TOP_MODE:
		CLRBIT(TCCR1A, WGM10);
		CLRBIT(TCCR1A, WGM11);
		SETBIT(TCCR1B, WGM12);
		SETBIT(TCCR1B, WGM13);
		break;

	case TIMER1_CTC_OCRA_TOP_MODE:
		CLRBIT(TCCR1A, WGM10);
		CLRBIT(TCCR1A, WGM11);
		SETBIT(TCCR1B, WGM12);
		CLRBIT(TCCR1B, WGM13);
		break;

	case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLRBIT(TCCR1A, WGM10);
		SETBIT(TCCR1A, WGM11);
		SETBIT(TCCR1B, WGM12);
		SETBIT(TCCR1B, WGM13);
		break;

	case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SETBIT(TCCR1A, WGM10);
		SETBIT(TCCR1A, WGM11);
		SETBIT(TCCR1B, WGM12);
		SETBIT(TCCR1B, WGM13);
		break;
	default:
		state = E_ERROR;
		break;
	}

	switch (oc1a_mode)
	{
	case OCRA_DISCONNECTED:
		CLRBIT(TCCR1A, COM1A0);
		CLRBIT(TCCR1A, COM1A1);
		break;
	case OCRA_TOGGLE:
		SETBIT(TCCR1A, COM1A0);
		CLRBIT(TCCR1A, COM1A1);
		break;
	case OCRA_NON_INVERTING:
		CLRBIT(TCCR1A, COM1A0);
		SETBIT(TCCR1A, COM1A1);
		break;
	case OCRA_INVERTING:
		SETBIT(TCCR1A, COM1A0);
		SETBIT(TCCR1A, COM1A1);
		break;
	default:
		state = E_ERROR;
		break;
	}

	switch (oc1b_mode)
	{
	case OCRB_DISCONNECTED:
		CLRBIT(TCCR1A, COM1B0);
		CLRBIT(TCCR1A, COM1B1);
		break;
	case OCRB_TOGGLE:
		SETBIT(TCCR1A, COM1B0);
		CLRBIT(TCCR1A, COM1B1);
		break;
	case OCRB_NON_INVERTING:
		CLRBIT(TCCR1A, COM1B0);
		SETBIT(TCCR1A, COM1B1);
		break;
	case OCRB_INVERTING:
		SETBIT(TCCR1A, COM1B0);
		SETBIT(TCCR1A, COM1B1);
		break;
	default:
		state = E_ERROR;
		break;
	}

	TCCR1B &= 0XF8;
	TCCR1B |= scaler;

	return state;
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if (edge == RISING)
		SETBIT(TCCR1B, ICES1);

	else if (edge == FALLING)
		CLRBIT(TCCR1B, ICES1);
}
/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SETBIT(SREG, I_BIT);
	SETBIT(TIMSK, TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLRBIT(TIMSK, TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SETBIT(SREG, I_BIT);
	SETBIT(TIMSK, TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLRBIT(TIMSK, TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SETBIT(SREG, I_BIT);
	SETBIT(TIMSK, OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLRBIT(TIMSK, OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SETBIT(SREG, I_BIT);
	SETBIT(TIMSK, OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLRBIT(TIMSK, OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void (*LocalFptr)(void))
{
	Timer1_OVF_Fptr = LocalFptr;
}
void Timer1_OCA_SetCallBack(void (*LocalFptr)(void))
{
	Timer1_OCA_Fptr = LocalFptr;
}
void Timer1_OCB_SetCallBack(void (*LocalFptr)(void))
{
	Timer1_OCB_Fptr = LocalFptr;
}
void Timer1_ICU_SetCallBack(void (*LocalFptr)(void))
{
	Timer1_ICU_Fptr = LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
void __vector_9(void)
{
	if (Timer1_OVF_Fptr != NULLPTR)
	{
		Timer1_OVF_Fptr();
	}
}

void __vector_7(void)
{
	if (Timer1_OCA_Fptr != NULLPTR)
	{
		Timer1_OCA_Fptr();
	}
}
void __vector_8(void)
{
	if (Timer1_OCB_Fptr != NULLPTR)
	{
		Timer1_OCB_Fptr();
	}
}
void __vector_6(void)
{
	if (Timer1_ICU_Fptr != NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}