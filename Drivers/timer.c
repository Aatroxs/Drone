#include "timer.h"

void TImer3_Init(uint16_t arr,uint16_t psc)
{
    TIM_TimeBaseInitTypeDef Timer3_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    Timer3_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    Timer3_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    Timer3_InitStructure.TIM_Period = arr;
    Timer3_InitStructure.TIM_Prescaler = psc;
    
    TIM_TimeBaseInit(TIM3,&Timer3_InitStructure);

    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM3,ENABLE);
}
