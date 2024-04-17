#ifndef _BSP_KEY_H

#define _BSP_KEY_H

#include "stm32f10x.h"

//GPIO输入有关KEY的宏定义

//按键KEY1
#define KEY1_GPIO_PIN			GPIO_Pin_0
#define KEY1_GPIO_CLK			RCC_APB2Periph_GPIOA	
#define KEY1_GPIO_PORT			GPIOA

//按键KEY2
#define KEY2_GPIO_PIN			GPIO_Pin_13
#define KEY2_GPIO_CLK			RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PORT			GPIOC

//定义开关状态的宏
#define KEY_ON		1
#define KEY_OFF		0



//调用KEY的GPIO的配置函数
void KEY_GPIO_Config(void);
//扫描KEY的按下状态函数的调用
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#endif /*_BSP_KEY_H*/
