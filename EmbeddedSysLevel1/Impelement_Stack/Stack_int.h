/*
 *  Author: El-Gharib
 *  Created On: 1/7/2021
 *  Version: 1
 */

#ifndef Stack_Linkedlist_H_
#define Stack_Linkedlist_H_

#include <stdio.h>
#include <stdlib.h>

#include "DataTypes.h"

#define No_Error 1
#define Error 0

void Stack_Initilaize(void);

uint8_t Stack_Push(sint32_t Data);

uint8_t Stack_Pop(sint32_t *DataPtr);


void Stack_Display(void);

#endif