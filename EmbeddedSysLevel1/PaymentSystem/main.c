/* **************************************************************************************
 *  main.c          															        *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/
#include "PaymentSystem_int.h"


int main()
{

    ST_transaction system;
    EN_transStat_t check;
    uint8_t contne;

    while (1)
    {
        check = PaymentSystem(&system);
        if (check == APPROVED)
        {
            printf("The Transaction is APPROVED.\n");
            printf("Do you want to continue (y/n)?\n");
            fflush(stdin);
            scanf("%c", &contne);
        }
        else
        {
            printf("The Transaction is DECLINED.\n");
            printf("Do you want to continue (y/n)?\n");
            fflush(stdin);
            scanf("%c", &contne);
        }
        while (contne != 'y' && contne != 'n')
        {
            fflush(stdin);
            printf("Wrong Enter.\n");
            printf("Do you want to continue (y/n)?\n");
            scanf("%c", &contne);
        }
        if (contne == 'n')
        {
            break;
        }
        contne = 0;
    }
}