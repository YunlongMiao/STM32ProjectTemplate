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
	* @brief  ��������
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
//	System.sys_stm32_clock_init(336, 8, 2, 7); 	// ����ʱ��,168Mhz
	System.SystemClock_Config();
//	Delay.delay_init(168);								//��ʱ��ʼ��
	Delay.SystemCoreClock = 168000000;								//��ʱ��ʼ��
	MX_GPIO_Init();															//GPIO��ʼ��
	usart_init(115200);													//
}

/********************************************************
  End Of File
********************************************************/
