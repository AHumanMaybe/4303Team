/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain = vex::brain();

vex::controller Controller = vex::controller();

vex::motor LEFT = vex::motor(vex::PORT1);
vex::motor RIGHT = vex::motor(vex::PORT2, true);
vex::motor HD = vex::motor(vex::PORT6);
vex::motor LARM = vex::motor(vex::PORT11);
vex::motor RARM = vex::motor(vex::PORT12, true);
vex::motor LCLAW = vex::motor(vex::PORT16, true);
vex::motor RCLAW = vex::motor(vex::PORT17);

//sensors
vex::pot AUTO = vex::pot(Brain.ThreeWirePort.A);
vex::limit LIMIT = vex::limit(Brain.ThreeWirePort.D);
vex::gyro GYRO = vex::gyro(Brain.ThreeWirePort.E);
vex::line LINE = vex::line(Brain.ThreeWirePort.H);