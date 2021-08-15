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
    uint32_t arr[256];

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
        
        SearchForNumb(arr, size, Numb);
    }
    else
    {
        printf("The Allowed Number from 1 to 255\n");
    }
}