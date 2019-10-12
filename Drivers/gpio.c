#include "gpio.h"

void ALL_GPIO_Init()
{
    LED_GPIO_Init();

}

void LED_GPIO_Init()
{
    GPIO_InitTypeDef LED_GPIO_InitStrcture;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    LED_GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
    LED_GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_12;
    LED_GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOB,&LED_GPIO_InitStrcture);
}