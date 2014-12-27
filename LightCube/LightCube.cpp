/***************************
 * 
 * YFRobot
 * www.yfrobot.com
 * 2013��11��10��
 * ���������ƺ����� 595����
 * V1.1
 ***************************/

#include "Arduino.h"
#include "LightCube.h"

#define u8 unsigned char
#define s8 signed char
#define u16 unsigned short

//��ʼ������
LightCube::LightCube(int SER0 ,int SCK0 ,int RCK0 )
{
  pinMode(SER0,OUTPUT);
  _SER0 = SER0;
  pinMode(SCK0,OUTPUT);
  _SCK0 = SCK0;
  pinMode(RCK0,OUTPUT);
  _RCK0 = RCK0;
  
}

const u8 tab_rain[]=
{//rain(s8 menu,s8 num,s8 v);
	0X00,0X84,0X01,0X00,0X00,0X01,0X02,0X44,
	0X84,0X00,0X24,0X08,0X04,0X20,0X80,0X00,
	0X00,0X20,0X00,0X00,0X20,0X00,0X40,0X00,
	0X00,0X04,0X00,0X40,0X00,0X00,0X08,0X00,
	
	0X40,0X00,0X10,0X00,0X00,0X04,0X04,0X11,
	0X00,0X41,0X00,0X00,0X80,0X00,0X40,0X00,
	0X00,0X00,0X00,0X24,0X01,0X18,0X00,0X00,
	0X22,0X10,0X02,0X00,0X40,0X00,0X02,0X00
};
const u8 tab_xuanzhuantiao[]=
{ //��ת��
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,//0
	0x00,0x01,0x06,0x08,0x10,0x60,0x80,0x00,
	0x00,0x00,0x01,0x0e,0x70,0x80,0x00,0x00,
	0x00,0x00,0x00,0x0f,0xf0,0x00,0x00,0x00,
	0x00,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,
	0x00,0x00,0x80,0x70,0x0e,0x01,0x00,0x00,
	0x00,0x80,0x60,0x10,0x08,0x06,0x01,0x00,
	0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,
	0x40,0x20,0x20,0x10,0x08,0x04,0x04,0x02,
	0x20,0x10,0x10,0x10,0x08,0x08,0x08,0x04,
	0x10,0x10,0x10,0x10,0x08,0x08,0x08,0x08,
	0x08,0x08,0x08,0x08,0x10,0x10,0x10,0x10,
	0x04,0x08,0x08,0x08,0x10,0x10,0x10,0x20,
	0x02,0x04,0x04,0x08,0x10,0x20,0x20,0x40//13
};
const u8 tab_xuanzhuantiao2[]=//��ת��
{
0X01,0X02,0X04,0X08,0X10,0X20,0X40,0X80,//0
0X02,0X04,0X08,0X00,0X10,0X20,0X40,0X80,//
0X04,0X08,0X00,0X10,0X20,0X20,0X40,0X80,//
0X08,0X10,0X10,0X20,0X20,0X40,0X40,0X80,//
0X10,0X10,0X20,0X20,0X20,0X40,0X40,0X80,//
0X20,0X20,0X40,0X40,0X40,0X80,0X80,0X80,//
0X40,0X40,0X40,0X40,0X80,0X80,0X80,0X80,//
0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,//7

0X80,0X80,0X80,0X80,0X40,0X40,0X40,0X40,//
0X80,0X80,0X00,0X40,0X40,0X40,0X20,0X20,//9
0X80,0X80,0X40,0X40,0X20,0X20,0X10,0X10,//
0X80,0X40,0X40,0X20,0X20,0X10,0X10,0X08,//
0X80,0X40,0X20,0X20,0X10,0X10,0X08,0X04,//
0X80,0X40,0X20,0X10,0X08,0X08,0X04,0X02,//
0X80,0X40,0X20,0X10,0X08,0X04,0X02,0X01,//14
0X80,0X40,0X20,0X10,0X0C,0X02,0X01,0X00,//15
0X80,0X40,0X30,0X0C,0X02,0X01,0X00,0X00,//
0X80,0X60,0X18,0X06,0X01,0X00,0X00,0X00,//17
0XC0,0X30,0X0E,0X01,0X00,0X00,0X00,0X00,//
0XE0,0X1C,0X03,0X00,0X00,0X00,0X00,0X00,//19
0XF0,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,//
0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,//21

0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,//22
0X07,0X38,0XC0,0X00,0X00,0X00,0X00,0X00,
0X03,0X0C,0X20,0XC0,0X00,0X00,0X00,0X00,
0X01,0X02,0X0C,0X30,0XC0,0X00,0X00,0X00,
0X01,0X02,0X04,0X08,0X30,0XC0,0X00,0X00,
0X01,0X02,0X04,0X08,0X10,0X60,0X80,0X00,
0X01,0X02,0X04,0X08,0X10,0X20,0X40,0X80,
0X01,0X02,0X04,0X08,0X10,0X20,0X20,0X40,
0X01,0X02,0X04,0X08,0X08,0X10,0X20,0X20,
0X01,0X02,0X04,0X04,0X08,0X08,0X10,0X10,
0X01,0X01,0X02,0X02,0X04,0X04,0X08,0X08,
0X01,0X01,0X01,0X02,0X02,0X02,0X04,0X04,
0X01,0X01,0X01,0X01,0X02,0X02,0X02,0X02,
0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,//35

0X02,0X02,0X02,0X02,0X01,0X01,0X01,0X01,//36
0X04,0X04,0X02,0X02,0X02,0X01,0X01,0X01,
0X08,0X08,0X04,0X04,0X02,0X02,0X01,0X01,
0X10,0X10,0X08,0X08,0X04,0X04,0X02,0X01,
0X20,0X10,0X00,0X08,0X08,0X04,0X02,0X01,
0X40,0X20,0X10,0X08,0X08,0X04,0X02,0X01,
0X80,0X40,0X20,0X10,0X08,0X04,0X02,0X01,
0X00,0X80,0X40,0X20,0X18,0X04,0X02,0X01,
0X00,0X00,0X80,0X40,0X38,0X04,0X02,0X01,
0X00,0X00,0X00,0X80,0X60,0X1C,0X02,0X01,
0X00,0X00,0X00,0X00,0X80,0X70,0X0E,0X01,
0X00,0X00,0X00,0X00,0X00,0XC0,0X3C,0X03,
0X00,0X00,0X00,0X00,0X00,0X00,0XF0,0X0F,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,//49

0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,//50
0X00,0X00,0X00,0X00,0X00,0X03,0X1C,0XE0,
0X00,0X00,0X00,0X00,0X03,0X0C,0X30,0XC0,
0X00,0X00,0X00,0X01,0X06,0X18,0X20,0XC0,
0X00,0X00,0X01,0X02,0X0C,0X30,0X40,0X80,
0X00,0X01,0X02,0X04,0X18,0X20,0X40,0X80,//56
};

const s8 tab00[]={ //��������
            0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1,//28
			1*8+1,1*8+1,1*8+1,1*8+1,1*8+1,1*8+1,1*8+2,1*8+3,1*8+4,1*8+5,1*8+6,1*8+6,1*8+6,1*8+6,1*8+6,1*8+6,1*8+5,1*8+4,1*8+3,1*8+2,//20
			2*8+2,2*8+2,2*8+2,2*8+2,2*8+3,2*8+4,2*8+5,2*8+5,2*8+5,2*8+5,2*8+4,2*8+3,//12
			3*8+3,3*8+3,3*8+4,3*8+4,//4+4
			4*8+3,4*8+3,4*8+4,4*8+4,
		    5*8+2,5*8+2,5*8+2,5*8+2,5*8+3,5*8+4,5*8+5,5*8+5,5*8+5,5*8+5,5*8+4,5*8+3,//12
			6*8+1,6*8+1,6*8+1,6*8+1,6*8+1,6*8+1,6*8+2,6*8+3,6*8+4,6*8+5,6*8+6,6*8+6,6*8+6,6*8+6,6*8+6,6*8+6,6*8+5,6*8+4,6*8+3,6*8+2,//20
			56+0,56+0,56+0,56+0,56+0,56+0,56+0,56+0,56+1,56+2,56+3,56+4,56+5,56+6,56+7,56+7,56+7,56+7,56+7,56+7,56+7,56+7,56+6,56+5,56+4,56+3,56+2,56+1,//28
           };
const s8 tab10[]={//��������
			56+0,56+0,56+0,56+0,56+0,56+0,56+0,56+0,56+1,56+2,56+3,56+4,56+5,56+6,56+7,56+7,56+7,56+7,56+7,56+7,56+7,56+7,56+6,56+5,56+4,56+3,56+2,56+1,//28
			6*8+1,6*8+1,6*8+1,6*8+1,6*8+1,6*8+1,6*8+2,6*8+3,6*8+4,6*8+5,6*8+6,6*8+6,6*8+6,6*8+6,6*8+6,6*8+6,6*8+5,6*8+4,6*8+3,6*8+2,//20
			5*8+2,5*8+2,5*8+2,5*8+2,5*8+3,5*8+4,5*8+5,5*8+5,5*8+5,5*8+5,5*8+4,5*8+3,//12
			4*8+3,4*8+3,4*8+4,4*8+4,
			3*8+3,3*8+3,3*8+4,3*8+4,//4+4
		    2*8+2,2*8+2,2*8+2,2*8+2,2*8+3,2*8+4,2*8+5,2*8+5,2*8+5,2*8+5,2*8+4,2*8+3,//12
			1*8+1,1*8+1,1*8+1,1*8+1,1*8+1,1*8+1,1*8+2,1*8+3,1*8+4,1*8+5,1*8+6,1*8+6,1*8+6,1*8+6,1*8+6,1*8+6,1*8+5,1*8+4,1*8+3,1*8+2,//20
			0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1,//28
           };
const s8 tab01[]={//�ƶ�����
            0,1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1,0,0,0,0,0,0,0,//28
			1,2,3,4,5,6,6,6,6,6,6,5,4,3,2,1,1,1,1,1,//20
			2,3,4,5,5,5,5,4,3,2,2,2,//12
			3,4,4,3,//
			3,4,4,3,
		    2,3,4,5,5,5,5,4,3,2,2,2,//12
			1,2,3,4,5,6,6,6,6,6,6,5,4,3,2,1,1,1,1,1,//20
			0,1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1,0,0,0,0,0,0,0,//28
            };
const u16 tab_water[]=
{
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0080,0x0140,0x0080,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0080,0x0140,0x0220,0x0140,0x0080,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x01c0,0x0220,0x0410,0x0410,0x0410,0x0220,0x01c0,0x0000,0x0000,0x0000,0x0000,0x0000,			 
0x0000,0x0000,0x0000,0x03e0,0x0410,0x0808,0x0808,0x0808,0x0808,0x0808,0x0410,0x03e0,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x07f0,0x0808,0x1004,0x1004,0x1004,0x1004,0x1004,0x1004,0x1004,0x0808,0x07f0,0x0000,0x0000,0x0000,
0x0000,0x0ff8,0x1004,0x2002,0x2002,0x2002,0x2002,0x2002,0x2002,0x2002,0x2002,0x2002,0x1004,0x0ff8,0x0000,0x0000,
0x1ffc,0x2002,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x4001,0x2002,0x1ffc,0x0000
};
const u8  flash_tab[]=
{
0X03,0X07,0X06,0X08,0X10,0X20,0X40,0X80,//0
0X07,0X07,0X0F,0X1C,0X18,0X20,0X40,0X80,
0X0F,0X0F,0X1F,0X3F,0X3C,0X78,0X60,0X80,
0X1F,0X1F,0X3F,0X3F,0X7F,0X7C,0X70,0X80,
0X3F,0X3F,0X3F,0X7F,0X7F,0X7F,0XF8,0XC0,
0X7F,0X7F,0X7F,0X7F,0XFF,0XFF,0XFF,0XF0,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF//6
};



void LightCube::clc(void)//ȫ������
{
  u8 i,j;
  for(i=0;i<9;i++) //��������ƣ�ѡͨĳһ�㣬
					//ʹ�õ�1�㵽��8�㣬���ε���
  {	
    digitalWrite(_RCK0,LOW);
    for(j=0;j<8;j++)  //������������
    {
      digitalWrite(_SER0,LOW);
      delayMicroseconds(1);
      digitalWrite(_SCK0,LOW); //�����أ����뵽��λ�Ĵ���
      delayMicroseconds(1);		
      digitalWrite(_SCK0,HIGH);
      delayMicroseconds(1);					
    }
  }
  digitalWrite(_RCK0,HIGH);
  delay(2);
}
/*595���нӷ���������*/
void LightCube::storey(u8 *a)//����亯��������ĳ��Ƶ�����ʽ
{
  u8 i,j,num;
  for(i=0;i<8;i++)
  {
    num=a[i];		 //��������������Ĵ���
    for(j=0;j<8;j++) //������������
    {
      if(num&0x80)
        digitalWrite(_SER0,HIGH);  // SER��������˿�
      else
        digitalWrite(_SER0,LOW);

      	digitalWrite(_SCK0,LOW);	  //�����أ����뵽��λ�Ĵ���
        delayMicroseconds(1);		
      	digitalWrite(_SCK0,HIGH);	
        num<<=1;
    }
  }
}
void LightCube::frame(u8 *a,u8 v)//һ֡,a��һ֡������ʼ��ַ
								 //һ�����棬v��ʾһ֡����ɨ��Ĵ���
								 // ���Կ�����֡��ʾ��ʱ��
{
  s8 i,j,num; //s8 �з��Ŷ���
  while(v--)
  {	
    num=0x01;
    for(i=0;i<8;i++) //��������ƣ�ѡͨĳһ�㣬
      //ʹ�õ�1�㵽��8�㣬���ε���
    {	
      num<<=i;
      digitalWrite(_RCK0,LOW);
      for(j=0;j<8;j++) //������������
      {
        digitalWrite(_SER0,LOW);
        delayMicroseconds(1);
       	digitalWrite(_SCK0,LOW); //�����أ����뵽��λ�Ĵ���
        delayMicroseconds(1);		
        digitalWrite(_SCK0,HIGH);	
      }
      for(j=0;j<8;j++) //������������
      {
        if(num&0x80)
          digitalWrite(_SER0,HIGH);	  // SER��������˿�
        else
          digitalWrite(_SER0,LOW);

        digitalWrite(_SCK0,LOW); //�����أ����뵽��λ�Ĵ���
        delayMicroseconds(1);		
       	digitalWrite(_SCK0,HIGH);	
        num<<=1;
      }
      storey(a+i*8);//����亯��������ĳ��Ƶ�����ʽ
      digitalWrite(_RCK0,HIGH);
      num=0x01;			
      delayMicroseconds(5);   // ����ʾʱ��    
	}

  }	
}

void LightCube::All(u8 v)	 
{

  u8 k[65]={
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF };

  frame(k,v);
}

void LightCube::dot(u8 v)	//���ε���00-1,01-1,02-1,03-1....63-1
{
  u8 b[64]={
    0  };
  s8 x,z;
  frame(b,v);
  for(z=0;z<8;z++)
  {
    for(x=0;x<8;x++)
    {
      b[z*8+x]=0x01;
      frame(b,v);	
    }
  }	
  for(x=0;x<64;x++)
    b[x]=0;	
}

void LightCube::LtoR_scan(u8 v) //��������������ε���
{
  u8 b[64]={
    0  };
  s8 x,z;
  for(z=0;z<8;z++)
  {
    b[z*8]=0xff;
  }
  frame(b,v);
  for(x=1;x<8;x++)
  {
    for(z=0;z<8;z++)
    {
      b[z*8+x]=0xff;
      b[z*8+(x-1)]=0;
    }
    frame(b,v);
  } 
}
void LightCube::RtoL_scan(u8 v) //��������������ε���
{	
  u8 b[64]={
    0  };
  s8 x,z;
  for(z=0;z<8;z++)
  {
    b[z*8+7]=0xff;
  }
  frame(b,v);
  for(x=6;x>=0;x--)
  {
    for(z=0;z<8;z++)
    {
      b[z*8+x]=0xff;
      b[z*8+(x+1)]=0;
    }
    frame(b,v);
  }
}
void LightCube::FtoB_scan(u8 v) //��ǰ����������ε���
{
  u8 b[64]={
    0  };
  s8 i,y;
  for(i=0;i<64;i++)
    b[i]=0x01;
  frame(b,v);
  for(y=0;y<7;y++)
  {
    for(i=0;i<64;i++)
      b[i]<<=1;
    frame(b,v);
  }	
}
void LightCube::BtoF_scan(u8 v) //�Ӻ�����ǰ�����ε���
{
  u8 b[64]={
    0  };
  s8 i,y;
  for(i=0;i<64;i++)
    b[i]=0x80;
  frame(b,v);
  for(y=0;y<7;y++)
  {
    for(i=0;i<64;i++)
      b[i]>>=1;
    frame(b,v);
  }	
}
void LightCube::UtoD_scan(u8 v) //�����������ε���
{
  u8 b[64]={
    0  };
  s8 x,z;
  for(x=0;x<8;x++)
  {
    b[x]=0xff;
  }
  frame(b,v);
  for(z=1;z<8;z++)
  {
    for(x=0;x<8;x++)
    {
      b[z*8+x]=0xff;
      b[(z-1)*8+x]=0;
    }
    frame(b,v);
  } 
}
void LightCube::DtoU_scan(u8 v) //�����������ε���
{	
  u8 b[64]={
    0  };
  s8 x,z;
  for(x=0;x<8;x++)
  {
    b[7*8+x]=0xff;
  }
  frame(b,v);
  for(z=6;z>=0;z--)
  {
    for(x=0;x<8;x++)
    {
      b[z*8+x]=0xff;
      b[(z+1)*8+x]=0;
    }
    frame(b,v);
  }
}
void LightCube::Acw(s8 num,s8 v)//anticlockwise��ʱ��,num����ת������v���ٶ�
{
  s8 i,k;
  u8 b[64]={
    0  };
  for(i=0;i<64;i++)
    b[i]=0x80;
  frame(b,v);
  while(num--)
    for(i=0;i<28;i++)
    {
      if(i<7)
        for(k=0;k<8;k++)
        {
          b[k*8]|=(0x80>>(i+1));
          b[k*8+7-i]=0;
        }
      else if(i<14)
        for(k=0;k<8;k++)
        {
          b[k*8+i-6]=0x01;
          b[k*8]>>=0x01;
        }
      else if(i<21)
        for(k=0;k<8;k++)
        {
          b[k*8+i-14]=0;
          b[k*8+7]|=(0x01<<(i-13));
        }
      else if(i<28)
        for(k=0;k<8;k++)
        {
          b[k*8+27-i]=0x80;
          b[k*8+7]<<=1;
        }
      frame(b,v);
    }
  clc();//1542  ����
}

void LightCube::Cw(s8 num,s8 v)//clockwise˳ʱ�룬num����ת������v���ٶ�
{
  s8 i,k;
  u8 b[64]={
    0  };
  for(i=0;i<64;i++)
    b[i]=0x80;
  frame(b,v);
  while(num--)
    for(i=0;i<28;i++)
    {
      if(i<7)
        for(k=0;k<8;k++)
        {
          b[k*8+7]|=(0x80>>(i+1));
          b[k*8+i]=0;
        }
      else if(i<14)
        for(k=0;k<8;k++)
        {
          b[k*8+13-i]=0x01;
          b[k*8+7]>>=0x01;
        }
      else if(i<21)
        for(k=0;k<8;k++)
        {
          b[k*8+21-i]=0;
          b[k*8]|=(0x01<<(i-13));
        }
      else if(i<28)
        for(k=0;k<8;k++)
        {
          b[k*8+i-20]=0x80;
          b[k*8]<<=1;
        }
      frame(b,v);
    }
  clc();//1542  ����
}

void LightCube::RCw(s8 num,s8 v)//�Ҳ࿴˳ʱ��
{
  s8 i,k;
  u8 a[64]={
    0  };
  for(i=0;i<8;i++)
    a[7*8+i]=0xff;
  frame(a,v);
  while(num--)
    for(i=0;i<28;i++)
    {
      if(i<7)
        for(k=0;k<8;k++)
        {
          a[(6-i)*8+k]=0x01;
          a[7*8+k]>>=1;
        }
      else if(i<14)
        for(k=0;k<8;k++)
        {
          a[k]|=0x01<<(i-6);
          a[(14-i)*8+k]=0;
        }
      else if(i<21)
        for(k=0;k<8;k++)
        {
          a[(i-13)*8+k]=0x80;
          a[k]<<=1;
        }	
      else 
        for(k=0;k<8;k++)
      {
        a[7*8+k]|=0x80>>(i-20);
        a[(i-21)*8+k]=0;
      }
      frame(a,v);
    }
  clc();
}

void move(u8 *a,s8 kind,s8 direction,s8 length)// kind=0 x��,1 y��,2 z�᣻
                              //direction=0,����,1����;length�ƶ�λ��������Ϊ8
{
  s8 i,x,z;
  if(kind==0)//x��
  {
    if(direction==1) //����
      for(z=0;z<8;z++)
      {
        for(x=7;x>=length;x--)
          a[z*8+x]=a[z*8+(x-length)];
        for(x=0;x<length;x++)
          a[z*8+x]=0;			
      }	
    else			 //����
    for(z=0;z<8;z++)
    {
      for(x=length;x<8;x++)
        a[z*8+(x-length)]=a[z*8+x];
      for(x=(8-length);x<8;x++)
        a[z*8+x]=0;			
    }				
  }
  else if(kind==1)//y��  
  {
    if(direction==1)//����
      for(i=0;i<64;i++)
        a[i]<<=length;
    else			//����
    for(i=0;i<64;i++)
      a[i]>>=length;
  }
  else		   //z��
  {
    if(direction==1) //����
      for(x=0;x<8;x++)
      {
        for(z=7;z>=length;z--)
          a[z*8+x]=a[(z-length)*8+x];
        for(z=0;z<length;z++)
          a[z*8+x]=0;			
      }	
    else			 //����
    for(x=0;x<8;x++)
    {
      for(z=length;z<8;z++)
        a[(z-length)*8+x]=a[z*8+x];
      for(z=(8-length);z<8;z++)
        a[z*8+x]=0;			
    }					
  }
}

void cube0(u8 *a,s8 n)//0<n<=8,ע��n����Ϊ0   �����壬������
{
	s8 i,j;
	for(i=0;i<64;i++)
		a[i]=0;
	j=0xff>>(8-n);
/***************************/	
	a[0]=j;
	a[n-1]=j;
	a[(n-1)*8]=j;
	a[(n-1)*8+n-1]=j;
	for(i=0;i<n;i++)
	{
		j=(0x01|(0x01<<(n-1)));
/************x��*************/
		a[i*8]|=j;
		a[i*8+n-1]|=j;
/************z��*************/
		a[i]|=j;
		a[(n-1)*8+i]|=j;
	}
}
void cube1(u8 *a,s8 n)//0<=n<=8	  ��ʵ��������
{
	s8 x,z;
	for(z=0;z<8;z++)
		for(x=0;x<8;x++)
		{
			if(z<n&&x<n)
				a[z*8+x]=0xff>>(8-n);
			else
				a[z*8+x]=0;
		}	
}

void LightCube::cube(u8 empty,u8 kind,u8 v)	//empty=0,��;1,ʵ 
										//kind=0���Ͻ�,1���Ͻ�,
										//     2���Ͻ�,3���½�
{
	u8 a[64]={0};
	s8 i;
	for(i=1;i<=8;i++)//����
	{
		if(empty==0)
			cube0(a,i);
		else
			cube1(a,i);
/***************************/		
		if(kind==0)			 
			{;}
		else if(kind==1)
			move(a,0,1,8-i);
		else if(kind==2)
			move(a,2,1,8-i);
		else
		{
			move(a,0,1,8-i);
			move(a,2,1,8-i);
		}
		frame(a,v);
	}

	for(i=7;i>0;i--)//�˳�
	{
		if(empty==0)
			cube0(a,i);
		else
			cube1(a,i);
/***************************/
		if(kind==0)
			move(a,0,1,8-i);
		else if(kind==1)
			{move(a,0,1,8-i);
			move(a,2,1,8-i);}
		else if(kind==2)
		    {;}
		else
			move(a,2,1,8-i);				
		frame(a,v);
	 }
 }

void LightCube::rain(s8 menu,s8 num,s8 v)
 //menu=0,down;menu=1,up��numѭ������
{
	u8 b[64]={0};
	s8 x,z;
	if(menu==1)	//up
	{
		for(x=0;x<8;x++)
			b[56+x]=tab_rain[x];
		frame(b,v);
		for(z=1;z<8;z++)
		{
			move(b,2,0,1);
			for(x=0;x<8;x++)
				b[56+x]=tab_rain[z*8+x];
			frame(b,v);
		}									 
		while(num--)
		{	
			for(z=0;z<8;z++)
			{
				move(b,2,0,1);
				for(x=0;x<8;x++)
					b[56+x]=tab_rain[z*8+x];
				frame(b,v);
			}
		}
	}
	else//down
	{
		for(x=0;x<8;x++)
			b[x]=tab_rain[x];
		frame(b,v);
		for(z=1;z<8;z++)
		{
			move(b,2,1,1);
			for(x=0;x<8;x++)
				b[x]=tab_rain[z*8+x];
			frame(b,v);
		}
		while(num--)
		{	
			for(z=0;z<8;z++)
			{
				move(b,2,1,1);
				for(x=0;x<8;x++)
					b[x]=tab_rain[z*8+x];
				frame(b,v);
			}				
		}
	}
}

void LightCube::up(s8 num,s8 v)//����
{
  u8 a[64]={
    0  };
  s8 X,Z;
  while(num--)
  {
    for(X=0;X<8;X++)
      a[56+X]=0xff;
    frame(a,v);
    for(Z=1;Z<8;Z++)
    {
      move(a,2,0,1);
      for(X=0;X<8;X++)
        a[56+X]=0xff;
      frame(a,v);
    }
    for(Z=0;Z<8;Z++)
    {
      if(num==0&&Z==7)
        continue;//��������ѭ������������ֹ��������ѭ��
      move(a,2,0,1);
      frame(a,v);
    }
  }
  for(Z=0;Z<7;Z++)
  {
    move(a,2,1,1);
    frame(a,v+0);
  }
}

void LightCube::xuanzhuantiao(s8 kind,s8 cw,s8 num,s8 v)//������ת,kind=1ʵ��,�������	,cw�Ƿ���ת
{
  u8 b[64]={
    0  };
  s8 i,x,z;
  while(num--)
  {
    if(cw==1)
      for(i=13;i>=0;i--)
      {
        for(z=0;z<8;z++)
        {
          for(x=0;x<8;x++)
          {
            if(x>1&&x<6&&z>1&&z<6&&kind!=1)
              b[z*8+x]=tab_xuanzhuantiao[i*8+x]&0xc3;
            else
              b[z*8+x]=tab_xuanzhuantiao[i*8+x];
          }
        }
        frame(b,v);
      }
    else
      for(i=0;i<14;i++)
      {
        for(z=0;z<8;z++)
        {
          for(x=0;x<8;x++)
          {
            if(x>1&&x<6&&z>1&&z<6&&kind!=1)
              b[z*8+x]=tab_xuanzhuantiao[i*8+x]&0xc3;
            else
              b[z*8+x]=tab_xuanzhuantiao[i*8+x];
          }
        }
        frame(b,v);
      }

  }
}

void LightCube::qumianxuanzhuan(s8 cw,s8 num,s8 v)//������ת;cw=1��ʱ��,����˳ʱ��
{
  u8 b[64]={
    0  };
  s8 i,x,z;
  for(z=0;z<8;z++)
    for(x=0;x<8;x++)
      b[z*8+x]=tab_xuanzhuantiao[x];
  frame(b,v);
  while(num--)//��ѭ��
  {
    if(cw==1)
      for(i=13;i>=0;i--)
      {
        move(b,2,1,1);				
        for(x=0;x<8;x++)
          b[x]=tab_xuanzhuantiao[i*8+x];
        frame(b,v);
      }
    else
      for(i=0;i<14;i++)
      {
        move(b,2,1,1);
        for(x=0;x<8;x++)
          b[x]=tab_xuanzhuantiao[i*8+x];
        frame(b,v);
      }
  }
  for(i=0;i<7;i++)
  {
    move(b,2,1,1);				
    for(x=0;x<8;x++)
      b[x]=tab_xuanzhuantiao[x];
    frame(b,v);
  }	
}

void LightCube::sandglass(s8 v) //ɳ©
{
  u8 b[64]={
    0  };
  u16 i;
  for(i=0;i<128;i++)//��
  {
    b[tab00[i]]=(0x01<<tab01[i]);
    frame(b,v);
    b[tab00[i]]=0;
  }

  for(i=0;i<128;i++)//8��
  {
    b[tab10[i]]|=(0x01<<tab01[i]);
    if(i>=8)
      b[tab10[i-8]]^=(0x01<<tab01[i-8]);//^��ʾ���
    frame(b,v);
  }
  b[7]|=0x01;
  b[0]=0x01;
  frame(b,v);
  for(i=1;i<128;i++)//��
  {
    if(i<8)
      b[8-i]=0;
    b[tab00[i]]|=(0x01<<tab01[i]);
    frame(b,v);
  }
  frame(b,100);
  for(i=0;i<128;i++)//��
  {
    b[tab10[i]]^=(0x01<<tab01[i]);//^��ʾ���
    frame(b,v);
  }
}
