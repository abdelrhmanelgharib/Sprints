/* **************************************************************************************
 *  PaymentSystem.c    															        *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#include "PaymentSystem_int.h"

ST_accountBalance_t ServerData[10] =
    {
        {10.12, "123123456"},
        {100.00, "123456789"},
        {6000.00, "234567891"},
        {500.00, "258649173"},
        {1500.12, "456789123"},
        {.55, "456789321"},
        {3250.25, "567891234"},
        {2100.00, "654823719"},
        {1.00, "793148625"},
        {0.00, "971362485"},
};

void ReadCardData(ST_transaction *card)
{
    printf("Please Enter Card Data\n");
    printf("Please Enter the Card Holder Name:\n");
    fflush(stdin);
    gets(card->cardHolderData.cardHolderName);
    printf("Please Enter the Primary Account Number:\n");
    fflush(stdin);
    gets(card->cardHolderData.primaryAccountNumber);
    printf("Please card Expiry Date:\n");
    scanf("%s", card->cardHolderData.cardExpirationDate);
}

void ReadTerminalData(ST_transaction *Terminal)
{
    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%f", &Terminal->transData.transAmount);
    printf("Please Enter transaction Date:\n");
    fflush(stdin);
    gets(Terminal->transData.transactionDate);
}

EN_transStat_t CheckExpired(ST_transaction *Expired)
{
    uint8_t i = strlen(Expired->cardHolderData.cardExpirationDate);
    uint8_t j = strlen(Expired->transData.transactionDate);

    /*              07/30                                               05/06/2029 */
    /*              07/22                                               05/06/2021 */
    /*              07/29                                               05/06/2030 */
    /*              07/22                                               05/06/2022 */
    /*              10/22                                               05/06/2022 */
    /*              07/29                                               05/06/2020 */
    /*              11/22                                               05/05/2023 */

    // printf("Test0\n%c\n", Expired->cardHolderData.cardExpirationDate[i]);
    /* check for last element of the year */
    if (Expired->cardHolderData.cardExpirationDate[i - 1] > Expired->transData.transactionDate[j - 1])
    {
        /* check last element -1 of the year */
        if (Expired->cardHolderData.cardExpirationDate[i - 2] >= Expired->transData.transactionDate[j - 2])
        {
            // printf("Test1\n");
            return APPROVED;
        }
        else
        {
            return DECLINED;
        }
    }
    else if(Expired->cardHolderData.cardExpirationDate[i - 1] < Expired->transData.transactionDate[j - 1] &&  Expired->cardHolderData.cardExpirationDate[i - 2] < Expired->transData.transactionDate[j - 2])
    {
        return DECLINED;
    }
    /* check last element -1 of the year */
    else if (Expired->cardHolderData.cardExpirationDate[i - 2] > Expired->transData.transactionDate[j - 2])
    {
        // printf("Test2\n%c\n", Expired->cardHolderData.cardExpirationDate[i - 2]);
        return APPROVED;
    }
    /* check for month */
    else if (Expired->cardHolderData.cardExpirationDate[i - 4] > Expired->transData.transactionDate[j - 6])
    {
        // printf("Test3\n");
        return APPROVED;
    }
    /* check for month */
    else if (Expired->cardHolderData.cardExpirationDate[i - 5] > Expired->transData.transactionDate[j - 7])
    {
        // printf("Test14\n");
        return APPROVED;
    }
}

/*  check card number is valid 
    return index of card number in the array
    or NotFound */
sint8_t CheckCardNumb(ST_transaction *AccountNumb)
{
    sint8_t i, result = -1;
    for (i = 0; i < NOELEMTARR; i++)
    {
        result = strcmp(AccountNumb->cardHolderData.primaryAccountNumber, ServerData[i].primaryAccountNumber);
        if (result == 0)
        {
            return i;
        }
    }
    return NOTFOUND;
}

EN_transStat_t CheckBalance(ST_transaction *Balance, sint8_t *index)
{
    *index = CheckCardNumb(Balance);
    if (*index == NOTFOUND)
    {
        return DECLINED;
    }
    else
    {
        /* Max Amount can Withdrawal Daily */
        Balance->transData.maxTransAmount = 5000.00;
        if (Balance->transData.transAmount <= Balance->transData.maxTransAmount)
        {
            if (Balance->transData.transAmount <= ServerData[*index].balance)
            {
                return APPROVED;
            }
        }
    }
}

void UpdateServer(ST_transaction *server, sint8_t index)
{
    ServerData[index].balance -= server->transData.transAmount;
}

EN_transStat_t PaymentSystem(ST_transaction *system)
{
    sint8_t Expired, Balance, index;

    ReadCardData(system);
    ReadTerminalData(system);
    Expired = CheckExpired(system);
    if (Expired == APPROVED)
    {
        Balance = CheckBalance(system, &index);
        if (Balance == APPROVED)
        {
            UpdateServer(system, index);
            return APPROVED;
        }
        else
        {
            return DECLINED;
        }
    }
    else
    {
        return DECLINED;
    }
}