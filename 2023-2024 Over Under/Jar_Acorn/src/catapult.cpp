#include "vex.h"
using namespace vex;
bool catapultActive = false;
  void catapult(){
    //cata.spin(rev, 25, pct);
    if ((Controller1.ButtonR2.pressing() && !catapultActive)){
    cata1.spin(reverse, 75, pct);
    cata2.spin(reverse, 75, pct);
    waitUntil(!Controller1.ButtonR2.pressing());
    catapultActive = true;
  }
  else if ((Controller1.ButtonR2.pressing() && !catapultActive)){
    cata1.stop();
    cata2.stop();
    waitUntil(!Controller1.ButtonR2.pressing());
    catapultActive = false;
  }
  }