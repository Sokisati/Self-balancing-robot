#ifndef KAAN_MOTOR_H
#define KAAN_MOTOR_H

#include "Arduino.h"

typedef int speed;
typedef unsigned short int pin;

class Motor
{
  //speed pin shall be a PWM pin
  //direction pins can be any digital pin
  pin speedPin;
  pin directionControlPin1;
  pin directionControlPin2;
  bool direction = true;

  void forwardWithSpeed(speed speedParam);
  void backwardWithSpeed(speed speedParam);
public:
  
  Motor(pin speedPin,pin directionControlPin1,pin directionControlPin2);
  void invertDirection();
  void driveMotor(speed speedParam);
  

};

#endif
