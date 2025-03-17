/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* 句柄Private variables----------------------------------------------------------*/
static TaskHandle_t xLED0Task_Handle = NULL;
static TaskHandle_t xLED1Task_Handle = NULL;

/* 声明Private function prototypes------------------------------------------------*/
static void AppTaskCreate(void);

static void vLED0_Task(void *pvParameters);
static void vLED1_Task(void *pvParameters);

/* Public variables-----------------------------------------------------------*/
MyTask_t MyTask = 
{
	AppTaskCreate
};      

/*
	* @name   AppTaskCreate
	* @brief  创建应用任务
	* @param  None
	* @retval None      
*/
static void AppTaskCreate()
{
	//LED0测试任务
	xTaskCreate(vLED0_Task,  //任务函数
  "vLED0_Task",            //任务名称
  512,                     //任务栈大小，单位word(4字节)
	NULL,                    //任务参数
	1,                       //任务优先级
	&xLED0Task_Handle);      //任务句柄
	
	//LED1测试任务
	xTaskCreate(vLED1_Task,  //任务函数
  "vLED1_Task",            //任务名称
	512,                     //任务栈大小，单位word(4字节)
	NULL,                    //任务参数
	2,                       //任务优先级
	&xLED1Task_Handle);      //任务句柄
	
}

/*
	* @name   vLED0_Task
	* @brief  LED1任务
	* @param  None
	* @retval None      
*/
static void vLED0_Task(void *pvParameters)
{
	//vTaskSuspendAll();	//开启调度锁
	 while(1)
	 {
		
		 //HAL_UART_Transmit(&g_uart1_handle, (uint8_t *)"中文测试!\r\n", 19 , 0xffff);
		 HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin); 
		 vTaskDelay(1000);
		 printf("中文测试\r\n");
		//xTaskResumeAll();

	 } 
}

/*
	* @name   vLED1_Task
	* @brief  LED1任务
	* @param  None
	* @retval None      
*/
static void vLED1_Task(void *pvParameters)
{
	 while(1)
	 {
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
		vTaskDelay(1000);
	 }
}


/********************************************************
  End Of File
********************************************************/
