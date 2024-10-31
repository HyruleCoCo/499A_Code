#include "vex.h"
//drive wont stop in autons
void far_side(){
  chassis.turn_timeout = 750;
  chassis.swing_timeout = 750;
  chassis.set_coordinates(36, 9.25, 0);
  enter.spin(fwd, 100, pct);
  chassis.drive_to_point(60, 24);
  chassis.right_swing_to_angle(0);
  enter.spin(reverse, 100, pct);
  wait(500, msec);
  chassis.drive_distance(10);
  chassis.drive_distance(-10);
  enter.stop();
  //chassis.set_coordinates(55, 22, -1);//reset bot position
  chassis.drive_to_point(36, 36);
  enter.spin(fwd, 100, pct);
  chassis.drive_to_point(12, 68);
  chassis.right_swing_to_angle(-65);
  chassis.drive_to_point(39, 62);
  chassis.drive_to_point(24, 62);
  chassis.turn_to_angle(90);
  chassis.set_coordinates(28, 59, 90);
  enter.spin(reverse, 100, pct);
  chassis.drive_to_point(42, 59);
  chassis.drive_to_point(27, 59);
  /*chassis.turn_to_point(6, 48);
  enter.spin(fwd, 100, pct);
  chassis.drive_to_point(6, 45);*/
}
void close_side(){
  chassis.set_coordinates(-36, 9.25, 0);
  enter.spin(fwd, 100, pct);
  chassis.drive_to_point(-60, 24);
  chassis.left_swing_to_angle(0);
  enter.spin(reverse, 100, pct);
  wait(500, msec);
  chassis.drive_distance(11);
  chassis.drive_distance(-11);
  enter.stop();
  chassis.turn_to_point(-36, 36);
  chassis.drive_to_point(-36, 36);
  chassis.turn_to_angle(0);
  chassis.drive_to_point(-33, 47);
  chassis.right_swing_to_angle(-90);
  rpusher.set(true);
  chassis.drive_distance(-28);
  chassis.drive_distance(26);
  rpusher.set(false);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-48);
  chassis.set_coordinates(-36, 12, 0);
  chassis.turn_to_angle(90);
  chassis.drive_distance(32);
  chassis.left_swing_to_angle(90);
}
void skills(){
  chassis.set_coordinates(36, 6, 0);
  enter.spin(reverse, 90, pct);//flywheel is currently plugged into intake port
  chassis.drive_to_point(56, 27);//match load start
  chassis.turn_to_angle(118);
  chassis.drive_distance(5);
  wait(30, sec);
  enter.stop(coast);//match load end flywheel is currently plugged into intake port
  chassis.drive_to_point(36, 36);
  chassis.turn_to_angle(185);
  chassis.drive_distance(-98);
  chassis.turn_to_angle(90);
  //fpusher = true;
  chassis.drive_to_point(-36, 132);
  lpusher = true;
  chassis.drive_to_point(-43, 120);
  //chassis.turn_to_point(-58, 96);
  chassis.drive_to_point(-58, 118);
  chassis.turn_to_angle(0);
  chassis.drive_distance(5);
  wait(0.25, sec);
  chassis.drive_distance(-11);
}
void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0); //voltage, kp, ki, kd, starti
  chassis.set_heading_constants(6, .4, 0, 1, 0); //voltage, kp, ki, kd, starti
  chassis.set_turn_constants(12, .4, .03, 3, 15); //voltage, kp, ki, kd, starti
  chassis.set_swing_constants(12, .3, .001, 2, 15); //voltage, kp, ki, kd, starti
  chassis.set_drive_exit_conditions(1.5, 300, 5000); //settle error, settle time, timeout
  chassis.set_turn_exit_conditions(1, 300, 3000); //settle error, settle time, timeout
  chassis.set_swing_exit_conditions(1, 300, 3000); //settle error, settle time, timeout
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
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