/***************************
 * YFRobot
 * www.yfrobot.com
 * 2013年10月10号
 * 光立方控制函数库
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
    
    void clc(void);//全局清屏
	void storey(u8 *a);
	void frame(u8 *a,u8 v);//一帧,a是一帧编码起始地址
                      //一个画面，v表示一帧画面扫描的次数
					  // 可以看作这帧显示的时间

	void All(u8 v);
	void dot(u8 v);	//依次点亮00-1,01-1,02-1,03-1....63-1
	void LtoR_scan(u8 v);  //侧面从左向右依次点亮
	void RtoL_scan(u8 v);  //侧面从右向左依次点亮
	void FtoB_scan(u8 v);  //从前排向后排依次点亮
	void BtoF_scan(u8 v);  //从后排向前排依次点亮
	void UtoD_scan(u8 v);  //从上向下依次点亮
	void DtoU_scan(u8 v);  //从下向上依次点亮

	void Acw(s8 num,s8 v); //anticlockwise逆时针  num；旋转周数，v；速度
	void Cw(s8 num,s8 v);  //clockwise顺时针
	void RCw(s8 num,s8 v);//右侧看顺时针

	void cube(u8 empty,u8 kind,u8 v);	//empty=0空,1实; kind=0左上角,1右上角,
									//                    2左下角,3右下脚
	void rain(s8 menu,s8 num,s8 v);//menu=0,down;menu=1,up；num循环次数
	void up(s8 num,s8 v); //上移
	void xuanzhuantiao(s8 kind,s8 cw,s8 num,s8 v);//空心旋转,kind=1实心,否则空心	,cw是否正转
	void qumianxuanzhuan(s8 cw,s8 num,s8 v);//曲面旋转;cw=1逆时针,否则顺时针
	void sandglass(s8 v);//沙漏

	void subtitle(const u8 *x,s8 n,s8 v,s8 num);//滚动字幕, n字符个数,  v表示滚动速度,   num表示循环次数
	void number(u8 *tab, s8 v);//数字显示方式
	void water1(s8 x,s8 y,s8 v);//一个水滴
	void water2(s8 x1,s8 y1,s8 x2,s8 y2,s8 v);//两个水滴
	void water3(s8 x1,s8 y1,s8 x2,s8 y2,s8 x3,s8 y3,s8 v);//三个水滴
	void xuanzhuantiao2(s8 num,s8 v);
	void qumiaxuanzhuan3(s8 kind,s8 num,s8 v);//曲面旋转;kind=1逆时针,否则顺时针
	void print(u8 *tab);//从上往下打印
	void print2(u8 *tab);//从后往前打印
	void flash(s8 v);//条状升降
	void donghua(u8 *tab,u8 num,u8 n,s8 v);//num帧数，n循环次数 
    
  private:
    int _SER0;
    int _SCK0;
    int _RCK0;
};

#endif


