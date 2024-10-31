#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor TL = motor(PORT16, ratio6_1, true);//front motor
motor BL = motor(PORT14, ratio6_1, true);//back motor on bottom
motor ML = motor(PORT10, ratio6_1, true);//high back motor
motor TR = motor(PORT7, ratio6_1, false);
motor BR = motor(PORT13, ratio6_1, false);
motor MR = motor(PORT5, ratio6_1, false);
motor armMotorA = motor(PORT9, ratio6_1, false);
motor armMotorB = motor(PORT19, ratio6_1, false);
motor_group arm = motor_group(armMotorA, armMotorB);
motor towerConvey = motor(PORT18, ratio6_1, true);
motor frontConvey = motor(PORT8, ratio6_1, false);
motor_group convey = motor_group(towerConvey, frontConvey);
//Add your devices below, and don't forget to do the same in robot-config.h:
controller Controller1 = controller(primary);
inertial imu = inertial(PORT11);
//rotation hori = rotation(PORT20, false);
//rotation vert = rotation(PORT9, false);
digital_out msClamp = digital_out(Brain.ThreeWirePort.A);
/*
motor_group enter = motor_group(enterMotorA, enterMotorB);
digital_out lpusher = digital_out(Brain.ThreeWirePort.G);
*/
void vexcodeInit( void ) {
  // nothing to initialize
}