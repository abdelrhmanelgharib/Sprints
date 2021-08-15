/*
 *  Author: El-Gharib
 *  Created On: 1/7/2021
 *  Version: 1
 */

#include "Stack_int.h"
#include <string.h>

typedef struct Node
{
    uint8_t Data;
    struct Node *Next;
} Node_t;

Node_t *Top;

/*************** Global Array******************/
// static uint8_t *STR_NBAL = "Not Balanced";
// static uint8_t *STR_BALA = "Balanced";
/**********************************************/

void Stack_Initilaize(void)
{

    Top = NULL;
}

uint8_t Stack_IsEmpty(void)
{
    if (Top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t Push(sint8_t Data)
{
    E_State_t ErrorState = E_OK;

    uint8_t size;
    Node_t *Temp = NULL;
    Temp = (Node_t *)malloc(sizeof(Node_t));
    if (Temp == NULL)
    {
        printf("No heap memory to allocate your element\n\n");
        ErrorState = Error;
    }
    else
    {
        Temp->Data = Data;
        Temp->Next = Top;
        Top = Temp;
        // printf("Pushing is done successfully\n\n");
    }
    return ErrorState;
}

uint8_t pull(sint8_t *DataPtr)
{
    E_State_t ErrorState = E_OK;

    Node_t *Temp = NULL;

    if (DataPtr == NULL)
    {
        ErrorState = Error;
    }
    else if (Stack_IsEmpty())
    {
        // printf("Stack is empty, popping operation will result in underflow\n\n");
        ErrorState = E_EMPTY;
    }
    else
    {
        *DataPtr = Top->Data;
        Temp = Top;
        Top = Top->Next;
        free(Temp);
        // printf("Popping is done successfully\n\n");
    }

    return ErrorState;
}

void printStack(void)
{
    Node_t *Ptr = Top;
    if (Stack_IsEmpty())
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        while (Ptr != NULL)
        {
            printf("%c\t", Ptr->Data);
            Ptr = Ptr->Next;
        }
        printf("\n");
    }
}

/*  
    this function to check brakets in the string are balanced or not
    Take string
    return address of the string 
*/
uint8_t *balancedParentheses(uint8_t *expression)
{
    uint8_t *STR_NBAL = "Not Balanced";
    uint8_t *STR_BALA = "Balanced";

    uint8_t i, data, PushPopCount = 0;
    uint8_t ErrorState, flag = 2;

    /* Return number of letters in var size */
    uint8_t size = strlen(expression);

    /* check if system is Balance or Not Balanced */
    for (i = 0; i < size; i++)
    {
        /* push all open Brakets */
        if (expression[i] == '{' || expression[i] == '(')
        {
            Push(expression[i]);

            /* increment count by 1 */
            PushPopCount++;
        }
        /* check if pushed Brackets is balanced with Close Brakets */
        else if (expression[i] == '}' || expression[i] == ')')
        {
            ErrorState = pull(&data);

            /* decrement count by 1 */
            PushPopCount--;

            /* Error state */
            if (ErrorState == E_OK)
            {
                if (data == '{')
                {
                    if (expression[i] == ')')
                    {
                        flag = NOTBALANCED;
                        break;
                    }
                    else if (expression[i] == '}')
                    {
                        flag = BALANCED;
                    }
                }
                else if (data == '(')
                {
                    if (expression[i] == '}')
                    {
                        flag = NOTBALANCED;
                        break;
                    }
                    else if (expression[i] == ')')
                    {
                        flag = BALANCED;
                    }
                }
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    
    /* for the case if right brakets is more than left */
    /* check if stack is not empty so string is not balanced */
    if (!Stack_IsEmpty())
    {
        flag = NOTBALANCED;
    }
    /* for the case if Left brakets is more than right*/
    else if (PushPopCount != 0)
    {
        flag = NOTBALANCED;
    }

    /* return string depened on flag state: balanced or not */
    if (flag == NOTBALANCED)
    {
        return STR_NBAL;
    }
    else if (flag == BALANCED)
    {
        return STR_BALA;
    }
} /* balancedParentheses */