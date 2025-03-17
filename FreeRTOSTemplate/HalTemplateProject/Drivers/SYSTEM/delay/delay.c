#include "delay.h"
#include "sys.h"

/*
操作步骤：
a.根据延时时间和定时器所选时钟频率，计算出定时器要计数的时间数值；
b.获取当前数值寄存器的数值；
c.以当前数值为基准开始计数；
d.当所计数值等于（大于）需要延时的时间数值时退出。
注：计数时间值的计算，我们以延时10us，时钟频率为72MHZ的STM32F103C8T6来计算，
        计数值 = 延时时间/1S × 时钟频率 = 0.000 01/1 *168 000 000 =  1680
        
*/
static void delay_us(uint32_t nus);

extern void vPortSetupTimerInterrupt(void);

Delay_t Delay =
{
	0,			//系统时钟频率
	delay_us,	//无调度延时n_us
};

static void delay_us(uint32_t nus)
{ 
       uint32_t ticks;
       uint32_t told,tnow,reload,tcnt=0;
       if((0x0001&(SysTick->CTRL)) ==0)    //定时器未工作
              vPortSetupTimerInterrupt();  //初始化定时器
 
       reload = SysTick->LOAD;                     //获取重装载寄存器值
       ticks = nus * (SystemCoreClock / 1000000);  //计数时间值
       
       vTaskSuspendAll();//阻止OS调度，防止打断us延时
       told=SysTick->VAL;  //获取当前数值寄存器值（开始时数值）
       while(1)
       {
              tnow=SysTick->VAL; //获取当前数值寄存器值
              if(tnow!=told)  //当前值不等于开始值说明已在计数
              {         
                     if(tnow<told)  //当前值小于开始数值，说明未计到0
                          tcnt+=told-tnow; //计数值=开始值-当前值
 
                     else     //当前值大于开始数值，说明已计到0并重新计数
                            tcnt+=reload-tnow+told;   //计数值=重装载值-当前值+开始值  （
                                                      //已从开始值计到0） 
 
                     told=tnow;   //更新开始值
                     if(tcnt>=ticks)break;  //时间超过/等于要延迟的时间,则退出.
              } 
       }  
       xTaskResumeAll();	//恢复OS调度		   
} 
//SystemCoreClock为系统时钟(system_stmf4xx.c中)，通常选择该时钟作为
//systick定时器时钟，根据具体情况更改




//nus为要延时的us数.		    								   
//void delay_us(uint32_t nus)
//{		
//	uint32_t ticks;
//	uint32_t told,tnow,tcnt=0;
//	uint32_t reload=SysTick->LOAD;						//LOAD的值	    	 
//	ticks=nus*(SystemCoreClock/1000000); 	//需要的节拍数	  		 
//	tcnt=0;
//	vTaskSuspendAll();									//阻止OS调度，防止打断us延时
//	told=SysTick->VAL;        					//刚进入时的计数器值
//	while(1)
//	{
//		tnow=SysTick->VAL;	
//		if(tnow!=told)
//		{	    
//			if(tnow<told)tcnt+=told-tnow;		//这里注意一下SYSTICK是一个递减的计数器就可以了.
//			else tcnt+=reload-tnow+told;	    
//			told=tnow;
//			if(tcnt>=ticks)break;						//时间超过/等于要延迟的时间,则退出.
//		}  
//	};
//	xTaskResumeAll();										//恢复OS调度									    
//}








// static uint8_t  fac_us=0;							//us延时倍乘数			   
// static uint16_t fac_ms=0;							//ms延时倍乘数,在os下,代表每个节拍的ms数

// void delay_init(uint8_t SYSCLK);
// void delay_us(uint32_t nus);
// void delay_ms(uint32_t nms);
// void delay_xms(uint32_t nms);

// Delay_t Delay =
// {
// 	delay_init,	//SYSCLK:系统时钟频率168
// 	delay_us,	//无调度延时n_us
// 	delay_ms,
// 	delay_xms
// };
// 
// extern void xPortSysTickHandler(void);
// 
// //systick中断服务函数,使用OS时用到
// void SysTick_Handler(void)
// {	
//     if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//系统已经运行
//     {
//         xPortSysTickHandler();	
//     }
// }
//			   
// //初始化延迟函数
// //SYSTICK的时钟固定为AHB时钟，基础例程里面SYSTICK时钟频率为AHB/8
// //这里为了兼容FreeRTOS，所以将SYSTICK的时钟频率改为AHB的频率！
// //SYSCLK:系统时钟频率
// void delay_init(uint8_t SYSCLK)
// {
// 	uint32_t reload;
//  	//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK); 
// 	fac_us=SYSCLK;							//不论是否使用OS,fac_us都需要使用
// 	reload=SYSCLK;							//每秒钟的计数次数 单位为M	   
// 	reload*=1000000/configTICK_RATE_HZ;		//根据delay_ostickspersec设定溢出时间
// 											//reload为24位寄存器,最大值:16777216,在168M下,约合0.0998s左右	
// 	fac_ms=1000/configTICK_RATE_HZ;			//代表OS可以延时的最少单位	   
// 	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;//开启SYSTICK中断
// 	SysTick->LOAD=reload; 					//每1/configTICK_RATE_HZ断一次	
// 	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk; //开启SYSTICK     
// }								    

// //延时nus
// //nus:要延时的us数.	
// //nus:0~204522252(最大值即2^32/fac_us@fac_us=168)	    								   
// void delay_us(uint32_t nus)
// {		
// 	uint32_t ticks;
// 	uint32_t told,tnow,tcnt=0;
// 	uint32_t reload=SysTick->LOAD;				//LOAD的值	    	 
// 	ticks=nus*fac_us; 						//需要的节拍数 
// 	told=SysTick->VAL;        				//刚进入时的计数器值
// 	while(1)
// 	{
// 		tnow=SysTick->VAL;	
// 		if(tnow!=told)
// 		{	    
// 			if(tnow<told)tcnt+=told-tnow;	//这里注意一下SYSTICK是一个递减的计数器就可以了.
// 			else tcnt+=reload-tnow+told;	    
// 			told=tnow;
// 			if(tcnt>=ticks)break;			//时间超过/等于要延迟的时间,则退出.
// 		}  
// 	};										    
// }  
// ////延时nms,会引起任务调度
// //nms:要延时的ms数
// //nms:0~65535
// void delay_ms(uint32_t nms)
// {	
// 	if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//系统已经运行
// 	{		
// 		if(nms>=fac_ms)						//延时的时间大于OS的最少时间周期 
// 		{ 
//    			vTaskDelay(nms/fac_ms);	 		//FreeRTOS延时
// 		}
// 		nms%=fac_ms;						//OS已经无法提供这么小的延时了,采用普通方式延时    
// 	}
// 	delay_us((uint32_t)(nms*1000));				//普通方式延时
// }

// //延时nms,不会引起任务调度
// //nms:要延时的ms数
// void delay_xms(uint32_t nms)
// {
// 	uint32_t i;
// 	for(i=0;i<nms;i++) delay_us(1000);
// }
 
 
 
 
 
 
 
 
 
 
 
 
// /** 
// * @brief systick 中断服务函数,使用 OS 时用到
// * @param ticks: 延时的节拍数 
// * @retval 无 
// */
//void SysTick_Handler(void) {
//	
//	HAL_IncTick(); /* OS开始跑了,才执行正常的调度处理 */ 
//	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) 
//	{
//		xPortSysTickHandler(); 
//	}
//}



			 
