/**
 * @file TrafficLight_int.h
 * @author Elgharib
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 */


#ifndef TRAFFICLIGHT_INT_H_
#define TRAFFICLIGHT_INT_H_




#define START   1;
#define STOP    2;
#define WAIT    3;

#define STRING_EQUL 0


/**
 * @brief Compare two string
 * 
 * @param Str1 first string
 * @param Str2 second string
 * @return uint8_t string is equal = 0 or not equal =1 
 */
uint8_t String_u8Comp(uint8_t *Str1, uint8_t *Str2);


/**
 * @brief initialized LED, UART And DIo
 * 
 */
void TrafficLight_voidInit(void);



/**
 * @brief update system while sending command "start - wait - stop"
 * 
 */
void TrafficLight_voidStart(void);


#endif  /* TRAFFICLIGHT_INT_H_ */