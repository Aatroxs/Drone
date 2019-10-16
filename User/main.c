#include "stm32f10x.h"
#include "core_cm3.h"
#include "stm32f10x_conf.h"
#include "delay.h"
#include "gpio.h"
#include "nvic.h"
#include "uart.h"
#include "timer.h"


int main(void)
{   
    Delay_Init();
	ALL_GPIO_Init();
    ALL_NVIC_Init();
    Uart_init(115200);
    Delay_Init();

    GPIO_ResetBits(GPIOB,GPIO_Pin_12);
    TImer3_Init(4999,7199);
    
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);

    
    while (1)
    {
       
       
       
    }
    
}
