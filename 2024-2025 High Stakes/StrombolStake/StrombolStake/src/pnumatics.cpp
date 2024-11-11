#include "vex.h"
using namespace vex;

void pnumatic(){
    bool clampActive = false;
    if (Controller1.ButtonR2.pressing() && !clampActive){
        msClamp.set(true);
        clampActive = true;
    }
    else if (Controller1.ButtonR2.pressing() && clampActive){
        msClamp.set(false);
        clampActive = false;
    }
}