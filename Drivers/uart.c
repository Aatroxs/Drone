#include "uart.h"

void Uart_init(uint32_t bound)
{
    // GPIO Initialed in gpio.c
    // NVIC Initialed in nvic.c
    USART_InitTypeDef Uart1_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

    Uart1_InitStructure.USART_BaudRate=bound;
    Uart1_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    Uart1_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    Uart1_InitStructure.USART_Parity=USART_Parity_No;
    Uart1_InitStructure.USART_StopBits=USART_StopBits_1;
    Uart1_InitStructure.USART_WordLength=USART_WordLength_8b;
}