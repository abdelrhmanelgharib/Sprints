/*
 * BCM.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Al Badr
 */


#include "DataTypes.h"
#include "BCM_cfg.h"
#include "BCM.h"
#include "DIO_Interface.h"
#include "UART_int.h"
#include "SPI_Interface.h"
#include "I2C_Interface.h"

bcm_taskControlBlock_t* pstr_currentTask;
int j=0;
/*channel mode (uart spi -i2c)(send-mode)*/
EN_ERRORSTATE_t BCM_init(gST_init_BCM_cfg_t* bcm_cfg )
{

	switch(bcm_cfg->channel){

	case BCM_UART_CHANAL:
		UART_ENInit();
		switch(bcm_cfg->mode){
		case BCM_SENDER:
		//UART_TxInit();
		UART_voidTXInterruptEnable();
		break;
		case BCM_RECIVER:
		//UART_RxInit();
		UART_voidRXInterruptEnable();
			break;
	}
		break;
	case BCM_SPI_CHANAL:
		switch(bcm_cfg->mode){
		case BCM_SENDER:
		//SPI_VidInitMaster();
		break;
		case BCM_RECIVER:
		//SPI_VidInitSlave();
			break;
	}

		break;
	case BCM_I2C_CHANAL:
		switch(bcm_cfg->mode){
		case BCM_SENDER:
	//	I2C_MasterInit()();
		break;
		case BCM_RECIVER:
		//I2C_SlaveInit();
			break;
	}
		break;

	}
}
EN_ERRORSTATE_t BCM_setup(gstr_BCM_Task_cfg_t* str_BCM_TaskCfg)
{
switch(str_BCM_TaskCfg->channel){

	case BCM_UART_CHANAL:
		switch(str_BCM_TaskCfg->mode){
		case BCM_SENDER:
			pstr_currentTask->apu8_BCM_Frame = str_BCM_TaskCfg->buffer;
			pstr_currentTask->u8_byteCounter=  str_BCM_TaskCfg->size;
			pstr_currentTask->bcmTask->bcm_cbf=		   str_BCM_TaskCfg->bcm_cbf;
			pstr_currentTask->u8_taskStatus=BCM_START;

			break;
		case BCM_RECIVER:
			pstr_currentTask->apu8_BCM_Frame= str_BCM_TaskCfg->buffer;
			pstr_currentTask->u8_byteCounter=  str_BCM_TaskCfg->size;
			pstr_currentTask->bcmTask->bcm_cbf=		   str_BCM_TaskCfg->bcm_cbf;
			pstr_currentTask->u8_taskStatus=BCM_START;

			break;

	}
		break;
//	case BCM_SPI_CHANAL:
//		switch(str_BCM_TaskCfg->mode){
//		case BCM_SENDER:
//		SPI_VidInitMaster();
//		break;
//		case BCM_RECIVER:
//		SPI_VidInitSlave();
//			break;


		break;
	case BCM_I2C_CHANAL:
		switch(str_BCM_TaskCfg->mode){
		case BCM_SENDER:
	//	I2C_MasterInit()();
		break;
		case BCM_RECIVER:
		//I2C_SlaveInit();
			break;
	}
		break;

	}


}

EN_ERRORSTATE_t BCM_RX_dispatcher(){

	if ((pstr_currentTask->u8_taskStatus==BCM_START)){
		pstr_currentTask->apu8_BCM_Frame[j]=UART_u8ReceiveNoBlock();
	pstr_currentTask->u8_taskStatus=BCM_SENDING;
	//in isr 		pstr_currentTask->u8_taskStatus==BCM_START;
	j++;
	}


}

EN_ERRORSTATE_t BCM_TX_dispatcher(){
	//static int i=0;
		if ((pstr_currentTask->u8_taskStatus==BCM_START)&&(j<pstr_currentTask->u8_byteCounter)){
			UART_ENSendNoBlock(pstr_currentTask->apu8_BCM_Frame[j]);
		pstr_currentTask->u8_taskStatus=BCM_SENDING;
		//in isr 		pstr_currentTask->u8_taskStatus==BCM_START;
		j++;
		}
//	if (j==pstr_currentTask->u8_byteCounter){
//		DIO_voidSetPinValue(PORT_B,PIN1,HIGH);
//		//pstr_currentTask->bcmTask->bcm_cbf();
//		pstr_currentTask->u8_taskStatus=BCM_IDLE;
//		//j=0;
//	}
}
EN_ERRORSTATE_t BCM_TX_Handller(){

	if (j<pstr_currentTask->u8_byteCounter){
			pstr_currentTask->u8_taskStatus=BCM_START;
	}
	//DIO_voidSetPinValue(PORT_B,PIN1,LOW);
	if (j>=pstr_currentTask->u8_byteCounter){
		//pstr_currentTask->bcmTask->bcm_cbf();
		pstr_currentTask->u8_taskStatus=BCM_IDLE;
		//j=0;
	}

}
EN_ERRORSTATE_t BCM_RX_Handller(){



	pstr_currentTask->u8_taskStatus=BCM_START;
	//DIO_voidSetPinValue(PORT_B,PIN1,LOW);
	if (j>=pstr_currentTask->u8_byteCounter){
		DIO_voidSetPinValue(PORT_A,PIN0,HIGH);

		//pstr_currentTask->bcmTask->bcm_cbf();
		pstr_currentTask->u8_taskStatus=BCM_IDLE;
		//j=0;
	}



}
