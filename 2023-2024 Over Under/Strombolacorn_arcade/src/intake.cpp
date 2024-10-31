#include "vex.h"
using namespace vex;

bool intakeActive = false;
void intake(){
  if(Controller1.ButtonR1.pressing() && !intakeActive){
    enter.spin(fwd, 100, pct);
    waitUntil(!Controller1.ButtonR1.pressing());
    intakeActive = true;
  }
  else if (Controller1.ButtonR1.pressing() && intakeActive){
    enter.stop();
    waitUntil(!Controller1.ButtonR1.pressing());
    intakeActive = false;
  }
}

bool outakeActive = false;
void outake(){
  if(Controller1.ButtonL1.pressing() && !outakeActive){
    enter.spin(reverse, 100, pct);
    waitUntil(!Controller1.ButtonL1.pressing());
    outakeActive = true;
  }
  else if (Controller1.ButtonL1.pressing() && outakeActive){
    enter.stop();
    waitUntil(!Controller1.ButtonL1.pressing());
    outakeActive = false;
  }
}