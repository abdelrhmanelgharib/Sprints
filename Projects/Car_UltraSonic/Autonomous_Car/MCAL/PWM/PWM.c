/**
 * @file PWM.c
 * @author 
 * @brief 
 * @version 0.1
 * @date 2021-08-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "DataTypes.h"
#include "PWM.h"

/**
 * @brief Initailze Phase Correct PWM
 * 
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t PWM_ENInitPhaseCorrect(void)
{
	EN_ERRORSTATE_t state;
	state = E_OK;
	CLRBIT(TCCR1A, WGM10);
	CLRBIT(TCCR1A, WGM11);
	CLRBIT(TCCR1B, WGM12);
	SETBIT(TCCR1B, WGM13);

#if OCRA_MODE == OCRA_NON_INVERTING_MODE
	CLRBIT(TCCR1A, COM1A0);
	SETBIT(TCCR1A, COM1A1);
#elif OCRA_MODE == OCRA_INVERTING_MODE
	SETBIT(TCCR1A, COM1A0);
	SETBIT(TCCR1A, COM1A1);
#endif

#if OCRB_MODE == OCRB_NON_INVERTING_MODE
	CLRBIT(TCCR1A, COM1B0);
	SETBIT(TCCR1A, COM1B1);
#elif OCRB_MODE == OCRB_INVERTING_MODE
	SETBIT(TCCR1A, COM1B0);
	SETBIT(TCCR1A, COM1B1);
#endif
	TCCR1B &= 0XF8;
	TCCR1B |= PWM_SCALER;

	return state;
}

/**
 * @brief DutyCycle
 * 
 * @param DutyCycle Speed
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t PWM_ENDutyCycle(uint8_t DutyCycle)
{
	EN_ERRORSTATE_t state;
	ICR1 = TIMER1_ICR_TOP_CAPACITY;
	state = E_OK;
#if OCRA_MODE == OCRA_NON_INVERTING_MODE

	OCR1A = ((TIMER1_ICR_TOP_CAPACITY * (uint32_t)DutyCycle) / 100);

#elif OCRA_MODE == OCRA_INVERTING_MODE

	OCR1A = TIMER1_ICR_TOP_CAPACITY - ((TIMER1_ICR_TOP_CAPACITY * DutyCycle) / 100);

#else

	state = E_ERROR;

#endif

#if OCRB_MODE == OCRB_NON_INVERTING_MODE

	OCR1B = ((TIMER1_ICR_TOP_CAPACITY * (uint32_t)DutyCycle) / 100);

#elif OCRB_MODE == OCRB_INVERTING_MODE

	OCR1B = TIMER1_ICR_TOP_CAPACITY - ((TIMER1_ICR_TOP_CAPACITY * DutyCycle) / 100);

#else

	state = E_ERROR;

#endif

	return state;
}
