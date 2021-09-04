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
#include "Timer.h"

/* array of struct hold the date of each task */
static ST_Task_t gTaskArr[NUMBER_OF_TASK];

static uint8_t gNoTaskCreated = 0;

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
    EN_ERRORSTATE_t state = (uint8_t)E_ERROR;

    /* Check the Function Pointer != NULL */
    if (Task == NULLPTR)
    {
        state = (uint8_t)E_NULL_POINTER;
    }
    /* Check the Task is within the limit of the task numbers */
    else if (gNoTaskCreated >= NUMBER_OF_TASK)
    {
        state = (uint8_t)E_COUNT_LIMIT;
    }
    /* Check the periodicity more than Hyper Period */
    else if (periodicity > HYPER_PERIOD)
    {
        state = (uint8_t)E_TIME_LIMIT;
    }
    else
    {
        /* Store data in struct */
        gTaskArr[gNoTaskCreated].Function = Task;
        gTaskArr[gNoTaskCreated].Task_Periodicity = periodicity;
        gTaskArr[gNoTaskCreated].Task_State = OSstate;
        /* Counter =1 Debend on Tick time = 1 Sec */
        gTaskArr[gNoTaskCreated].Task_Counter = 1;

        gNoTaskCreated++;

        state = E_OK;
    }
    return state;
}

/**
 * @brief Manage state for The Task for every Tick Time
 * 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t OS_Task_Handler(void)
{
    uint8_t Task_Number = 0;

    for (Task_Number = 0; Task_Number < gNoTaskCreated; Task_Number++)
    {
        if (gTaskArr[Task_Number].Task_State != SUSPENDED)
        {
            /* check if the task is ready */
            if (gTaskArr[Task_Number].Task_Counter >= gTaskArr[Task_Number].Task_Periodicity)
            {
                gTaskArr[Task_Number].Task_State = READY;
                /* Reset Counter to Initial */
                gTaskArr[Task_Number].Task_Counter = 1;
            }
            else
            {
                gTaskArr[Task_Number].Task_Counter++;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* GCM */
}

/**
 * @brief Execute Task that it is in Ready state
 * 
 * @return EN_ERRORSTATE_t 
 */
EN_ERRORSTATE_t OS_TaskExecution(void)
{
    uint8_t Task_Number = 0;

    for (Task_Number = 0; Task_Number < gNoTaskCreated; Task_Number++)
    {
        /* Check For task is ready */
        if (gTaskArr[Task_Number].Task_State == READY)
        {
            gTaskArr[Task_Number].Function();
            gTaskArr[Task_Number].Task_State = IDLE;
        }
        else
        {
            /* Do Nothing */
        }
    }
}