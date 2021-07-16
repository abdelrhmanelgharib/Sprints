/**
 * @file TWI_private.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-16
 * 
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


/********************************************************************
 *                      MASTER Transmit                             *
*********************************************************************/
#define START_CONDITION                  0x08
#define REPEATED_START                   0x10
#define SLV_W_TRANSMIT_ACK_RECEIVD       0x18
#define SLV_W_TRANSMIT_NOTACK_RECEIVD    0x20
#define DATA_M_TRANSMIT_ACK_RECEIVD      0x28

/********************************************************************
 *                      MASTER Receive                              *
*********************************************************************/
#define SLA_R_ACK_RECEIVD                0x40
#define SLA_R_NOTACK_RECEIVD             0x48
#define DATA_M_RECEIVE_ACK_SEND          0x48



/********************************************************************
 *                      SLAVE Receive                              *
*********************************************************************/
#define SLA_W_RECEIVD_ACK_SEND           0x60
#define DATA_S_RECEIVD_ACK_SEND          0x80
#define STOP_OR_REPEATED_CONDITION       0xA0


/********************************************************************
 *                      SLAVE Transmit                              *
*********************************************************************/
#define SLA_R_Received_ACK_SEND          0xA8          
#define DATA_S_TRANSMIT_ACK_SEND         0xB0          




/* SCALER_1 - SCALER_4 - SCALER_16 - SCALER_64 */
#define SCALER_1                         0
#define SCALER_4                         1
#define SCALER_16                        2
#define SCALER_64                        3

#endif  /* TWI_PRIVATE_H_ */