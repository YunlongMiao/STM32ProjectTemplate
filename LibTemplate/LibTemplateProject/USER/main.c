#define FLAG 0
/*

  红绿灯闪烁
	
	新建工程的时候，请确保Option for target->C/C++选项卡的全部宏定义Define输入框字符串为：STM32F40_41xxx,USE_STDPERIPH_DRIVER
 
*/


#ifdef FLAG

/*
最简配置，库函数只需引用gpio和rcc
*/
#include "stm32f4xx.h"
  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  while(1){
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
		GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
	
	}
}





#else

/*
正常最简配置，库函数需引用gpio、rcc、misc、usart
*/

#include "stm32f4xx.h" 
#include "usart.h" 
#include "delay.h"

int main(void) {
	
	u32 t=0; 
	uart_init(115200); 
	delay_init(84);
	

	while(1){ 
		
		printf("t:%d\r\n",t); 
		delay_ms(500); t++;
	}
	
}


#endif



