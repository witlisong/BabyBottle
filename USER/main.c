//#include "led.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "ds18b20.h"
#include "usart.h"
#include "HX711.h"

// 未判断传感器
void Init_Weight()
{
	Init_HX711pin();
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	
	Get_Maopi();				//称毛皮重量
	printf("毛皮重量 = %d g\r\n",Get_Maopi);
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//重新获取毛皮重量
	printf("毛皮重量 = %d g\r\n",Get_Maopi);
}

void Init_OLED()
{
	OLED_Init();			  //初始化OLED  
	OLED_Clear(); 
}

void Init_Temp()
{
		while(DS18B20_Init())
	{
		printf("DS18B20 Error\r\n");
		delay_ms(1000);
	}
	
	printf("DS18B20 ok\r\n");	
	delay_ms(1000);
}

 int main(void)
 {	
	u8 t;
	int i = 0;
  char buf[10] = {"\0"};	 
	delay_init();	    	//延时函数初始化
	uart_init(9600);    //串口初始化为9600
	 
	Init_OLED();
  Init_Weight();	
	Init_Temp();	

	while(1) 
	{		
		if(i >=5)
		{
			i = 0;
		}
		
		Inter_ShowTemper(Inter_GetTemp());
		Inter_ShowWeight();
		Inter_ShowPower(i);
		++i;
		//Inter_ShowChargePower();
		
		
		//printf("t=%0.1f\r\n",fTemper);
		
		delay_ms(1000);
		//delay_ms(1000);
	  //delay_ms(1000);
		OLED_Clear(); 
		
	}
 }

