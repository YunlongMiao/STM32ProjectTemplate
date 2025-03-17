

/* Includes ------------------------------------------------------------------*/
// #include "MyApplication.h"
#include "sys.h"
#include "main.h"
#include "usart.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

//��ʼ��
static void Run(void);
//static uint8_t sys_stm32_clock_init(uint32_t plln, uint32_t pllm, uint32_t pllp, uint32_t pllq);   //����ϵͳʱ��
void SystemClock_Config(void);

//ȫ��
static void sys_nvic_set_vector_table(uint32_t baseaddr, uint32_t offset);     //�����ж�ƫ����
static void sys_standby(void);             // �������ģʽ 
static void sys_soft_reset(void);          // ϵͳ��λ 
static void Error_Handler(void);
static void Assert_Failed(void);

/* ����Ϊ��ຯ�� */
static void sys_wfi_set(void);             // ִ��WFIָ�� 
static void sys_intx_disable(void);        // �ر������ж� 
static void sys_intx_enable(void);         // ���������ж� 
static void sys_msr_msp(uint32_t addr);    // ����ջ����ַ 



/* Public variables-----------------------------------------------------------*/
System_t System  =   {
                        Run,
 //                       sys_stm32_clock_init
												SystemClock_Config
                    };


gSystem_t gSystem = {
                        sys_nvic_set_vector_table,
                        sys_standby,
                        sys_soft_reset,
                        Error_Handler,
                        Assert_Failed,

                        sys_wfi_set,
                        sys_intx_disable,
                        sys_intx_enable,
                        sys_msr_msp
                    };

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run
	* @brief  ϵͳ����
	* @param  None
	* @retval None      
*/
static void Run()
{
	//��ʼ��ʱ����
	printf("Test����Test\r\n");
}



/**
 * @brief       �����ж�������ƫ�Ƶ�ַ
 * @param       baseaddr: ��ַ
 * @param       offset: ƫ����
 * @retval      ��
 */
static void sys_nvic_set_vector_table(uint32_t baseaddr, uint32_t offset)
{
    /* ����NVIC��������ƫ�ƼĴ���,VTOR��9λ����,��[8:0]���� */
    SCB->VTOR = baseaddr | (offset & (uint32_t)0xFFFFFE00);
}

/**
 * @brief       ִ��: WFIָ��(ִ�����ָ�����͹���״̬, �ȴ��жϻ���)
 * @param       ��
 * @retval      ��
 */
static void sys_wfi_set(void)
{
    __ASM volatile("wfi");
}

/**
 * @brief       �ر������ж�(���ǲ�����fault��NMI�ж�)
 * @param       ��
 * @retval      ��
 */
static void sys_intx_disable(void)
{
    __ASM volatile("cpsid i");
}

/**
 * @brief       ���������ж�
 * @param       ��
 * @retval      ��
 */
static void sys_intx_enable(void)
{
    __ASM volatile("cpsie i");
}

/**
 * @brief       ����ջ����ַ
 * @note        ��������ֺ�X, ����MDK��, ʵ����û�����
 * @param       addr: ջ����ַ
 * @retval      ��
 */
static void sys_msr_msp(uint32_t addr)
{
    __set_MSP(addr);    /* ����ջ����ַ */
}

/**
 * @brief       �������ģʽ
 * @param       ��
 * @retval      ��
 */
static void sys_standby(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();    /* ʹ�ܵ�Դʱ�� */
    SET_BIT(PWR->CR, PWR_CR_PDDS); /* �������ģʽ */
}

/**
 * @brief       ϵͳ��λ
 * @param       ��
 * @retval      ��
 */
static void sys_soft_reset(void)
{
    NVIC_SystemReset();
}

/**
 * @brief       ʱ�����ú���
 * @param       plln: ��PLL��Ƶϵ��(PLL��Ƶ), ȡֵ��Χ: 64~432.
 * @param       pllm: ��PLL����ƵPLLԤ��Ƶϵ��(��PLL֮ǰ�ķ�Ƶ), ȡֵ��Χ: 2~63.
 * @param       pllp: ��PLL��p��Ƶϵ��(PLL֮��ķ�Ƶ), ��Ƶ����Ϊϵͳʱ��, ȡֵ��Χ: 2, 4, 6, 8.(������4��ֵ)
 * @param       pllq: ��PLL��q��Ƶϵ��(PLL֮��ķ�Ƶ), ȡֵ��Χ: 2~15.
 * @note
 *
 *              Fvco: VCOƵ��
 *              Fsys: ϵͳʱ��Ƶ��, Ҳ����PLL��p��Ƶ���ʱ��Ƶ��
 *              Fq:   ��PLL��q��Ƶ���ʱ��Ƶ��
 *              Fs:   ��PLL����ʱ��Ƶ��, ������HSI, HSE��.
 *              Fvco = Fs * (plln / pllm);
 *              Fsys = Fvco / pllp = Fs * (plln / (pllm * pllp));
 *              Fq   = Fvco / pllq = Fs * (plln / (pllm * pllq));
 *
 *              �ⲿ����Ϊ 8M��ʱ��, �Ƽ�ֵ: plln = 336, pllm = 8, pllp = 2, pllq = 7.
 *              �õ�:Fvco = 8 * (336 / 8) = 336Mhz
 *                   Fsys = pll_p_ck = 336 / 2 = 168Mhz
 *                   Fq   = pll_q_ck = 336 / 7 = 48Mhz
 *
 *              F407Ĭ����Ҫ���õ�Ƶ������:
 *              CPUƵ��(HCLK) = pll_p_ck = 168Mhz
 *              AHB1/2/3(rcc_hclk1/2/3) = 168Mhz
 *              APB1(rcc_pclk1) = pll_p_ck / 4 = 42Mhz
 *              APB1(rcc_pclk2) = pll_p_ck / 2 = 84Mhz
 *
 * @retval      �������: 0, �ɹ�; 1, ����;
 */
//static uint8_t sys_stm32_clock_init(uint32_t plln, uint32_t pllm, uint32_t pllp, uint32_t pllq)
//{
//    HAL_StatusTypeDef ret = HAL_OK;
//    RCC_OscInitTypeDef rcc_osc_init = {0};
//    RCC_ClkInitTypeDef rcc_clk_init = {0};

//    __HAL_RCC_PWR_CLK_ENABLE();                                         /* ʹ��PWRʱ�� */

//    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);      /* ���õ�ѹ�������ѹ�����Ա�������δ�����Ƶ�ʹ��� */

//    /* ʹ��HSE����ѡ��HSE��ΪPLLʱ��Դ������PLL1������USBʱ�� */
//    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;        /* ʱ��ԴΪHSE */
//    rcc_osc_init.HSEState = RCC_HSE_ON;                          /* ��HSE */
//    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;                      /* ��PLL */
//    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;              /* PLLʱ��Դѡ��HSE */
//    rcc_osc_init.PLL.PLLN = plln;
//    rcc_osc_init.PLL.PLLM = pllm;
//    rcc_osc_init.PLL.PLLP = pllp;
//    rcc_osc_init.PLL.PLLQ = pllq;
//    ret = HAL_RCC_OscConfig(&rcc_osc_init);                      /* ��ʼ��RCC */
//    if(ret != HAL_OK)
//    {
//        return 1;                                                /* ʱ�ӳ�ʼ��ʧ�ܣ���������������Լ��Ĵ��� */
//    }

//    /* ѡ��PLL��Ϊϵͳʱ��Դ��������HCLK,PCLK1��PCLK2 */
//    rcc_clk_init.ClockType = ( RCC_CLOCKTYPE_SYSCLK \
//                                    | RCC_CLOCKTYPE_HCLK \
//                                    | RCC_CLOCKTYPE_PCLK1 \
//                                    | RCC_CLOCKTYPE_PCLK2);

//    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;         /* ����ϵͳʱ��ʱ��ԴΪPLL */
//    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;                /* AHB��Ƶϵ��Ϊ1 */
//    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV4;                 /* APB1��Ƶϵ��Ϊ4 */
//    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV2;                 /* APB2��Ƶϵ��Ϊ2 */
//    ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_5);   /* ͬʱ����FLASH��ʱ����Ϊ5WS��Ҳ����6��CPU���� */
//    if(ret != HAL_OK)
//    {
//        return 1;                                                /* ʱ�ӳ�ʼ��ʧ�� */
//    }
//    
//    /* STM32F405x/407x/415x/417x Z�汾������֧��Ԥȡ���� */
//    if (HAL_GetREVID() == 0x1001)
//    {
//        __HAL_FLASH_PREFETCH_BUFFER_ENABLE();                    /* ʹ��flashԤȡ */
//    }
//    return 0;
//}



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}










/*
	* @name   Error_Handler
	* @brief  ϵͳ������
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
	* @brief  ��������������
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





