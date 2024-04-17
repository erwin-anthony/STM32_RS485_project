//bsp:board support package 板级支持包（stm32f103VE6T）
#include "bsp_key.h"

void KEY_GPIO_Config(void){
	
	//初始化key的结构体
	GPIO_InitTypeDef GPIO_InitStructure_KEY1;
	GPIO_InitTypeDef GPIO_InitStructure_KEY2;
	
	//时钟的使能
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);

	//调用库函数，初始化GPIO
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure_KEY1);
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure_KEY2);

	//对KEY1的引脚，引脚输入模式进行配置
	//KEY1的GPIO配置
	GPIO_InitStructure_KEY1.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_InitStructure_KEY1.GPIO_Mode = GPIO_Mode_IN_FLOATING;

	
	
	//对KEY2的引脚，引脚输入模式进行配置
	//KEY2的GPIO配置
	GPIO_InitStructure_KEY2.GPIO_Pin = KEY2_GPIO_PIN;
	GPIO_InitStructure_KEY2.GPIO_Mode = GPIO_Mode_IN_FLOATING;

}


//检测按键状态(读取高低电平)
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
