

#ifndef X_O_INT_H
#define X_O_INT_H

#include <stdio.h>
#include "DataTypes.h"


typedef struct
{
    uint8_t name[7];
    uint8_t sign;
    uint16_t key;
} Player_t;






#define MAX_TRY         9
#define WIN             1
#define FIRST_PLYR      0
#define SECO_PLYR       1

/*******************************************************
 *                    Erorr Status                     *
********************************************************/
typedef char E_Status_t;
#define E_OK                        1
#define E_INVALID_POSITION          2
#define E_POSSITION_ALREADY_TAKEN   3
#define E_ERROR                     4      



/* Functions ProtoType */
void Bordervoid(void);
Player_t EnterPlayer1(void);
Player_t EnterPlayer2(void);
E_Status_t checkwin(void);
E_Status_t X_OGame_voidStart(void);



#endif  /* X_O_INT_H */