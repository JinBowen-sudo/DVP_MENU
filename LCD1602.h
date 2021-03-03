

#ifndef _LCD1602_H_
#define _LCD1602_H_

#include<REG52.h>


//IO接口声明
#define LCD1602_DB P0  //声明LCD1602的8位数据口为单片机的P0口
sbit LCD1602_RS = P2^3; //声明LCD1602的数据/命令操作端口为单片机的P2^5口
sbit LCD1602_RW = P2^4; //声明LCD1602的读写操作端口为单片机的P2^6口
sbit LCD1602_EN = P2^5;  //声明LCD1602的使能端口为单片机的P2^7口

//LCD1602指令声明

#define LCD_MODE_PIN8 0x38  //8位数据口，两行，5*8点阵
#define LCD_MODE_PIN4 0x28  //4位数据口，两行，5*8点阵

#define LCD_SCREEN_CLR 0x01  //清屏指令
#define LCD_CURSOR_RST 0x02  //光标复位

#define LCD_DIS_CUR_BLK_ON 0x0F  //显示开、光标开、光标闪烁
#define LCD_DIS_CUR_ON 0x0E  //显示开、光标开、光标不闪烁
#define LCD_DIS_ON 0x0C  //显示开、光标关、光标不闪烁
#define LCD_DIS_OFF 0x08  //显示关、光标关、光标不闪烁

#define LCD_CURSOR_LEFT 0x04  //光标左移，显示不移动
#define LCD_CURSOR_RIGHT 0x06  //光标右移，显示不移动
#define LCD_DIS_MODE_LEFT 0x07  //操作后、AC自增、画面平移
#define LCD_DIS_MODE_RIGHT 0x05  //操作后、AC自减、画面平移

#define LCD_CUR_MOVE_LEFT 0x10  //光标左移
#define LCD_CUR_MOVE_RIGHT 0x14  //光标右移
#define LCD_DIS_MOVE_LEFT 0x18  //显示左移
#define LCD_DIS_MOVE_RIGHT 0x1C  //显示右移


void LCDShowStr(unsigned char x,unsigned char y,unsigned char *str);
void LCDInit();
void LCDWriteData(unsigned char dat);
void LCDWriteCmd(unsigned char cmd);
void LCDReadBF();

#endif