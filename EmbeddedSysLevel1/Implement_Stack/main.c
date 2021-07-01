/*
 *  Author: El-Gharib
 *  Created On: 1/7/2021
 *  Version: 1
 */

#include "Stack_int.h"
#include <string.h>


uint8_t* balancedParentheses(uint8_t* expression)
{

}

void main()
{
    char Input;
    uint8_t Check;
    sint8_t PushVal[4], PopVal, PeekVal, StackSize;

    Stack_Initilaize();

    printf("Please Enter The Value To Push: ");
    scanf("%s", PushVal);
    uint8_t size = strlen(PushVal);
    for (uint8_t i = 0; i < size; i++)
    {
        Stack_Push(PushVal[i]);
    }


    Stack_Display();
    // while (1)
    // {
    //     printf("Press 1 to Push\nPress 2 to Pop\nPress 3 to Display\nPress 4 to quit\n\n");
    //     scanf(" %c", &Input);

    //     switch (Input)
    //     {
    //     case '1':
    //         printf("Please Enter The Value To Push: ");
    //         scanf("%d", &PushVal);
    //         Stack_Push(PushVal);
    //         break;
    //     case '2':
    //         Check = Stack_Pop(&PopVal);
    //         if (Check == E_OK)
    //         {
    //             printf("The Popped value is %d\n", PopVal);
    //         }
    //         else
    //         {
    //             /* do nothing */
    //         }
    //         break;
    //     case '3':
    //         Stack_Display();
    //         break;

    //     default:
    //         printf("wrong option please try again\n");
    //         break;
    //     }
    //     if (Input == '4')
    //     {
    //         break;
    //     }
    // }
}