
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "X_O_int.h"

static char arr[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/* 
    this function to display Border
 */
void Bordervoid(void)
{
    // system("cls");

    printf("    |     |    \n");
    printf("  %c |  %c  |  %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("____|_____|____\n");

    printf("  %c |  %c  |  %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("____|_____|____\n");
    printf("    |     |    \n");

    printf("  %c |  %c  |  %c\n", arr[2][0], arr[2][1], arr[2][2]);
    printf("    |     |    \n");
}   /* Bordervoid */

/* 
    this function to scan name from user 
*/
void Enter_voidUser(void)
{
    Player_t player1, player2;

    printf("Enter name of first player: ");
    scanf("%s", &player1.name);
    printf("\n");

    printf("Enter name of second player: ");
    scanf("%s", &player2.name);

}

void X_OGame_voidStart(void)
{
    Player_t player1, player2;
    char count = 0, Winner = 0;
    char *Ptr = arr;

    Bordervoid();
    printf("%s you will play with X symbol\n", player1.name);
    scanf("%d", &player1.key);

    /* 
        loop unitl some on wim the game and number of loop is < 9 
        9 is a number of try can happened
    */
    while ((Winner != 1) && (count < 9))
    {   
        /* check if count is even player1 is playing */
        if (count % 2 == 0)
        {
            // sign ='x';
        }
        if (*(Ptr + player1.key) == 'x' || *(Ptr + player1.key) == 'O')
        {
        }
    }
}

int main(void)
{
    char str[15];
    Player_t player1, player2;

    Enter_voidUser();

    // printf("Put the number of case\n");
    // scanf("%d", &player2.key);
    X_OGame_voidStart();
}