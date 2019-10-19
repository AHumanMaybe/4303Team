#include "v5.h"
#include "v5_vcs.h"
#include "vision.h"

using namespace vex;

struct stackRed
{
  //59.69 cm/tile
  const double four = 93.98;
  const double three = 153.67;
  const double two = 213.36;
  const double one = 273.05;
};

struct stackBlue
{
  const double one = 93.98;
  const double two = 153.67;
  const double three = 213.36;
  const double four = 273.05;
};

namespace dir
{
  const short left = -1;
  const short right = 1;
}

//=============================================================================
//SENSORS
extern controller Controller;
extern motor LEFT;
extern motor RIGHT;
extern motor HD;
extern motor LARM;
extern motor RARM;
extern motor LCLAW;
extern motor RCLAW;
extern line LINE; 
extern pot AUTO;
extern limit LIMIT;
extern gyro GYRO; //degrees of rotation * 10 = gyro value (long/int32_t)
//=============================================================================

vision::signature colors[] = {ORANGE, GREEN, PURPLE};
unsigned short potvalue;

void pre_auton(void)
{  
  //unsigned short lightlevel = LINE.value(analogUnits::range12bit); //0 (shining light) to 4095 (pitch black)
  potvalue = AUTO.value(analogUnits::range12bit); //0 to 4095
  GYRO.startCalibration(1300);
}

void autonomous(void) 
{
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

  while(cube->exists && cube->width < 280)
  {
    LEFT.spin(directionType::fwd, 80, percentUnits::pct);
    RIGHT.spin(directionType::fwd, 80, percentUnits::pct);

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

  LEFT.stop();
  RIGHT.stop();

  LCLAW.rotateFor(-90, rotationUnits::deg, false);
  RCLAW.rotateFor(-90, rotationUnits::deg);

  RARM.rotateFor(90, rotationUnits::deg, false);
  LARM.rotateFor(90, rotationUnits::deg);

  while(cube->exists && cube->width > 50)
  {
    LEFT.spin(directionType::rev, 80, percentUnits::pct);
    RIGHT.spin(directionType::rev, 80, percentUnits::pct);

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

  LEFT.stop();
  RIGHT.stop();

  
}