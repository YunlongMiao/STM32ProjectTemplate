#include "delay.h"
#include "sys.h"

/*
�������裺
a.������ʱʱ��Ͷ�ʱ����ѡʱ��Ƶ�ʣ��������ʱ��Ҫ������ʱ����ֵ��
b.��ȡ��ǰ��ֵ�Ĵ�������ֵ��
c.�Ե�ǰ��ֵΪ��׼��ʼ������
d.��������ֵ���ڣ����ڣ���Ҫ��ʱ��ʱ����ֵʱ�˳���
ע������ʱ��ֵ�ļ��㣬��������ʱ10us��ʱ��Ƶ��Ϊ72MHZ��STM32F103C8T6�����㣬
        ����ֵ = ��ʱʱ��/1S �� ʱ��Ƶ�� = 0.000 01/1 *168 000 000 =  1680
        
*/
static void delay_us(uint32_t nus);

extern void vPortSetupTimerInterrupt(void);

Delay_t Delay =
{
	0,			//ϵͳʱ��Ƶ��
	delay_us,	//�޵�����ʱn_us
};

static void delay_us(uint32_t nus)
{ 
       uint32_t ticks;
       uint32_t told,tnow,reload,tcnt=0;
       if((0x0001&(SysTick->CTRL)) ==0)    //��ʱ��δ����
              vPortSetupTimerInterrupt();  //��ʼ����ʱ��
 
       reload = SysTick->LOAD;                     //��ȡ��װ�ؼĴ���ֵ
       ticks = nus * (SystemCoreClock / 1000000);  //����ʱ��ֵ
       
       vTaskSuspendAll();//��ֹOS���ȣ���ֹ���us��ʱ
       told=SysTick->VAL;  //��ȡ��ǰ��ֵ�Ĵ���ֵ����ʼʱ��ֵ��
       while(1)
       {
              tnow=SysTick->VAL; //��ȡ��ǰ��ֵ�Ĵ���ֵ
              if(tnow!=told)  //��ǰֵ�����ڿ�ʼֵ˵�����ڼ���
              {         
                     if(tnow<told)  //��ǰֵС�ڿ�ʼ��ֵ��˵��δ�Ƶ�0
                          tcnt+=told-tnow; //����ֵ=��ʼֵ-��ǰֵ
 
                     else     //��ǰֵ���ڿ�ʼ��ֵ��˵���ѼƵ�0�����¼���
                            tcnt+=reload-tnow+told;   //����ֵ=��װ��ֵ-��ǰֵ+��ʼֵ  ��
                                                      //�Ѵӿ�ʼֵ�Ƶ�0�� 
 
                     told=tnow;   //���¿�ʼֵ
                     if(tcnt>=ticks)break;  //ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
              } 
       }  
       xTaskResumeAll();	//�ָ�OS����		   
} 
//SystemCoreClockΪϵͳʱ��(system_stmf4xx.c��)��ͨ��ѡ���ʱ����Ϊ
//systick��ʱ��ʱ�ӣ����ݾ����������




//nusΪҪ��ʱ��us��.		    								   
//void delay_us(uint32_t nus)
//{		
//	uint32_t ticks;
//	uint32_t told,tnow,tcnt=0;
//	uint32_t reload=SysTick->LOAD;						//LOAD��ֵ	    	 
//	ticks=nus*(SystemCoreClock/1000000); 	//��Ҫ�Ľ�����	  		 
//	tcnt=0;
//	vTaskSuspendAll();									//��ֹOS���ȣ���ֹ���us��ʱ
//	told=SysTick->VAL;        					//�ս���ʱ�ļ�����ֵ
//	while(1)
//	{
//		tnow=SysTick->VAL;	
//		if(tnow!=told)
//		{	    
//			if(tnow<told)tcnt+=told-tnow;		//����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ�����.
//			else tcnt+=reload-tnow+told;	    
//			told=tnow;
//			if(tcnt>=ticks)break;						//ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
//		}  
//	};
//	xTaskResumeAll();										//�ָ�OS����									    
//}








// static uint8_t  fac_us=0;							//us��ʱ������			   
// static uint16_t fac_ms=0;							//ms��ʱ������,��os��,����ÿ�����ĵ�ms��

// void delay_init(uint8_t SYSCLK);
// void delay_us(uint32_t nus);
// void delay_ms(uint32_t nms);
// void delay_xms(uint32_t nms);

// Delay_t Delay =
// {
// 	delay_init,	//SYSCLK:ϵͳʱ��Ƶ��168
// 	delay_us,	//�޵�����ʱn_us
// 	delay_ms,
// 	delay_xms
// };
// 
// extern void xPortSysTickHandler(void);
// 
// //systick�жϷ�����,ʹ��OSʱ�õ�
// void SysTick_Handler(void)
// {	
//     if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//ϵͳ�Ѿ�����
//     {
//         xPortSysTickHandler();	
//     }
// }
//			   
// //��ʼ���ӳٺ���
// //SYSTICK��ʱ�ӹ̶�ΪAHBʱ�ӣ�������������SYSTICKʱ��Ƶ��ΪAHB/8
// //����Ϊ�˼���FreeRTOS�����Խ�SYSTICK��ʱ��Ƶ�ʸ�ΪAHB��Ƶ�ʣ�
// //SYSCLK:ϵͳʱ��Ƶ��
// void delay_init(uint8_t SYSCLK)
// {
// 	uint32_t reload;
//  	//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK); 
// 	fac_us=SYSCLK;							//�����Ƿ�ʹ��OS,fac_us����Ҫʹ��
// 	reload=SYSCLK;							//ÿ���ӵļ������� ��λΪM	   
// 	reload*=1000000/configTICK_RATE_HZ;		//����delay_ostickspersec�趨���ʱ��
// 											//reloadΪ24λ�Ĵ���,���ֵ:16777216,��168M��,Լ��0.0998s����	
// 	fac_ms=1000/configTICK_RATE_HZ;			//����OS������ʱ�����ٵ�λ	   
// 	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;//����SYSTICK�ж�
// 	SysTick->LOAD=reload; 					//ÿ1/configTICK_RATE_HZ��һ��	
// 	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk; //����SYSTICK     
// }								    

// //��ʱnus
// //nus:Ҫ��ʱ��us��.	
// //nus:0~204522252(���ֵ��2^32/fac_us@fac_us=168)	    								   
// void delay_us(uint32_t nus)
// {		
// 	uint32_t ticks;
// 	uint32_t told,tnow,tcnt=0;
// 	uint32_t reload=SysTick->LOAD;				//LOAD��ֵ	    	 
// 	ticks=nus*fac_us; 						//��Ҫ�Ľ����� 
// 	told=SysTick->VAL;        				//�ս���ʱ�ļ�����ֵ
// 	while(1)
// 	{
// 		tnow=SysTick->VAL;	
// 		if(tnow!=told)
// 		{	    
// 			if(tnow<told)tcnt+=told-tnow;	//����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ�����.
// 			else tcnt+=reload-tnow+told;	    
// 			told=tnow;
// 			if(tcnt>=ticks)break;			//ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
// 		}  
// 	};										    
// }  
// ////��ʱnms,�������������
// //nms:Ҫ��ʱ��ms��
// //nms:0~65535
// void delay_ms(uint32_t nms)
// {	
// 	if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//ϵͳ�Ѿ�����
// 	{		
// 		if(nms>=fac_ms)						//��ʱ��ʱ�����OS������ʱ������ 
// 		{ 
//    			vTaskDelay(nms/fac_ms);	 		//FreeRTOS��ʱ
// 		}
// 		nms%=fac_ms;						//OS�Ѿ��޷��ṩ��ôС����ʱ��,������ͨ��ʽ��ʱ    
// 	}
// 	delay_us((uint32_t)(nms*1000));				//��ͨ��ʽ��ʱ
// }

// //��ʱnms,���������������
// //nms:Ҫ��ʱ��ms��
// void delay_xms(uint32_t nms)
// {
// 	uint32_t i;
// 	for(i=0;i<nms;i++) delay_us(1000);
// }
 
 
 
 
 
 
 
 
 
 
 
 
// /** 
// * @brief systick �жϷ�����,ʹ�� OS ʱ�õ�
// * @param ticks: ��ʱ�Ľ����� 
// * @retval �� 
// */
//void SysTick_Handler(void) {
//	
//	HAL_IncTick(); /* OS��ʼ����,��ִ�������ĵ��ȴ��� */ 
//	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) 
//	{
//		xPortSysTickHandler(); 
//	}
//}



			 
