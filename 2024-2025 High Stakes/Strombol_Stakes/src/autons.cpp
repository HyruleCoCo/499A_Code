#include "vex.h"

int grab(){
  wait(880, msec);
  msClamp.set(true);
  return 0;
}

void redPos(){
  chassis.set_coordinates(-63, -23.4, 270);
  // grab the first ms
  vex::task mS(grab);
  chassis.drive_to_point(-38, -23.4);// 270
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-11);
  chassis.drive_max_voltage = 9;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);
  // get the secong ring
  chassis.drive_distance(6);
  chassis.turn_to_angle(180);
  chassis.drive_to_point(-33, -43.744);// 145
  wait(1.5, sec);
  chassis.drive_distance(6);
  //chassis.turn_to_angle(270);
  
  /*chassis.drive_to_point(-40, -2.5);// 0  possibly doink a ring stack, probably not going to happen for now
  chassis.drive_to_point(-40, -2.5);// 270
  chassis.drive_to_point(-42.144, -4.297);// 235*/
  wait(500, msec);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(0);
  convey.stop();
  chassis.drive_to_point(-26, 0);// 90 
}

void redNeg(){
  chassis.set_coordinates(-63, 23.4, 270);
  // grab the first ms
  vex::task mS(grab);
  chassis.drive_to_point(-38, 23.4);// 270
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-11);
  chassis.drive_max_voltage = 9;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);
  // get the secong ring
  chassis.drive_distance(6);
  chassis.turn_to_angle(0);
  chassis.drive_to_point(-33, 43.744);// 145
  wait(1.5, sec);
  chassis.drive_distance(6);
  //chassis.turn_to_angle(270);
  
  /*chassis.drive_to_point(-40, -2.5);// 0  possibly doink a ring stack, probably not going to happen for now
  chassis.drive_to_point(-40, -2.5);// 270
  chassis.drive_to_point(-42.144, -4.297);// 235*/
  wait(500, msec);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(180);
  convey.stop();
  chassis.drive_to_point(-26, 0);// 90  
}

void bluePos(){
  chassis.set_coordinates(63, -23.4, 90);
  // grab the first ms
  vex::task mS(grab);
  chassis.drive_to_point(38, -23.4);// 270
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-11);
  chassis.drive_max_voltage = 9;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);
  // get the secong ring
  chassis.drive_distance(6);
  chassis.turn_to_angle(180);
  chassis.drive_to_point(33, -43.744);// 145
  wait(1.5, sec);
  chassis.drive_distance(6);
  //chassis.turn_to_angle(270);x
  
  /*chassis.drive_to_point(-40, -2.5);// 0  possibly doink a ring stack, probably not going to happen for now
  chassis.drive_to_point(-40, -2.5);// 270
  chassis.drive_to_point(-42.144, -4.297);// 235*/
  wait(500, msec);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(0);
  convey.stop();
  chassis.drive_to_point(26, 0);// 90 
}

void blueNeg(){
  chassis.set_coordinates(63, 23.4, 90);
  // grab the first ms
  vex::task mS(grab);
  chassis.drive_to_point(38, 23.4);// 270
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-11);
  chassis.drive_max_voltage = 9;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);
  // get the secong ring
  chassis.drive_distance(6);
  chassis.turn_to_angle(0);
  chassis.drive_to_point(33, 43.744);// 145
  wait(1.5, sec);
  chassis.drive_distance(6);
  //chassis.turn_to_angle(270);
  
  /*chassis.drive_to_point(-40, -2.5);// 0  possibly doink a ring stack, probably not going to happen for now
  chassis.drive_to_point(-40, -2.5);// 270
  chassis.drive_to_point(-42.144, -4.297);// 235*/
  wait(500, msec);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(180);
  convey.stop();
  chassis.drive_to_point(26, 0);// 90 
}


int snatch2(){
  wait(405, msec);
  msClamp.set(true);
  return 0;
}
void skills(){
  chassis.set_coordinates(-75, 23, 270);

  // grab first ms
  vex::task msSnatch(snatch2);   
  chassis.drive_to_point(-56.004, 23.697);// 270
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);

  // grab first ring
  chassis.turn_to_angle(90);
  chassis.drive_to_point(-23.057, 23.057);// 90
  wait(500, msec);

  // grab second ring
  chassis.drive_to_point(-24.016, 49.607);// 0
  wait(500, msec);

  // grab thrid & fourth ring
  chassis.turn_to_angle(270);
  chassis.drive_max_voltage = 7;
  chassis.drive_to_point(-63.361, 46.088);// 45
  wait(500, msec);

  // grab fifth ring
  chassis.drive_to_point(-45.448, 60.482);// 100

  // put ms in corner
  chassis.turn_to_angle(110);
  chassis.drive_to_point(-60, 59);// 135
  msClamp.set(false);

  // grab another ring
  chassis.drive_to_point(-3.864, 2.265);// 0
  wait(250, msec);
  convey.stop(hold);

  // grab next ms
  chassis.drive_to_point(-23.377, -9.251);// 0
  chassis.turn_to_angle(45);
  vex::task mS(grab);
  chassis.drive_to_point(-41.29, -18.847);// 45
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;// resets voltage
  convey.spin(fwd, 100, pct);
  wait(1, sec);

  // grab first ring
  chassis.turn_to_angle(135);
  chassis.drive_to_point(-23.057, -24.925);// 0
  wait(500, msec);

  // grab second ring
  chassis.turn_to_angle(180);
  chassis.drive_to_point(-24.656, -46.037);// 0
  wait(500, msec);

  // grab third & fourth ring
  chassis.drive_max_voltage = 7;
  chassis.drive_to_point(-66.24, -45.077);// 0
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // grab fifth ring
  chassis.drive_to_point(-46.728, -46.037);// 0
  chassis.turn_to_angle(180);
  chassis.drive_to_point(-47.687, -56.593);// 0
  wait(500, msec);

  // put ms in corner
  chassis.turn_to_angle(45);
  chassis.drive_to_point(-61.442, -57.552);// 45
  msClamp.set(false);
  wait(200, msec);

  // grab next ms
  chassis.drive_to_point(23.325, -33.562);// 0
  convey.stop();
  chassis.turn_to_angle(225);
  vex::task ms(grab);
  chassis.drive_to_point(48.596, -24.285);// 260
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;// resets voltage

  // put in corner
  chassis.turn_to_angle(180);
  chassis.drive_to_point(62.351, -58.512);// 325
  doink.set(true);
  chassis.turn_to_angle(0);
  msClamp.set(false);
  doink.set(false);

  // grab next ms
  chassis.drive_to_point(59.472, 0.665);// 0
  chassis.turn_to_angle(180);
  vex::task msGrab(snatch2);
  chassis.drive_to_point(59.152, 14.74);// 180
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;// resets voltage

  // put ms in corner
  chassis.turn_to_angle(0);
  chassis.drive_to_point(63.63, 59.523);// 225
  doink.set(true);
  chassis.turn_to_angle(135);
  wait(40, msec);
  chassis.turn_to_angle(180);
  msClamp.set(false);
  doink.set(false);

  // grab next ms
  chassis.drive_to_point(46.996, 25.296);// 0
  chassis.turn_to_angle(0);
  vex::task msGrabs(snatch2);
  chassis.drive_to_point(46.357, 6.423);// 0
  chassis.drive_max_voltage = 4;// go to a lower voltage to make sure we get the ms
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;// resets voltage

  // grab first ms
  convey.spin(fwd, 100, pct);
  chassis.drive_to_point(22.046, 23.377);// 0
  wait(500, msec);

  // grab second ms
  chassis.drive_to_point(21.406, 49.607);// 0
  wait(500, msec);

  // grab thrid ms
  chassis.drive_to_point(-0.345, 58.563);// 0
  wait(300, msec);

  // grab fourth ms
  chassis.drive_to_point(34.521, 29.454);// 0
  chassis.turn_to_angle(180);
  chassis.drive_to_pose(36, -3, 200);
  chassis.drive_to_point(22.686, -23.325);// 0
  wait(300, msec);

  // grab fifth ms
  chassis.drive_to_pose(24.285, -47.316, 200);// 0

  // grab sixth ms
  chassis.drive_to_point(2.533, -59.152);// 0
  msClamp.set(false);

  // donuts
  chassis.drive_to_point(-8, -40);
  chassis.DriveL.spin(fwd, 100, pct);
}

void donuts(){
  chassis.drive_distance(-10);
  chassis.DriveL.spin(fwd, 100, pct);
  chassis.DriveR.spin(reverse, 100, pct);
}
/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(5, .4, .03, 5, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  
  chassis.drive_kp = 1.5;
  chassis.drive_ki = 0.1;
  chassis.drive_kd = 7.05;

  chassis.heading_kp = 0.4;
  chassis.heading_ki = 0;
  chassis.heading_kd = 1;

  chassis.turn_kp =1;
  chassis.turn_ki = 0.09;
  chassis.turn_kd = 10;

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 8;
  chassis.drive_max_voltage = 10;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = 0;// was set to 0.5 as defai;t
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(48);
  wait(1, sec);
  chassis.drive_distance(-48);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}
