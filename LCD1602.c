#include"LCD1602.h"
#include<REG52.h>

void LCDReadBF()  //��æλ
{	
	unsigned char state;
	unsigned char i;
	LCD1602_DB=0xFF;  //���ݿ��ڲ���֮ǰͳһ��Ϊ��1��
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

void LCDWriteCmd(unsigned char cmd)  //дָ��
{
	LCDReadBF();//��æ��ʱ�����
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_DB = cmd;
	LCD1602_EN = 1;
	LCD1602_EN = 0;	
}

void LCDWriteData(unsigned char dat) //д����
{
	LCDReadBF();//��æ��ʱ�����
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_DB = dat;
	LCD1602_EN = 1;
	LCD1602_EN = 0;		
}

void LCDInit()  //LCD��Ļ��ʼ��
{
	LCDWriteCmd(LCD_MODE_PIN8);  //��ʾģʽ�������С�5*8����
	LCDWriteCmd(LCD_DIS_ON);  //��ʾ�������ء���겻��˸
	LCDWriteCmd(LCD_CURSOR_RIGHT);  //�������
	LCDWriteCmd(LCD_SCREEN_CLR); //����
}

void LCDShowStr(unsigned char x,unsigned char y,unsigned char *str)	 //д�ַ�����ʾ
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








