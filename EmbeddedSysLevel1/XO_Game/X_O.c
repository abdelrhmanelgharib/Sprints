#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "X_O_int.h"

static char pos[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/* 
    this function to display Border
 */
void Bordervoid(void)
{
    // system("cls");

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

char checkwin(void)
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
}

void X_OGame_voidStart(void)
{
    Player_t player1, player2;
    char count = 0, Winner = 0, flag = -1;

    player1 = EnterPlayer1();
    player2 = EnterPlayer2();

    printf("\n");
    printf("%s you will play with X symbol\n", player1.name);
    printf("%s you will play with O symbol\n", player2.name);

    Bordervoid();

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
            printf("test %s ", player1.name);
            scanf("%d", &player1.key);

            /* Assign sybol x for player 1 */
            player1.sign = 'X';

            /* check number that player enter is between 1 && 9 */
            if (player1.key < 1 || player1.key > 9)
            {
                printf("The Allowed Number is 1 to 9\n");
            }
            /* check if player enter number that user before */
            else if (pos[player1.key - 1] == 'X' || pos[player1.key - 1] == 'O')
            {
                printf("Position is Used\n");
            }
            else
            {
                /* update game with symbol in the postion that user enter */
                pos[player1.key - 1] = player1.sign;
                /* update counter by 1*/
                count++;
            }
        }
        /* check if count is odd player2 is playing */
        else if (count % 2 == SECO_PLYR)
        {
            flag = 1;
            printf("%s ", player2.name);
            scanf("%d", &player2.key);

            /* Assign sybol x for player 1 */
            player2.sign = 'O';

            /* check number that player enter is between 1 && 9 */
            if (player2.key < 1 || player2.key > 9)
            {
                printf("The Allowed Number is 1 to 9\n");
            }
            /* check if player enter number that user before */
            else if (pos[player2.key - 1] == 'X' || pos[player2.key - 1] == 'O')
            {
                printf("Position is Used\n");
            }
            else
            {
                /* update game with symbol in the postion that user enter */
                pos[player2.key - 1] = player2.sign;
                /* update counter by 1*/
                count++;
            }
        }

        /* display border each update */
        Bordervoid();
        /* check if any player is winner */
        Winner = checkwin();
    }

    /* to know which player is playing now */
    if (flag == 0)
    {
        printf("Winner is %s\n", player1.name);
        printf("Good Luck %s Next Time", player2.name);
    }
    else if (flag == 1)
    {
        printf("Winner is %s\n", player2.name);
        printf("Good Luck %s Next Time", player1.name);
    }
}



int main(void)
{
    X_OGame_voidStart();
}