/**
 * @file Sensor_int.h
 * @author ELgharib
 * @brief Lm35 sensor "Temperature sensor"
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LM35_INT_H_
#define LM35_INT_H_

#include "DataTypes.h"
#include "ADC_int.h"

#define VOLT_CH        ADC_CHANNEL_1
#define LM35_CH        ADC_CHANNEL_0
#define Vref           5000
#define Resolution     1024


/**
 * @brief This Function to Convert Adc value to Volt
 * 
 * @return uint16_t volt value
 */
uint16_t Volt_u16Read(void);


/**
 * @brief This Function to Convert Adc value to Temp
 * 
 * @return uint16_t Temp Value
 */
uint16_t Temp_u16Read(void);






#endif  /* LM35_INT_H_ */
