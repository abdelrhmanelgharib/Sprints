/* **************************************************************************************
 *  TestCases.c 															            *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "Stack_int.h"

void Testcase1(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{{}";

    uint8_t *Ptr = balancedParentheses(Testarr);

    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'N')
    {
        Estate = E_OK;
        printf("Test Case 1 Passed\n");
    }
    else
    {
        printf("Test Case 1 Failed\n");
    }
}

void Testcase2(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{}}";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'N')
    {
        Estate = E_OK;
        printf("Test Case 2 Passed\n");
    }
    else
    {
        printf("Test Case 2 Failed\n");
    }
}

void Testcase3(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "(({2*3}+5){8/3})";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  Balanced*/
    if (Ptr[0] == 'B')
    {
        Estate = E_OK;
        printf("Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}


void Testcase4(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{({2+10}}*11}})}";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'N')
    {
        Estate = E_OK;
        printf("Test Case 4 Passed\n");
    }
    else
    {
        printf("Test Case 4 Failed\n");
    }
}


int main()
{
    Testcase3();
    Testcase1();
    Testcase2();
    Testcase4();
}