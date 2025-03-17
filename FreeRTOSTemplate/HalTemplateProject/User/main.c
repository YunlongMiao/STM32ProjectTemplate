
#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "MyInit.h"
#include "main.h"
#include "MyTask.h"

//void led_init(void);                    /* LED��ʼ���������� */

int main(void)
{
		HAL_Init();                         /* ��ʼ��HAL�� */
		MyInit.Peripheral_Set();
		
    System.Run();
		
	  MyTask.AppTaskCreate(); //��������
		vTaskStartScheduler();  //���õ���
	
    while(1)
    {
			
    }
}

