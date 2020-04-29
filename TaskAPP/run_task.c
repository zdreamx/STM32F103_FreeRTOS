#include "led.h"
#include "FreeRTOS.h"
#include "task.h"
/**
 * task configure
 */

extern TaskHandle_t StartTask_Handler;

#define LED_TASK_PRIO 2 //task prio
#define LED_STK_SIZE  64 //task stack size 0.5
TaskHandle_t LEDTask_Handler; 
void Led_task(void *p_arg); //task func


/**
 * start task
 * @param pvParameters [para]
 */
void Start_task(void *pvParameters)
{
    taskENTER_CRITICAL();

    xTaskCreate((TaskFunction_t  )Led_task,		//创建指示灯任务
                (const char*     )"Led_task",
                (uint16_t        )LED_STK_SIZE,
                (void*           )NULL,
                (UBaseType_t     )LED_TASK_PRIO,
                &LEDTask_Handler);
                                                                                               
    vTaskDelete(StartTask_Handler);//delete start tassk

    taskEXIT_CRITICAL();
    
}



