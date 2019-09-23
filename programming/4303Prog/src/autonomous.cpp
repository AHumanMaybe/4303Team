#include "usercontrol.h"
#include "vision.h"

using namespace vex;

//dark = high, light - low
long int lightLevel;
vision::signature colors[] = {ORANGE, GREEN, PURPLE};

//=============================================================================
//define ALL MOTORS AND SENSORS

//BASE
extern motor A;
extern motor B;
extern motor HD;

//ARM
extern motor CLAW;
extern motor L1;
extern motor L2;
extern motor R1;
extern motor R2;

//SENSORS
extern line LINE; 
extern pot POT;
extern limit LIMIT;
extern gyro GYRO; //degrees of rotation * 10 = gyro value (long/int32_t)
//=============================================================================

void pre_auton(void)
{
  lightLevel = LINE.value(analogUnits::range12bit); //0 (shining light) to 4095 (pitch black)
  GYRO.startCalibration(1300);
}

void autonomous(void) 
{
  short c = 1;
  VS.takeSnapshot(ORANGE);
  
  find:
  while(!VS.largestObject.exists && VS.largestObject.width > 15)
  {
    VS.takeSnapshot(colors[c]);
    c++;
  }

  //obj:
}