
#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "MyInit.h"
#include "main.h"
#include "MyTask.h"

//void led_init(void);                    /* LED初始化函数声明 */

int main(void)
{
		HAL_Init();                         /* 初始化HAL库 */
		MyInit.Peripheral_Set();
		
    System.Run();
		
	  MyTask.AppTaskCreate(); //创建任务
		vTaskStartScheduler();  //启用调度
	
    while(1)
    {
			
    }
}

