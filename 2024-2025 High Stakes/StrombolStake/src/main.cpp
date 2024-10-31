#include "vex.h"
#include <autons.h>

using namespace vex;
competition Competition;
int i = 0;
/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(TL, BL, ML),

//Right Motors:
motor_group(TR, BR, MR),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT11,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.8,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
357.7,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.25,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
4

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */
//! temperature print
/*startsummary
this is our code that will print the temperatures of the motors to the brain screen every 50 
miliseconds asynchronously while everything else runs
endsummary*/
int temperatures(){// prints temperature stuff during autonomous and user control every 100 ms
  while(auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 5, "Battery Percentage: %d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 55, "Heading is %d", imu.angle(deg));

    Brain.Screen.printAt(5, 15, "Top Left Temp: %d", TL.temperature(celsius), "Top Right Temp: %d", TR.temperature(celsius));
    Brain.Screen.printAt(5, 25, "Middle Left Temp: %d", ML.temperature(celsius), "Middle Right Temp: %d", MR.temperature(celsius));
    Brain.Screen.printAt(5, 35, "Bottom Left Temp: %d", BL.temperature(celsius), "Bottom Right Temp: %d", BR.temperature(celsius));
    
    /*Brain.Screen.printAt(50, 15, "Top Right Temp: %d", TR.temperature(celsius));
    Brain.Screen.printAt(50, 25, "Middle Right Temp: %d", MR.temperature(celsius));
    Brain.Screen.printAt(50, 35, "Bottom Right Temp: %d", BR.temperature(celsius));*/
    
    Brain.Screen.printAt(5, 45, "Conveyor Temp: %d", frontConvey.temperature(celsius));
    Brain.Screen.printAt(50, 45, "Tower is %d", towerConvey.temperature(celsius));
    
    wait(50, msec);
  }
  return 0;
}
//ENDVEXDOC
void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  imu.calibrate();
  armMotorA.setBrake(hold);// set arm to hold naturally when .stop is called
  armMotorB.setBrake(hold);// set arm to hold naturally when .stop is called
  towerConvey.setBrake(hold);// set conveytor to hold naturally when .stop is called
  frontConvey.setBrake(hold);
  vex::task temperature(temperatures);
  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage: %d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading: %2.f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 110, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 130, "Blue Alliance Positive corner");
        Brain.Screen.drawImageFromFile("blue pos v2.png", 100, 200);
        break;
      case 1:
        Brain.Screen.printAt(5, 130, "Red Alliance Positive corner");
        break;
      case 2:
        Brain.Screen.printAt(5, 130, "Red Alliance Negative corner");
        break;
      case 3:
        Brain.Screen.printAt(5, 130, "Blue Alliance Negative Corner");
        Brain.Screen.drawImageFromFile("blue neg v2.png", 100, 200);
        break;
      case 4:
        Brain.Screen.printAt(5, 130, "Skills");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 5){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}
//Brain.Screen.drawImageFromFile("file name", x,y); how to put pcture on brain screen
/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  //enableArmPid = true;
  switch(current_auton_selection){ 
        case 0:
        drive_test();
        //leftPos();
        break;
        case 1:         
        rightPos();
        break;
        case 2:
        leftNeg();
        break;
        case 3:
        rightNeg();
        break;
        case 4:
        skills();
        break;
        }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  //enableArmPid = false; // uninistializes the arm pid  
  //find out how to make printing a gif a task for user control
  while (1) {
    //enableArmPid = false; // uninistializes the arm pid
    chassis.control_arcade();
    arms();
    conveyor();
    pnumatics();
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  
 
  // Prevent main from exiting with an infinite loop.
  while(true) {
    wait(100, msec);
  }
}
