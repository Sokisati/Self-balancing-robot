
#ifndef KAAN_PID_H
#define KAAN_PID_H

#include "Arduino.h"

class PIDController
{
 
 
 float dtCoefficent;
 float setPoint;
 float lowerLimitForSum;
 float upperLimitForSum;

 float integralSum = 0;
 float previousError = 0;
 float lastTime = millis();
 float dt;
 
 float kP;
 float kI;
 float kD;

 public:

 PIDController(float dtCoefficent,float setPoint, float kP, float kI, float kD,float lowerLimitForSum, float upperLimitForSum);
 float getP(float pos);
 float getI(float pos);
 float getD(float pos);
 void  printValues(float P, float I, float D);
 float getSum(float pos);

};


#endif
