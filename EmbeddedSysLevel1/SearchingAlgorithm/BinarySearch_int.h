/* **************************************************************************************
 *  BinarySearch_int.h 															        *
 *																						*
 *  Created on: July 2, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#ifndef BINARYSEARCH_INT_H_
#define BINARYSEARCH_INT_H_

#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"

typedef char E_state;


uint8_t IsArraySorted(uint32_t *arr, uint8_t size);
void Bubble_Sort(uint32_t *arr, uint8_t size);
uint8_t binary_search(uint32_t *arr, uint8_t size, uint32_t Numb);
E_state SearchForNumb(uint32_t *arr, uint8_t size, uint32_t Numb);



#define NOTSORTED   0
#define SORTED      1
#define NOTFOUND    0
#define FOUND       1
#define TEST        1
#define E_OK        1
#define ERROR       0



#endif  /* BINARYSEARCH_INT_H_ */