/* **************************************************************************************
 *  BinarySearch.c    															        *
 *																						*
 *  Created on: July 2, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"

void Swap(uint8_t *Numb1, uint8_t *Numb2)
{
    uint8_t Temp;
    Temp = *Numb1;
    *Numb1 = *Numb2;
    *Numb2 = Temp;
}

uint8_t IsArraySorted(uint8_t *arr, uint8_t size)
{
    if (size == 1 || size == 0)
        return SORTED;

    if (arr[size - 1] < arr[size - 2])
        return NOTSORTED;

    return IsArraySorted(arr, size - 1);
}

/* Bubble Sorting Algorithm */
uint8_t *Bubble_Sort(uint8_t *arr, uint8_t size)
{
    uint8_t i, j, Flag = 0;

    uint8_t *PTemp = (uint8_t *)malloc(sizeof(uint8_t) * size);

    /* array start from 0 to size - 1*/
    size -= 1;

    /* Store array in Heap to return address */
    for (i = 0; i < size + 1; i++)
    {
        PTemp[i] = arr[i];
    }

    /* Outer loop for pass squence */
    for (i = 0; i < size; i++)
    {
        Flag = 0;
        /* internal loop to get larg element */
        for (j = 0; j < size - i; j++)
        {
            if (PTemp[j] > PTemp[j + 1])
            {
                /* swap the larg element with small */
                Swap(&PTemp[j], &PTemp[j + 1]);
                Flag = 1;
            }
        }
        /* check if the array is sorted */
        if (Flag == 0)
        {
            return PTemp;
        }
    }
}

sint8_t binary_search(uint8_t *arr, uint8_t size, uint32_t Numb)
{
    uint8_t Start, End, Mid;

    Start = 0;
    End = size - 1;
    if(arr[0] == Numb)
    {
        return 0;
    }
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
            Start = Mid - 1;
        }
    }
    return NOTFOUND;
}

sint8_t SearchForNumb(uint8_t *arr, uint8_t size, uint32_t Numb)
{
    sint16_t index;

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
        uint8_t *Ptr = Bubble_Sort(arr, size);

        index = binary_search(Ptr, size, Numb);

        /* check if search number found */
        if (index == NOTFOUND)
        {
            printf("%d Not Found", Numb);
            return NOTFOUND;
        }
        else
        {
            printf("Number Found in Index %d", index);
            free(Ptr);
            return FOUND;
        }
    }
}