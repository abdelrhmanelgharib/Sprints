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


uint8_t IsArraySorted(uint8_t *arr, uint8_t size);
uint8_t *Bubble_Sort(uint8_t *arr, uint8_t size);
sint8_t binary_search(uint8_t *arr, uint8_t size, uint32_t Numb);
sint8_t SearchForNumb(uint8_t* arr, uint8_t size, uint32_t Numb);



#define NOTSORTED   0
#define SORTED      1
#define NOTFOUND    -1
#define FOUND       1



#endif  /* BINARYSEARCH_INT_H_ */