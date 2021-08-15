/**
 * @file ADC_int.h
 * @author Elghairb
 * @brief ADC Interface File
 * @version 0.1
 * @date 2021-07-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "Memmap.h"

typedef enum
{
    ADC_CHANNEL_0 = 0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7
} ADC_channel_t;

typedef enum
{
    ADC_prescaler_2 = 1,
    ADC_prescaler_4,
    ADC_prescaler_8,
    ADC_prescaler_16,
    ADC_prescaler_32,
    ADC_prescaler_64,
    ADC_prescaler_128
} prescaler_t;

typedef enum
{
    ADC_AREFF = 0,
    ADC_AVCC,
    ADC_INTERNAL = 3
} vreff_t;

/**
 * @brief Initialize Adc prescaler and volt referance
 * 
 * @param Scaler Prescaler enum ADC_prescaler_2 -> ADC_prescaler_128 
 * @param vref enum ADC_AREFF - ADC_AVCC - ADC_INTERNAL
 * @return EN_ERRORSTATE_t Error status E_OK - E_ERROR
 */
EN_ERRORSTATE_t ADC_enInit(prescaler_t Scaler, vreff_t vref);

/**
 * @brief Read Adc and wait for start conversion
 * 
 * @param Channel enum ADC_CHANNEL_0 -> ADC_CHANNEL_7
 * @return uint16_t value of analog signal
 */
uint16_t ADC_u16ReadStartConversion(ADC_channel_t Channel);

/**
 * @brief start converstion only
 * 
 * @param Channel enum ADC_CHANNEL_0 -> ADC_CHANNEL_7
 * @return EN_ERRORSTATE_t Error status E_OK - E_ERROR
 */
EN_ERRORSTATE_t ADC_enStartConversion(ADC_channel_t Channel);

/**
 * @brief Read Analog Signal After call start conversion Function
 * 
 * @return uint16_t value of anaglog signal
 */
uint16_t ADC_u16Read(void);

/**
 * @brief Read Analog Signal without waitting Conversion
 *        this function can ignore adc if conversion doesn't end at same time PC in the function
 * 
 * @param Pread store adc value on Pread
 * @return uint8_t conversion end or Not
 */
uint8_t ADC_u16ReadNoBlock(uint16_t *Pread);

#endif /* ADC_INT_H_ */
