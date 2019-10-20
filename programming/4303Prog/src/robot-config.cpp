#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;

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



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}