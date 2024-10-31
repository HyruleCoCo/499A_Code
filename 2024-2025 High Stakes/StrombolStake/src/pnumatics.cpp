#include "vex.h"
using namespace vex;

bool clampActive = false;
void pnumatics(){
    if (Controller1.ButtonL1.pressing() && !clampActive){
        msClamp.set(true);
        waitUntil(!Controller1.ButtonL1.pressing());
        clampActive = true;
    }

    else if(Controller1.ButtonL2.pressing() && clampActive){
        msClamp.set(false);
        waitUntil(!Controller1.ButtonL2.pressing());
        clampActive = false;
    }
}