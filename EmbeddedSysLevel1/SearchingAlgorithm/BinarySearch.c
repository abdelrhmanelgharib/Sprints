/* **************************************************************************************
 *  BinarySearch.c    															        *
 *																						*
 *  Created on: July 2, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"

void Swap(uint32_t *Numb1, uint32_t *Numb2)
{
    uint32_t Temp;
    Temp = *Numb1;
    *Numb1 = *Numb2;
    *Numb2 = Temp;
}

uint8_t IsArraySorted(uint32_t *arr, uint8_t size)
{
    if (size == 1 || size == 0)
        return SORTED;

    if (arr[size - 1] < arr[size - 2])
        return NOTSORTED;

    return IsArraySorted(arr, size - 1);
}

/* Bubble Sorting Algorithm */
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

sint8_t SearchForNumb(uint32_t *arr, uint8_t size, uint32_t Numb)
{
    uint8_t index;

    /* check if array sorted start search */
    if (IsArraySorted(arr, size))
    {
        index = binary_search(arr, size, Numb);
        if (index == NOTFOUND)
        {
            printf("%d Not Found", Numb);
            return NOTFOUND;
        }
        else
        {
            printf("Number Found in Index %d", index);
            return FOUND;
        }
    }
    else
    {
        Bubble_Sort(arr, size);
   
        index = binary_search(arr, size, Numb);

        /* check if search number found */
        if (index == NOTFOUND)
        {
            printf("%d Not Found", Numb);
            return NOTFOUND;
        }
        else
        {
            printf("Number Found in Index %d", index);
            return FOUND;
        }
    }
}