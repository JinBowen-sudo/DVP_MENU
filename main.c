#include<REG52.h>
#include"LCD1602.h"
#include"delay.h"
#include"Level_1Menu.h"
#include"Level_2Menu.h"
#include"Level_3Menu.h"
#include"Level_4Menu.h"
#include"EC11.h"
#include"PowerMode.h"
#include"interrupt.h"
#include"relay.h"



void T0_Service() interrupt 1 using 0
{
	TR0=0;//关闭定时器
	TL0=0x33;    //低八位赋初值
	TH0=0XFE;    //高八位赋初值

	EC11_Action();
	switch(menu)
		{
			case 0:break;
			case 1:BAIC_C62X();break;
			case 2:BAIC_B40();break;
			default:break;
		}

	TR0=1;//重新开启定时器	
}







void main()
{	
	LCDInit();
	T0_Init();
	while(1);
}


