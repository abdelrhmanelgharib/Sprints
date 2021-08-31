/**
 * @file Interrupts.c
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "DataTypes.h"
#include "BIT_Math.h"
#include "Memmap.h"
#include "Interrupts_cfg.h"
#include "Interrupts_Lcfg.h"
#include "Interrupts.h"

volatile extern uint32_t gOVFNUM;


void (*PtrFunc[VECTOR_SIZE])(void);

void Install(void (*LocalPtr)(void), uint8_t InterruptType)
{
	PtrFunc[InterruptType] = LocalPtr;
}

void DeInstall(void (*LocalPtr)(void), uint8_t InterruptType)
{
	PtrFunc[InterruptType] = NULLPTR;
}

/**
 * @brief Enable External interrupt
 * 
 * @param Interrupt 
 * @return EN_ERRORSTATE_t 
 */
void Interrupt_ENEnable(void)
{
	SETBIT(SREG, I_BIT);
}

void Interrupt_ENDisable(void)
{
	CLRBIT(GICR, I_BIT);
} /* EXTI_voidDisable */

void __vector_1(void)
{
	if (PtrFunc[INT0_VECTOR_NUMBER] != NULLPTR)
	{
		PtrFunc[INT0_VECTOR_NUMBER]();
	}
}

void __vector_2(void)
{
	if (PtrFunc[INT1_VECTOR_NUMBER] != NULLPTR)
	{
		PtrFunc[INT1_VECTOR_NUMBER]();
	}
}

void __vector_3(void)
{
	if (PtrFunc[INT2_VECTOR_NUMBER] != NULLPTR)
	{
		PtrFunc[INT2_VECTOR_NUMBER]();
	}
}


void __vector_11(void)
{
	TCNT0 = 6;
	static volatile uint32_t count = 0;
	count++;
	if (PtrFunc[TIMER0_VECTOR_NUMBER] != NULLPTR)
	{
		if (count == gOVFNUM)
		{
			PtrFunc[TIMER0_VECTOR_NUMBER]();
			count = 0;
		}
	}
}
