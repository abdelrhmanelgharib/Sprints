/* **************************************************************************************
 *  BinarySearch.c    															        *
 *																						*
 *  Created on: July 2, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"


/* *************************************************************************************
 * in this function Swap Two Numbers                        							*
 * Parameters : Numb1 and Numb2                                            				*
 * Return : void                                                                		*
 * **************************************************************************************/
void Swap(uint32_t *Numb1, uint32_t *Numb2)
{
    uint32_t Temp;
    Temp = *Numb1;
    *Numb1 = *Numb2;
    *Numb2 = Temp;
}
/* *************************************************************************************
 * Check is array sorted or not                             							*
 * Parameters : arr and size of array                                   				*
 * Return   : is array sorted or unsorted                                       		*
 * **************************************************************************************/
uint8_t IsArraySorted(uint32_t *arr, uint8_t size)
{
    if (size == 1 || size == 0)
        return SORTED;

    if (arr[size - 1] < arr[size - 2])
        return NOTSORTED;

    return IsArraySorted(arr, size - 1);
}

/* *************************************************************************************
 * Bubble Sort Algo                                         							*
 * Parameters : arr and size of array                                   				*
 * Return   : void                                                                		*
 * **************************************************************************************/
void Bubble_Sort(uint32_t *arr, uint8_t size)
{
    uint8_t i, j, Flag = 0;

    size -= 1;

    /* Outer loop for pass squence */
    for (i = 0; i < size; i++)
    {
        // Flag = 0;
        /* internal loop to get larg element */
        for (j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /* swap the larg element with small */
                Swap(&arr[j], &arr[j + 1]);
                Flag = 1;
            }
        }
        // /* check if the array is sorted */
        if (Flag == 0)
        {
            break;
        }
    }
}


/* *************************************************************************************
 * Binary Search                                             							*
 * Parameters : arr, size of array and Number to Search                    				*
 * Return   : if Numb found return index in the array                                   *
 *            else return Notfound                                                 		*
 * **************************************************************************************/
uint8_t binary_search(uint32_t *arr, uint8_t size, uint32_t Numb)
{
    uint8_t Start, End, Mid;

    Start = 0;
    End = size - 1;

    while (Start <= End)
    {
        Mid = End + Start;
        Mid /= 2;
        if (Numb == arr[Mid])
        {
            return Mid; // return place of search number
        }
        else if (arr[Mid] < Numb)
        {
            Start = Mid + 1;
        }
        else if (arr[Mid] > Numb)
        {
            End = Mid - 1;
        }
    }
    return NOTFOUND;
}

/* *************************************************************************************
 * print Numb if found                                      							*
 * Parameters : arr and size of array                                     				*
 * Return   : E_state                                                           		*
 * **************************************************************************************/
E_state SearchForNumb(uint32_t *arr, uint8_t size, uint32_t Numb)
{
    uint8_t index;
    E_state state = ERROR;

    /* check if array sorted start search */
    if (IsArraySorted(arr, size))
    {
        index = binary_search(arr, size, Numb);
        if (index == NOTFOUND)
        {
            #if TEST
                printf("%d Not Found", Numb);
            #endif  
            return state;
        }
        else
        {
            #if TEST
            printf("Number Found in Index %d", index);
            #endif  
            state =E_OK;
            return state;
        }
    }
    else
    {
        Bubble_Sort(arr, size);
   
        index = binary_search(arr, size, Numb);

        /* check if search number found */
        if (index == NOTFOUND)
        {
            #if TEST
            printf("%d Not Found", Numb);
            #endif            
            return state;
        }
        else
        {
            #if TEST
            printf("Number Found in Index %d", index);
            #endif
            state =E_OK;
            return state;
        }
    }
}