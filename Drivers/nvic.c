#include "nvic.h"

void Uart1_Nvic_Init()
{
    NVIC_InitTypeDef Uart1_Nvic_InitStructure;

    Uart1_Nvic_InitStructure.NVIC_IRQChannel=USART1_IRQn;
    Uart1_Nvic_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    Uart1_Nvic_InitStructure.NVIC_IRQChannelPreemptionPriority=4;
    NVIC_Init(&Uart1_Nvic_InitStructure);

}
void Timer3_Nvic_Init()
{
    NVIC_InitTypeDef Timer3_NVIC_InitStructure;

    Timer3_NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
    Timer3_NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    Timer3_NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
    NVIC_Init(&Timer3_NVIC_InitStructure);
}
void ALL_NVIC_Init(void)
{
    /* 只有16级主优先级 无副优先级 */
    NVIC_SetPriorityGrouping(NVIC_PriorityGroup_4);
    Uart1_Nvic_Init();
    Timer3_Nvic_Init();

}