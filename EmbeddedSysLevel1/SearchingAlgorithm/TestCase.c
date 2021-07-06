/* **************************************************************************************
 *  TestCases.c 															            *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "BinarySearch_int.h"


/****************************************************************************
 *  Please change MACRO TEST in BinarySearch_int.h to 0 before strt Testing *
 ****************************************************************************/

void Test_sorted(void)
{
    uint32_t arr[] = {1, 2, 3, 4};

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
    uint32_t arr[] = {1, 6, 3, 0};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);

    if (SearchForNumb(arr, size, 1))
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
    uint32_t arr[] = {1, 6, 3, 0};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);

    if (SearchForNumb(arr, size, 5) == NOTFOUND)
    {
        printf(" Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}

int main()
{
    Test_sorted();
    Test_Firstelement();
    Test_Notfound();
}