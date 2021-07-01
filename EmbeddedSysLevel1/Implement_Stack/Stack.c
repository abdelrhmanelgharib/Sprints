/*
 *  Author: El-Gharib
 *  Created On: 1/7/2021
 *  Version: 1
 */

#include "Stack_int.h"
#include <string.h>

typedef struct Node
{
    sint32_t Data;
    struct Node *Next;
} Node_t;

Node_t *Top;

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

uint8_t Stack_Push(sint8_t Data)
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
        printf("Pushing is done successfully\n\n");
    }
    return ErrorState;
}

uint8_t Stack_Pop(sint8_t *DataPtr)
{
    E_State_t ErrorState = E_OK;

    Node_t *Temp = NULL;

    if (DataPtr == NULL)
    {
        ErrorState = Error;
    }
    else if (Stack_IsEmpty())
    {
        printf("Stack is empty, popping operation will result in underflow\n\n");
        ErrorState = E_EMPTY;
    }
    else
    {
        *DataPtr = Top->Data;
        Temp = Top;
        Top = Top->Next;
        free(Temp);
        printf("Popping is done successfully\n\n");
    }

    return ErrorState;
}

void Stack_Display(void)
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