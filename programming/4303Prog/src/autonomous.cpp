#include "v5.h"
#include "v5_vcs.h"
#include "vision.h"

using namespace vex;

//=============================================================================
//SENSORS
extern line LINE; 
extern pot AUTO;
extern limit LIMIT;
extern gyro GYRO; //degrees of rotation * 10 = gyro value (long/int32_t)
//=============================================================================

void pre_auton(void)
{
  /*
  lightlevel = LINE.value(analogUnits::range12bit); //0 (shining light) to 4095 (pitch black)
  potvalue = POT.value(analogUnits::range12bit); //0 to 4095
  GYRO.startCalibration(1300);*/
}
void autonomous(void) 
{/*
  short c = 1;
  vision::object *cube;
  VS.takeSnapshot(ORANGE);
  
  find:
  Controller.Screen.clearScreen();
  Controller.Screen.setCursor(1, 1);
  Controller.Screen.print("Looking for object...");

  while(!VS.largestObject.exists || !(VS.largestObject.width > 15)) //resolution is 316x212
  {
    VS.takeSnapshot(colors[c]);
    c++;

    c = (c > 2) ? 0 : c;

    if(potvalue > 2047) //scan right
    {
      HD.spin(directionType::rev, 75, percentUnits::pct);
    }
    else if(potvalue <= 2047)
    {
      HD.spin(directionType::fwd, 75, percentUnits::pct);
    }
  }

  Controller.Screen.clearScreen();
  Controller.Screen.setCursor(1, 1);
  Controller.Screen.print("Object found!");

  c = (c == 0) ? 2 : c--; //set c to 2 if c == 0

  cube = &VS.largestObject;

  Controller.Screen.newLine();
  Controller.Screen.print("Moving...");

  //find cube position and move to it
  while(cube->centerX != 157)
  {
    if(cube->centerX < 157) //turn right
    {
      HD.spin(directionType::rev, 75, percentUnits::pct);
    }
    else if(cube->centerX > 157) //turn left
    {
      HD.spin(directionType::fwd, 75, percentUnits::pct);
    }

    VS.takeSnapshot(colors[c]);
    cube = &VS.largestObject;

    if(!cube->exists || !(cube->width > 15))
    {
      Controller.Screen.clearScreen();
      Controller.Screen.setCursor(1, 1);
      Controller.Screen.print("Object lost.");
      Controller.Screen.newLine();
      Controller.Screen.print("Searching...");
      goto find;
    }
  }

  HD.stop(brakeType::brake);

  //TODO: move toward and grab cube*/
}