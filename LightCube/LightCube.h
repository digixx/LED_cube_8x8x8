/***************************
 * YFRobot
 * www.yfrobot.com
 * 2013��10��10��
 * ���������ƺ�����
 * V1.0
****************************/

#ifndef LightCube_h
#define LightCube_h

#include "Arduino.h"

#define u8 unsigned char
#define s8 signed char
#define u16 unsigned short

class LightCube
{
  public:
    LightCube(int SER0 ,int SCK0 ,int RCK0 );
    
    void clc(void);//ȫ������
	void storey(u8 *a);
	void frame(u8 *a,u8 v);//һ֡,a��һ֡������ʼ��ַ
                      //һ�����棬v��ʾһ֡����ɨ��Ĵ���
					  // ���Կ�����֡��ʾ��ʱ��

	void All(u8 v);
	void dot(u8 v);	//���ε���00-1,01-1,02-1,03-1....63-1
	void LtoR_scan(u8 v);  //��������������ε���
	void RtoL_scan(u8 v);  //��������������ε���
	void FtoB_scan(u8 v);  //��ǰ����������ε���
	void BtoF_scan(u8 v);  //�Ӻ�����ǰ�����ε���
	void UtoD_scan(u8 v);  //�����������ε���
	void DtoU_scan(u8 v);  //�����������ε���

	void Acw(s8 num,s8 v); //anticlockwise��ʱ��  num����ת������v���ٶ�
	void Cw(s8 num,s8 v);  //clockwise˳ʱ��
	void RCw(s8 num,s8 v);//�Ҳ࿴˳ʱ��

	void cube(u8 empty,u8 kind,u8 v);	//empty=0��,1ʵ; kind=0���Ͻ�,1���Ͻ�,
									//                    2���½�,3���½�
	void rain(s8 menu,s8 num,s8 v);//menu=0,down;menu=1,up��numѭ������
	void up(s8 num,s8 v); //����
	void xuanzhuantiao(s8 kind,s8 cw,s8 num,s8 v);//������ת,kind=1ʵ��,�������	,cw�Ƿ���ת
	void qumianxuanzhuan(s8 cw,s8 num,s8 v);//������ת;cw=1��ʱ��,����˳ʱ��
	void sandglass(s8 v);//ɳ©

	void subtitle(const u8 *x,s8 n,s8 v,s8 num);//������Ļ, n�ַ�����,  v��ʾ�����ٶ�,   num��ʾѭ������
	void number(u8 *tab, s8 v);//������ʾ��ʽ
	void water1(s8 x,s8 y,s8 v);//һ��ˮ��
	void water2(s8 x1,s8 y1,s8 x2,s8 y2,s8 v);//����ˮ��
	void water3(s8 x1,s8 y1,s8 x2,s8 y2,s8 x3,s8 y3,s8 v);//����ˮ��
	void xuanzhuantiao2(s8 num,s8 v);
	void qumiaxuanzhuan3(s8 kind,s8 num,s8 v);//������ת;kind=1��ʱ��,����˳ʱ��
	void print(u8 *tab);//�������´�ӡ
	void print2(u8 *tab);//�Ӻ���ǰ��ӡ
	void flash(s8 v);//��״����
	void donghua(u8 *tab,u8 num,u8 n,s8 v);//num֡����nѭ������ 
    
  private:
    int _SER0;
    int _SCK0;
    int _RCK0;
};

#endif


