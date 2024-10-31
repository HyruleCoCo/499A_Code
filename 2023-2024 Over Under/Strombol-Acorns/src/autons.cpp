#include "vex.h"

void far_side(){
  //chassis.drive_timeout = 1000;
  //chassis.turn_timeout = 1000;
  chassis.set_coordinates(36, 9.25, 0);
  chassis.drive_distance(51);
  chassis.turn_to_angle(90);
  enter.spin(reverse, 100, pct);
  chassis.drive_distance(8.25);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-48);
  enter.spin(fwd, 100, pct);
  chassis.drive_distance(33);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(1.75);
  rpusher = true;
  chassis.drive_distance(-32.25);
  rpusher = false;
  chassis.drive_distance(18);
  chassis.turn_to_angle(90);
  enter.spin(reverse, 100, pct);
  chassis.drive_distance(18);
  chassis.drive_distance(-18);
  enter.spin(fwd, 75, pct);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-21.5);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(15);
  chassis.drive_distance(-12);
  chassis.turn_to_angle(45);
  chassis.drive_distance(24);
  chassis.turn_to_angle(90);
  enter.spin(reverse, 100, pct);
  chassis.drive_distance(14);
  enter.stop(coast);
  chassis.drive_distance(-14);
  chassis.turn_to_angle(210);
  chassis.drive_distance(57);
  /*chassis.turn_to_angle(180);
  chassis.drive_distance(56);
  chassis.left_swing_to_angle(-90);
  chassis.drive_distance(24);*/
}
void close_side(){
  chassis.set_coordinates(-36, 9.25, 0);
  chassis.drive_distance(5);
  enter.spin(reverse, 100, pct);
  wait(500, msec);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(-90);
  chassis.set_coordinates(-36, 9.25, 0);
  chassis.drive_distance(24);
  enter.spin(fwd, 100, pct);
  chassis.turn_to_angle(37);
  chassis.drive_distance(37);
  chassis.drive_distance(-40);
  chassis.turn_to_angle(180);
  enter.spin(reverse, 100, pct);
  wait(500, msec);
  chassis.turn_to_angle(0);
  enter.spin(fwd, 100, pct);
  chassis.drive_distance(36);
  chassis.drive_distance(-59);
  chassis.turn_to_angle(90);
  chassis.drive_distance(27);
  enter.spin(reverse, 100, pct);
  wait(500, msec);
  chassis.drive_distance(-27);
  chassis.turn_to_angle(-90);
  enter.spin(fwd, 100, pct);
  chassis.drive_distance(27);
  chassis.drive_distance(-27);
  chassis.turn_to_angle(90);
  chassis.drive_distance(20);
  enter.spin(reverse, 100, pct);
  wait(1, sec);
  enter.stop(coast);
}
void skills(){
  chassis.set_coordinates(36, 9.25, 0);
  enter.spin(fwd, 100, pct);
  chassis.turn_to_angle(78);
  chassis.drive_distance(31);
  chassis.turn_to_angle(0);
  enter.spin(reverse, 100, pct);
  chassis.drive_distance(16);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(78);
  enter.stop(coast);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-2.5);
  wait(3, sec);
  chassis.drive_distance(84);
  chassis.turn_to_angle(135);
  chassis.drive_distance(31);
  chassis.turn_to_angle(0);
  chassis.drive_distance(16);
  chassis.drive_distance(-10);
}
void driveskills(){
  chassis.set_coordinates(36, 9.25, 0);
  enter.spin(fwd, 100, pct);
  chassis.turn_to_angle(78);
  chassis.drive_distance(31);
  chassis.turn_to_angle(0);
  enter.spin(reverse, 100, pct);
  chassis.drive_distance(14);
  chassis.drive_distance(-20);
  enter.stop(coast);
  chassis.turn_to_point(-48, 60);
  chassis.drive_distance(-2.5);
  lpusher = true;
  fly.spin(fwd, 100, pct);
  chassis.DriveL.spin(reverse, 1, pct);
  chassis.DriveR.spin(reverse, 1, pct);
  wait(25, sec);
  Controller1.rumble("___");
  wait(5, sec);
  fly.stop(coast);
  chassis.DriveL.stop();
  chassis.DriveR.stop();
  Controller1.rumble("___");
}
void default_constants(){
  chassis.set_drive_constants(12, 1.5, 0, 10, 0); //voltage, kp, ki, kd, starti
  chassis.set_heading_constants(6, .4, 0, 1, 0); //voltage, kp, ki, kd, starti
  chassis.set_turn_constants(12, .4, .03, 3, 15); //voltage, kp, ki, kd, starti
  chassis.set_swing_constants(12, .3, .001, 2, 15); //voltage, kp, ki, kd, starti
  chassis.set_drive_exit_conditions(1.5, 10, 5000); //settle error, settle time, timeout
  chassis.set_turn_exit_conditions(1, 10, 3000); //settle error, settle time, timeout
  chassis.set_swing_exit_conditions(1, 10, 3000); //settle error, settle time, timeout
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(48);
  chassis.drive_distance(-48);
  /*chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);*/
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}