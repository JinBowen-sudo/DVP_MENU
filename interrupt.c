#include<reg52.h>
#include"interrupt.h"

void T0_Init()//20ms����һ���ж�
{
	TMOD = 0x01;//����ʹ�ö�ʱ��0
	TL0 = 0x33;    //�Ͱ�λ����ֵ
	TH0 = 0XFE;    //�߰�λ����ֵ
	ET0 = 1;          //������ʱ��0�ж�
	TR0 = 1;         //���ж�ʱ��0
	EA = 1;          //�����ж��ܿ���
}