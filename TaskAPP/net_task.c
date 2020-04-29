/*
** 网络等相关任务
*/
#include "FreeRTOS.h"
#include "task.h"

/**
 * 
 * @param pvParameters [任务参数]
 */
void NET_task(void *pvParameters)
{    
    
    while(1)
    {
        vTaskDelay(1000);
        //网络
    }
}
