#include "nvic.h"

void Uart1_Nvic_Init(){
    
}
void ALL_NVIC_Init(void)
{
    /* 只有16级主优先级 无副优先级 */
    NVIC_SetPriorityGrouping(NVIC_PriorityGroup_4);


}