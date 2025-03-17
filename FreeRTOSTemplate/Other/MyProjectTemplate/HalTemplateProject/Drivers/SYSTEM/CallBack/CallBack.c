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
		//taskENTER_CRITICAL();  // �����жϣ������ٽ���
	
		UBaseType_t uxSavedInterruptStatus;	// FreeRTOS �����ڱ����ж�״̬�ı���
		uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();// �����ж�״̬�������ٽ���
  if (htim->Instance == TIM6) {
			HAL_IncTick();
  }
	
//	 if (htim->Instance == TIM1) {
//			HAL_IncTick();
//  }
	 
	
		taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);// �˳��ٽ������ָ��ж�״̬
	
		//taskEXIT_CRITICAL();   // ���������жϣ��˳��ٽ���
}




/********************************************************
  End Of File
********************************************************/
