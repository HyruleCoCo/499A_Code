#include "vex.h"
using namespace vex;
void frontIntake(){
    if(Controller1.ButtonL1.pressing()){
        FI.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonL2.pressing()){
        FI.spin(reverse, 100, pct);
    }
    else{
    FI.stop(hold);
    }
}
void conveyor(){
    if(Controller1.ButtonL1.pressing()){
        convey.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonL2.pressing()){
        convey.spin(reverse, 100, pct);
    }
    else{
        convey.stop(hold);
    }
}
