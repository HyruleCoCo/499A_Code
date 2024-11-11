#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor TL = motor(PORT1, ratio6_1, false);//front motor
motor BL = motor(PORT2, ratio6_1, true);//back motor on bottom
motor TBL = motor(PORT3, ratio6_1, false);//high back motor
motor TR = motor(PORT4, ratio6_1, true);
motor BR = motor(PORT5, ratio6_1, false);
motor TBR = motor(PORT6, ratio6_1, true);
motor arm = motor(PORT10, ratio6_1, false);
motor FI = motor(PORT20, ratio6_1, false);//front intake
motor convey = motor(PORT21, ratio6_1, false);
//Add your devices below, and don't forget to do the same in robot-config.h:
controller Controller1 = controller(primary);
inertial imu = inertial(PORT7);
rotation hori = rotation(PORT8, false);
rotation vert = rotation(PORT9, false);
rotation armTrack = rotation(PORT11, false);
rotation armTrack2 = rotation(PORT12, false);
digital_out msClamp = digital_out(Brain.ThreeWirePort.A);
/*
motor_group enter = motor_group(enterMotorA, enterMotorB);
digital_out lpusher = digital_out(Brain.ThreeWirePort.G);
*/
void vexcodeInit( void ) {
  // nothing to initialize
}