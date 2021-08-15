/*
 *  Author: Vicious
 *  Created on: 11/7/2021
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

#include "DataTypes.h"
#include "Bit_Math.h"

#include "DIO_Interface.h"
#include "SWITCH_prev.h"
#include "SWITCH_config.h"
#include "SWITCH_int.h"






uint8_t SWITCH_u8GetState(uint8_t switch_num);



#define PRESSED         1
#define NOT_PRESSED     0 

#define SWITCH0     0     
#define SWITCH1     1
#define SWITCH2     2
#define SWITCH3     3



#endif /* SWITCH_INT_H_ */