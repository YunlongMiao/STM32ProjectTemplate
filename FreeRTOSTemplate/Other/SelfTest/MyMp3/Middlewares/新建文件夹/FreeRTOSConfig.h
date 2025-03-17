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
//Ӳ����ض���
/******************************************************************************/

//����CPU��ʱ��Ƶ�ʡ�
#define configCPU_CLOCK_HZ    ( ( unsigned long ) 168000000 )




/******************************************************************************/
/* Scheduling behaviour related definitions. **********************************/
//������ض���
/******************************************************************************/

//������FreeRTOS�δ�ʱ����Ƶ�ʡ���������Ϊ1000Hz����ζ��ÿ����1000���δ�
#define configTICK_RATE_HZ                         ( 1000U )

//����Ϊ1����ʾ������ռʽ���ȡ�����ζ�ŵ�һ���������ȼ�������׼��������ʱ������������ռ��ǰ���е������CPU��
#define configUSE_PREEMPTION                       1

#define configUSE_TIME_SLICING                     1

#define configUSE_PORT_OPTIMISED_TASK_SELECTION    0

#define configUSE_TICKLESS_IDLE                    1

//������FreeRTOS�п���ʹ�õ�����������ȼ���������������Ϊ5��
#define configMAX_PRIORITIES                       5U

//������ÿ���������Сջ��С�����ֽ�Ϊ��λ������������Ϊ128�ֽڡ�
#define configMINIMAL_STACK_SIZE                   128U

//�������������Ƶ���󳤶ȡ���������Ϊ4���ַ���
#define configMAX_TASK_NAME_LEN                    4U

//ϵͳʱ�ӽ��ļ���ʹ�� TickType_t �������Ͷ���ģ�������������
#define configTICK_TYPE_WIDTH_IN_BITS              TICK_TYPE_WIDTH_16_BITS

//����Ϊ1����ʾ�ڿ���������Ӧ�ý��������л����������������׼�������У���
#define configIDLE_SHOULD_YIELD                    1

#define configTASK_NOTIFICATION_ARRAY_ENTRIES      1U

//�����˶���ע��������������������ٶ��е�ʹ����������������ԡ�
#define configQUEUE_REGISTRY_SIZE                  0U

#define configENABLE_BACKWARD_COMPATIBILITY        1

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS    0

#define configSTACK_DEPTH_TYPE                     size_t

#define configMESSAGE_BUFFER_LENGTH_TYPE           size_t

#define configUSE_NEWLIB_REENTRANT                 0



/******************************************************************************/
/* Software timer related definitions. ****************************************/
//�����ʱ����ض���
/******************************************************************************/

//����Ϊ1����ʾ����FreeRTOS�������ʱ�����ܡ������ʱ����������û��Ӳ����ʱ�����û���Ҫ�����ӵĶ�ʱ��Ϊʱʹ�����ʵ�ֶ�ʱ����
#define configUSE_TIMERS                1

//�����������ʱ����������ȼ����������������Ϊ2����ζ�������ʱ����������ȼ�Ϊ2��
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1U )

//�����������ʱ�������ջ��ȡ�������������ΪconfigMINIMAL_STACK_SIZE����ζ�������ʱ�������ջ��С����Сջ��С��
#define configTIMER_TASK_STACK_DEPTH    configMINIMAL_STACK_SIZE

//�����������ʱ�����еĳ��ȡ�����ʱ������ʱ�����ǻᱻ��ӵ�����������Թ������ʱ�����������г���Ϊ10��ʾ��������10����ʱ���ȴ�����
#define configTIMER_QUEUE_LENGTH        10U





/******************************************************************************/
/* Memory allocation related definitions. *************************************/
//�ڴ������ض���
/******************************************************************************/

#define configSUPPORT_STATIC_ALLOCATION              1

#define configSUPPORT_DYNAMIC_ALLOCATION             1

//������FreeRTOS���õ��ܶѴ�С�����ֽ�Ϊ��λ������������Ϊ4KB��
#define configTOTAL_HEAP_SIZE                        4096U

#define configAPPLICATION_ALLOCATED_HEAP             1

#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP    0

#define configUSE_MINI_LIST_ITEM                     0



/******************************************************************************/
/* Interrupt nesting behaviour configuration. *********************************/
//�ж�Ƕ������
/******************************************************************************/

//�������ں�ʱ���жϺ��������� FreeRTOS �жϵ����ȼ���ͨ������Ϊ������ȼ�
#define configKERNEL_INTERRUPT_PRIORITY          255U

//�����˿��Ե��� FreeRTOS API ����������ж����ȼ������仰˵���������˿��԰�ȫ���� FreeRTOS �������жϵ�������ȼ���
#define configMAX_SYSCALL_INTERRUPT_PRIORITY     5U

#define configMAX_API_CALL_INTERRUPT_PRIORITY    0U



/******************************************************************************/
/* Hook and callback function related definitions. ****************************/
//���Ӻ����ͻص���������ض���
/******************************************************************************/

//����Ϊ0����ʾ�����ÿ��й��Ӻ��������й��Ӻ�����һ��������ϵͳ���ڿ���״̬ʱ���õĺ�����
#define configUSE_IDLE_HOOK                   0

//����Ϊ0����ʾ�����õδ�ʱ�����Ӻ��������������ÿ���δ�ʱ���ж�ʱ���ᱻ���á�
#define configUSE_TICK_HOOK                   0

//����Ϊ0����ʾ�������ڴ����ʧ�ܹ��Ӻ�������FreeRTOS�Ķ��ڴ�ľ�ʱ����������ᱻ���á�
#define configUSE_MALLOC_FAILED_HOOK          0

#define configUSE_DAEMON_TASK_STARTUP_HOOK    0

//������ջ����������͡���������Ϊ0��//������ĳ���ض����͵ļ�飨����ļ�鷽ʽ������FreeRTOS�汾���죩��
#define configCHECK_FOR_STACK_OVERFLOW        0



/******************************************************************************/
/* Run time and task stats gathering related definitions. *********************/
//������������ʱ����Ϣͳ����Ϊ��
/******************************************************************************/

//����Ϊ0����ʾ����������ʱͳ����Ϣ���������Ϊ0��FreeRTOS�����ռ�������������ʱ�����Ϣ��
#define configGENERATE_RUN_TIME_STATS           0

//����Ϊ1����ʾ���ø��ٹ��ܡ����������ռ��й�����ִ�С����в���������RTOS�����Ϣ��
#define configUSE_TRACE_FACILITY                1

#define configUSE_STATS_FORMATTING_FUNCTIONS    0

#define configKERNEL_PROVIDED_STATIC_MEMORY     1



/******************************************************************************/
/* Definitions that include or exclude functionality. *************************/
//����������ų�����
/******************************************************************************/

#define configUSE_TASK_NOTIFICATIONS           1

//����Ϊ1����ʾ���û�������mutex�����ܡ�
#define configUSE_MUTEXES                      1

//����Ϊ1����ʾ���õݹ黥�������ݹ黥��������ͬһ�������λ�ȡͬһ����������
#define configUSE_RECURSIVE_MUTEXES            1

//����Ϊ1����ʾ���ü����ź�����
#define configUSE_COUNTING_SEMAPHORES          1

#define configUSE_QUEUE_SETS                   1

//����Ϊ1����ʾ����Ӧ�ó��������ǩ���ܡ�
#define configUSE_APPLICATION_TASK_TAG         1

//����Ϊ1����ʾ����vTaskPrioritySet����������������ڶ�̬�ظı���������ȼ���
#define INCLUDE_vTaskPrioritySet               1

//����Ϊ1����ʾ����uxTaskPriorityGet����������������ڻ�ȡ����ĵ�ǰ���ȼ���
#define INCLUDE_uxTaskPriorityGet              1

////����Ϊ1����ʾ����vTaskDelete�����������������ɾ��һ�������ͷ���ռ�õ���Դ��
#define INCLUDE_vTaskDelete                    1

//����Ϊ1����ʾ����vTaskSuspend����������������ڹ���һ������ʹ�䲻�����У�ֱ�������ָ���
#define INCLUDE_vTaskSuspend                   1

#define INCLUDE_xResumeFromISR                 1

//����Ϊ1����ʾ����vTaskDelayUntil�����������������ʹ��ǰ�����ӳٵ�ָ���ľ���ʱ�䡣
#define INCLUDE_vTaskDelayUntil                1

//����Ϊ1����ʾ����vTaskDelay�����������������ʹ��ǰ�����ӳ�ָ����ʱ��Ƭ�����δ�������
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

//���
#define xPortPendSVHandler 		PendSV_Handler
#define xPortSysTickHandler		SysTick_Handler
#define xPortSVCHandler				SVC_Handler

#endif /* FREERTOS_CONFIG_H */





/*����Ϊ1����ʾ������ռʽ���ȡ�����ζ�ŵ�һ���������ȼ�������׼��������ʱ������������ռ��ǰ���е������CPU��*/
//#define configUSE_PREEMPTION			1
/*����Ϊ1����ʾ���ÿ��й��Ӻ��������й��Ӻ�����һ��������ϵͳ���ڿ���״̬ʱ���õĺ�����*/
//#define configUSE_IDLE_HOOK				1
/*����Ϊ1����ʾ���õδ�ʱ�����Ӻ��������������ÿ���δ�ʱ���ж�ʱ���ᱻ���á�*/
//#define configUSE_TICK_HOOK				1
/*����CPU��ʱ��Ƶ�ʡ�����ʹ����SystemCoreClock�꣬���������������ط�����ġ�*/
//#define configCPU_CLOCK_HZ				( SystemCoreClock )
/*������FreeRTOS�δ�ʱ����Ƶ�ʡ���������Ϊ1000Hz����ζ��ÿ����1000���δ�*/
//#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )
/*������FreeRTOS�п���ʹ�õ�����������ȼ���������������Ϊ5��*/
//#define configMAX_PRIORITIES			( 5 )
/*������ÿ���������Сջ��С�����ֽ�Ϊ��λ������������Ϊ130�ֽڡ�*/
//#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 130 )
/*������FreeRTOS���õ��ܶѴ�С�����ֽ�Ϊ��λ������������Ϊ75KB��*/	
//#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 75 * 1024 ) )
/*�������������Ƶ���󳤶ȡ���������Ϊ10���ַ���*/
//#define configMAX_TASK_NAME_LEN			( 10 )
/*����Ϊ1����ʾ���ø��ٹ��ܡ����������ռ��й�����ִ�С����в���������RTOS�����Ϣ��*/
//#define configUSE_TRACE_FACILITY		1
/*����Ϊ0����ʾʹ��32λ�δ���������������Ϊ1����ʹ��16λ�δ��������*/
//#define configUSE_16_BIT_TICKS			0
/*����Ϊ1����ʾ�ڿ���������Ӧ�ý��������л����������������׼�������У���*/
//#define configIDLE_SHOULD_YIELD			1
/*����Ϊ1����ʾ���û�������mutex�����ܡ�*/
//#define configUSE_MUTEXES				1
/*�����˶���ע��������������������ٶ��е�ʹ����������������ԡ�*/
//#define configQUEUE_REGISTRY_SIZE		8
/*������ջ����������͡���������Ϊ2��������ĳ���ض����͵ļ�飨����ļ�鷽ʽ������FreeRTOS�汾���죩��*/
//#define configCHECK_FOR_STACK_OVERFLOW	2
/*����Ϊ1����ʾ���õݹ黥�������ݹ黥��������ͬһ�������λ�ȡͬһ����������*/
//#define configUSE_RECURSIVE_MUTEXES		1
/*����Ϊ1����ʾ�����ڴ����ʧ�ܹ��Ӻ�������FreeRTOS�Ķ��ڴ�ľ�ʱ����������ᱻ���á�*/
//#define configUSE_MALLOC_FAILED_HOOK	1
/*����Ϊ0����ʾ������Ӧ�ó��������ǩ���ܡ�*/
//#define configUSE_APPLICATION_TASK_TAG	0
/*����Ϊ1����ʾ���ü����ź�����*/
//#define configUSE_COUNTING_SEMAPHORES	1
/*����Ϊ0����ʾ����������ʱͳ����Ϣ���������Ϊ1��FreeRTOS���ռ�������������ʱ�����Ϣ��*/
//#define configGENERATE_RUN_TIME_STATS	0
 
 
/* Software timer definitions. */
/*����Ϊ1����ʾ����FreeRTOS�������ʱ�����ܡ������ʱ����������û��Ӳ����ʱ�����û���Ҫ�����ӵĶ�ʱ��Ϊʱʹ�����ʵ�ֶ�ʱ����*/
//#define configUSE_TIMERS				1
/*�����������ʱ����������ȼ����������������Ϊ2����ζ�������ʱ����������ȼ�Ϊ2��*/
//#define configTIMER_TASK_PRIORITY		( 2 )
/*�����������ʱ�����еĳ��ȡ�����ʱ������ʱ�����ǻᱻ��ӵ�����������Թ������ʱ�����������г���Ϊ10��ʾ��������10����ʱ���ȴ�����*/
//#define configTIMER_QUEUE_LENGTH		10
/*�����������ʱ�������ջ��ȡ�������������ΪconfigMINIMAL_STACK_SIZE * 2����ζ�������ʱ�������ջ��С����Сջ��С��������*/
//#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 )
 
/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
/*����Ϊ1����ʾ����vTaskPrioritySet����������������ڶ�̬�ظı���������ȼ���*/
//#define INCLUDE_vTaskPrioritySet		1
/*����Ϊ1����ʾ����uxTaskPriorityGet����������������ڻ�ȡ����ĵ�ǰ���ȼ���*/
//#define INCLUDE_uxTaskPriorityGet		1
/*����Ϊ1����ʾ����vTaskDelete�����������������ɾ��һ�������ͷ���ռ�õ���Դ��*/
//#define INCLUDE_vTaskDelete				1
/*����Ϊ1����ʾ����vTaskCleanUpResources���������������������FreeRTOS�ں��ڲ�����Ҫʱռ�õ���Դ��ͨ������Ӧ�ó�������һ���������ʱ���á�*/
//#define INCLUDE_vTaskCleanUpResources	1
/*����Ϊ1����ʾ����vTaskSuspend����������������ڹ���һ������ʹ�䲻�����У�ֱ�������ָ���*/
//#define INCLUDE_vTaskSuspend			1
/*����Ϊ1����ʾ����vTaskDelayUntil�����������������ʹ��ǰ�����ӳٵ�ָ���ľ���ʱ�䡣*/
//#define INCLUDE_vTaskDelayUntil			1
/*����Ϊ1����ʾ����vTaskDelay�����������������ʹ��ǰ�����ӳ�ָ����ʱ��Ƭ�����δ�������*/
//#define INCLUDE_vTaskDelay				1

