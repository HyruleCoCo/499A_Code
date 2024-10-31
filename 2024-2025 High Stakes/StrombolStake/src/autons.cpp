#include "vex.h"
#include <autons.h>

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

//! blue alliance left side
/*startsummary
this is our solo autonomous win point for the left side of blue alliance
endsummary*/
void leftPos(){
  chassis.set_coordinates(0, 0, 90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(180);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(1, sec);
  chassis.drive_distance(-12);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(2, sec);
  msClamp.set(true);
  convey.spin(fwd, 100, pct);
  wait(3, sec);
  //chassis.drive_distance(-3);
  //chassis.turn_to_angle(180);
  //chassis.drive_to_point(-30, -60);
  //wait(500, msec);
  chassis.turn_to_angle(0);
  convey.stop();
  chassis.drive_distance(23);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  msClamp.set(false);
  /*chassis.set_coordinates(66, -30, 0);
  chassis.drive_to_point(65.507, -5.407);// heading of 45
  chassis.turn_to_angle(-135);

  // put preload onto alliance stake
  convey.spin(fwd, 100, pct);
  wait(100, msec);
  convey.stop();

  chassis.drive_to_point(56.574, -17.787);// heading of 0
  chassis.drive_to_point(47.642, -13.556);// heading of 0
  // get bottom ring
  convey.spin(fwd, 100, pct);

  chassis.drive_to_point(47.328, -8.698);// heading of 0 
  wait(50, msec);
  convey.stop();

  chassis.drive_to_point(30.873, -21);// heading of 50
  chassis.turn_to_angle(50);
  msClamp.set(true); // clamp ms stake
  chassis.drive_to_point(54.38, -39.884);// heading of 160
  chassis.drive_to_point(60.932, -60.134);// heading of 145
  // get bottom and second from top ring
  convey.spin(fwd, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.drive_distance(-10);
  convey.spin(fwd, 100, pct);
  wait(50, msec);
  convey.stop();
  chassis.drive_distance(10);
  convey.spin(fwd, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.drive_distance(-10);
  chassis.turn_to_angle(90);
  convey.spin(reverse, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.turn_to_angle(145);
  chassis.drive_distance(10);
  convey.spin(fwd, 100, pct);
  wait(25, msec);

  chassis.drive_to_point(37.208, -62.128);// heading of 305
  chassis.drive_to_point(24, -53.356);// heading of 0
  // get bottom ring
  chassis.drive_to_point(8.619, -19.511);// heading of 0
  convey.stop();
  // touch ladder*/
}
//ENDVEXDOC

//! red alliance right side
/*startsummary
this is our solo autonomous win point for the positive corner for the red alliance
endsummary*/
void rightPos(){// red alliance
  chassis.set_coordinates(0, 0, -90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(180);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(1, sec);
  chassis.drive_distance(-12);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(2, sec);
  msClamp.set(true);
  convey.spin(fwd, 100, pct);
  wait(3, sec);
  //chassis.drive_distance(-3);
  //chassis.turn_to_angle(180);
  //chassis.drive_to_point(-30, -60);
  //wait(500, msec);
  chassis.turn_to_angle(0);
  convey.stop();
  chassis.drive_distance(23);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  msClamp.set(false);
  /*
  chassis.drive_to_point(-29.104, -20.494);// get mobile goal
  chassis.drive_distance(-5);
  chassis.turn_to_angle(315);
  chassis.drive_distance(-5);
  msClamp.set(true);
  convey.spin(fwd, 100, pct);
  wait(500, msec);
  convey.stop();

  chassis.drive_to_point(-61.603, -61.239);// grab bottom and second to top ring
  frontConvey.spin(fwd, 100, pct);
  wait(50, msec);
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(500, msec);
  towerConvey.stop();
  chassis.drive_distance(5);// spit out second ring
  wait(50, msec);
  chassis.drive_distance(-5);
  chassis.left_swing_to_angle(45);
  frontConvey.spin(reverse, 100, pct);
  wait(75, msec);
  chassis.left_swing_to_angle(255);// grab second ring we want
  frontConvey.spin(fwd, 100, pct);
  chassis.drive_distance(5);
  wait(50, msec);
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(500, msec);
  towerConvey.stop();
  chassis.drive_distance(5);// replace top ring with mobile goal
  wait(50, msec);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(45);
  frontConvey.spin(reverse, 100, pct);
  chassis.drive_distance(-5);
  msClamp.set(false);

  chassis.drive_to_point(-15, -60);
  chassis.turn_to_angle(225);
  chassis.drive_to_point(-7.518, -51.295);// 225
  msClamp.set(true);
  chassis.drive_to_point(-17.462, -47.9);// 270
  convey.spin(fwd, 100, pct);
  chassis.drive_to_point(-22, -17);
  convey.stop();
  chassis.drive_to_point(-24.496, -4.487);// 0
*/
}
//ENDVEXDOC

//! red alliance left side
/*startsummary
this is our max point route for the negative corner of the red alliance
endsummary*/
void leftNeg(){// red alliance
  chassis.set_coordinates(0, 0, -90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(0);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(1, sec);
  chassis.drive_distance(-12);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(2, sec);
  msClamp.set(true);
  convey.spin(fwd, 100, pct);
  wait(3, sec);
  //chassis.drive_distance(-3);
  //chassis.turn_to_angle(180);
  //chassis.drive_to_point(-30, -60);
  //wait(500, msec);
  chassis.turn_to_angle(180);
  convey.stop();
  chassis.drive_distance(23);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  msClamp.set(false);
  /*chassis.set_coordinates(-65, 27, 90);
  chassis.drive_to_point(-36, 33);// grab mobile stake
  chassis.turn_to_angle(315);
  msClamp.set(true);
  
  chassis.drive_to_point(-61.603, 61.239);// grab bottom and second to top ring
  frontConvey.spin(fwd, 100, pct);
  wait(50, msec);
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(500, msec);
  towerConvey.stop();
  chassis.drive_distance(5);// spit out second ring
  wait(50, msec);
  chassis.drive_distance(-5);
  chassis.right_swing_to_angle(45);
  frontConvey.spin(reverse, 100, pct);
  wait(75, msec);
  chassis.right_swing_to_angle(-45);// grab second ring we want
  frontConvey.spin(fwd, 100, pct);
  chassis.drive_distance(5);
  wait(50, msec);
  chassis.drive_distance(-5);
  convey.spin(fwd, 100, pct);
  wait(500, msec);
  towerConvey.stop();
  chassis.drive_distance(5);// replace top ring with mobile goal
  wait(50, msec);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(135);
  frontConvey.spin(reverse, 100, pct);
  chassis.drive_distance(-5);
  msClamp.set(false);

  chassis.drive_to_point(-38, 49);
  convey.spin(fwd, 100, pct);
  chassis.turn_to_angle(90);
  chassis.drive_to_point(-29, 49);// 90
  wait(50, msec);
  chassis.drive_to_point(-7, 51);// 90
  wait(50, msec);
  chassis.drive_to_point(-16, 47);// 90
  
  chassis.drive_to_point(-8.974, 43.049);// 90
  wait(50, msec);
  chassis.drive_distance(-5);
  chassis.drive_to_point(-25, 12);
  convey.stop();
  chassis.drive_to_point(-24.253, 6.427);// 180 */
}
//ENDVEXDOC

//! blue alliance negative side
/*startsummary
this is our solo autonomous win point for the negative corner for blue alliance
endsummary*/
void rightNeg(){// blue alliance
  chassis.set_coordinates(0, 0, 90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(0);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(1, sec);
  chassis.drive_distance(-12);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  wait(2, sec);
  msClamp.set(true);
  convey.spin(fwd, 100, pct);
  wait(3, sec);
  //chassis.drive_distance(-3);
  //chassis.turn_to_angle(180);
  //chassis.drive_to_point(-30, -60);
  //wait(500, msec);
  chassis.turn_to_angle(180);
  convey.stop();
  chassis.drive_distance(23);
  TL.stop(hold);
  ML.stop(hold);
  BL.stop(hold);
  TR.stop(hold);
  BR.stop(hold);
  MR.stop(hold);
  msClamp.set(false);
/*
  chassis.set_coordinates(66, 30, 180);
  chassis.drive_to_point(63.723, 4.258);// heading of 130
  chassis.turn_to_angle(130);
  // put preload onto alliance stake
  convey.spin(fwd, 100, pct);
  wait(50, msec);
  convey.stop();

  chassis.drive_to_point(32.822, 22.998);// heading of 90
  chassis.turn_to_angle(90);
  msClamp.set(true); // clamp ms stake
  chassis.drive_to_point(61.53, 60.676);// heading of 45
  // get bottom and second from top ring
  convey.spin(fwd, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.drive_distance(-10);
  convey.spin(fwd, 100, pct);
  wait(50, msec);
  convey.stop();
  chassis.drive_distance(10);
  convey.spin(fwd, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.drive_distance(-10);
  chassis.turn_to_angle(90);
  convey.spin(reverse, 100, pct);
  wait(25, msec);
  convey.stop();
  chassis.turn_to_angle(45);
  chassis.drive_distance(10);
  convey.spin(fwd, 100, pct);
  wait(25, msec);

  chassis.drive_to_point(29.433, 47.319);// heading of 270
  // get bottom ring
  chassis.drive_to_point(24.25, 56.889);// heading of 270
  chassis.drive_to_point(15.279, 50.11);// heading of 270
  chassis.drive_to_point(8.899, 50.11);// heading of 270
  // get bottom ring
  chassis.drive_to_point(18.269, 47.319);// heading of 0
  chassis.drive_to_point(18.468, 41.139);// heading of 270
  chassis.drive_to_point(9.298, 43.93);// heading of 270
  // get bottom ring
  chassis.drive_to_point(17.472, 36.155);// heading of 180
  chassis.drive_to_point(9.298, 19.409);// heading of 230
  convey.stop();
  // touch ladder*/
}
//ENDVEXDOC

//! skills
/*startsummary
this is our autonomous code for skills
endsummary*/
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
//ENDVEXDOC

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 15, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 500, 1500);
  chassis.set_turn_exit_conditions(1, 500, 3000);
  chassis.set_swing_exit_conditions(1, 500, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 3;
  chassis.drive_max_voltage = 4;
  chassis.drive_settle_error = 1;
  chassis.boomerang_lead = 0;// boomerang notes are after drive to point data in drive.cpp
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, 48);
  wait(500, msec);
  chassis.drive_to_point(0, 0);
  //chassis.drive_distance(48);
  //chassis.drive_distance(-48);
  /*chassis.turn_to_angle(90);
  wait(500, msec);
  chassis.turn_to_angle(-90);
  wait(500, msec);
  chassis.turn_to_angle(45);
  wait(500, msec);
  chassis.turn_to_angle(-135);
  wait(500, msec);
  chassis.turn_to_angle(0);*/
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
 * will be curved while the conveyrst is straight.
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