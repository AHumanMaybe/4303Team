/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain = vex::brain();
vex::competition Competition = vex::competition();

vex::controller Controller = vex::controller();

vex::motor A = vex::motor(vex::PORT1);
vex::motor B = vex::motor(vex::PORT5, true);
vex::motor HD = vex::motor(vex::PORT11);

vex::motor CLAW = vex::motor(vex::PORT15);
vex::motor L1 = vex::motor(vex::PORT16);
vex::motor L2 = vex::motor(vex::PORT16);
vex::motor R1 = vex::motor(vex::PORT16, true);
vex::motor R2 = vex::motor(vex::PORT20, true);

vex::pot AUTO = vex::pot(Brain.ThreeWirePort.A);
vex::limit LIMIT = vex::limit(Brain.ThreeWirePort.D);
vex::line LINE = vex::line(Brain.ThreeWirePort.H);