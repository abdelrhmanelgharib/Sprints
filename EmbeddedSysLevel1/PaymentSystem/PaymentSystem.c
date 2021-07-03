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

void ReadCardData(ST_transaction* card)
{
    // ST_cardData_t card;

    printf("Please Enter Card Data\n");
    printf("Please Enter the Card Holder Name:\n");
    scanf("%s", card->cardHolderData.cardHolderName);
    printf("Please Enter the Primary Account Number:\n");
    scanf("%s", card->cardHolderData.primaryAccountNumber);
    printf("Please card Expiry Date:\n");
    scanf("%s", card->cardHolderData.cardExpirationDate);
}

void ReadTerminalData(ST_transaction* Terminal)
{
    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%f", Terminal->transData.transAmount);
    printf("Please Enter transaction Date:");
    scanf("%s", Terminal->transData.transactionDate);
}

