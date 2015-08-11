#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK MiniSTM32������
//DS18B20��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/12
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

//IO��������
// #define DS18B20_IO_IN()  {GPIOA->CRL&=0XFFFFFFF0;GPIOA->CRL|=8<<0;}
// #define DS18B20_IO_OUT() {GPIOA->CRL&=0XFFFFFFF0;GPIOA->CRL|=3<<0;}
#define DS18B20_IO_IN()  {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=8<<28;}//����I/OģʽCRH/CRL����Ϊ��ͨ�����������0x3��ͨ�ÿ�©�����0x7���������������0xb�����ÿ�©�����0xf��ģ�����룺0x0;�������룺0x4���ϵ�Ĭ�ϣ�����/�������룺0x8
#define DS18B20_IO_OUT() {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=3<<28;}
// #define DS18B20_IO_IN()  {GPIOA->CRH&=0X0FFFFFFF;GPIOA->CRH|=8<<12;}//����I/OģʽCRH/CRL����Ϊ��ͨ�����������0x3��ͨ�ÿ�©�����0x7���������������0xb�����ÿ�©�����0xf��ģ�����룺0x0;�������룺0x4���ϵ�Ĭ�ϣ�����/�������룺0x8
// #define DS18B20_IO_OUT() {GPIOA->CRH&=0X0FFFFFFF;GPIOA->CRH|=3<<12;}

////IO��������
// #define	DS18B20_DQ_OUT PAout(0) //���ݶ˿�	PA0
// #define	DS18B20_DQ_IN  PAin(0)  //���ݶ˿�	PA0  
#define	DS18B20_DQ_OUT PCout(15) //���ݶ˿�	PC15
#define	DS18B20_DQ_IN  PCin(15)  //���ݶ˿�	PC15 
// #define	DS18B20_DQ_OUT PAout(11) //���ݶ˿�	PA11
// #define	DS18B20_DQ_IN  PAin(11)  //���ݶ˿�	PA11 

u8 DS18B20_Init(void);			//��ʼ��DS18B20
short DS18B20_Get_Temp(void);	//��ȡ�¶�
void DS18B20_Start(void);		//��ʼ�¶�ת��
void DS18B20_Write_Byte(u8 dat);//д��һ���ֽ�
u8 DS18B20_Read_Byte(void);		//����һ���ֽ�
u8 DS18B20_Read_Bit(void);		//����һ��λ
u8 DS18B20_Check(void);			//����Ƿ����DS18B20
void DS18B20_Rst(void);			//��λDS18B20

u8* Inter_GetTemp();

#endif















