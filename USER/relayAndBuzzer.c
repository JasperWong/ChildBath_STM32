#include "relayAndBuzzer.h"
#include "bsp_SysTick.h"

void relayAndBuzzer_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOF, ENABLE); 															   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);															   
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13);
}

void Buzz(uint8_t isBuzz)
{
	if(isBuzz)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
//		Delay_ms(10);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	}	
		
		
	if(!isBuzz) GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void Relay(uint8_t isOn)
{
	if(isOn) GPIO_SetBits(GPIOB,GPIO_Pin_13);
	if(!isOn) GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}