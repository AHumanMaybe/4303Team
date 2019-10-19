#include "vex.h"
 
using namespace vex;

void usercontrol(void) 
{
  while(true)
  {
    LEFT.spin(directionType::fwd, Controller.Axis3.position(percentUnits::pct), percentUnits::pct);
    RIGHT.spin(directionType::fwd, Controller.Axis2.position(percentUnits::pct), percentUnits::pct);
    
    if(Controller.ButtonRight.pressing())
    {
      HD.spin(directionType::fwd, 100, percentUnits::pct);
    }
    else if(Controller.ButtonLeft.pressing())
    {
      HD.spin(directionType::rev, 100, percentUnits::pct);
    }
    else
    {
      HD.stop();
    }

    if(Controller.ButtonL1.pressing())
    {
      LCLAW.spin(directionType::fwd, 75, percentUnits::pct);
      RCLAW.spin(directionType::fwd, 75, percentUnits::pct);
    }
    if(Controller.ButtonL2.pressing())
    {
      LCLAW.spin(directionType::rev, 75, percentUnits::pct);
      RCLAW.spin(directionType::rev, 75, percentUnits::pct);
    }
    else
    {
      LCLAW.stop();
      RCLAW.stop();
    }
  }
}