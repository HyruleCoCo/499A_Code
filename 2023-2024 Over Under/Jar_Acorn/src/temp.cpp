#include "vex.h"
using namespace vex;
bool tempControlActive = false;
  void tempControl(){
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("TL Temp: %.2f%C",TL.temperature(celsius));
    Brain.Screen.print("  | TR Temp: %.2f%C",TR.temperature(celsius));
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("BL Temp: %.2f%C",BL.temperature(celsius));
    Brain.Screen.print("  | BR Temp: %.2f%C",BR.temperature(celsius));
    Brain.Screen.setCursor(3,1);
    Brain.Screen.print("cata1: %.2f%C",cata1.temperature(celsius));
    Brain.Screen.print("  | cata2: &.2f%C",cata2.temperature(celsius));
    Brain.Screen.setCursor(7,1);
    Brain.Screen.print("-------------------------------------------------------------------");
    Brain.Screen.setCursor(9,1);
    Brain.Screen.print("Battery: %d%%", Brain.Battery.capacity());
    tempAlert();
  }

  
  bool tempAlertActive = false;

  void tempAlert(){
    if ((TL.temperature(celsius) >= 55 || TR.temperature(celsius) >=55 || BL.temperature(celsius) >= 55 || BR.temperature(celsius) >= 55)){
      Controller1.rumble("-");
      Brain.Screen.setFillColor(red);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("dt");
    }
    if ((cata1.temperature(celsius) >= 55 || cata1.temperature(celsius) >= 55)){
      Controller1.rumble("-_");
      Brain.Screen.setFillColor(red);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("cata");
  }
  }