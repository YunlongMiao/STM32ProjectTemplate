/* Includes ------------------------------------------------------------------*/
#include "CallBack.h"
#include "main.h"
#include "MyTask.h"
#include "sys.h"
/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
		//taskENTER_CRITICAL();  // 禁用中断，进入临界区
	
		UBaseType_t uxSavedInterruptStatus;	// FreeRTOS 中用于保存中断状态的变量
		uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();// 保存中断状态并进入临界区
  if (htim->Instance == TIM6) {
			HAL_IncTick();
  }
	
//	 if (htim->Instance == TIM1) {
//			HAL_IncTick();
//  }
	 
	
		taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);// 退出临界区并恢复中断状态
	
		//taskEXIT_CRITICAL();   // 重新启用中断，退出临界区
}




/********************************************************
  End Of File
********************************************************/
