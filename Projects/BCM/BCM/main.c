/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Al Badr
 */


#include "BCM.h"
#include "BCM_cfg.h"
#include "DIO_Interface.h"
void led(void){

DIO_voidSetPinValue(PORT_A,PIN0,HIGH);
}
char arr[1000];
int main(){

	DIO_voidSetPinDirection(PORT_A,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORT_D,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORT_D,PIN0,INPUT);

	gST_init_BCM_cfg_t data_init={BCM_UART_CHANAL,BCM_RECIVER};

	BCM_init(&data_init);


	gstr_BCM_Task_cfg_t data_setup={arr,6,	BCM_UART_CHANAL,led,5,BCM_RECIVER,1};

	BCM_setup(&data_setup);



	while (1){
		BCM_RX_dispatcher();
	}

}
