#include "motor.h"


Motor::Motor(pin speedPin,pin directionControlPin1,pin directionControlPin2)
{

this->directionControlPin1 = directionControlPin1;
this->directionControlPin2 = directionControlPin2;
this->speedPin = speedPin;

pinMode(directionControlPin1,OUTPUT);
pinMode(directionControlPin2,OUTPUT);
pinMode(speedPin,OUTPUT);

}

void Motor::forwardWithSpeed(speed speedParam)
{
  analogWrite(speedPin,speedParam);
  digitalWrite(directionControlPin1,HIGH);
  digitalWrite(directionControlPin2,LOW);
}

void Motor::backwardWithSpeed(speed speedParam)
{
  analogWrite(speedPin,speedParam);
  digitalWrite(directionControlPin1,LOW);
  digitalWrite(directionControlPin2,HIGH);
}

void Motor::invertDirection()
{
  direction = !direction;
}

void Motor::driveMotor(speed speedParam)
{
  bool positiveDirection;
  if(speedParam>0)
  {
    positiveDirection = true;
  }
  else
  {
    positiveDirection = false;
  }

  //I know it looks confusing, think of it like a 2x2 matrix
  if(positiveDirection==direction)
  {
    forwardWithSpeed(speedParam);
  }
  else
  {
    speedParam*=-1;
    backwardWithSpeed(speedParam);
  }
}

