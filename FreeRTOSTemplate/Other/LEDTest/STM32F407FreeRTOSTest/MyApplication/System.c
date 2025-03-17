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
	* @brief  系统运行
	* @param  None
	* @retval None      
*/
static void Run()
{
	//初始化时，LED0，LED1均亮灯
	//HAL_GPIO_TogglePin -> 取反GPIO输出状态
	//HAL_GPIO_WritePin  -> 设置GPIO输出状态
	//                      GPIO_PIN_SET   -> 输出高电平，灯亮
	//                      GPIO_PIN_RESET -> 输出低电平
	
	//延时500ms，LE01，LED1均灭灯
	HAL_Delay(500);
	HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin); 
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	
	//延时500ms，LED0亮灯，LED1灭灯
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
	
	//延时500ms，LED1亮灯，LED0灭灯
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
	
	//延时500ms，LED0亮灯，LED1灭灯
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
	
	//延时500ms，LED0，LED1均亮灯
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
}

/*
	* @name   Error_Handler
	* @brief  系统错误处理
	* @param  None
	* @retval None      
*/
static void Error_Handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  函数参数错误处理
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
