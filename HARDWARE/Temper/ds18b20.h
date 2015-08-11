#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK MiniSTM32开发板
//DS18B20驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/12
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////

//IO方向设置
// #define DS18B20_IO_IN()  {GPIOA->CRL&=0XFFFFFFF0;GPIOA->CRL|=8<<0;}
// #define DS18B20_IO_OUT() {GPIOA->CRL&=0XFFFFFFF0;GPIOA->CRL|=3<<0;}
#define DS18B20_IO_IN()  {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=8<<28;}//八种I/O模式CRH/CRL配置为：通用推挽输出：0x3；通用开漏输出：0x7；复用推挽输出：0xb；复用开漏输出：0xf；模拟输入：0x0;浮空输入：0x4（上电默认）；下/上拉输入：0x8
#define DS18B20_IO_OUT() {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=3<<28;}
// #define DS18B20_IO_IN()  {GPIOA->CRH&=0X0FFFFFFF;GPIOA->CRH|=8<<12;}//八种I/O模式CRH/CRL配置为：通用推挽输出：0x3；通用开漏输出：0x7；复用推挽输出：0xb；复用开漏输出：0xf；模拟输入：0x0;浮空输入：0x4（上电默认）；下/上拉输入：0x8
// #define DS18B20_IO_OUT() {GPIOA->CRH&=0X0FFFFFFF;GPIOA->CRH|=3<<12;}

////IO操作函数
// #define	DS18B20_DQ_OUT PAout(0) //数据端口	PA0
// #define	DS18B20_DQ_IN  PAin(0)  //数据端口	PA0  
#define	DS18B20_DQ_OUT PCout(15) //数据端口	PC15
#define	DS18B20_DQ_IN  PCin(15)  //数据端口	PC15 
// #define	DS18B20_DQ_OUT PAout(11) //数据端口	PA11
// #define	DS18B20_DQ_IN  PAin(11)  //数据端口	PA11 

u8 DS18B20_Init(void);			//初始化DS18B20
short DS18B20_Get_Temp(void);	//获取温度
void DS18B20_Start(void);		//开始温度转换
void DS18B20_Write_Byte(u8 dat);//写入一个字节
u8 DS18B20_Read_Byte(void);		//读出一个字节
u8 DS18B20_Read_Bit(void);		//读出一个位
u8 DS18B20_Check(void);			//检测是否存在DS18B20
void DS18B20_Rst(void);			//复位DS18B20

u8* Inter_GetTemp();

#endif















