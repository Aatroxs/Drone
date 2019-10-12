#include "stm32f10x.h"
#include "core_cm3.h"
#include "stm32f10x_conf.h"
#include "delay.h"



int LED_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef LED_GPIO_InitStructure;

    LED_GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    LED_GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
    LED_GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOB,&LED_GPIO_InitStructure);
    return 1;
}



int main(void)
{
	LED_Init();
    Delay_Init();
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);

    
    while (1)
    {
        Delay_Ms(500);
        GPIO_SetBits(GPIOB,GPIO_Pin_12);
        Delay_Ms(500);
        GPIO_ResetBits(GPIOB,GPIO_Pin_12);
    }
    
}
