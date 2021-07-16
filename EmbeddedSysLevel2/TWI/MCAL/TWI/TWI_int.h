/**
 * @file TWI_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-16
 * 
 */


#ifndef TWI_INT_H_
#define TWI_INT_H_

#include "DataTypes.h"
#include "BIT_Math.h"
#include "Memmap.h"

#include "TWI_private.h"
#include "TWI_config.h"


typedef enum
{
    E_ERROR,
    E_OK
}EN_ErrorTWI_t;


/**
 * @brief This Function to Enable TWI
 *        and Clear TWI Flag
 * @param void
 * @return void
 */
void TWI_voidEnable(void);



/**
 * @brief initialize TWI
 * @param void
 * @return void
 */
void TWI_voidInit(void);



/**
 * @brief start Condition For Master MCU
 * 
 * @return EN_ErrorTWI_t Error status
 */
EN_ErrorTWI_t TWI_voidStartBit()




#endif  /* TWI_INT_H_ */