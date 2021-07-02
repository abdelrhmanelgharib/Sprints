/*
 *  Author: El-Gharib
 *  Created On: 1/7/2021
 *  Version: 1
 */

#include "Stack_int.h"

void main()
{
    char Input;
    uint8_t Check, i = 0;
    sint8_t PushVal[20];

    Stack_Initilaize();

    printf("Please Enter The string To Push: ");
    scanf("%s", PushVal);

    uint8_t *arr = balancedParentheses(PushVal);

    /* Display the output of balancedParentheses */
    printf("%s", arr);
}
