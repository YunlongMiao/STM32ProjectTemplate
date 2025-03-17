/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Run(void); 
static void Error_Handler(void);
static void Assert_Failed(void);
	
/* Public variables-----------------------------------------------------------*/
System_t System = 
{
	Run,
	Error_Handler,
	Assert_Failed
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run
	* @brief  ϵͳ����
	* @param  None
	* @retval None      
*/
static void Run()
{
	//��ʼ��ʱ��LED0��LED1������
	//HAL_GPIO_TogglePin -> ȡ��GPIO���״̬
	//HAL_GPIO_WritePin  -> ����GPIO���״̬
	//                      GPIO_PIN_SET   -> ����ߵ�ƽ������
	//                      GPIO_PIN_RESET -> ����͵�ƽ
	
	//��ʱ500ms��LE01��LED1�����
	HAL_Delay(500);
	HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin); 
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	
	//��ʱ500ms��LED0���ƣ�LED1���
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
	
	//��ʱ500ms��LED1���ƣ�LED0���
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
	
	//��ʱ500ms��LED0���ƣ�LED1���
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
	
	//��ʱ500ms��LED0��LED1������
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
}

/*
	* @name   Error_Handler
	* @brief  ϵͳ������
	* @param  None
	* @retval None      
*/
static void Error_Handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  ��������������
	* @param  None
	* @retval None      
*/
static void Assert_Failed()
{
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
/********************************************************
  End Of File
********************************************************/
