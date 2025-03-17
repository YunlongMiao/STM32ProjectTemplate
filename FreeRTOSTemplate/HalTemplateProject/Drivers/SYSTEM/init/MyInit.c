/* Includes ------------------------------------------------------------------*/
//#include "MyApplication.h"
#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "MyInit.h"
#include "gGpio.h"
/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Peripheral_Set(void); 

/* Public variables-----------------------------------------------------------*/
MyInit_t MyInit = 
{
	Peripheral_Set
};

/* Private function prototypes------------------------------------------------*/      


/*
	* @name   Peripheral_Set
	* @brief  外设设置
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
//	System.sys_stm32_clock_init(336, 8, 2, 7); 	// 设置时钟,168Mhz
	System.SystemClock_Config();
//	Delay.delay_init(168);								//延时初始化
	Delay.SystemCoreClock = 168000000;								//延时初始化
	MX_GPIO_Init();															//GPIO初始化
	usart_init(115200);													//
}

/********************************************************
  End Of File
********************************************************/
