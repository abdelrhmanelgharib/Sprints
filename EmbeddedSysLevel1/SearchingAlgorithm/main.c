/* **************************************************************************************
 *  main.c																		        *
 *																						*
 *  Created on: July 2, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"

int main(void)
{
    uint8_t size, i;
    uint32_t Numb;
    uint8_t index;

    uint8_t arr[256];

    printf("Max Number of Element is 255 \n");
    printf("Please Enter Number of Element: ");

    scanf("%d", &size);

    if (size <= 255 && size > 0)
    {
        printf("Enter %d Elements: \n", size);
        for (i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Search For: ");
        scanf("%d", &Numb);

        /* check if array sorted start search */
        if (IsArraySorted(arr, size))
        {
            index = binary_search(arr, size, Numb);
            printf("Number Found in Index %d", index);
        }
        else
        {
            uint8_t *Ptr = Bubble_Sort(arr, size);

            index = binary_search(Ptr, size, Numb);

            /* check if search number found */
            if (index == NOTFOUND)
            {
                printf("%d Not Found", Numb);
            }
            else
            {
                printf("Number Found in Index %d", index);
                free(Ptr);
            }
        }
    }
    else
    {
        printf("The Allowed Number from 1 to 255\n");
    }
}