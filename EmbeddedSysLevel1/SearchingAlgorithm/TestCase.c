/* **************************************************************************************
 *  TestCases.c 															            *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"


void Test_sorted(void)
{
    uint8_t arr[] = {1, 2, 3, 4};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);
    if (SearchForNumb(arr, size, 2))
    {
        printf(" Test Case 1 Passed\n");
    }
    else
    {
        printf(" Test Case 1 Failed\n");
    }
}

void Test_Firstelement(void)
{
    uint8_t arr[] = {5, 6, 8, 11};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);

    if (SearchForNumb(arr, size, 5))
    {
        printf(" Test Case 2 Passed\n");
    }
    else
    {
        printf(" Test Case 2 Failed\n");
    }
}

void Test_Notfound(void)
{
    uint8_t arr[] = {1, 6, 3, 0};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);

    if (SearchForNumb(arr, size, 0) == NOTFOUND)
    {
        printf(" Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
    printf(" Test Case 4 Passed\n");
}

int main()
{
    Test_sorted();
    Test_Firstelement();
    Test_Notfound();
}