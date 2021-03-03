#include"EC11.h"
#include<REG52.h>
#include"delay.h"
#include"relay.h"
#include"LCD1602.h"

unsigned char data menu = 1;
unsigned char data NEXT_flag = 0;

unsigned char EC11_Action()
{
	if(ENTER == 0)//�ж�ENTER���Ƿ���
		{
			DelayXms(5);//��ʱ������ʱ��һ��Ϊ5-10ms
			if(ENTER == 0)
			{
				menu++;
				if(menu>2)
				{	
					menu = 1;
				}								
			}
			while(ENTER == 0);//�ȴ�����
			LCDWriteCmd(LCD_SCREEN_CLR); //����
		}

	if((NEXT == 1) && (NEXT_flag == 0))
		{
			if(BEFORE == 1)
			{
				menu++;
				if(menu>2)
				{	
					menu = 1;
				}
				LCDWriteCmd(LCD_SCREEN_CLR); //����
			}
			else
			{
				menu--;
				if(menu<1)
				{	
					menu = 2;
				}
				LCDWriteCmd(LCD_SCREEN_CLR); //����
			}
		}

		NEXT_flag = NEXT;

	return menu;	
}













