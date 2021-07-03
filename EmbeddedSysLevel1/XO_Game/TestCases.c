/* **************************************************************************************
 *  TestCases.c 															            *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/
#include <stdio.h>
#include "X_O_int.h"

extern char pos[9];
/* this function test first column for player1 */

E_Status_t Test_Ply1Column1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'X';
    pos[3] = 'X';
    pos[6] = 'X';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* TesWinHorizontal */

E_Status_t Test_Ply1Column3(void)
{
    E_Status_t E_State = E_ERROR;

    pos[2] = 'X';
    pos[5] = 'X';
    pos[8] = 'X';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply1Column3 */

E_Status_t Test_Ply1Row1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'X';
    pos[1] = 'X';
    pos[2] = 'X';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply1Row1 */

E_Status_t Test_Ply1Diagonal1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'X';
    pos[4] = 'X';
    pos[8] = 'X';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply1Diagonal1 */

/* ********************* */

E_Status_t Test_Ply2Column1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'O';
    pos[3] = 'O';
    pos[6] = 'O';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply2Column1 */

E_Status_t Test_Ply2Column2(void)
{
    E_Status_t E_State = E_ERROR;

    pos[1] = 'O';
    pos[4] = 'O';
    pos[7] = 'O';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply2Column2 */

E_Status_t Test_Ply2Row1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'O';
    pos[1] = 'O';
    pos[2] = 'O';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply2Row1 */

E_Status_t Test_Ply2Diagonal1(void)
{
    E_Status_t E_State = E_ERROR;

    pos[0] = 'O';
    pos[4] = 'O';
    pos[8] = 'O';

    if (checkwin())
    {
        E_State = E_OK;
    }
    return E_State;
} /* Test_Ply2Diagonal1 */

int main()
{
    E_Status_t E_state;

    E_state = Test_Ply1Column1();
    if (E_state == E_OK)
    {
        printf("Test 1 Passed\n");
    }
    else
    {
        printf("Test 1 Fallied\n");
    }

    E_state = Test_Ply1Column3();
    if (E_state == E_OK)
    {
        printf("Test 3 Passed\n");
    }
    else
    {
        printf("Test 3 Fallied\n");
    }

    E_state = Test_Ply1Row1();
    if (E_state == E_OK)
    {
        printf("Test 4 Passed\n");
    }
    else
    {
        printf("Test 4 Fallied\n");
    }

    E_state = Test_Ply2Column1();
    if (E_state == E_OK)
    {
        printf("Test 5 Passed\n");
    }
    else
    {
        printf("Test 5 Fallied\n");
    }

    E_state = Test_Ply2Column2();
    if (E_state == E_OK)
    {
        printf("Test 6 Passed\n");
    }
    else
    {
        printf("Test 6 Fallied\n");
    }

    E_state = Test_Ply2Column2();
    if (E_state == E_OK)
    {
        printf("Test 7 Passed\n");
    }
    else
    {
        printf("Test 7 Fallied\n");
    }

    E_state = Test_Ply1Diagonal1();
    if (E_state == E_OK)
    {
        printf("Test 9 Passed\n");
    }
    else
    {
        printf("Test 9 Fallied\n");
    }

    E_state = Test_Ply2Diagonal1();
    if (E_state == E_OK)
    {
        printf("Test 11 Passed\n");
    }
    else
    {
        printf("Test 11 Fallied\n");
    }
}