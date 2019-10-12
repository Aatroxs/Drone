#include "gpio.h"

void ALL_GPIO_Init()
{
    LED_GPIO_Init();
    UART1_GPIO_Init();
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
void UART1_GPIO_Init()
{
    GPIO_InitTypeDef UART1_GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    // USART1_TX PA9
    UART1_GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    UART1_GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
    UART1_GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOA,&UART1_GPIO_InitStructure);

    // UART1_RX PA10
    UART1_GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    UART1_GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
    GPIO_Init(GPIOA,&UART1_GPIO_InitStructure);

}