#include "stm32f10x.h"
#include "core_cm3.h"
#include "stm32f10x_conf.h"
#include "delay.h"
#include "gpio.h"


int main(void)
{
	ALL_GPIO_Init();
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
