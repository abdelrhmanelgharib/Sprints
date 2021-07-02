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

/*******************************************************
 *                    Erorr Status                     *
********************************************************/
typedef char E_State_t;
#define E_OK                        1
#define Error                       2
#define E_EMPTY                     3
#define BALANCED                    0
#define NOTBALANCED                 1

void Stack_Initilaize(void);

uint8_t Stack_IsEmpty(void); 

uint8_t Stack_Push(sint8_t Data);

uint8_t Stack_Pop(sint8_t *DataPtr);

void Stack_Display(void);

uint8_t *balancedParentheses(uint8_t *expression);

#endif