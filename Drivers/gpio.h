#ifndef __GPIO_H
#define __GPIO_H


/* 
    LED:
    PB12

    UART1;
    RX  PA10
    TX  PA9
 */
#include "stm32f10x_conf.h"


void ALL_GPIO_Init();
void LED_GPIO_Init();
void UART1_GPIO_Init();

#endif 