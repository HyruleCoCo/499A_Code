#include "vex.h"
using namespace vex;
bool driveActive = false;
//arcade drive commands

void udrive(){
  double jValuesTL = Controller1.Axis3.position() + Controller1.Axis4.position();
  double jValuesTR = Controller1.Axis3.position() - Controller1.Axis4.position();
  double jValuesBL = Controller1.Axis3.position() + Controller1.Axis4.position();
  double jValuesBR = Controller1.Axis3.position() - Controller1.Axis4.position();

  TL.spin(fwd, jValuesTL, pct);
  TR.spin(fwd, jValuesTR, pct);
  BL.spin(fwd, jValuesBL, pct);
  BR.spin(fwd, jValuesBR, pct);
}