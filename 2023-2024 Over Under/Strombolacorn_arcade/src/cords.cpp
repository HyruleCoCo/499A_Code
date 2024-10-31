#include "vex.h"
using namespace vex;
bool cordsActive = false;
  void cords(){
    //Brain.Screen.setCursor(9,1);
    Brain.Screen.printAt(50, 90, "Battery: %d%%", Brain.Battery.capacity());
    //Brain.Screen.setCursor(10,1);
    Brain.Screen.printAt(5, 100, "corodonates: (", chassis.get_X_position(), " , ", chassis.get_Y_position(), " )");
    //Brain.Screen.setCursor(11, 1);
    Brain.Screen.printAt(50, 100, "heading: %.2f%C",chassis.get_absolute_heading());
  }

bool bateryPercentActive = false;
  void batteryPercent(){
    //a
  }