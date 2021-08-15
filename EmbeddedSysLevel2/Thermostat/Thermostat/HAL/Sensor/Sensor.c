/**
 * @file Sensor.c
 * @author Elgharib
 * @brief Lm35 sensor "Temperature sensor"
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Sensor_int.h"


/**
 * @brief This Function to Convert Adc value to Volt
 * 
 * @return uint16_t volt value
 */
uint16_t Volt_u16Read(void)
{
    uint16_t Adc_Read = ADC_u16ReadStartConversion(VOLT_CH);

    uint16_t Vin = (((uint32_t)Adc_Read * Vref)/ Resolution);

    return Vin;
}

/**
 * @brief This Function to Convert Adc value to Temp
 * 
 * @return uint16_t Temp Value
 */
uint16_t Temp_u16Read(void)
{
    uint16_t Adc_Read = ADC_u16ReadStartConversion(LM35_CH);

    uint16_t Vin = (((uint32_t)Adc_Read * Vref)/ Resolution);

    uint16_t Temp = Vin;

    return Temp/10;

}
