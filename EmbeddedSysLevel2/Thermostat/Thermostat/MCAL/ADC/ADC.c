/**
 * @file ADC.c
 * @author Elgharib
 * @brief Adc Program
 * @version 0.1
 * @date 2021-07-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ADC_int.h"
#include "Memmap.h"

/* to prevents conversion in new loop if conversion dosent end */
static uint8_t gReadFlag = 0;

/**
 * @brief Initialize Adc prescaler and volt referance
 * 
 * @param Scaler Prescaler enum ADC_prescaler_2 -> ADC_prescaler_128 
 * @param vref enum ADC_AREFF - ADC_AVCC - ADC_INTERNAL
 * @return EN_ERRORSTATE_t Error status E_OK - E_ERROR
 */
EN_ERRORSTATE_t ADC_enInit(prescaler_t Scaler, vreff_t vref)
{
    EN_ERRORSTATE_t state;
    state = E_OK;

    switch (vref)
    {
    case ADC_AREFF:
        CLRBIT(ADMUX, REFS0);
        CLRBIT(ADMUX, REFS1);
        break;
    case ADC_AVCC:
        SETBIT(ADMUX, REFS0);
        CLRBIT(ADMUX, REFS1);
        break;
    case ADC_INTERNAL:
        SETBIT(ADMUX, REFS0);
        SETBIT(ADMUX, REFS1);
        break;
    default:
        state = E_ERROR;
        break;
    }

    /* prescaler */
    ADCSRA &= 0xF8;
    ADCSRA |= Scaler;

    /* Enable ADC */
    SETBIT(ADCSRA, ADEN);

    return state;
}

/**
 * @brief Read Adc and wait for start conversion
 * 
 * @param Channel enum ADC_CHANNEL_0 -> ADC_CHANNEL_7
 * @return uint16_t value of analog signal
 */
uint16_t ADC_u16ReadStartConversion(ADC_channel_t Channel)
{
    /* Select ADC Channel */
    ADMUX &= 0xE0;
    ADMUX |= Channel;

    /* start single conversion */
    SETBIT(ADCSRA, ADSC);

    /* wait for conversion */
    while (GETBIT(ADCSRA, ADSC))
        ;

    return ADC;
}

/**
 * @brief start converstion only
 * 
 * @param Channel enum ADC_CHANNEL_0 -> ADC_CHANNEL_7
 * @return EN_ERRORSTATE_t Error status E_OK - E_ERROR
 */
EN_ERRORSTATE_t ADC_enStartConversion(ADC_channel_t Channel)
{
    EN_ERRORSTATE_t state;
    state = E_OK;
    if (gReadFlag == 0)
    {
        ADMUX &= 0xE0;
        ADMUX |= Channel;

        /* start single conversion */
        SETBIT(ADCSRA, ADSC);
        gReadFlag = 1;
    }
    else
    {
        state = E_ERROR;
    }
    return state;
}

/**
 * @brief Read Analog Signal After call start conversion Function
 * 
 * @return uint16_t value of anaglog signal
 */
uint16_t ADC_u16Read(void)
{
    /* wait for conversion */
    while (GETBIT(ADCSRA, ADSC))
        ;

    return ADC;
}

/**
 * @brief Read Analog Signal without waitting Conversion
 *        this function can ignore adc if conversion doesn't end at same time PC in the function
 * 
 * @param Pread store adc value on Pread
 * @return uint8_t conversion end or Not
 */
uint8_t ADC_u16ReadNoBlock(uint16_t *Pread)
{
    if (GETBIT(ADCSRA, ADSC) == 0)
    {
        *Pread = ADC;
        gReadFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}
