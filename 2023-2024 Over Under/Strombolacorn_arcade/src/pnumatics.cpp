#include "vex.h"
using namespace vex;
bool lpushActive = false;
  void lpush(){
    //left wing
    if (Controller1.ButtonY.pressing() && !lpushActive){
      lpusher.set(true);
      waitUntil(!Controller1.ButtonY.pressing());
      lpushActive = true;
    }

    else if (Controller1.ButtonY.pressing() && lpushActive){
      lpusher.set(false);
      waitUntil(!Controller1.ButtonY.pressing());
      lpushActive = false;
    }
  }
bool rpushActive = false;
  void rpush(){
    //Right wing
    if (Controller1.ButtonA.pressing() && !rpushActive){
      rpusher.set(true);
      waitUntil(!Controller1.ButtonA.pressing());
      rpushActive = true;
    }

    else if (Controller1.ButtonA.pressing() && rpushActive){
      rpusher.set(false);
      waitUntil(!Controller1.ButtonA.pressing());
      rpushActive = false;
    }
  }
  bool pushActive = false;
  void push(){
    //both wings
    if (Controller1.ButtonB.pressing() && !pushActive){
      lpusher.set(true);
      rpusher.set(true);
      waitUntil(!Controller1.ButtonB.pressing());
      pushActive = true;
    }

    else if (Controller1.ButtonB.pressing() && pushActive){
      lpusher.set(false);
      rpusher.set(false);
      waitUntil(!Controller1.ButtonB.pressing());
      pushActive = false;
    }
  }
bool fpushActive = false;
  void fpush(){
    //Right wing
    if (Controller1.ButtonX.pressing() && !rpushActive){
      fpusher.set(true);
      waitUntil(!Controller1.ButtonX.pressing());
      fpushActive = true;
    }

    else if (Controller1.ButtonX.pressing() && rpushActive){
      fpusher.set(false);
      waitUntil(!Controller1.ButtonX.pressing());
      fpushActive = false;
    }
  }