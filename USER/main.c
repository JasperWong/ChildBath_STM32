#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "oled.h"
#include "bsp_dht11.h"
#include "bsp_usart1.h"
#include "bsp_ds18b20.h"
#include <stdlib.h>
#include <stdio.h>

DHT11_Data_TypeDef DHT11_Data;

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  	/* ����SysTick Ϊ1us�ж�һ�� */
	SysTick_Init();

	USART1_Config();

	/*��ʼ��DTT11������*/
	DHT11_GPIO_Config();
	
	DS18B20_Init();
    
    OLED_Init();
    OLED_Clear();
    
    u8 room_temp[2];
    u8 *water_temp;
    int dec_pl, sign, ndigits = 3; 
	while(1)
	{
        printf("\r\ntemperature %.1f\r\n",DS18B20_Get_Temp());
        water_temp=fcvt(DS18B20_Get_Temp,ndigits,&dec_pl,&sign);
        
		Delay_ms(10);

		if( Read_DHT11(&DHT11_Data)==SUCCESS)
		{
			printf("\r\n�¶�Ϊ %d�� \r\n",DHT11_Data.temp_int);
            sprintf(room_temp, " %d" ,DHT11_Data.temp_int);
		}
        OLED_Clear();
		OLED_ShowString(0,0,"room temperature:");
        OLED_ShowString(6,2,room_temp);
        OLED_ShowString(0,4,"water temperature:");
        OLED_ShowString(20,6,"27");
		Delay_ms(2000);
	}
	  
}



