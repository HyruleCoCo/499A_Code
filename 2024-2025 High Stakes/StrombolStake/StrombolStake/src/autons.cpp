#include "vex.h"
#include <autons.h>

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */
void leftPos(){// blue alliance
  chassis.set_coordinates(64, -24, -90);
  chassis.drive_to_point(66, -5);// drive to wall stake
  //put ring on stake
  arm.spin(reverse, 100, pct);
  wait(500, msec);
  arm.stop();
  chassis.drive_distance(5);
  arm.spin(fwd, 100, pct);
  wait(200, msec);
  arm.stop(hold);
  //drop ring off of arm
  arm.spin(reverse, 100, pct);
  wait(200, msec);
  arm.stop(hold);
  chassis.drive_distance(-5);
  arm.spin(fwd, 100, pct);
  wait(500, msec);
  arm.stop();
  //put ring on alliance stake
  chassis.drive_to_point(52, -9);// drive to ring stack
  chassis.drive_to_point(46, -4);
  //yoink top ring
  chassis.turn_to_angle(0);// turn to face stack
  FI.spin(fwd, 100, pct);//take in bottom ring
  wait(250, msec);
  chassis.turn_to_angle(45);
  FI.spin(reverse, 100, pct);// spit out ring
  wait(250, msec);
  chassis.turn_to_angle(0);// turn back to stack
  FI.spin(fwd, 100, pct);
  convey.spin(fwd, 100, pct);// get ring onto conveytor
  wait(250, msec);
  convey.stop();
  //yoink top ring
  chassis.drive_to_point(26, -22);// drive to mobile stake
  //yoink stake
  chassis.turn_to_angle(45);// turn to clamp faces stake
  msClamp.set(true);
  convey.spin(fwd, 100, pct);// get ring onto the ms
  //yoink stake
  chassis.drive_to_point(57, -43);
  convey.spin(reverse, 100, pct);
  FI.spin(fwd, 100, pct);
  chassis.drive_to_point(62, -63);// drive to corner 4 stack
  // yoink second to top ring and bottom ring 
  chassis.turn_to_angle(145);// turn to face stack
  wait(100, msec);
  chassis.drive_distance(-5);// back up so the intake wont intake the second ring
  convey.spin(fwd, 100, pct);// get ring on ms
  wait(100, msec);
  convey.stop();
  chassis.drive_distance(5);// drive back into stack
  wait(100, msec);
  chassis.turn_to_angle(200);// turn to spit out ring we dont want
  FI.spin(reverse, 100, pct);//spit out ring
  chassis.turn_to_angle(145);// turn back to stack
  FI.spin(fwd, 100, pct);// get ring we want
  wait(100, msec);
  chassis.turn_to_angle(-90);//turn away from stack
  convey.spin(fwd, 100, pct);
  // put rings on stake
  chassis.drive_to_point(23, -51);// drive to ring stack
  //yoink bottom ring 
  convey.stop();
  FI.spin(fwd, 100, pct);
  //yoink bottom ring
  chassis.drive_to_point(13, -19);// drive to ladder
  convey.spin(fwd, 100, pct);
  arm.spin(reverse, 100, pct);// make sure arm reaches ladder
  wait(500, msec);
  arm.stop();
  convey.stop();
}

void rightPos(){// red alliance
  chassis.set_coordinates(-64, -24, 90);
  chassis.drive_to_point(-66.127, -5.684);// drive to wall stake
  //put ring on stake
  chassis.drive_to_point(-52.339, -9.322);// drive to ring stack
  chassis.drive_to_point(-46.786, -4.535);
  //yoink top ring
  chassis.drive_to_point(-26.679, -22.152);// drive to mobile stake
  //yoink stake
  //put ring on stake
  chassis.drive_to_point(-56.935, -43.408);
  chassis.drive_to_point(-62.489, -63.706);// drive to cornor 4 stack
  // yoink top ring and second to bottom ring
  //put rings on stake
  chassis.drive_to_point(-22.849, -51.451);// drive to ring stack
  //yoink bottom ring
  chassis.drive_to_point(-12.891, -19.28);// drive to ladder
}
void leftNeg(){// red alliance
  chassis.set_coordinates(-64, 24, 90);
  chassis.drive_to_point(-63.446, 5.615);// drive to the alliance wall stake
  //put ring on stake
  chassis.drive_to_point(-65.744, 59.042);// driving to the 4 stack 
  // grab bottom and second from top
  chassis.drive_to_point(-23.424, 21.892);// drive to mobile goal
  // grab mobile goal
  // place rings onto mobile goal
  chassis.drive_to_point(-23.998, 46.403);// drive to 2 stack
  // grab bottom ring
  chassis.drive_to_point(-3.508, 50.807);// drive to border rings
  // grab bottom ring
  chassis.drive_to_point(-11.551, 50.424);// back up
  chassis.drive_to_point(-12.125, 43.722);// align with 2nd border ring
  chassis.drive_to_point(-3.317, 42.573);// drive to 2nd border ring
  // grab bottom ring
  chassis.drive_to_point(-15.125, 43.722);// back up to not go over auton line
  chassis.drive_to_point(-9.828, 15.764);// drive and touch with ladder
}
void rightNeg(){// blue alliance
  chassis.set_coordinates(64, 24, -90);
  chassis.drive_to_point(63, 5);// drive to alliance wall stake
  //put ring on stake
  arm.spin(reverse, 100, pct);
  wait(500, msec);
  arm.stop();
  chassis.drive_distance(5);
  arm.spin(fwd, 100, pct);
  wait(200, msec);
  arm.stop(hold);
  //drop ring off of arm
  arm.spin(reverse, 100, pct);
  wait(200, msec);
  arm.stop(hold);
  chassis.drive_distance(-5);
  arm.spin(fwd, 100, pct);
  wait(500, msec);
  arm.stop();
  // put ring on alliance stake
  chassis.drive_to_point(64, 60);// drive to 4 stack
  chassis.drive_to_point(26, 22);// drive to mobile goal
  //grab mobile goal
  chassis.turn_to_angle(90);
  msClamp.set(true);
  //grab ms
  // grab bottom and second from top ring
  chassis.turn_to_angle(45);
  FI.spin(fwd, 100, pct);
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(250, msec);
  convey.stop();
  chassis.drive_distance(5);
  wait(100, msec);
  chassis.turn_to_angle(-20);
  FI.spin(reverse, 100, pct);
  FI.spin(fwd, 100, pct);
  chassis.turn_to_angle(45);
  wait(250, msec);
  chassis.drive_distance(5);
  convey.spin(fwd, 100, pct);
  // grab 4 stack rings
  // place rings on goal
  convey.stop();
  chassis.drive_to_point(25.5, 46);// drive to 2 stack
  // grab bottom ring
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(100, msec);
  convey.stop();
  // grabbed bottom ring
  chassis.drive_to_point(3, 50);// drive to border rigns
  // grab bottom ring
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(100, msec);
  convey.stop();
  // grabbed bottom ring
  chassis.drive_distance(-10);//back up
  chassis.drive_to_point(12, 43);// align with 2nd border rings
  chassis.drive_to_point(3, 42);// drive to 2nd border rings
  // grab bottom ring
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(100, msec);
  convey.stop();
  // grabbed bottom ring
  chassis.drive_distance(-10);// back up to not go over auton
  chassis.drive_to_point(10, 19);// drive and touch with ladder
  arm.spin(fwd, 100, pct);
}

void skills(){
  chassis.set_coordinates(-63, -24, 0);// red alliance pos corner
  chassis.drive_to_point(-65, -4);// drive to alliance stake
  // put preload onto stake
  chassis.drive_to_point(-46, -16);// drive to mobile goal
  // clamp mobile goal
  // set intake and conveyor to constantly be going
  chassis.drive_to_point(-26, -20);// drive to ring
  chassis.drive_to_point(-21, -44);// drive to ring
  chassis.drive_to_point(-44, -45);// drive to ring
  chassis.drive_to_point(-43, -58);// drive to ring
  chassis.drive_to_point(-56, -48);// drive to ring
  chassis.drive_to_point(-63, -62);// drive into pos corner
  // drop off goal into pos corner
  chassis.drive_to_point(-47, 17);// drive to mobile goal in red neg zone
  //pick up goal
  chassis.drive_to_point(-24, 22);// drive to ring
  chassis.drive_to_point(-23, 42);// drive to ring
  chassis.drive_to_point(-46, 43);// drive to ring
  chassis.drive_to_point(-60, 44);// drive to ring
  chassis.drive_to_point(-49, 55);// drive to ring
  chassis.drive_to_point(1, 47);// path to blue ring
  chassis.drive_to_point(41, 58);// drive to blue ring
  // make blue ring top ring
  chassis.turn_to_point(0, 0);
  //drop off goal
  chassis.drive_to_point(35, 10);
  chassis.drive_to_point(42, 2);// drive to mobile goal'
  // clamp goal
  chassis.drive_to_point(42, 2);// drive to ring
  chassis.drive_to_point(27, -21);// drive to ring
  chassis.drive_to_point(26, -45);// drive to ring
  chassis.drive_to_point(3, -56);// path to ring
  chassis.drive_to_point(13, -22);// drive to ring
  chassis.drive_to_point(1, 0);// drive to ring
  chassis.drive_to_point(21, 21);// drive to ring
  chassis.drive_to_point(22, 43);// drive to blue ring
  // make blue ring top ring
  chassis.turn_to_point(0, 0);
  // drop goal
  chassis.drive_to_point(7, 22);
  // hang
}

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

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
  chassis.heading_max_voltage = 11;
  chassis.drive_max_voltage = 11;
  chassis.drive_settle_error = 1;
  chassis.boomerang_lead = .5;//boomerang notes are after drive to point data in drive.cpp
  chassis.boomerang_lead;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
  chassis.drive_distance(5);
  chassis.drive_distance(-5);
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