/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan N. Hess                                              */
/*    Created:      Sun Sep 08 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "vision.h"

using namespace vex;

void pre_auton(void) 
{

}

void autonomous(void) 
{
  
}

void usercontrol(void) 
{
  HD.setVelocity(75, percentUnits::pct);   //set speeds for h-drive
  L1.setVelocity(50, percentUnits::pct);   //set speeds for arm
  L2.setVelocity(50, percentUnits::pct);
  R1.setVelocity(50, percentUnits::pct);
  R2.setVelocity(50, percentUnits::pct);
  CLAW.setVelocity(50, percentUnits::pct); //set speeds for claw

  while(true)
  {
    A.spin(directionType::fwd, Controller.Axis3.position(), percentUnits::pct); //tank drive left stick
    B.spin(directionType::fwd, Controller.Axis2.position(), percentUnits::pct); //tank drive right stick
    
    if(Controller.ButtonLeft.pressing()) //h-drive
    {
      HD.spin(directionType::fwd);
    }
    else if(Controller.ButtonRight.pressing())
    {
      HD.spin(directionType::rev);
    }
    else 
    {
      HD.stop(brakeType::hold);
    }

    if(Controller.ButtonR1.pressing()) //claw control
    {
      CLAW.spin(directionType::fwd);
    }
    else if(Controller.ButtonR2.pressing())
    {
      CLAW.spin(directionType::fwd);
    }
    else
    {
      CLAW.stop(brakeType::hold);
    }

    if(Controller.ButtonUp.pressing()) //arm raise
    {
      L1.spin(directionType::fwd);
      L2.spin(directionType::fwd);
      R1.spin(directionType::fwd);
      R2.spin(directionType::fwd);
    }
    else if(Controller.ButtonDown.pressing())
    {
      L1.spin(directionType::fwd);
      L2.spin(directionType::fwd);
      R1.spin(directionType::fwd);
      R2.spin(directionType::fwd);
    }
    else
    {
      L1.stop(brakeType::hold);
      L2.stop(brakeType::hold);
      R1.stop(brakeType::hold);
      R2.stop(brakeType::hold);
    }
  }
}

int main() 
{
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );
    
  pre_auton();
       
  while(1) 
  {
    vex::task::sleep(100); //Sleep the task for a short amount of time to prevent wasted resources.
  }
}