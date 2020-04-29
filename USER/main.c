#include "FreeRTOS.h"
#include "task.h"
#include "stm32f1xx_hal.h"

//start task
#define START_TASK_PRIO 1 //task prio
#define START_STK_SIZE  128 //task stack size
TaskHandle_t StartTask_Handler; 
extern void Start_task(void *pvParameters); //task func

void Stm32_Clock_Init(uint32_t plln,uint32_t pllm,uint32_t pllp,uint32_t pllq);

int main(void)
{    
    HAL_Init();                    	
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); 
    
    // set cpu clock here
	      
	xTaskCreate((TaskFunction_t)Start_task,
                (const char*   )"Start_task",
                (uint16_t      )START_STK_SIZE,
                (void*         )NULL,
                (UBaseType_t   )START_TASK_PRIO,
                &StartTask_Handler);
    vTaskStartScheduler(); //start OS 
    while(1){}
}

