#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "oled.h"
#include "bsp_dht11.h"
#include "bsp_usart1.h"
#include "bsp_ds18b20.h"
#include <stdlib.h>
#include <stdio.h>
#include "relayAndBuzzer.h"

void tempControl(int roomTemp,float waterTemp);
DHT11_Data_TypeDef DHT11_Data;
u8 tempFlag=0;
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
  	/* 配置SysTick 为1us中断一次 */
	SysTick_Init();

	USART1_Config();

	/*初始化DTT11的引脚*/
	DHT11_GPIO_Config();
	
	DS18B20_Init();
    
    OLED_Init();
    OLED_Clear();
    relayAndBuzzer_init();
    int nRoomTemp=0;
	float fWaterTemp=0;	
    char room_temp[2];
    char water_temp[5];
    int dec_pl, sign, ndigits = 3; 


	
	while(1)
	{
		fWaterTemp=DS18B20_Get_Temp();
        printf("\r\ntemperature %.1f\r\n",fWaterTemp);
        sprintf(water_temp,"%.1f",fWaterTemp);
		Delay_ms(10);

		if( Read_DHT11(&DHT11_Data)==SUCCESS)
		{
			printf("\r\n温度为 %d℃ \r\n",DHT11_Data.temp_int);
            sprintf(room_temp,```````` " %d" ,DHT11_Data.temp_int);
		}
		
		tempControl(nRoomTemp,fWaterTemp);
        OLED_Clear();
		OLED_ShowString(0,0,"room temperature:");
        OLED_ShowString(6,2,room_temp);
        OLED_ShowString(0,4,"water temperature:");
        OLED_ShowString(20,6,water_temp);
		Delay_ms(2000);
	}
	  
}

void tempControl(int roomTemp,float waterTemp)
{
	if(roomTemp<15)	
	{
		tempFlag=1;
		if(waterTemp>38)
		{
			Buzz(0);
			Relay(0);
		}
		else 
		{
			Buzz(1);
			Relay(1);
		}
		
	}
	if(roomTemp>15&&roomTemp<25)
	{
		tempFlag=2;
		if(waterTemp>37)
		{
			Buzz(0);
			Relay(0);
		}
		else 
		{
			Buzz(1);
			Relay(1);
		}
	}
	if(roomTemp>25)
	{
		tempFlag=3;
		if(waterTemp>35)
		{
			Buzz(0);
			Relay(0);
		}
		else 
		{
			Buzz(1);
			Relay(1);
		}
	}
	
}

















