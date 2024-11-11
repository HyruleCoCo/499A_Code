#include "vex.h"
using namespace vex;
void arms(){
    if(Controller1.ButtonR1.pressing()){
        arm.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonR2.pressing()){
        arm.spin(reverse, 100, pct);
    }
    else{
        arm.stop(hold);
    }
}