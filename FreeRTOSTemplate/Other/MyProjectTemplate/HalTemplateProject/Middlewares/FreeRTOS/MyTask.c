/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* ���Private variables----------------------------------------------------------*/
static TaskHandle_t xLED0Task_Handle = NULL;
static TaskHandle_t xLED1Task_Handle = NULL;

/* ����Private function prototypes------------------------------------------------*/
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
	* @brief  ����Ӧ������
	* @param  None
	* @retval None      
*/
static void AppTaskCreate()
{
	//LED0��������
	xTaskCreate(vLED0_Task,  //������
  "vLED0_Task",            //��������
  512,                     //����ջ��С����λword(4�ֽ�)
	NULL,                    //�������
	1,                       //�������ȼ�
	&xLED0Task_Handle);      //������
	
	//LED1��������
	xTaskCreate(vLED1_Task,  //������
  "vLED1_Task",            //��������
	512,                     //����ջ��С����λword(4�ֽ�)
	NULL,                    //�������
	2,                       //�������ȼ�
	&xLED1Task_Handle);      //������
	
}

/*
	* @name   vLED0_Task
	* @brief  LED1����
	* @param  None
	* @retval None      
*/
static void vLED0_Task(void *pvParameters)
{
	//vTaskSuspendAll();	//����������
	 while(1)
	 {
		
		 //HAL_UART_Transmit(&g_uart1_handle, (uint8_t *)"���Ĳ���!\r\n", 19 , 0xffff);
		 HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin); 
		 vTaskDelay(1000);
		 printf("���Ĳ���\r\n");
		//xTaskResumeAll();

	 } 
}

/*
	* @name   vLED1_Task
	* @brief  LED1����
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
