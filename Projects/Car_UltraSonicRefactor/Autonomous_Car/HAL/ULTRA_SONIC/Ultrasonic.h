#ifndef ULTRASONIC_INT_H
#define ULTRASONIC_INT_H

#include "DataTypes.h"
#include "BIT_Math.h"
#include "Timer.h"
#include "DIO.h"
#include "Ultrasonic_cfg.h"




/**
 * @brief Initialize Ultrasonic
 *
 * @return EN_ERRORSTATE_t Error state
 */
EN_ERRORSTATE_t Ultrasonic_init(void);



/**
 * @brief This function for calculate distance
 *
 * @param void
 */
void Ultrasonic_u16GetDistance(void);
#endif  /* ULTRASONIC_INT_H */
