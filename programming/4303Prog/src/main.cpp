/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan N. Hess                                              */
/*    Created:      Sun Sep 08 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "v5.h"
#include "v5_vcs.h"
#include "usercontrol.h"
#include "autonomous.h"

using namespace vex;

vex::competition Competition = vex::competition();

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