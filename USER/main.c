#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "oled.h"
#include "bsp_dht11.h"
#include "bsp_usart1.h"
#include "bsp_ds18b20.h"


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
    
	while(1)
	{
        OLED_Clear();
        
		printf("\r\ntemperature %.1f\r\n",DS18B20_Get_Temp());	
		
		Delay_ms(10);

		if( Read_DHT11(&DHT11_Data)==SUCCESS)
		{
			printf("\r\n�¶�Ϊ %d�� \r\n",DHT11_Data.temp_int);
		}
		OLED_ShowString(0,0,"room temperature:");
        OLED_ShowString(18,2,"27");
        OLED_ShowString(0,4,"water temperature:");
        OLED_ShowString(22,6,"27");
		Delay_ms(2000);
	}
	  
}



