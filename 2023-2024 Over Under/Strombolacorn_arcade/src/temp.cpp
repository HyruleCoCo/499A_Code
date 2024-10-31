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
    Brain.Screen.print("fly: %.2f%C",fly.temperature(celsius));
    Brain.Screen.setCursor(7,1);
    Brain.Screen.print("-------------------------------------------------------------------");
    Brain.Screen.setCursor(9,1);
    Brain.Screen.print("Battery: %d%%", Brain.Battery.capacity());
    Brain.Screen.setCursor(10,1);
    Brain.Screen.print("corodonates: (", chassis.get_X_position(), " , ", chassis.get_Y_position(), " )");
    Brain.Screen.setCursor(11, 1);
    Brain.Screen.print("heading: %.2f%C",chassis.get_absolute_heading());
    tempAlert();
  }

  
  bool tempAlertActive = false;
  void tempAlert(){
    if ((TL.temperature(celsius) >= 55 || TR.temperature(celsius) >=55 || BL.temperature(celsius) >= 55 || BR.temperature(celsius) >= 55)){
      Controller1.rumble("-");
      Brain.Screen.setFillColor(red);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("dt");
      wait(1, sec);
      Controller1.rumble("");
    }
    if ((fly.temperature(celsius) >= 55)){
      Controller1.rumble("-_");
      Brain.Screen.setFillColor(red);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("fly");
      wait(1, sec);
      Controller1.rumble("");
  }
  }