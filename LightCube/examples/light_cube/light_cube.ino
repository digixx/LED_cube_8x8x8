/**********************************
 * 光立方例程
 * 
 * by YFROBOT
 ***********************************/
#include "LightCube.h"

LightCube lightCube(8, 9, 10);
  
void setup(){
  lightCube.clc();
}

void loop(){
  lightCube.All(10);

  lightCube.UtoD_scan(1);

  lightCube.dot(5);

  lightCube.LtoR_scan(10);//侧面从左向右依次点亮 

  lightCube.RtoL_scan(10); //侧面从右向左依次点亮

  lightCube.FtoB_scan(10); //从前排向后排依次点亮

  lightCube.BtoF_scan(10); //从后排向前排依次点亮

  lightCube.Acw(3,10);//anticlockwise逆时针,num；旋转周数，v；速度

  lightCube.Cw(3,10);//clockwise顺时针，num；旋转周数，v；速度

  lightCube.RCw(3,10);//右侧看顺时针

  lightCube.cube(0,0,6);	//empty=0,实1空; kind=0左上角,1右上角,2左下角,3右下脚.	
  lightCube.cube(1,3,10);
  lightCube.cube(0,2,10);

  lightCube.rain(0,5,6);//menu=0,down;menu=1,up；num循环次数
  lightCube.rain(1,5,6);
   		

  lightCube.up(1,10); //上移
  lightCube.DtoU_scan(20);  //从下向上依次点亮
  lightCube.xuanzhuantiao(0,1,4,8);//空心旋转,kind=1实心,否则空心；cw是否正转
  lightCube.qumianxuanzhuan(1,4,5);//曲面旋转;cw=1逆时针,否则顺时针;
  lightCube.qumianxuanzhuan(0,4,5);//曲面旋转;cw=1逆时针,否则顺时针

  lightCube.sandglass(10);//沙漏
}
