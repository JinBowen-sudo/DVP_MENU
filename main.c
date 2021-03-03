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
	TR0=0;//�رն�ʱ��
	TL0=0x33;    //�Ͱ�λ����ֵ
	TH0=0XFE;    //�߰�λ����ֵ

	EC11_Action();
	switch(menu)
		{
			case 0:break;
			case 1:BAIC_C62X();break;
			case 2:BAIC_B40();break;
			default:break;
		}

	TR0=1;//���¿�����ʱ��	
}







void main()
{	
	LCDInit();
	T0_Init();
	while(1);
}


