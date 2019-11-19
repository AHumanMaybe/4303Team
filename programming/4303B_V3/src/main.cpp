/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan Hess                                                 */
/*    Created:      Sun Nov 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*---Device:-------Port:[#]-----Button:[UP/FWD]-[DOWN/REV]---*/
/*---Left Base-------[1]---------------[Left Stick]----------*/
/*---Right Base------[5]---------------[Right Stick]---------*/
/*---H-Drive---------[6]---------------[Left]-[Right]--------*/
/*---Vision Sensor---[10]------------------[N/A]-------------*/
/*---Left Arm--------[11]----------------[R1]-[R2]-----------*/
/*---Right Arm-------[15]----------------[R1]-[R2]-----------*/
/*---Top Claw--------[16]----------------[L1]-[L2]-----------*/
/*---Bottom Claw-----[20]-----------------[X]-[B]------------*/
/*---Radio-----------[21]------------------[N/A]-------------*/
/*---Gyro------------[A]-------------------[N/A]-------------*/
/*---Potentiometer---[D]-------------------[N/A]-------------*/
/*---Limit Switch----[H]-------------------[N/A]-------------*/

#include "vex.h"

using namespace vex;

competition Competition = competition();

void pre_auton()
{

}

void autonomous()
{

}

void usercontrol()
{
  hdrive.setVelocity(75, percentUnits::pct);
  arm.setVelocity(100, percentUnits::pct);
  top.setVelocity(50, percentUnits::pct);
  bottom.setVelocity(50, percentUnits::pct);

  while(true)
  {
    b_left.spin(directionType::fwd, Controller.Axis3.position(), percentUnits::pct);
    b_right.spin(directionType::fwd, Controller.Axis2.position(), percentUnits::pct);


    //---H-Drive
    if(Controller.ButtonLeft.pressing())
    {
      hdrive.spin(directionType::fwd);
    }
    else if(Controller.ButtonRight.pressing())
    {
      hdrive.spin(directionType::rev);
    }
    else 
    {
      hdrive.stop();
    }


    //---Arm
    if(Controller.ButtonR1.pressing())
    {
      arm.spin(directionType::fwd);
    }
    else if(Controller.ButtonR2.pressing())
    {
      arm.spin(directionType::rev);
    }
    else 
    {
      arm.stop(brakeType::hold);
    }

    //---Top claw
    if(Controller.ButtonL1.pressing())
    {
      top.spin(directionType::fwd);
    }
    else if(Controller.ButtonL2.pressing())
    {
      top.spin(directionType::rev);
    }
    else
    {
      top.stop();
    }

    //---Bottom claw
    if(Controller.ButtonX.pressing())
    {
      bottom.spin(directionType::fwd);
    }
    else if(Controller.ButtonB.pressing())
    {
      bottom.spin(directionType::rev);
    }
    else
    {
      bottom.stop();
    }
  }
}

int main() 
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while(true)
  {
    vex::task::sleep(10);
  }
}
