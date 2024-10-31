#include "vex.h"
using namespace vex;

bool flywheelActive = false;
  void flywheel(){
    if ((Controller1.ButtonR2.pressing() && !flywheelActive)){
      fly.spin(fwd, 100, pct);
      waitUntil(!Controller1.ButtonR2.pressing());
      flywheelActive = true;
    }
    else if((Controller1.ButtonR2.pressing() && flywheelActive)){
      fly.stop(coast);
      waitUntil(!Controller1.ButtonR2.pressing());
      flywheelActive = false;
  }
}