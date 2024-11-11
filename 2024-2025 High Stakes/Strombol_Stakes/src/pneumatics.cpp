#include "vex.h"
using namespace vex;

bool clampActive = false;
bool doinkActive = false;
void pnumatics(){
    if (Controller1.ButtonL1.pressing() && !clampActive){
        msClamp.set(true);
        waitUntil(!Controller1.ButtonL1.pressing());
        clampActive = true;
    }

    else if(Controller1.ButtonL1.pressing() && clampActive){
        msClamp.set(false);
        waitUntil(!Controller1.ButtonL1.pressing());
        clampActive = false;
    }

    if (Controller1.ButtonL2.pressing() && !doinkActive){
        doink.set(true);
        waitUntil(!Controller1.ButtonL2.pressing());
        doinkActive = true;
    }

    else if(Controller1.ButtonL2.pressing() && doinkActive){
        doink.set(false);
        waitUntil(!Controller1.ButtonL2.pressing());
        doinkActive = false;
    }
}