/*
 *  Author: El-Gharib
 *  Created On: 30/1/2021
 *  Version: 1
 */


#include "LinkedList.h"

void main()
{
    char Input;
    u8 Check;
    s32 PushVal, PopVal, PeekVal, StackSize;

    Stack_Initilaize();

    while(1)
    {
        printf("Press 1 to Push\nPress 2 to Pop\nPress 3 to Display\nPress 4 to Peek\nPress 5 to get size\nPress 6 to quit\n\n");
        scanf(" %c",&Input);

        switch (Input)
        {
        case '1':
            printf("Please Enter The Value To Push: ");
            scanf("%d",&PushVal);
            Stack_Push(PushVal);
            break;
        case '2':
            Check = Stack_Pop(&PopVal);
            if (Check == No_Error)
            {
                printf("The Popped value is %d\n",PopVal);
            }
            else
            {
                /* do nothing */
            }
            break;   
        case '3':
            Stack_Display();
            break;    
        case '4':
            Check = Stack_Peek(&PeekVal);
            if ( Check == No_Error )
            {
                printf("The Peek is %d\n",PeekVal);
            }
            break;
        case '5':
            StackSize = Stack_GetSize();
            printf("The stack size is %d\n\n",StackSize);
            break;
        case '6': break;    

        default:
            printf("wrong option please try again\n");
            break;
        }
        if (Input == '6')
        {
            break;
        }
    }
    
}