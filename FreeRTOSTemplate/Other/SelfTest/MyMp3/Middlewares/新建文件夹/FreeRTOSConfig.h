/*
 * FreeRTOS Kernel V11.1.0
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H



/******************************************************************************/
/* Hardware description related definitions. **********************************/
//硬件相关定义
/******************************************************************************/

//定义CPU的时钟频率。
#define configCPU_CLOCK_HZ    ( ( unsigned long ) 168000000 )




/******************************************************************************/
/* Scheduling behaviour related definitions. **********************************/
//调度相关定义
/******************************************************************************/

//定义了FreeRTOS滴答定时器的频率。这里设置为1000Hz，意味着每秒有1000个滴答。
#define configTICK_RATE_HZ                         ( 1000U )

//设置为1，表示启用抢占式调度。这意味着当一个更高优先级的任务准备好运行时，它会立即抢占当前运行的任务的CPU。
#define configUSE_PREEMPTION                       1

#define configUSE_TIME_SLICING                     1

#define configUSE_PORT_OPTIMISED_TASK_SELECTION    0

#define configUSE_TICKLESS_IDLE                    1

//定义了FreeRTOS中可以使用的最大任务优先级数量。这里设置为5。
#define configMAX_PRIORITIES                       5U

//定义了每个任务的最小栈大小（以字节为单位）。这里设置为128字节。
#define configMINIMAL_STACK_SIZE                   128U

//定义了任务名称的最大长度。这里设置为4个字符。
#define configMAX_TASK_NAME_LEN                    4U

//系统时钟节拍计数使用 TickType_t 数据类型定义的，基本数据类型
#define configTICK_TYPE_WIDTH_IN_BITS              TICK_TYPE_WIDTH_16_BITS

//设置为1，表示在空闲任务中应该进行任务切换（如果有其他任务准备好运行）。
#define configIDLE_SHOULD_YIELD                    1

#define configTASK_NOTIFICATION_ARRAY_ENTRIES      1U

//定义了队列注册表的项数。这允许你跟踪队列的使用情况，并帮助调试。
#define configQUEUE_REGISTRY_SIZE                  0U

#define configENABLE_BACKWARD_COMPATIBILITY        1

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS    0

#define configSTACK_DEPTH_TYPE                     size_t

#define configMESSAGE_BUFFER_LENGTH_TYPE           size_t

#define configUSE_NEWLIB_REENTRANT                 0



/******************************************************************************/
/* Software timer related definitions. ****************************************/
//软件定时器相关定义
/******************************************************************************/

//设置为1，表示启用FreeRTOS的软件定时器功能。软件定时器允许你在没有硬件定时器可用或想要更复杂的定时行为时使用软件实现定时器。
#define configUSE_TIMERS                1

//定义了软件定时器任务的优先级。在这里，它被设置为2，意味着软件定时器任务的优先级为2。
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1U )

//定义了软件定时器任务的栈深度。这里它被设置为configMINIMAL_STACK_SIZE，意味着软件定时器任务的栈大小是最小栈大小。
#define configTIMER_TASK_STACK_DEPTH    configMINIMAL_STACK_SIZE

//定义了软件定时器队列的长度。当定时器到期时，它们会被添加到这个队列中以供软件定时器任务处理。队列长度为10表示最多可以有10个定时器等待处理。
#define configTIMER_QUEUE_LENGTH        10U





/******************************************************************************/
/* Memory allocation related definitions. *************************************/
//内存分配相关定义
/******************************************************************************/

#define configSUPPORT_STATIC_ALLOCATION              1

#define configSUPPORT_DYNAMIC_ALLOCATION             1

//定义了FreeRTOS可用的总堆大小（以字节为单位）。这里设置为4KB。
#define configTOTAL_HEAP_SIZE                        4096U

#define configAPPLICATION_ALLOCATED_HEAP             1

#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP    0

#define configUSE_MINI_LIST_ITEM                     0



/******************************************************************************/
/* Interrupt nesting behaviour configuration. *********************************/
//中断嵌套配置
/******************************************************************************/

//定义了内核时钟中断和其他核心 FreeRTOS 中断的优先级，通常设置为最低优先级
#define configKERNEL_INTERRUPT_PRIORITY          255U

//定义了可以调用 FreeRTOS API 函数的最高中断优先级。换句话说，它设置了可以安全调用 FreeRTOS 函数的中断的最大优先级。
#define configMAX_SYSCALL_INTERRUPT_PRIORITY     5U

#define configMAX_API_CALL_INTERRUPT_PRIORITY    0U



/******************************************************************************/
/* Hook and callback function related definitions. ****************************/
//钩子函数和回调函数的相关定义
/******************************************************************************/

//设置为0，表示不启用空闲钩子函数。空闲钩子函数是一个可以在系统处于空闲状态时调用的函数。
#define configUSE_IDLE_HOOK                   0

//设置为0，表示不启用滴答定时器钩子函数。这个函数在每个滴答定时器中断时都会被调用。
#define configUSE_TICK_HOOK                   0

//设置为0，表示不启用内存分配失败钩子函数。当FreeRTOS的堆内存耗尽时，这个函数会被调用。
#define configUSE_MALLOC_FAILED_HOOK          0

#define configUSE_DAEMON_TASK_STARTUP_HOOK    0

//定义了栈溢出检查的类型。这里设置为0，//可能是某种特定类型的检查（具体的检查方式可能因FreeRTOS版本而异）。
#define configCHECK_FOR_STACK_OVERFLOW        0



/******************************************************************************/
/* Run time and task stats gathering related definitions. *********************/
//定义任务运行时的信息统计行为。
/******************************************************************************/

//设置为0，表示不生成运行时统计信息。如果设置为0，FreeRTOS不会收集关于任务运行时间的信息。
#define configGENERATE_RUN_TIME_STATS           0

//设置为1，表示启用跟踪功能。这允许你收集有关任务执行、队列操作和其他RTOS活动的信息。
#define configUSE_TRACE_FACILITY                1

#define configUSE_STATS_FORMATTING_FUNCTIONS    0

#define configKERNEL_PROVIDED_STATIC_MEMORY     1



/******************************************************************************/
/* Definitions that include or exclude functionality. *************************/
//定义包含或排除功能
/******************************************************************************/

#define configUSE_TASK_NOTIFICATIONS           1

//设置为1，表示启用互斥量（mutex）功能。
#define configUSE_MUTEXES                      1

//设置为1，表示启用递归互斥量。递归互斥量允许同一个任务多次获取同一个互斥量。
#define configUSE_RECURSIVE_MUTEXES            1

//设置为1，表示启用计数信号量。
#define configUSE_COUNTING_SEMAPHORES          1

#define configUSE_QUEUE_SETS                   1

//设置为1，表示启用应用程序任务标签功能。
#define configUSE_APPLICATION_TASK_TAG         1

//设置为1，表示包含vTaskPrioritySet函数。这个函数用于动态地改变任务的优先级。
#define INCLUDE_vTaskPrioritySet               1

//设置为1，表示包含uxTaskPriorityGet函数。这个函数用于获取任务的当前优先级。
#define INCLUDE_uxTaskPriorityGet              1

////设置为1，表示包含vTaskDelete函数。这个函数用于删除一个任务，释放其占用的资源。
#define INCLUDE_vTaskDelete                    1

//设置为1，表示包含vTaskSuspend函数。这个函数用于挂起一个任务，使其不再运行，直到它被恢复。
#define INCLUDE_vTaskSuspend                   1

#define INCLUDE_xResumeFromISR                 1

//设置为1，表示包含vTaskDelayUntil函数。这个函数用于使当前任务延迟到指定的绝对时间。
#define INCLUDE_vTaskDelayUntil                1

//设置为1，表示包含vTaskDelay函数。这个函数用于使当前任务延迟指定的时间片数（滴答数）。
#define INCLUDE_vTaskDelay                     1

#define INCLUDE_xTaskGetSchedulerState         1

#define INCLUDE_xTaskGetCurrentTaskHandle      1	//

#define INCLUDE_uxTaskGetStackHighWaterMark    1

#define INCLUDE_xTaskGetIdleTaskHandle         1

#define INCLUDE_eTaskGetState                  1

#define INCLUDE_xEventGroupSetBitFromISR       1

#define INCLUDE_xTimerPendFunctionCall         1

#define INCLUDE_xTaskAbortDelay                1

#define INCLUDE_xTaskGetHandle                 1

#define INCLUDE_xTaskResumeFromISR             1

//添加
#define xPortPendSVHandler 		PendSV_Handler
#define xPortSysTickHandler		SysTick_Handler
#define xPortSVCHandler				SVC_Handler

#endif /* FREERTOS_CONFIG_H */





/*设置为1，表示启用抢占式调度。这意味着当一个更高优先级的任务准备好运行时，它会立即抢占当前运行的任务的CPU。*/
//#define configUSE_PREEMPTION			1
/*设置为1，表示启用空闲钩子函数。空闲钩子函数是一个可以在系统处于空闲状态时调用的函数。*/
//#define configUSE_IDLE_HOOK				1
/*设置为1，表示启用滴答定时器钩子函数。这个函数在每个滴答定时器中断时都会被调用。*/
//#define configUSE_TICK_HOOK				1
/*定义CPU的时钟频率。这里使用了SystemCoreClock宏，它可能是在其他地方定义的。*/
//#define configCPU_CLOCK_HZ				( SystemCoreClock )
/*定义了FreeRTOS滴答定时器的频率。这里设置为1000Hz，意味着每秒有1000个滴答。*/
//#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )
/*定义了FreeRTOS中可以使用的最大任务优先级数量。这里设置为5。*/
//#define configMAX_PRIORITIES			( 5 )
/*定义了每个任务的最小栈大小（以字节为单位）。这里设置为130字节。*/
//#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 130 )
/*定义了FreeRTOS可用的总堆大小（以字节为单位）。这里设置为75KB。*/	
//#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 75 * 1024 ) )
/*定义了任务名称的最大长度。这里设置为10个字符。*/
//#define configMAX_TASK_NAME_LEN			( 10 )
/*设置为1，表示启用跟踪功能。这允许你收集有关任务执行、队列操作和其他RTOS活动的信息。*/
//#define configUSE_TRACE_FACILITY		1
/*设置为0，表示使用32位滴答计数器。如果设置为1，则使用16位滴答计数器。*/
//#define configUSE_16_BIT_TICKS			0
/*设置为1，表示在空闲任务中应该进行任务切换（如果有其他任务准备好运行）。*/
//#define configIDLE_SHOULD_YIELD			1
/*设置为1，表示启用互斥量（mutex）功能。*/
//#define configUSE_MUTEXES				1
/*定义了队列注册表的项数。这允许你跟踪队列的使用情况，并帮助调试。*/
//#define configQUEUE_REGISTRY_SIZE		8
/*定义了栈溢出检查的类型。这里设置为2，可能是某种特定类型的检查（具体的检查方式可能因FreeRTOS版本而异）。*/
//#define configCHECK_FOR_STACK_OVERFLOW	2
/*设置为1，表示启用递归互斥量。递归互斥量允许同一个任务多次获取同一个互斥量。*/
//#define configUSE_RECURSIVE_MUTEXES		1
/*设置为1，表示启用内存分配失败钩子函数。当FreeRTOS的堆内存耗尽时，这个函数会被调用。*/
//#define configUSE_MALLOC_FAILED_HOOK	1
/*设置为0，表示不启用应用程序任务标签功能。*/
//#define configUSE_APPLICATION_TASK_TAG	0
/*设置为1，表示启用计数信号量。*/
//#define configUSE_COUNTING_SEMAPHORES	1
/*设置为0，表示不生成运行时统计信息。如果设置为1，FreeRTOS会收集关于任务运行时间的信息。*/
//#define configGENERATE_RUN_TIME_STATS	0
 
 
/* Software timer definitions. */
/*设置为1，表示启用FreeRTOS的软件定时器功能。软件定时器允许你在没有硬件定时器可用或想要更复杂的定时行为时使用软件实现定时器。*/
//#define configUSE_TIMERS				1
/*定义了软件定时器任务的优先级。在这里，它被设置为2，意味着软件定时器任务的优先级为2。*/
//#define configTIMER_TASK_PRIORITY		( 2 )
/*定义了软件定时器队列的长度。当定时器到期时，它们会被添加到这个队列中以供软件定时器任务处理。队列长度为10表示最多可以有10个定时器等待处理。*/
//#define configTIMER_QUEUE_LENGTH		10
/*定义了软件定时器任务的栈深度。这里它被设置为configMINIMAL_STACK_SIZE * 2，意味着软件定时器任务的栈大小是最小栈大小的两倍。*/
//#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 )
 
/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
/*设置为1，表示包含vTaskPrioritySet函数。这个函数用于动态地改变任务的优先级。*/
//#define INCLUDE_vTaskPrioritySet		1
/*设置为1，表示包含uxTaskPriorityGet函数。这个函数用于获取任务的当前优先级。*/
//#define INCLUDE_uxTaskPriorityGet		1
/*设置为1，表示包含vTaskDelete函数。这个函数用于删除一个任务，释放其占用的资源。*/
//#define INCLUDE_vTaskDelete				1
/*设置为1，表示包含vTaskCleanUpResources函数。这个函数用于清理FreeRTOS内核在不再需要时占用的资源。通常，在应用程序的最后一个任务结束时调用。*/
//#define INCLUDE_vTaskCleanUpResources	1
/*设置为1，表示包含vTaskSuspend函数。这个函数用于挂起一个任务，使其不再运行，直到它被恢复。*/
//#define INCLUDE_vTaskSuspend			1
/*设置为1，表示包含vTaskDelayUntil函数。这个函数用于使当前任务延迟到指定的绝对时间。*/
//#define INCLUDE_vTaskDelayUntil			1
/*设置为1，表示包含vTaskDelay函数。这个函数用于使当前任务延迟指定的时间片数（滴答数）。*/
//#define INCLUDE_vTaskDelay				1

