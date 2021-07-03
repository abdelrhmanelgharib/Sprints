#include <stdio.h>
#include <stdlib.h>

#include "X_O_int.h"

uint8_t pos[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/* Functions */

/* 
    this function to display Border
 */
void Bordervoid(void)
{
    system("cls");

    printf("    |     |    \n");
    printf("  %c |  %c  |  %c \n", pos[0], pos[1], pos[2]);
    printf("____|_____|____\n");

    printf("  %c |  %c  |  %c \n", pos[3], pos[4], pos[5]);
    printf("____|_____|____\n");
    printf("    |     |    \n");

    printf("  %c |  %c  |  %c\n", pos[6], pos[7], pos[8]);
    printf("    |     |    \n");
}

/* 
    this function to scan name from player 1
    and return name 
*/
Player_t EnterPlayer1(void)
{
    Player_t player1, player2;

    printf("Enter name of first player: ");
    scanf("%s", player1.name);

    return player1;
}

/* 
    this function to scan name from player 2
    and return name 
*/
Player_t EnterPlayer2(void)
{
    Player_t player2;
    printf("Enter name of second player: ");
    scanf("%s", player2.name);

    return player2;
}

/* 
    check for winner and Draw
 */
E_Status_t checkwin(void)
{
    if (pos[0] == pos[1] && pos[1] == pos[2])
    {
        return 1;
    }
    else if (pos[3] == pos[4] && pos[4] == pos[5])
    {
        return 1;
    }
    else if (pos[6] == pos[7] && pos[7] == pos[8])
    {
        return 1;
    }
    else if (pos[0] == pos[3] && pos[3] == pos[6])
    {
        return 1;
    }
    else if (pos[1] == pos[4] && pos[4] == pos[7])
    {
        return 1;
    }
    else if (pos[2] == pos[5] && pos[5] == pos[8])
    {
        return 1;
    }
    else if (pos[0] == pos[4] && pos[4] == pos[8])
    {
        return 1;
    }
    else if (pos[2] == pos[4] && pos[4] == pos[6])
    {
        return 1;
    }
    else if (pos[0] != '1' && pos[1] != '2' && pos[2] != '3' &&
             pos[3] != '4' && pos[4] != '5' && pos[5] != '6' && pos[6] != '7' && pos[7] != '8' && pos[8] != '9')
    {
        return -1;
    }
}

E_Status_t X_OGame_voidStart(void)
{
    E_Status_t status = E_OK;

    Player_t player1, player2;
    sint16_t count = 0, Winner = 0, flag = -1;

    player1 = EnterPlayer1();
    player2 = EnterPlayer2();
    
    Bordervoid();

    printf("\n");
    printf("%s you will play with X symbol\n", player1.name);
    printf("%s you will play with O symbol\n", player2.name);

    

    /* 
        loop until someone win the game or numbers of loop is < 9 
        9 is a number of try can happened
    */
    while ((Winner != 1) && (count < MAX_TRY))
    {
        /* check if count is even player1 is playing */
        if (count % 2 == FIRST_PLYR)
        {
            /*  */
            flag = 0;
            printf("%s ", player1.name);
            scanf("%hd", &player1.key);

            /* Assign symbol x for player 1 */
            player1.sign = 'X';

            /* check number that player enter is between 1 && 9 */
            if (player1.key < 1 || player1.key > 9)
            {
                printf("The Allowed Number is 1 to 9\n");
                status = E_INVALID_POSITION;
            }
            /* check if player enter number that user before */
            else if (pos[player1.key - 1] == 'X' || pos[player1.key - 1] == 'O')
            {
                printf("Position is Used\n");
                status = E_POSSITION_ALREADY_TAKEN;
            }
            else
            {
                /* update game with symbol in the postion that user enter */
                pos[player1.key - 1] = player1.sign;
                /* update counter by 1*/
                count++;
                /* display border each update */
                Bordervoid();
            }
        }
        /* check if count is odd player2 is playing */
        else if (count % 2 == SECO_PLYR)
        {
            flag = 1;
            printf("%s \n", player2.name);
            // printf("test2 %s \n", player1.name);
            scanf("%hd", &player2.key);
            // printf("test3 %s \n", player1.name);
            /* Assign sybol x for player 1 */
            player2.sign = 'O';

            /* check number that player enter is between 1 && 9 */
            if (player2.key < 1 || player2.key > 9)
            {
                printf("The Allowed Number is 1 to 9\n");
                status = E_INVALID_POSITION;
            }
            /* check if player enter number that user before */
            else if (pos[player2.key - 1] == 'X' || pos[player2.key - 1] == 'O')
            {
                printf("Position is Used\n");
                status = E_POSSITION_ALREADY_TAKEN;
            }
            else
            {
                /* update game with symbol in the postion that user enter */
                pos[player2.key - 1] = player2.sign;
                /* update counter by 1*/
                count++;
                /* display border each update */
                Bordervoid();
            }
        }

        /* check if any player is winner */
        Winner = checkwin();
        if (Winner == -1)
        {
            flag = -1;
            break;
        }
    }

    /* to know which player is playing now */
    if (flag == 0)
    {
        printf("%s is Winner\n", player1.name);
        printf("Good Luck %s Next Time", player2.name);
    }
    else if (flag == 1)
    {
        printf("%s is Winner\n", player2.name);
        printf("Good Luck %s Next Time", player1.name);
    }
    else
    {
        printf("Game is Draw\n");
    }

    return status;
}
