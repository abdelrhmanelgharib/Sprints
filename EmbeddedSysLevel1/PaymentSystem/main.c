/* **************************************************************************************
 *  main.c          															        *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/
#include "PaymentSystem_int.h"

int main()
{
    ST_transaction card;
    ReadCardData(&card);

    printf("%s",card.cardHolderData.cardHolderName);
}