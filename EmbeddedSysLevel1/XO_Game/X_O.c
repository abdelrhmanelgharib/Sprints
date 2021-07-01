#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#include "X_O_int.h"

static char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/* 
    this function to display Border
 */
void Bordervoid(void)
{
    // system("cls");

    printf("    |     |    \n");
    printf("  %c |  %c  |  %c \n", arr[0], arr[1], arr[2]);
    printf("____|_____|____\n");

    printf("  %c |  %c  |  %c \n", arr[3], arr[4], arr[5]);
    printf("____|_____|____\n");
    printf("    |     |    \n");

    printf("  %c |  %c  |  %c\n", arr[6], arr[7], arr[8]);
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
    scanf("%s", &player1.name);
    // gets(player1.name);
    printf("\n");
    printf("Enter name of second player: ");
    scanf("%s", player2.name);

    return player1;
}

/* 
    this function to scan name from player 2
    and return name 
*/
Player_t EnterPlayer2(void)
{
    Player_t player2;
    printf("\n");
    printf("Enter name of second player: ");
    scanf("%s", player2.name);

    return player2;
}


void X_OGame_voidStart(void)
{
    Player_t player1, player2;
    char count = 0, Winner = 0;
    char *Ptr = arr;

    Bordervoid();
    player1 = EnterPlayer1();
    printf("the no %s you will play with X symbol\n", player1.name);
    player2 = EnterPlayer2();
    printf("the no %s you will play with X symbol\n", player2.name);

    /* 
        loop unitl some on wim the game and number of loop is < 9 
        9 is a number of try can happened
    */
    while ((Winner != 1) && (count < 9))
    {
        /* check if count is even player1 is playing */
        if (count % 2 == 0)
        {
            printf("%s", player1.name);
            scanf("%d", player1.key);
            player1.sign = 'X';
            if (player1.key < 1 || player1.key > 9)
            {
                printf("The Allowed Number is 1 to 9\n");
            }
            else if (arr[player1.key] == 'X' || arr[player1.key] == 'O')
            {
                printf("Position is Used\n");
            }
            arr[player1.key - 1] = player1.sign;
        }
        else if (count % 2 == 1) /* Player 2 */
        {
            printf("%s", player2.name);
            scanf("%d", &player2.key);
            player2.sign = 'O';
            if (player2.key  < 1 || player2.key> 9)
            {
                printf("The Allowed Number is 1 to 9\n");
            }
            else if (arr[player2.key] == 'X' || arr[player2.key] == 'O')
            {
                printf("Position is Used\n");
            }
            arr[player2.key - 1] = player2.sign;
        }
        count++;
    Bordervoid();
    }
}

int main(void)
{
    char str[15];
    Player_t player1, player2;

    // Enter_voidUser();
    // printf("the no %s you will play with X symbol\n", player1.name);

    // printf("Put the number of case\n");
    // scanf("%d", &player2.key);
    X_OGame_voidStart();
}