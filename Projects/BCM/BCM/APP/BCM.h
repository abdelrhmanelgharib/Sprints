/*
 * BCM.h
 *
 *  Created on: Aug 26, 2021
 *      Author: Al Badr
 */

#ifndef APP_BCM_H_
#define APP_BCM_H_

#include "DataTypes.h"


typedef void(*BCM_UserNotifier)(void);

typedef struct BCM_cfg_t{
	uint8_t channel;
	uint8_t mode;
}gST_init_BCM_cfg_t;

typedef struct bcmTask_cfg{
	uint8_t *buffer;			/*data buffer to receive or send data*/
	uint16_t size;				/*size of buffer*/
	uint8_t channel;				/*uart spi i2c*/
	BCM_UserNotifier bcm_cbf;	/*notify function*/
	uint16_t check_sum;				/*size of buffer*/
	uint8_t mode;				/*send || recive*/
	uint8_t command;				/*send || recive*/

}gstr_BCM_Task_cfg_t;

typedef struct bcm_taskControlBlock{
	gstr_BCM_Task_cfg_t* bcmTask;/*user configuration*/
	uint8_t  u8_taskStatus;/*idle,sending,complete_sending*/
	uint8_t  u8_counter; /*counter to point to BCM_FRAM_POINTER to send 0 ,1 ,2 ,3 */
	uint8_t  u8_byteCounter; /*for each fram loop on its bytes*/
	uint8_t  u8_checkSum;/*hold sum of the bytes*/
	uint16_t u8_BCM_framSize;/*data size +2 bytes for numOfBytes + 1byte for BCM_ID +1 byte for checksum*/
	uint8_t  *apu8_BCM_Frame;
}bcm_taskControlBlock_t;




typedef enum
{
    BCM_IDLE,
    BCM_START,
	BCM_SENDING,
	BCM_COMPLETE
}EN_BCM_STATE_t;



EN_ERRORSTATE_t BCM_init(gST_init_BCM_cfg_t* bcm_cfg );
/*
*
*
*
*/
EN_ERRORSTATE_t BCM_setup(gstr_BCM_Task_cfg_t* str_BCM_TaskCfg);
/*
*
*
*
*/


EN_ERRORSTATE_t BCM_RX_dispatcher();
/*
*
*
*
*/
EN_ERRORSTATE_t BCM_TX_dispatcher();
EN_ERRORSTATE_t BCM_TX_Handller();
#endif /* APP_BCM_H_ */
