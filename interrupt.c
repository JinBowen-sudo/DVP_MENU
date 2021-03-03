#include<reg52.h>
#include"interrupt.h"

void T0_Init()//20ms进行一次中断
{
	TMOD = 0x01;//设置使用定时器0
	TL0 = 0x33;    //低八位赋初值
	TH0 = 0XFE;    //高八位赋初值
	ET0 = 1;          //开启定时器0中断
	TR0 = 1;         //运行定时器0
	EA = 1;          //开启中断总开关
}