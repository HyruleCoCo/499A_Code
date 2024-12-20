#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor TL = motor(PORT13, ratio6_1, true);
motor BL = motor(PORT11, ratio6_1, true);
motor TR = motor(PORT8, ratio6_1, false);
motor BR = motor(PORT9, ratio6_1, false);
inertial Inertial = inertial(PORT5);
digital_out lpusher = digital_out(Brain.ThreeWirePort.G);
digital_out rpusher = digital_out(Brain.ThreeWirePort.H);
digital_out fpusher = digital_out(Brain.ThreeWirePort.F);
motor flyMotorA = motor(PORT18, ratio6_1, false);
motor flyMotorB = motor(PORT19, ratio6_1, true);
motor_group fly = motor_group(flyMotorA, flyMotorB);
motor enterMotorA = motor(PORT16, ratio18_1, false);
motor enterMotorB = motor(PORT17, ratio18_1, true);
motor_group enter = motor_group(enterMotorA, enterMotorB);
motor ML = motor(PORT3, ratio6_1, true);
motor MR = motor(PORT15, ratio6_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}