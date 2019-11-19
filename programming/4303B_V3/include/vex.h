/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain = vex::brain();
vex::controller Controller = vex::controller();

vex::gyro GYRO(Brain.ThreeWirePort.A);
vex::limit LIMIT(Brain.ThreeWirePort.H);

vex::motor b_left(vex::PORT1);
vex::motor b_right(vex::PORT5, true);
vex::motor hdrive(vex::PORT6);
vex::smartdrive base(b_left, b_right, GYRO, 319.19, 355.6, 130, vex::distanceUnits::mm);

//arm (r1, r2)
vex::motor l_arm(vex::PORT11, true);
vex::motor r_arm(vex::PORT15);
vex::motor_group arm(l_arm, r_arm);

//top claw (l1, l2) [1 is open]
vex::motor top(vex::PORT16);
//bottom claw (x, b) [x is open]
vex::motor bottom(vex::PORT20);

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)