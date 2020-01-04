/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan Hess                                                 */
/*    Created:      Sun Nov 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*---Device:-------Port:[#]-----Button:[UP/FWD]-[DOWN/REV]---*/
/*---Left Base-------[13]--------------[Left Stick]----------*/
/*---Right Base------[17]--------------[Right Stick]---------*/
/*---H-Drive---------[6]---------------[Left]-[Right]--------*/
/*---Vision Sensor---[20]------------------[N/A]---- ---------*/
/*---Left Arm--------[11]----------------[R1]-[L1]-----------*/
/*---Right Arm-------[15]----------------[R1]-[L1]-----------*/
/*---Claw------------[4]-----------------[R2]-[L2]-----------*/
/*---Radio-----------[21]------------------[N/A]-------------*/
/*---Gyro------------[A]-------------------[N/A]-------------*/
/*---Line Follower---[B]-------------------[N/A]-------------*/
/*---Tower/Stack-----[D]-------------------[L/R]-------------*/
/*---Left/Right------[E]-------------------[L/R]-------------*/
/*---Left Limit------[G]-------------------[N/A]-------------*/
/*---Right Limit-----[H]-------------------[N/A]-------------*/

#include "vision.h"

using namespace vex;

competition Competition = competition();
int potval, typeval;
const double TILE = 589.28; //mm
bool b = false;
 
void upArm();
void downArm();

void pre_auton()
{
  GYRO.startCalibration();
  while(GYRO.isCalibrating())
  {
    vex::task::sleep(10);
  }
  potval = POT.value(percentUnits::pct);
  typeval = POT2.value(percentUnits::pct);
}

void autonomous()
{

}

void usercontrol()
{
  arm.setVelocity(50, percentUnits::pct);
  claw.setVelocity(50, percentUnits::pct);

  while(true)
  {
    b_left.spin(directionType::fwd, Controller.Axis3.position(), percentUnits::pct);
    b_right.spin(directionType::fwd, Controller.Axis2.position(), percentUnits::pct);


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

    //---claw
    if(Controller.ButtonL1.pressing())
    {
      claw.spin(directionType::fwd);
    }
    else if(Controller.ButtonL2.pressing())
    {
      claw.spin(directionType::rev);
    }
    else
    {
      claw.stop(brakeType::hold);
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

void upArm()
{
  arm.spinFor(directionType::fwd, 90, rotationUnits::deg, false);
}

void downArm()
{
  arm.spinFor(directionType::rev, 90, rotationUnits::deg, false);
}