/**
 * @file OS.c
 * @author Elgharib
 * @brief Implement Non Preemptive Scheduler
 * @version 0.1
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "DataTypes.h"
#include "OS.h"





/**
 * @brief create task, add periodicity and state
 * 
 * @param task Pointer to function 
 * @param periodicity Periodicity of the Task
 * @param default_state Task state IDLE - READY - SUSPENDED
 * @return EN_ERRORSTATE_t E_ERROR - E_OK - E_NULL_POINTER - E_COUNT_LIMIT - E_TIME_LIMIT 
 */
EN_ERRORSTATE_t OS_TaskCreate(PFunc_t Task, uint8_t periodicity, EN_OSstate_t OSstate)
{

}

/**
 * @brief Manage state for The Task for every Tick Time
 * 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t OS_Task_Handler(void)
{

}


/**
 * @brief Execute Task that it is in Ready state
 * 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t OS_TaskExecution(void)
{

}
