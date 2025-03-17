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


/**
 * @brief       设置中断向量表偏移地址
 * @param       baseaddr: 基址
 * @param       offset: 偏移量
 * @retval      无
 */
void sys_nvic_set_vector_table(uint32_t baseaddr, uint32_t offset)
{
    /* 设置NVIC的向量表偏移寄存器,VTOR低9位保留,即[8:0]保留 */
    SCB->VTOR = baseaddr | (offset & (uint32_t)0xFFFFFE00);
}

/**
 * @brief       执行: WFI指令(执行完该指令进入低功耗状态, 等待中断唤醒)
 * @param       无
 * @retval      无
 */
void sys_wfi_set(void)
{
    __ASM volatile("wfi");
}

/**
 * @brief       关闭所有中断(但是不包括fault和NMI中断)
 * @param       无
 * @retval      无
 */
void sys_intx_disable(void)
{
    __ASM volatile("cpsid i");
}

/**
 * @brief       开启所有中断
 * @param       无
 * @retval      无
 */
void sys_intx_enable(void)
{
    __ASM volatile("cpsie i");
}

/**
 * @brief       设置栈顶地址
 * @note        左侧若出现红X, 属于MDK误报, 实际是没问题的
 * @param       addr: 栈顶地址
 * @retval      无
 */
void sys_msr_msp(uint32_t addr)
{
    __set_MSP(addr);    /* 设置栈顶地址 */
}

/**
 * @brief       进入待机模式
 * @param       无
 * @retval      无
 */
void sys_standby(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();    /* 使能电源时钟 */
    SET_BIT(PWR->CR, PWR_CR_PDDS); /* 进入待机模式 */
}

/**
 * @brief       系统软复位
 * @param       无
 * @retval      无
 */
void sys_soft_reset(void)
{
    NVIC_SystemReset();
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
	__disable_irq();
  while (1)
  {
  }
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
