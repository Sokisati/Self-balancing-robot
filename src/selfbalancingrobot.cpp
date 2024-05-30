#include "selfbalancingrobot.h"

SelfBalancingRobot::SelfBalancingRobot(pin motor1SpeedPin, pin motor1DirectionPin1,\
 pin motor1DirectionPin2,pin motor2SpeedPin,pin motor2DirectionPin1,pin motor2DirectionPin2\
 ,float dtCoefficent,float setPoint, float kP, float kI, float kD,float lowerLimitForSum, float upperLimitForSum)
: motor1(motor1SpeedPin,motor1DirectionPin1,motor1DirectionPin2), motor2(motor2SpeedPin,motor2DirectionPin1,motor2DirectionPin2),\
 pidController(dtCoefficent,setPoint,kP,kI,kD,lowerLimitForSum,upperLimitForSum)
{
    
}

float SelfBalancingRobot::getSelfCorrectingCommand()
{
  
  mpuSensor.update();
  if(mpuSensor.update())
  {
  
  float pos = mpuSensor.getRoll();

  float correctiveCommand = pidController.getSum(pos);
  
  Serial.print("Corrective command: ");
  Serial.println(correctiveCommand);

  //map function, needs math revision
  //correctiveCommand = map(correctiveCommand,pidController.lowerLimitForSum,pidController.upperLimitForSum,-255,255);

  return correctiveCommand; 
  }
  else
  {
    return -666.666;
  }
  
}

void SelfBalancingRobot::initialiseMpu()
{
     if (!mpuSensor.setup(0x68)) 
    {  // change to your own address
        while (true) 
        {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
}

void SelfBalancingRobot::getClosedLoopControl()
{
  float correctiveCommand = getSelfCorrectingCommand();
  if(correctiveCommand>255)
  {
    correctiveCommand=255;
  }
  else if(correctiveCommand<-255)
  {
    correctiveCommand=-255;
  }
  
  motor1.driveMotor(static_cast<speed>(correctiveCommand));
  motor2.driveMotor(static_cast<speed>(correctiveCommand));
}
