/* **************************************************************************************
 *  PaymentSystem_int.h    														        *
 *																						*
 *  Created on: July 3, 2021															*
 *      Author: Elgharib																*
 ****************************************************************************************/

#ifndef PAYMENTSYSTEM_INT_
#define PAYMENTSYSTEM_INT_
#include <stdio.h>
#include <string.h>
#include "DataTypes.h"

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
} ST_cardData_t;

typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
} ST_terminalData_t;

typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
} EN_transStat_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
} ST_transaction;

typedef struct ST_accountBalance_t
{
    float balance;
    uint8_t primaryAccountNumber[20];
} ST_accountBalance_t;


/*************Functions ProtoType****************/

void ReadCardData(ST_transaction *card);
void ReadTerminalData(ST_transaction *Terminal);
EN_transStat_t CheckExpired(ST_transaction *Expired);
sint8_t CheckCardNumb(ST_transaction *AccountNumb);
EN_transStat_t CheckBalance(ST_transaction *Balance, sint8_t* index);
void UpdateServer(ST_transaction *server, sint8_t index);
EN_transStat_t PaymentSystem(ST_transaction *system);




#define NOELEMTARR  10
#define NOTFOUND    -1

#endif /* PAYMENTSYSTEM_INT_ */