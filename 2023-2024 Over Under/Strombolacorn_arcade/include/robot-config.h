using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor TL;
extern motor BL;
extern motor TR;
extern motor BR;
extern inertial Inertial;
extern digital_out lpusher;
extern digital_out rpusher;
extern digital_out fpusher;
extern motor_group fly;
extern motor_group enter;
extern motor ML;
extern motor MR;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );