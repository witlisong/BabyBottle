//#include "led.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "ds18b20.h"
#include "usart.h"
#include "HX711.h"

// δ�жϴ�����
void Init_Weight()
{
	Init_HX711pin();
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	
	Get_Maopi();				//��ëƤ����
	printf("ëƤ���� = %d g\r\n",Get_Maopi);
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//���»�ȡëƤ����
	printf("ëƤ���� = %d g\r\n",Get_Maopi);
}

void Init_OLED()
{
	OLED_Init();			  //��ʼ��OLED  
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
	delay_init();	    	//��ʱ������ʼ��
	uart_init(9600);    //���ڳ�ʼ��Ϊ9600
	 
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

