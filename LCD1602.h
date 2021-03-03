

#ifndef _LCD1602_H_
#define _LCD1602_H_

#include<REG52.h>


//IO�ӿ�����
#define LCD1602_DB P0  //����LCD1602��8λ���ݿ�Ϊ��Ƭ����P0��
sbit LCD1602_RS = P2^3; //����LCD1602������/��������˿�Ϊ��Ƭ����P2^5��
sbit LCD1602_RW = P2^4; //����LCD1602�Ķ�д�����˿�Ϊ��Ƭ����P2^6��
sbit LCD1602_EN = P2^5;  //����LCD1602��ʹ�ܶ˿�Ϊ��Ƭ����P2^7��

//LCD1602ָ������

#define LCD_MODE_PIN8 0x38  //8λ���ݿڣ����У�5*8����
#define LCD_MODE_PIN4 0x28  //4λ���ݿڣ����У�5*8����

#define LCD_SCREEN_CLR 0x01  //����ָ��
#define LCD_CURSOR_RST 0x02  //��긴λ

#define LCD_DIS_CUR_BLK_ON 0x0F  //��ʾ������꿪�������˸
#define LCD_DIS_CUR_ON 0x0E  //��ʾ������꿪����겻��˸
#define LCD_DIS_ON 0x0C  //��ʾ�������ء���겻��˸
#define LCD_DIS_OFF 0x08  //��ʾ�ء����ء���겻��˸

#define LCD_CURSOR_LEFT 0x04  //������ƣ���ʾ���ƶ�
#define LCD_CURSOR_RIGHT 0x06  //������ƣ���ʾ���ƶ�
#define LCD_DIS_MODE_LEFT 0x07  //������AC����������ƽ��
#define LCD_DIS_MODE_RIGHT 0x05  //������AC�Լ�������ƽ��

#define LCD_CUR_MOVE_LEFT 0x10  //�������
#define LCD_CUR_MOVE_RIGHT 0x14  //�������
#define LCD_DIS_MOVE_LEFT 0x18  //��ʾ����
#define LCD_DIS_MOVE_RIGHT 0x1C  //��ʾ����


void LCDShowStr(unsigned char x,unsigned char y,unsigned char *str);
void LCDInit();
void LCDWriteData(unsigned char dat);
void LCDWriteCmd(unsigned char cmd);
void LCDReadBF();

#endif