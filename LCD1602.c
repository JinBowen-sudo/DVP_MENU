#include"LCD1602.h"
#include<REG52.h>

void LCDReadBF()  //读忙位
{	
	unsigned char state;
	unsigned char i;
	LCD1602_DB=0xFF;  //数据口在操作之前统一置为“1”
	LCD1602_RS = 0;
	LCD1602_RW = 1;
	i = 0;
	do
	{	
		LCD1602_EN = 1;
		state = LCD1602_DB;
		LCD1602_EN = 0;
		i++;
		if(i>5)
			break;
	}while(state & 0x80);
}

void LCDWriteCmd(unsigned char cmd)  //写指令
{
	LCDReadBF();//不忙的时候操作
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_DB = cmd;
	LCD1602_EN = 1;
	LCD1602_EN = 0;	
}

void LCDWriteData(unsigned char dat) //写数据
{
	LCDReadBF();//不忙的时候操作
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_DB = dat;
	LCD1602_EN = 1;
	LCD1602_EN = 0;		
}

void LCDInit()  //LCD屏幕初始化
{
	LCDWriteCmd(LCD_MODE_PIN8);  //显示模式设置两行、5*8点阵
	LCDWriteCmd(LCD_DIS_ON);  //显示开、光标关、光标不闪烁
	LCDWriteCmd(LCD_CURSOR_RIGHT);  //光标右移
	LCDWriteCmd(LCD_SCREEN_CLR); //清屏
}

void LCDShowStr(unsigned char x,unsigned char y,unsigned char *str)	 //写字符串显示
{
	if(0 == y)
	{
		LCDWriteCmd(0x80 | x);
	}
	else
	{
		LCDWriteCmd(0x80|(0x40 + x));
	}
	while(*str != '\0')
	{
		LCDWriteData(*str++);		
	}
}








