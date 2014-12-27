/**********************************
 * 光立方 Test
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
}
