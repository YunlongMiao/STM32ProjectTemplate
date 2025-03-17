#ifndef __gGpio_H__
#define __gGpio_H__

#include "main.h"

#define LED0_Pin GPIO_PIN_9
#define LED0_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_10
#define LED1_GPIO_Port GPIOF

#define LCD_BL_Pin GPIO_PIN_15
#define LCD_BL_GPIO_Port GPIOB

void MX_GPIO_Init(void);


#endif
