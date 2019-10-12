#include "delay.h"

uint32_t fac_us = 0;
uint32_t fac_ms = 0;
void Delay_Init()
{
    
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	
	fac_us=SystemCoreClock/8000000;
	fac_ms=(uint16_t)fac_us*1000;

}

void Delay_Ms(int ms){
    uint32_t temp;
	
	SysTick->LOAD=ms*fac_ms;
	SysTick->VAL=0x00;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
	
	do{
	temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));
	
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL=0x00;

}

void Delay_Us(int us)
{
	uint32_t temp;
	
	SysTick->LOAD=us*fac_us;
	SysTick->VAL=0x00;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
	
	do{
	temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));
	
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL=0x00;
}