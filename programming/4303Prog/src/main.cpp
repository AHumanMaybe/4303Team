/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Evan N. Hess                                              */
/*    Created:      Sun Sep 08 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

void pre_auton(void) 
{

}

void autonomous(void) 
{
  
}

void usercontrol(void) 
{
  while(1)
  {

  }
}

int main() 
{
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    pre_auton();
       
    while(1) 
    {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}