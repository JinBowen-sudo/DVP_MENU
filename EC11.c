#include"EC11.h"
#include<REG52.h>
#include"delay.h"
#include"relay.h"
#include"LCD1602.h"

unsigned char data menu = 1;
unsigned char data NEXT_flag = 0;

unsigned char EC11_Action()
{
	if(ENTER == 0)//判断ENTER键是否按下
		{
			DelayXms(5);//延时消抖，时间一般为5-10ms
			if(ENTER == 0)
			{
				menu++;
				if(menu>2)
				{	
					menu = 1;
				}								
			}
			while(ENTER == 0);//等待松手
			LCDWriteCmd(LCD_SCREEN_CLR); //清屏
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
				LCDWriteCmd(LCD_SCREEN_CLR); //清屏
			}
			else
			{
				menu--;
				if(menu<1)
				{	
					menu = 2;
				}
				LCDWriteCmd(LCD_SCREEN_CLR); //清屏
			}
		}

		NEXT_flag = NEXT;

	return menu;	
}













