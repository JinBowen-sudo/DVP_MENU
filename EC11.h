#ifndef _EC11_H_
#define _EC11_H_

#include<REG52.h>

sbit ENTER = P2^2;
sbit NEXT = P2^1;
sbit BEFORE = P2^0;

extern unsigned char NEXT_flag;
//extern unsigned char BEFORE_flag;


extern unsigned char data menu;


unsigned char EC11_Action();


#endif