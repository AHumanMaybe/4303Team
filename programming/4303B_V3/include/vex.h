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
vex::light LINE(Brain.ThreeWirePort.B);
vex::pot POT(Brain.ThreeWirePort.D);
vex::pot POT2(Brain.ThreeWirePort.E);
vex::limit LL(Brain.ThreeWirePort.G);
vex::limit RL(Brain.ThreeWirePort.H);

vex::motor b_left(vex::PORT13);
vex::motor b_right(vex::PORT17, true);
vex::smartdrive base(b_left, b_right, GYRO, 319.19, 355.6, 130, vex::distanceUnits::mm);

//arm (l1, r1) [r1 is up]
vex::motor l_arm1(vex::PORT14, vex::gearSetting::ratio36_1, true);
vex::motor l_arm2(vex::PORT12, vex::gearSetting::ratio36_1);
vex::motor r_arm1(vex::PORT15, vex::gearSetting::ratio36_1, true);
vex::motor r_arm2(vex::PORT16, vex::gearSetting::ratio36_1);
vex::motor_group arm(l_arm1, l_arm2, r_arm1, r_arm2);

//bottom claw (l2, r2) [r2 is open]
vex::motor claw(vex::PORT4, true);