

#ifndef KAAN_SELFBALANCINGROBOT_H
#define KAAN_SELFBALANCINGROBOT_H

#include "motor.h"
#include "pid.h"
#include <MPU9250.h>


class SelfBalancingRobot
{
  public:
  Motor motor1;
  Motor motor2;
  MPU9250 mpuSensor;
  PIDController pidController;

  SelfBalancingRobot(pin motor1SpeedPin,pin motor1DirectionPin1,pin motor1DirectionPin2,\
  pin motor2SpeedPin,pin motor2DirectionPin1,pin motor2DirectionPin2,float dtCoefficent,float setPoint,\
  float kP, float kI, float kD,float lowerLimitForSum, float upperLimitForSum);
  float getSelfCorrectingCommand();
  void getClosedLoopControl();
  void initialiseMpu();

};



#endif
