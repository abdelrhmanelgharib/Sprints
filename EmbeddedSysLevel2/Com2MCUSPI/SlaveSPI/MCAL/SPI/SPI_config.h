/**
 * @file SPI_config.h
 * @author Elghrib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* 
 *  Clk Polarity 
 *  CLK_LOW - CLK_HIGH 
*/
#define CLK_IDLE       CLK_LOW


/**
 * Clock Phase 
 * Sample in Leading or Trailing Edge
 * LEADING - TRAILING
 */

#define CLK_PHASE   LEADING


/**
 * CLK Frequency
 * F_CPU_2 - F_CPU_4 - F_CPU_8 - F_CPU_16 - F_CPU_32 - F_CPU_64 - F_CPU_128
 */

#define SPI_SPEED         F_CPU_4     




#endif  /* SPI_CONFIG_H_ */