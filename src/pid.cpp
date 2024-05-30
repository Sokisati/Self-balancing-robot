#include "pid.h"

PIDController::PIDController(float dtCoefficent,float setPoint, float kP, float kI, float kD,float lowerLimitForSum, float upperLimitForSum)
{
  this->dtCoefficent = dtCoefficent;
  this->setPoint = setPoint;
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}

float PIDController::getP(float pos)
{
   float error = (setPoint-pos);
  return (kP*error);
}

float PIDController::getI(float pos)
{
  float error = (setPoint-pos);
  integralSum += error*dt;
  return (kI*integralSum);
}

float PIDController::getD(float pos)
{
  float error = (setPoint-pos);
  float derivative = (error-previousError)/dt;
  previousError = error;
  return (kD*derivative);
}

void PIDController::printValues(float P, float I, float D)
{
  Serial.print("P:");
  Serial.println(P);

  Serial.print("I:");
  Serial.println(I);

  Serial.print("D:");
  Serial.println(D);

  Serial.println("");
}

float PIDController::getSum(float pos)
{
  float now = millis();
  dt = (now-lastTime)/dtCoefficent;
  lastTime = now;

  float p = getP(pos);
  float i =  getI(pos);
  float d =  getD(pos);

  printValues(p,i,d);

  return ( p+i+d );
}