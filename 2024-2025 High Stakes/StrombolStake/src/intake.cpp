#include "vex.h"
using namespace vex;

void conveyor(){
    if(Controller1.ButtonR2.pressing()){
        convey.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonR1.pressing()){
        convey.spin(reverse, 100, pct);
    }
    else{
        convey.stop(hold);
    }
}
