/*
    FreeRTOS V10.3.1 - Copyright (C) 2018 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

/* Normal assert() semantics without relying on the provision of an assert.h header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }	

/***************************************************************************************************************/
/*                                        FreeRTOS base config                                              */
/***************************************************************************************************************/
#define configUSE_PREEMPTION					1                       
#define configUSE_TIME_SLICING					1						
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1                       
                                                                        
                                                                       
#define configUSE_TICKLESS_IDLE					0                       
#define configUSE_QUEUE_SETS					1                       
#define configCPU_CLOCK_HZ						(SystemCoreClock)       
#define configTICK_RATE_HZ						(1000)                  
#define configMAX_PRIORITIES					(32)                    
#define configMINIMAL_STACK_SIZE				((unsigned short)130)   
#define configMAX_TASK_NAME_LEN					(16)                    

#define configUSE_16_BIT_TICKS					0                       
                                                                        
#define configIDLE_SHOULD_YIELD					1                       
#define configUSE_TASK_NOTIFICATIONS            1                       
#define configUSE_MUTEXES						1                       
#define configQUEUE_REGISTRY_SIZE				8                       
                                                                        
#define configCHECK_FOR_STACK_OVERFLOW			0                       
                                                                        
                                                                        
#define configUSE_RECURSIVE_MUTEXES				1                       
#define configUSE_MALLOC_FAILED_HOOK			0                       
#define configUSE_APPLICATION_TASK_TAG			0                       
#define configUSE_COUNTING_SEMAPHORES			1                       

/***************************************************************************************************************/
/*                                FreeRTOS dynamic ram                                                */
/***************************************************************************************************************/
#define configSUPPORT_DYNAMIC_ALLOCATION        1                       
#define configTOTAL_HEAP_SIZE					((size_t)(5*1024))     //all heap size

/***************************************************************************************************************/
/*                                FreeRTOS HOOK Config                                      */
/***************************************************************************************************************/
#define configUSE_IDLE_HOOK						0                       
#define configUSE_TICK_HOOK						0                       

/***************************************************************************************************************/
/*                                FreeRTOS run time and stat config                               */
/***************************************************************************************************************/
#define configGENERATE_RUN_TIME_STATS	        0                       
                                                                        
/***************************************************************************************************************/
/*                                FreeRTOS Co-routine definitions                                                 */
/***************************************************************************************************************/
#define configUSE_CO_ROUTINES 			        0                       
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )                   

/***************************************************************************************************************/
/*                                FreeRTOS Software timer Config                                            */
/***************************************************************************************************************/
#define configUSE_TIMERS				        1                               
#define configTIMER_TASK_PRIORITY		        (configMAX_PRIORITIES-1)        
#define configTIMER_QUEUE_LENGTH		        5                               
#define configTIMER_TASK_STACK_DEPTH	        (configMINIMAL_STACK_SIZE*2)    

/***************************************************************************************************************/
/*                                FreeRTOS API Config                                                          */
/* Set the following definitions to 1 to include the API function, or zero to exclude the API function.        */
/***************************************************************************************************************/
#define INCLUDE_xTaskGetSchedulerState          1                       
#define INCLUDE_vTaskPrioritySet		        1
#define INCLUDE_uxTaskPriorityGet		        1
#define INCLUDE_vTaskDelete				        1
#define INCLUDE_vTaskCleanUpResources	        1
#define INCLUDE_vTaskSuspend			        1
#define INCLUDE_vTaskDelayUntil			        1
#define INCLUDE_vTaskDelay				        1
#define INCLUDE_eTaskGetState			        1
#define INCLUDE_xTimerPendFunctionCall	        1
#define INCLUDE_uxTaskGetStackHighWaterMark     1 

/***************************************************************************************************************/
/*                                FreeRTOS Cortex-M NVIC specific definitions                                                  */
/***************************************************************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15                      //中断最低优先级
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5                       //系统可管理的最高中断优先级
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/***************************************************************************************************************/
/*                          Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
**                          standard names.                                     
**************************************************************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler


#endif /* FREERTOS_CONFIG_H */

