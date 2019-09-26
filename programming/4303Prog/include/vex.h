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

/*//sensors
vex::pot AUTO = vex::pot(Brain.ThreeWirePort.A);
vex::limit LIMIT = vex::limit(Brain.ThreeWirePort.D);
vex::gyro GYRO = vex::gyro(Brain.ThreeWirePort.E);
vex::line LINE = vex::line(Brain.ThreeWirePort.H);*/