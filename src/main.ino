#include "selfbalancingrobot.h"

#define motor1SpeedPin 3 
#define motor1DirectionPin1 4
#define motor1DirectionPin2 5

#define motor2SpeedPin 6 
#define motor2DirectionPin1 7 
#define motor2DirectionPin2 8

#define dtCoefficent 1000
#define setPoint  0
#define kP 8.3
#define kI 2
#define kD 1
#define upperLimitForSum 1000
#define lowerLimitForSum -1000

SelfBalancingRobot kaanRobot(motor1SpeedPin,motor1DirectionPin1,motor1DirectionPin2,motor2SpeedPin,motor2DirectionPin1,\
                             motor2DirectionPin2,dtCoefficent,setPoint,kP,kI,kD,lowerLimitForSum,upperLimitForSum);

void setup()
{ 
   Serial.begin(115200);
   Wire.begin();
   delay(1000);

   //because this can only be done AFTER Wire has begun
   kaanRobot.initialiseMpu();
   
   Serial.println("Setup succesful");
   
}


void loop()
{
  kaanRobot.getClosedLoopControl();
}
